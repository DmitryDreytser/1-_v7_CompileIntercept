#pragma once

#include "../mycontextbase.h"

class CSettings : public CMyContextBase
{
	DECLARE_DYNCREATE(CSettings);

public:
	
	BOOL funcGet(CValue &RetVal, CValue **ppValue);
	
	BOOL procSet(CValue **ppValue); // 2 ���������
	BOOL procSetup(CValue **ppValue); // 1 ��������
	BOOL procClear(CValue **ppValue); // 1 ��������

	// service
	LPCSTR ResolveKey(LPCSTR key);
	LPCSTR ResolveKey(CValue *cvKey);
private:
		
	// ������������ ��� �������� ������� ��� �������� �����
	static LPCSTR m_voidKey;

	void Set(LPCSTR key, int iValue);

public:

	DECLARE_MY_CONTEXT();
};
