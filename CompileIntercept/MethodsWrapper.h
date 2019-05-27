
#ifndef METHODSWRAPPER_H
#define METHODSWRAPPER_H

HANDLE hProcess;
typedef unsigned __int64 ui64;

template <class TFunctionType>
class CDllMethodWrapper
{
private:
	ui64* m_pFunc;
	ui64 m_SwapBuf;
	DWORD m_dwProtection;
	
	union PtrC
	{
		void *pV;
		TFunctionType pMethod;
	};
	
	// ��������������� � ����� ����� "RestoreOrigAddress" � "RestoreWrapAddress"
	BOOL m_bIsActive;
public:
	CDllMethodWrapper() : m_pFunc(NULL), m_bIsActive(TRUE){};
	virtual ~CDllMethodWrapper(){};
	
	void Swap(void)
	{
		if (!IsWrapped()) {}
			//RuntimeError("CDllMethodWrapper::Swap failed: m_pFunc == NULL");
			
		VirtualProtect(m_pFunc, 8, PAGE_EXECUTE_READWRITE, &m_dwProtection);

		ui64 buf = *m_pFunc;
		*m_pFunc = m_SwapBuf;
		m_SwapBuf = buf;
		
		m_bIsActive = !m_bIsActive;

		VirtualProtect(m_pFunc, 8, m_dwProtection, &m_dwProtection);
		FlushInstructionCache(hProcess, m_pFunc, 8);
	}
	
	void RestoreOrigAddress(void)
	{
		if (!m_bIsActive)
			Swap();
		//	else
		//		Msg("double orig %x", m_pFunc);
	}
	
	void RestoreWrapAddress(void)
	{
		if (m_bIsActive)
			Swap();
		//	else
		//		Msg("double wrap %x", m_pFunc);
	}
	
	TFunctionType GetOrigMethod(void)
	{
		if (!IsWrapped()) {}
			//RuntimeError("CDllMethodWrapper::GetOrigMethod failed: m_pFunc == NULL");

		register PtrC conv;
		
		conv.pV = m_pFunc;
		return conv.pMethod;
	}
	
	// FALSE: �������� �� ����������; TRUE: �������� ��������
	BOOL IsWrapped(void)
	{
		return (m_pFunc != NULL);
	}
	
	// FALSE: ���������� ����� ���������� ���������
	// TRUE: ���������� ������������ ����������
	// ������������ ��� ���� ������� ������������� �����������
	BOOL IsActive(void)
	{
		return m_bIsActive;
	}
	
	void DoWrap(HINSTANCE hDllInstance, LPCSTR strMethodNameInDll, TFunctionType pNewFunc)
	{
		if (!IsWrapped())
		{
			m_pFunc = reinterpret_cast<ui64*>(GetProcAddress(hDllInstance, strMethodNameInDll));
			if (m_pFunc)
			{
				register PtrC conv;
				conv.pMethod = pNewFunc;
				
				// ���������� ������������� ��������
				m_SwapBuf = (static_cast<ui64>((DWORD)conv.pV - reinterpret_cast<DWORD>(m_pFunc)-5))<<8 | 0xE9;
				Swap();
			}
			else 
			{}
				//RuntimeError("DoWrap failed: %s", strMethodNameInDll);
		}
	};

	void DoWrap(DWORD dwrdMethodOffset, TFunctionType pNewFunc)
		{
			if (!IsWrapped())
			{
				m_pFunc = reinterpret_cast<ui64*>(dwrdMethodOffset);
				if (m_pFunc)
				{
					register PtrC conv;
					conv.pMethod = pNewFunc;
				
					// ���������� ������������� ��������
					m_SwapBuf = (static_cast<ui64>((DWORD)conv.pV - reinterpret_cast<DWORD>(m_pFunc)-5))<<8 | 0xE9;
					Swap();
				}
				else 
				{}
					//RuntimeError("DoWrap failed: %s", strMethodNameInDll);
			}
		};
	
};

// ������ ������ ������������ � �������� ��������� �������
template <class TFunctionType>
class CDllMethodWrapperGuard
{

	private:
		CDllMethodWrapper<TFunctionType>& m_DllMethodWrapper;
	
	public:
		CDllMethodWrapperGuard(CDllMethodWrapper<TFunctionType>& aDllMethodWrapper ) :
			m_DllMethodWrapper(aDllMethodWrapper)
		{
			m_DllMethodWrapper.RestoreOrigAddress();
		};

		~CDllMethodWrapperGuard()
		{
			m_DllMethodWrapper.RestoreWrapAddress();
		};

		TFunctionType GetOrigMethod(void)
		{
			return m_DllMethodWrapper.GetOrigMethod();
		}
		
};

class CTrapSwap
{
public:
	CTrapSwap() : m_pFunc(NULL), m_SwapBuf(0), m_bTrapped(FALSE) {}

	template<typename T>
	void SetTrapByName(HINSTANCE hDll, LPCSTR strFuncName, T newFunc)
	{
		DWORD* pFunc=reinterpret_cast<DWORD*>(GetProcAddress(hDll, strFuncName));
		if (!pFunc) {};
			//RuntimeError("������ ��������� ��������� �� ������� %s", strFuncName);

		DWORD pNewFunc=*reinterpret_cast<DWORD*>(&newFunc);
		_SetTrap(pFunc, pNewFunc);
	}
	
	template<typename T>
	void SetTrapByName(LPCSTR strDll, LPCSTR strFuncName, T newFunc)
	{
		HINSTANCE hDll = GetModuleHandle(strDll);
		if (!hDll) {};
			//RuntimeError("������ ��������� ����������� ������ %s", strDll);

		SetTrapByName(hDll, strFuncName, newFunc);
	}

	template<typename T, typename M>
	void SetTrapOnImportFunc(T oldFunc, M newFunc)
	{
		BYTE* ptr=*reinterpret_cast<BYTE**>(&oldFunc);
		ptr+=2;
		DWORD* pFunc=**reinterpret_cast<DWORD***>(ptr);
		DWORD pNewFunc=*reinterpret_cast<DWORD*>(&newFunc);
		_SetTrap(pFunc, pNewFunc);
	}

	template<typename T, typename M>
	void SetTrapOnFunc(T oldFunc, M newFunc)
	{
		DWORD* pFunc=*reinterpret_cast<DWORD**>(&oldFunc);
		DWORD pNewFunc=*reinterpret_cast<DWORD*>(&newFunc);
		_SetTrap(pFunc, pNewFunc);
	}

	void Swap()
	{
		VirtualProtect(m_pFunc, 8, PAGE_EXECUTE_READWRITE, &m_dwProtection);

		ui64 t = *m_pFunc;
		*m_pFunc = m_SwapBuf;
		m_SwapBuf = t;

		m_bTrapped ^= TRUE;

		VirtualProtect(m_pFunc, 8, m_dwProtection, &m_dwProtection);
		FlushInstructionCache(hProcess, m_pFunc, 8);
	}

	BOOL IsTrapped() const { return m_bTrapped; }
	
protected:

	ui64* m_pFunc;

	ui64 m_SwapBuf;
	DWORD m_dwProtection;
	BOOL m_bTrapped;

	void _SetTrap(DWORD* pFunc, DWORD pNewFunc)
	{
		m_pFunc=reinterpret_cast<ui64*>(pFunc);
		// ��������� ����� �� ����� ����� �������
		m_SwapBuf = (static_cast<ui64>(pNewFunc - reinterpret_cast<DWORD>(pFunc)-5)<<8) | 0xE9;
		// � ��������� � ������ ������� �������������� �����
		Swap();
	}
};

struct trapswapper
{
	CTrapSwap& trap;
	trapswapper(CTrapSwap& t):trap(t){trap.Swap();}
	~trapswapper(){trap.Swap();}
};

#endif
