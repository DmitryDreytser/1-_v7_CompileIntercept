
#include "stdafx.h"
#include "..\\TurboBL\\gcboost.h"

#include "GroupContextWrap.h"
#include "DllHooker.h"
#include "..\\ExecuteModule.h"

//CHookGroupContext hookInstaller;
//CHookGroupContext::PHookGroupContext hookInstaller(new CHookGroupContext);
//CHookGroupContext::PHookGroupContext CHookGroupContext::hookInstaller(new CHookGroupContext);
CHookGroupContext::PHookGroupContext CHookGroupContext::hookInstaller(NULL);

#ifndef VK_FormEx_Hooks

//typedef int(CBLModule::*PF_FF)(char const * ); //const;
CDllMethodWrapper<PF_FF> wrapperFindFunc;

//typedef int(CBLModule::*PF_FP)(char const * ,int ); //const;
CDllMethodWrapper<PF_FP> wrapperFindProc;

// typedef int(CBLModule::*PF_CAP)(int,int,CValue * *);
CDllMethodWrapper<PF_CAP> wrapperCallAsProc;

// typedef int(CBLModule::*PF_CAF)(int,CValue &,int,CValue * *);
CDllMethodWrapper<PF_CAF> wrapperCallAsFunc;

// typedef int(CBLModule::*PF_GPI)(int,class CBLProcInfo &); //const;
CDllMethodWrapper<PF_GPI> wrapperGetProcInfo;

// typedef void (CGetDoc7::*PF_ONCD)(void);
//CDllMethodWrapper<PF_ONCD> wrapperOnCloseDocument;

CDllMethodWrapper<PF_CGetDoc7Destructor> wrapperGetDoc7Destructor;

#endif

// typedef void (CBLProcInfo::*PF_CBLProcInfo)(void);
CDllMethodWrapper<PF_CBLProcInfo> wrapperCBLProcInfo_CBLProcInfo;

// typedef int  (CBLProcInfo::*PF_GetNParams)(void); //const;
CDllMethodWrapper<PF_GetNParams> wrapperCBLProcInfo_GetNParams;

// typedef int  (CBLProcInfo::*PF_GetType)(void); //const;
CDllMethodWrapper<PF_GetType> wrapperCBLProcInfo_GetType;

// typedef int  (CBLProcInfo::*PF_CBLProcInfo_IsExported)(void); //const;
CDllMethodWrapper<PF_CBLProcInfo_IsExported> wrapperCBLProcInfo_IsExported;

// typedef	int  (CBLModule7::*CBLModule7_PF_ExecProc)(unsigned int,int,CValue *,int,CValue * *,int,int);	//592
CDllMethodWrapper<CBLModule7_PF_ExecProc> wrapperCBLModule7_ExecProc;

// typedef	int (CBLModule::*CBLModule_PF_IsCompiled)(void)const;
CDllMethodWrapper<CBLModule_PF_IsCompiled> wrapperCBLModule_IsCompiled;

// CDllMethodWrapper<CValue_PF_CopyConstructor> wrapperCValue_CopyConstructor;
CDllMethodWrapper<CNumeric_PF_Constructor> wrapperCNumeric_Constructor;

//void  CMainMessageHandler::WriteError(char const *,enum MessageMarker,char const *,long,int,int);	//371
typedef	int (CMainMessageHandler::*CMainMessageHandler_PF_WriteError)(char const *,enum MessageMarker,char const *,long,int,int);
CDllMethodWrapper<CMainMessageHandler_PF_WriteError> wrapperCMainMessageHandler_WriteError;

// 	int  ReportEventA(CString EventCategory,CString Event,enum EventType EvType,CString comment,CString object,CString ObjDescr);	//1683
typedef	int (CAdminService::*CAdminService_PF_ReportEventA)(CString EventCategory,CString Event,enum EventType EvType,CString comment,CString object,CString ObjDescr);
CDllMethodWrapper<CAdminService_PF_ReportEventA> wrapperCAdminService_ReportEventA;

// 	int  ReportUserEvent(CString,CString,enum EventType,CString,CValue *,CString);	//1684
typedef	int (CAdminService::*CAdminService_PF_ReportUserEvent)(CString,CString,enum EventType,CString,CValue *,CString);
CDllMethodWrapper<CAdminService_PF_ReportUserEvent> wrapperCAdminService_ReportUserEvent;

//void  WriteMessage(char const *,class CMessageInfo &,int);	//372
typedef	void (CMainMessageHandler::*CMainMessageHandler_PF_WriteMessage)(char const *,class CMessageInfo &,int);
CDllMethodWrapper<CMainMessageHandler_PF_WriteMessage> wrapperCMainMessageHandler_PF_WriteMessage;

void CHookGroupContext::DisableToFormClose(CBLContext* pCont)
{
	CBLModule* pMod = GetModuleByContext((CGroupContext*)pCont);
	GetHooker()->m_MapNotClosedModules[pMod] = NULL;
	GetHooker()->m_MapDisableOnCloseEvent[pMod] = NULL;

//LogErr("DisableToFormClose pCont = %d pMod = %d", pCont, pMod);
}

void CHookGroupContext::EnableToFormClose(CBLContext* pCont)
{
	CBLModule* pMod = GetModuleByContext((CGroupContext*)pCont);
	GetHooker()->m_MapNotClosedModules.RemoveKey(pMod);

//LogErr("EnableToFormClose pCont = %d pMod = %d", pCont, pMod);
}

void CHookGroupContext::IfWrapEnableThenRestoreWrapAddressForEvents() const
{
	if (wrapperCallAsProc.IsWrapped())
		wrapperCallAsProc.RestoreWrapAddress();
	if (wrapperCallAsFunc.IsWrapped())
	wrapperCallAsFunc.RestoreWrapAddress();
}

// artbear
// ���������� ��������� ������ - http://www.1cpp.ru/forum/YaBB.pl?num=1172047061/80#80
// ��������, ���� ��� ������� ������ �� �������� ����� � ������ � ������������ 
//	�������� ��� �� �������� �����-�� ����� ����� (������������), 
// � ���� ������ �� ����� ������ �������� ������� 1�.  
// ��� ��������� �� ���� ������� �������, � ������� ���� ������ ��������� - 
// ��� �����, �������� ����� �� �������, �������� �� ����������. 
//  
// ������� ��� � ���, ��� ��� ��������� ������� �� ������ ������� ���������� ���������� 
// ������������, ������� ���������� ���������� 1�, 
// �������������� ��� ������������� ������� CBLModule7::ExecProc. 
// ��� �������� ������� 1� �������� ��� 1� �� ��������� �����������, ������� � ���� ������� 
// � �������� ������������. ��� �������� ����� 1� �������� ��������� ������� CBLModule7::ExecProc,
// �������� �� ������� �� ����������  � ���������� �����
//
// ����� �� �������� ������ ����� - �� ���� 1� �����, ��� 1� ������ ��� ������ CBLModule7::ExecProc
// �������� ����� CBLModule::IsCompiled
// ������� ����� ������� �������� CBLModule7::ExecProc (� ���� ������ �������� ���� ������� ��� ����, ��� ����� �����)
// � ������������ CBLModule::IsCompiled � ������� �������� CBLModule7::ExecProc
// ����� ������� � ���� �������� CBLModule::IsCompiled � �������������� ���� �� �������� CBLModule7::ExecProc
// ����� ����� �������� CBLModule::IsCompiled ��������� � ��� �������� ��� ������
// � �����, �������� ������ !! ��� :)


class CWrapper_ExecProc_Guard
{
	static bool isNeedAddWrapExecProc;
public:
	CWrapper_ExecProc_Guard()
	{
		wrapperCBLModule_IsCompiled.RestoreWrapAddress(); // ������������ ��������
		isNeedAddWrapExecProc = true;
	};

	~CWrapper_ExecProc_Guard()
	{
		wrapperCBLModule_IsCompiled.RestoreOrigAddress(); // ������ ��������
	};

	static void RestoreWrapAddress()
	{
		if (isNeedAddWrapExecProc)
		{
			wrapperCBLModule7_ExecProc.RestoreWrapAddress(); // ������������ ��������
			isNeedAddWrapExecProc = true;
//LogErr("CBLModule_IsCompiled RestoreWrapAddress of ExecProc");

			wrapperFindProc.RestoreWrapAddress();
			wrapperFindFunc.RestoreWrapAddress();
		}
		isNeedAddWrapExecProc = false;

	}
};

bool CWrapper_ExecProc_Guard::isNeedAddWrapExecProc = false;

int CHookGroupContext::CBLModule_IsCompiled(void)
{
	CDllMethodWrapperGuard<CBLModule_PF_IsCompiled> wrapper(wrapperCBLModule_IsCompiled);
	CWrapper_ExecProc_Guard::RestoreWrapAddress();

	CBLModule* pThisMod = (CBLModule*)this;
	return pThisMod->IsCompiled();
}

int  CHookGroupContext::CBLModule7_ExecProc(unsigned int iStringResourceId,int bFlagNotShowErrorIfNotFoundProcFunc,CValue *value1,int iParamsCount, CValue * *params,int i4, int i5)	//592
{
	CBLModule7* pThisMod = (CBLModule7*)this;
	
	char resStr[255];
	HINSTANCE h1CResource = AfxGetResourceHandle();
	::LoadString(h1CResource, iStringResourceId, resStr, 255);

//LogErr("CBLModule7_ExecProc %s<%s(%d)> %d %s<%d> %d %d", "iStringResourceId", resStr, iStringResourceId, bFlagNotShowErrorIfNotFoundProcFunc, "iParamsCount", iParamsCount, i4, i5);
/*
LogErr("CBLModule7_ExecProc (pMod = %d) pCont = %d ", pThisMod, CBLModuleWrapper::GetContextFromModule(pThisMod));
*/

	// ������� ��� ���� "OnOpen,�����������" �� ��� ������
	char* sEngName; char* sRusName;
	sRusName = strchr(resStr, ',');
	sRusName[0] = '\0'; 
	sRusName++;
	sEngName = resStr;

	//bFlagNotShowErrorIfNotFoundProcFunc = 0; // ��������, ��� �������� ����� ���� � ������ ��� �����������, ������ ������
	
	// ���� ������� 0, ��������� �������� ����������� �� �����
	int ret = TRUE;
	
	const ULONG iResId_OnOpen = 2935;
	const ULONG iResId_InputNew = 2903;
	const ULONG iResId_InputCausedBy = 2902;
	const ULONG iResId_OnClose = 2946;

	//������� ���� ����������� ��� ����������� ������, � ����� ��� ����������
	switch (iStringResourceId)
	{
		case iResId_OnOpen:	// OnOpen,�����������
		case iResId_InputNew:	// InputNew,����������
		case iResId_InputCausedBy:	// InputCausedBy,���������������
		{
			CDllMethodWrapperGuard<CBLModule7_PF_ExecProc> wrapper(wrapperCBLModule7_ExecProc);
			CWrapper_ExecProc_Guard wrapper_ExecProc;

			int iRes = CEventsWrapperManager::GetWrapper()->FindAndRunGlobalModuleEventHandler(sRusName, sEngName, pThisMod, iParamsCount, params);
			if (iRes)
				return iRes;
			
			break;
		}
		default:
			break;
	}

	{
		CDllMethodWrapperGuard<CBLModule7_PF_ExecProc> wrapper(wrapperCBLModule7_ExecProc);
		CWrapper_ExecProc_Guard wrapper_ExecProc;
		
		int iRes = CEventsWrapperManager::GetWrapper()->FindAndRunModuleEventHandler(pThisMod, sRusName, sEngName, params);
		if (iRes) 
			return iRes;	
		else
		{
// 			CDllMethodWrapperGuard<CBLModule7_PF_ExecProc> wrapper(wrapperCBLModule7_ExecProc);
// 			CWrapper_ExecProc_Guard wrapper_ExecProc;
			
			ret = (pThisMod->*wrapper.GetOrigMethod())(iStringResourceId, bFlagNotShowErrorIfNotFoundProcFunc,value1,iParamsCount, params,i4, i5);
		}
	}

	if (iResId_OnClose == iStringResourceId) // �����������
	{
		void *p;
		if (GetHooker()->m_MapNotClosedModules.Lookup(pThisMod, p))
			pThisMod->SetStatusCode(0);

		/*  ---------------------------------------------------
			TODO � ��������� ��-�� ��������� �������
				���������� ��� http://cvs.alterplast.ru/bugs/show_bug.cgi?id=2622

				���������� �������, ��������� � ������ �������, �� ���� ������� 1�

				��������, ���� 
				� ���������� ������ ��������
				����� ��������;
				��������� ����������������������()
						��������������������������("1cpp.dll");
				// � ������ �������� ����� �������
						�������� = �������������("���"); 
				// ������ ������ � ������ �������, ��� ���������� ����� ����� �� ������
				��������������  // ���������������������� 

				����� ������� ����� ������������ � ������ �������
				1� ���������� ������� ������������ ���������� :(

				� ���������, �� �������� � ����� ����� �������
				��������� ��������������������������()
						�������� = 0;
				��������������  // ��������������������������
				�� ���� ��������� ���� ������ �� ������� :(

				������� ������� ������� � ���� ������ - ����. ���������, ���������� ��� ���������� �������

		  --------------------------------------------------- */		
	}

	return ret;
}

#ifndef VK_FormEx_Hooks

int  CHookGroupContext::CBLModule_GetProcInfo(int nProc, class CBLProcInfo & cProcInfo) //const
{
	int ret = 0;
	CDllMethodWrapperGuard<PF_GPI> wrapper(wrapperGetProcInfo);
//LogErr("%s c ������� %d, %s = %d", "CBLModule_GetProcInfo", nProc, "pMod", (CBLModule*)this);

	ret = CEventsWrapperManager::GetWrapper()->GetProcInfo((CBLModule*)this, nProc, cProcInfo);
//LogErr("� ��������� ��������� %d", ret);
//LogErr("� ��������� cProcInfo.GetName() %s", cProcInfo.GetName());
	if (!ret)
		ret = ((CBLModule*)this)->GetProcInfo(nProc, cProcInfo);

	CString szName = cProcInfo.GetName();
//LogErr("������� ���������� cProcInfo.GetName() %s", cProcInfo.GetName());

//LogErr("������� ���������� ��������� %d", ret);
	return ret;
}

int  CHookGroupContext::CBLModule_FindFunc(char const * fName) //const
{
	int ret = -1;
	CDllMethodWrapperGuard<PF_FF> wrapper(wrapperFindFunc);

	CBLModule* pThisMod = (CBLModule*)this;
//LogErr("%s ����� %s", "WrapFindFunc", fName);

	int ret1 = CEventsWrapperManager::GetWrapper()->FindFunc(pThisMod, fName);
	if (-1 != ret1)
	{
		return ret1;
	}
	else
		//ret = (((CBLModule*)this)->*wrapper.GetOrigMethod())(fName);
		if (-1 == ret)
			ret = (pThisMod->*wrapper.GetOrigMethod())(fName);

	return ret;
}

int CHookGroupContext::FindOriginalEventOfGlobalModule(const CString& sEventName)
{
	CDllMethodWrapperGuard<PF_FP> wrapper(wrapperFindProc);
	CBLModule* pMod = ::GetGlobalModule();
	int ret = pMod->FindProc(sEventName, 1);
	if (-1 == ret)
		ret = pMod->FindProc(sEventName, 0);

	return ret;
}

int  CHookGroupContext::CBLModule_FindProc(char const * pName,int flag) //const
{
	int ret = -1;
	CBLModule* pThisMod = (CBLModule*)this;

	CDllMethodWrapperGuard<PF_FP> wrapper(wrapperFindProc);

// LogErr("%s ����� %s c ������ %d", "WrapFindProc", pName, flag);

	void* p;
	if (GetHooker()->m_MapDisableOnCloseEvent.Lookup(pThisMod, p))
	{
		if (!strcmp("�����������", pName) || !strcmp("OnClose", pName))
		{
//LogErr("%s ����� %s c ������ %d - ����� ����� <%d>", "WrapFindProc", pName, flag, -1);
			GetHooker()->m_MapDisableOnCloseEvent.RemoveKey(pThisMod);
			return -1;
		}
	}

	int ret1 = CEventsWrapperManager::GetWrapper()->FindProc(pThisMod, pName,flag);
	if (-1 != ret1)
	{
//LogErr("%s ����� %s c ������ %d - ��� ����� %d", "WrapFindProc", pName, flag, ret1);
		
		// TODO ???
// 		1//if (strcmp(pName,"�������������������")) // ��� ����� ������� �� RWidjets �� �������� !
// 		// ��-�� FormEx ���������� ��� ����������� :(
// 		// � ��������� ������ �� ���������� �����������/��������� ����� ������� ������� !
 		wrapperCallAsProc.RestoreWrapAddress();

		return ret1;
	}
	else
		if (-1 == ret)
			ret = ((CBLModule*)this)->FindProc(pName,flag);

//LogErr("%s ����� %s c ������ %d - ������� ����� ����� <%d>", "WrapFindProc", pName, flag, ret);
	return ret;
}

int CHookGroupContext::CBLModule_CallAsFunc(int num,CValue & retValue,int argNum,CValue * * ppValue)
{
	int ret = FALSE;
	CDllMethodWrapperGuard<PF_CAF> wrapper(wrapperCallAsFunc);

//LogErr("%s c ������� %d, %s = %d", "WrapCallAsFunc", num, "pMod", (CBLModule*)this);

	int ret1 = CEventsWrapperManager::GetWrapper()->CallAsFunc((CBLModule7*)this, num,retValue,argNum,ppValue);
	if (ret1)
	{
		return ret1;
	}
	else
		ret = ((CBLModule*)this)->CallAsFunc(num,retValue,argNum,ppValue);

	return ret;
}

int CHookGroupContext::CBLModule_CallAsProc(int num,int argNum,CValue * * ppValue)
{
	int ret = FALSE;
	CDllMethodWrapperGuard<PF_CAP> wrapper(wrapperCallAsProc);

//LogErr("%s c ������� %d, %s = %d", "WrapCallAsProc", num, "pMod", (CBLModule*)this);

	int ret1 = CEventsWrapperManager::GetWrapper()->CallAsProc((CBLModule7*)this, num,argNum,ppValue);
	if (ret1)
	{
		return ret1;
	}
	else
		ret = ((CBLModule*)this)->CallAsProc(num,argNum,ppValue);

	return ret;
}

// 1//CGetDoc7::OnCloseDocument
// void CHookGroupContext::CGetDoc7_OnCloseDocument(void)
// {
// 	CGetDoc7* ThisDoc = (CGetDoc7*)this;
// 	
// 	{ // ��������� ���� ����� ��� �������������� ������
// 		CDllMethodWrapperGuard<PF_ONCD> wrapper(wrapperOnCloseDocument);
// 		(ThisDoc->*wrapper.GetOrigMethod())();
// 
// 		CEventsWrapperManager::GetWrapper()->DestroyWrapper(ThisDoc->m_pBLModule);
// 
// 		GetHooker()->m_MapNotClosedModules.RemoveKey(ThisDoc->m_pBLModule);
// 
// 	}
// }

void CHookGroupContext::CGetDoc7_Destructor(void)
{
	CGetDoc7* ThisDoc = (CGetDoc7*)this;

// 	CGetDoc7* doc1 = NULL;
// 	delete doc1;

	CEventsWrapperManager::GetWrapper()->DestroyWrapper(ThisDoc->m_pBLModule);

	GetHooker()->m_MapNotClosedModules.RemoveKey(ThisDoc->m_pBLModule);

	{ // ��������� ���� ����� ��� �������������� ������
		CDllMethodWrapperGuard<PF_CGetDoc7Destructor> wrapper(wrapperGetDoc7Destructor);
		(ThisDoc->*wrapper.GetOrigMethod())();
	}
}

#endif // VK_FormEx_Hooks

// ��������� 3 ������ ����� ��� ��������� ������� FormEx, ������� ��� � ������ �����
// TODO � FormEx ��� ��� ������ ���������� � ����.�������
// ������� ����������� CBLProcInfo
// ����� (�� �� ������ ���������� !) ��� ������ - GetType � GetNParams
//
// TODO �.�. ���� ���������� � ������� ��������� :(
// ������ ��� ����� ������ ����������������� :(
//
//
CBLProcInfo* CHookGroupContext::CBLProcInfo_CBLProcInfo(void)
{
	CBLProcInfo* ThisProcInfo = (CBLProcInfo*)this;
	CDllMethodWrapperGuard<PF_CBLProcInfo> wrapper(wrapperCBLProcInfo_CBLProcInfo);

	(ThisProcInfo->*wrapper.GetOrigMethod())();
	
	CEventsWrapperManager::GetWrapper()->CBLProcInfo_CBLProcInfo();
	return ThisProcInfo;
}

int  CHookGroupContext::CBLProcInfo_GetType(void)
{
	CBLProcInfo* ThisProcInfo = (CBLProcInfo*)this;
	CDllMethodWrapperGuard<PF_GetType> wrapper(wrapperCBLProcInfo_GetType);

	return 	CEventsWrapperManager::GetWrapper()->CBLProcInfo_GetType(ThisProcInfo);
}

int  CHookGroupContext::CBLProcInfo_GetNParams(void)
{
	CBLProcInfo* ThisProcInfo = (CBLProcInfo*)this;
	CDllMethodWrapperGuard<PF_GetNParams> wrapper(wrapperCBLProcInfo_GetNParams);

	return 	CEventsWrapperManager::GetWrapper()->CBLProcInfo_GetNParams(ThisProcInfo);
}

int  CHookGroupContext::CBLProcInfo_IsExported(void)
{
	CBLProcInfo* ThisProcInfo = (CBLProcInfo*)this;
	CDllMethodWrapperGuard<PF_CBLProcInfo_IsExported> wrapper(wrapperCBLProcInfo_IsExported);

	//int iIsExported = 1;
	//int iIsExported = ThisProcInfo->IsExported();
	int iIsExported = CEventsWrapperManager::GetWrapper()->CBLProcInfo_IsExported(ThisProcInfo);
	return iIsExported;
}

enum GlobalModuleEvents
{
    meOnCMainMessageHandler_WriteError,
    meOnCAdminService_ReportEventA,
	meOnCAdminService_ReportUserEvent,
    meLastEvent
};

stModuleEventData CV7GlobalEvents[]  =  
{
    {"��������������������", "UnHandledError", 6},
    {"�������������������������������", "ReportEventA", 6},
    {"������������������������������������������������", "ReportUserEvent", 6},
};

bool CV7IsGlobalEventsAdded[]  =  
{
    false,
    false,
    false,
};

void  CHookGroupContext::CMainMessageHandler_WriteError(char const * szErrorMessage, enum MessageMarker marker, char const * szFileName, long param_IntegerNegativeOne, int iErrorRow, int param_IntegerOne)
{
	CDllMethodWrapperGuard<CMainMessageHandler_PF_WriteError> wrapper(wrapperCMainMessageHandler_WriteError);

	CMainMessageHandler* pThisHandler = (CMainMessageHandler*)this;

	BOOL bSuccess = TRUE;

	// ����� ������� ��

	if (GetModuleEventManager().IsAppointed(meOnCMainMessageHandler_WriteError))
	{
		CValue vP_FlagUseSystem(bSuccess);

		CValue vP_ErrorMessage(szErrorMessage);
		CValue vP_Marker(marker);
		CValue vP_FileName(szFileName);
		CValue vP_param_IntegerNegativeOne(param_IntegerNegativeOne);
		CValue vP_iErrorRow(iErrorRow);
		CValue vP_param_IntegerOne(param_IntegerOne);
		CValue* ppValues[] = {&vP_ErrorMessage, &vP_Marker, &vP_FileName, &vP_param_IntegerNegativeOne, &vP_iErrorRow, &vP_param_IntegerOne};

		//CExecBatchHelper ExecBatchHelper(pDoc, FALSE);
		GetModuleEventManager().InvokeEvent(meOnCMainMessageHandler_WriteError, vP_FlagUseSystem, ppValues);

		bSuccess = vP_FlagUseSystem.GetNumeric().operator long();
	}

	if (bSuccess)
		pThisHandler->WriteError(szErrorMessage, marker, szFileName, param_IntegerNegativeOne, iErrorRow, param_IntegerOne);
}

int CHookGroupContext::CAdminService_ReportEventA(CString EventCategory, CString Event, int EvType, CString comment,CString object,CString ObjDescr)
{
	CDllMethodWrapperGuard<CAdminService_PF_ReportEventA> wrapper(wrapperCAdminService_ReportEventA);

	CAdminService* pThisHandler = (CAdminService*)this;

	BOOL bSuccess = TRUE;

	// ����� ������� ��

	if (GetModuleEventManager().IsAppointed(meOnCAdminService_ReportEventA))
	{
		CValue vP_FlagUseSystem(bSuccess);

		CValue vP_EventCategory(EventCategory);
		CValue vP_Event(Event);
		CValue vP_EvType(EvType);
		CValue vP_comment(comment);
		CValue vP_object(object);
		CValue vP_ObjDescr(ObjDescr);
		CValue* ppValues[] = {&vP_EventCategory, &vP_Event, &vP_EvType, &vP_comment, &vP_object, &vP_ObjDescr};

		//CExecBatchHelper ExecBatchHelper(pDoc, FALSE);
		GetModuleEventManager().InvokeEvent(meOnCAdminService_ReportEventA, vP_FlagUseSystem, ppValues);

		bSuccess = vP_FlagUseSystem.GetNumeric().operator long();
	}

	if (bSuccess)
		return pThisHandler->ReportEventA(EventCategory, Event, (EventType)EvType, comment, object, ObjDescr);
	else
		return TRUE;
}

int CHookGroupContext::CAdminService_ReportUserEvent(CString EventCategory, CString Event, int EvType, CString comment, CValue * pValue, CString ObjDescr)
{
	CDllMethodWrapperGuard<CAdminService_PF_ReportUserEvent> wrapper(wrapperCAdminService_ReportUserEvent);

	CAdminService* pThisHandler = (CAdminService*)this;

	BOOL bSuccess = TRUE;

	// ����� ������� ��

	if (GetModuleEventManager().IsAppointed(meOnCAdminService_ReportEventA))
	{
		CValue vP_FlagUseSystem(bSuccess);

		CValue vP_EventCategory(EventCategory);
		CValue vP_Event(Event);
		CValue vP_EvType(EvType);
		CValue vP_comment(comment);
		//CValue& vP_object(*pValue);
		CValue vP_ObjDescr(ObjDescr);
		CValue* ppValues[] = {&vP_EventCategory, &vP_Event, &vP_EvType, &vP_comment, pValue, &vP_ObjDescr};

		//CExecBatchHelper ExecBatchHelper(pDoc, FALSE);
		GetModuleEventManager().InvokeEvent(meOnCAdminService_ReportEventA, vP_FlagUseSystem, ppValues);

		bSuccess = vP_FlagUseSystem.GetNumeric().operator long();
	}

	if (bSuccess)
		return pThisHandler->ReportUserEvent(EventCategory, Event, (EventType)EvType, comment, pValue, ObjDescr);
	else
		return TRUE;
}

void CHookGroupContext::AddGlobalEvent(int EventIndex)
{
	GlobalModuleEvents event = (GlobalModuleEvents)EventIndex;
	CV7IsGlobalEventsAdded[event] = GetModuleEventManager().AddEvent(CV7GlobalEvents[event], "�������_");
}

void CHookGroupContext::AddGlobalEvent(void)
{
	GetModuleEventManager().ClearEvents();
	
	AddGlobalEvent(meOnCMainMessageHandler_WriteError);
	AddGlobalEvent(meOnCAdminService_ReportEventA);
	AddGlobalEvent(meOnCAdminService_ReportUserEvent);
}

void CHookGroupContext::AddEvent_UnHandledError(void)
{
	VerifyEnabled();
	AddGlobalEvent();
	
	bool bSuccess = CV7IsGlobalEventsAdded[meOnCMainMessageHandler_WriteError];
	if (!bSuccess)
		return;

	wrapperCMainMessageHandler_WriteError.RestoreWrapAddress();
// 	bool bSuccess = GetModuleEventManager().AddEvent(CV7GlobalEvents[meOnCMainMessageHandler_WriteError], "�������_");
// 	if (!bSuccess)
// 		wrapperCMainMessageHandler_WriteError.RestoreOrigAddress();
}

void CHookGroupContext::AddEvent_ReportEventA(void)
{
	VerifyEnabled();
	AddGlobalEvent();

	bool bSuccess = CV7IsGlobalEventsAdded[meOnCAdminService_ReportEventA];
	if (!bSuccess)
		return;

	wrapperCAdminService_ReportEventA.RestoreWrapAddress();
// 	bool bSuccess = GetModuleEventManager().AddEvent(CV7GlobalEvents[meOnCAdminService_ReportEventA], "�������_");
// 	if (!bSuccess)
// 		wrapperCAdminService_ReportEventA.RestoreOrigAddress();
}

void CHookGroupContext::AddEvent_ReportUserEvent(void)
{
	VerifyEnabled();
	AddGlobalEvent();

	bool bSuccess = CV7IsGlobalEventsAdded[meOnCAdminService_ReportUserEvent];
	if (!bSuccess)
		return;

 	wrapperCAdminService_ReportUserEvent.RestoreWrapAddress();
// 	bool bSuccess = GetModuleEventManager().AddEvent(CV7GlobalEvents[meOnCAdminService_ReportUserEvent], "�������_");
// 	if (!bSuccess)
// 		wrapperCAdminService_ReportUserEvent.RestoreOrigAddress();
}

void CHookGroupContext::VerifyEnabled() const
{
	if (!IsEnabled())
		RuntimeError("���������� �������� �������� ������� � ������� ����������� ������ 1�++ - ���������������������.");
}

// CValue* CHookGroupContext::CValue_CopyConstructor(CValue const & Value)
// {
// 	CValue* ThisValue = (CValue*)this;
// 
// 	CDllMethodWrapperGuard<CValue_PF_CopyConstructor> wrapper(wrapperCValue_CopyConstructor);
// 	//CWrapper_ExecProc_Guard::RestoreWrapAddress();
// 
// 	(ThisValue->*wrapper.GetOrigMethod())(Value);
// 	
// 	return ThisValue;
// }

bool CWrapper_CBLModule_CallAs_Guard::isNeedAddWrapCallAsMethods = false;

CNumeric* CHookGroupContext::CNumeric_Constructor(void)
{
	CNumeric* ThisNumeric = (CNumeric*)this;

	CDllMethodWrapperGuard<CNumeric_PF_Constructor> wrapper(wrapperCNumeric_Constructor);
	
	CWrapper_CBLModule_CallAs_Guard::RestoreWrapAddress();

	(ThisNumeric->*wrapper.GetOrigMethod())();
	
	return ThisNumeric;
}

void CHookGroupContext::InitHooks(void)
{
	CHookGroupContext::GetHooker()->SetHook(); 

	CHookGroupContext::GetModuleEventManager().Init(::GetGlobalModule());
	
}

void CHookGroupContext::SetHook(void)
{
	m_bEnable = true;

	HINSTANCE hBl = GetModuleHandle("blang.dll");
	HINSTANCE hSev = GetModuleHandle("seven.dll");
	HINSTANCE hBas = GetModuleHandle("basic.dll");
	HINSTANCE hTxtEdt = GetModuleHandle("txtedt.dll");
	//HINSTANCE hBkEnd = GetModuleHandle("bkend.dll");
	HINSTANCE hType32 = GetModuleHandle("type32.dll");

#ifndef VK_FormEx_Hooks
	wrapperCallAsFunc.DoWrap(hBl, "?CallAsFunc@CBLModule@@QAEHHAAVCValue@@HPAPAV2@@Z", (PF_CAF)&CHookGroupContext::CBLModule_CallAsFunc);

	wrapperCallAsProc.DoWrap(hBl, "?CallAsProc@CBLModule@@QAEHHHPAPAVCValue@@@Z", (PF_CAP)&CHookGroupContext::CBLModule_CallAsProc);

	wrapperFindProc.DoWrap(hBl, "?FindProc@CBLModule@@QBEHPBDH@Z", (PF_FP)&CHookGroupContext::CBLModule_FindProc);

	wrapperFindFunc.DoWrap(hBl,"?FindFunc@CBLModule@@QBEHPBD@Z", (PF_FF)&CHookGroupContext::CBLModule_FindFunc);

	wrapperGetProcInfo.DoWrap(hBl, "?GetProcInfo@CBLModule@@QBEHHAAVCBLProcInfo@@@Z", (PF_GPI)&CHookGroupContext::CBLModule_GetProcInfo);

	//wrapperOnCloseDocument.DoWrap(hBas, "?OnCloseDocument@CGetDoc7@@UAEXXZ", (PF_ONCD)CGetDoc7_OnCloseDocument);

	wrapperGetDoc7Destructor.DoWrap(hBas, "??1CGetDoc7@@MAE@XZ", (PF_CGetDoc7Destructor)&CHookGroupContext::CGetDoc7_Destructor);

#endif // VK_FormEx_Hooks

	wrapperCBLProcInfo_CBLProcInfo.DoWrap(hBl, "??0CBLProcInfo@@QAE@XZ", (PF_CBLProcInfo)&CHookGroupContext::CBLProcInfo_CBLProcInfo);

	wrapperCBLProcInfo_GetNParams.DoWrap(hBl, "?GetNParams@CBLProcInfo@@QBEHXZ", (PF_GetNParams)&CHookGroupContext::CBLProcInfo_GetNParams);

	//wrapperCBLProcInfo_GetType.DoWrap(hBl, "?GetType@CBLProcInfo@@QBEHXZ", (PF_GetType)CBLProcInfo_GetType);

	wrapperCBLModule7_ExecProc.DoWrap(hSev, "?ExecProc@CBLModule7@@QAEHIHPAVCValue@@HPAPAV2@HH@Z", (CBLModule7_PF_ExecProc)&CHookGroupContext::CBLModule7_ExecProc);

	wrapperCBLModule_IsCompiled.DoWrap(hBl, "?IsCompiled@CBLModule@@QBEHXZ", (CBLModule_PF_IsCompiled)&CHookGroupContext::CBLModule_IsCompiled);
	wrapperCBLModule_IsCompiled.RestoreOrigAddress(); // ����� �� ������ ��������, �� ����� �������������� ������ � ExecProc

// 	wrapperCValue_CopyConstructor.DoWrap(hBkEnd, "??0CValue@@QAE@ABV0@@Z", (CValue_PF_CopyConstructor)CValue_CopyConstructor);
// 	wrapperCValue_CopyConstructor.RestoreOrigAddress(); // ����� �� ������ ��������, �� ����� �������������� ������ ��� ������ ������������ �������

	wrapperCBLProcInfo_IsExported.DoWrap(hBl, "?IsExported@CBLProcInfo@@QBEHXZ", (PF_CBLProcInfo_IsExported)&CHookGroupContext::CBLProcInfo_IsExported);
	wrapperCBLProcInfo_IsExported.RestoreOrigAddress(); // ��� ��������� ������� �������� ������ � ������ ������

	// ������, ������� ��������� ������� ����������� ����� ������������� � ��������� ������� !!
	// ����� ����� ���� ��������� �������� � ��� ��� ���� �������
	wrapperCMainMessageHandler_WriteError.DoWrap(hTxtEdt, "?WriteError@CMainMessageHandler@@QAEXPBDW4MessageMarker@@0JHH@Z", (CMainMessageHandler_PF_WriteError)&CHookGroupContext::CMainMessageHandler_WriteError);
	wrapperCMainMessageHandler_WriteError.RestoreOrigAddress(); // ������������� ������ ����� ��������� ����� ����. ����� ������������

	wrapperCAdminService_ReportEventA.DoWrap(hSev, "?ReportEventA@CAdminService@@QAEHVCString@@0W4EventType@@000@Z", (CAdminService_PF_ReportEventA)&CHookGroupContext::CAdminService_ReportEventA);
	wrapperCAdminService_ReportEventA.RestoreOrigAddress(); // ������������� ������ ����� ��������� ����� ����. ����� ������������

	wrapperCAdminService_ReportUserEvent.DoWrap(hSev, "?ReportUserEvent@CAdminService@@QAEHVCString@@0W4EventType@@0PAVCValue@@0@Z", (CAdminService_PF_ReportUserEvent)&CHookGroupContext::CAdminService_ReportUserEvent);
	wrapperCAdminService_ReportUserEvent.RestoreOrigAddress(); // ������������� ������ ����� ��������� ����� ����. ����� ������������

	wrapperCMainMessageHandler_PF_WriteMessage.DoWrap(hTxtEdt, "?WriteMessage@CMainMessageHandler@@IAEXPBDAAVCMessageInfo@@H@Z", (CMainMessageHandler_PF_WriteMessage)&CHookGroupContext::CMainMessageHandler_WriteMessage_DoRestructureVeryLongString);
	wrapperCMainMessageHandler_PF_WriteMessage.RestoreOrigAddress(); // ������������� ������ ����� ��������� ����� ����. ����� ������������
}

void CHookGroupContext::DestroyHooks(void)
{
	GetHooker()->DestroyHook(); 
}

void CHookGroupContext::DestroyHook(void)
{
	m_bEnable = false;

	CEventsWrapperManager::GetWrapper()->DestroyWrapper(::GetGlobalModule());
	//CEventsWrapperManager::GetWrapper()->~CEventsWrapperManager();
	CEventsWrapperManager::GetWrapper() = CEventsWrapperManager::PGroupContextWrap(NULL);

/*	HINSTANCE hBl=GetModuleHandle("blang.dll");
	HINSTANCE hSev=GetModuleHandle("seven.dll");
	HINSTANCE hBas=GetModuleHandle("basic.dll");
*/
#ifndef VK_FormEx_Hooks
	wrapperCallAsFunc.RestoreOrigAddress();

	wrapperCallAsProc.RestoreOrigAddress();

	wrapperFindProc.RestoreOrigAddress();

	wrapperFindFunc.RestoreOrigAddress();

	wrapperGetProcInfo.RestoreOrigAddress();

	//wrapperOnCloseDocument.RestoreOrigAddress();
	wrapperGetDoc7Destructor.RestoreOrigAddress();
#endif // VK_FormEx_Hooks

	wrapperCBLModule7_ExecProc.RestoreOrigAddress();
	
	wrapperCBLProcInfo_GetNParams.RestoreOrigAddress();

	wrapperCBLProcInfo_IsExported.RestoreOrigAddress();
	
	wrapperCMainMessageHandler_WriteError.RestoreOrigAddress();

	wrapperCAdminService_ReportEventA.RestoreOrigAddress();
	wrapperCAdminService_ReportUserEvent.RestoreOrigAddress();

	wrapperCMainMessageHandler_PF_WriteMessage.RestoreOrigAddress();
}

using std::vector;

static bool GetAllowString(LPCSTR str, const int iAllowStringLen, vector<char>& vect)
{
	const int len = strlen(str);
	//const int iAllowStringLen = 2;
	const int count = len / iAllowStringLen;
	if (!count )
		return false;

	const int mod = len % iAllowStringLen;

	vect.resize((iAllowStringLen+2)*count + mod+1);

	char* destpos = &vect[0];
	const char* srcpos = str;

	for (int i = 0; i < count; i++)
	{
		memcpy(destpos, srcpos, iAllowStringLen);
		destpos += iAllowStringLen;
		*destpos++ = '\r';
		*destpos++ = '\n';
		srcpos += iAllowStringLen;
	}
	memcpy(destpos, srcpos, mod);
	destpos += mod;
	*destpos = '\0';

	return true;
}

class CMainMessageHandlerEx : public CMainMessageHandler
{
public:
	void  WriteMessageEx(char const * str,class CMessageInfo & info,int iparam1)
	{
		WriteMessage(str, info, iparam1);
	}
};

void  CHookGroupContext::CMainMessageHandler_WriteMessage_DoRestructureVeryLongString(char const * str,class CMessageInfo & info,int iparam1)
{
	CDllMethodWrapperGuard<CMainMessageHandler_PF_WriteMessage> wrapper(wrapperCMainMessageHandler_PF_WriteMessage);

	CMainMessageHandlerEx* pThisHandler = reinterpret_cast<CMainMessageHandlerEx*>(this);

	const int iAllowStringLen = 450;
	vector<char> vect;
	if (!GetAllowString(str, iAllowStringLen, vect))
		pThisHandler->WriteMessageEx(str, info, iparam1);
	else
		pThisHandler->WriteMessageEx(&vect[0], info, iparam1);
}

void CHookGroupContext::AddEvent_WriteMessageEvent()
{
	//VerifyEnabled();
	wrapperCMainMessageHandler_PF_WriteMessage.RestoreWrapAddress();
}
