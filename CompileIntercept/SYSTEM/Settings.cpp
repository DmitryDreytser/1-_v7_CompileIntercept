// Settings.cpp: implementation of the CSettings class.
// develop by artbear
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "Settings.h"
#include "..\addin.h"

//_____________________________________________________________________________
//
// CSettings Maps
//_____________________________________________________________________________
//
BEGIN_BL_METH_MAP(CSettings) 
    BL_METH_FUNC("Get",	"��������",		1,	&funcGet)
//    BL_METH_FUNC("Get",	"���������",	1,	funcGet)

    BL_METH_PROC("Set",	"����������",		2,	&procSet)

    BL_METH_PROC("Setup",	"��������",		1,	&procSetup)
	BL_METH_PROC("Clear",	"��������",		1,	&procClear)
END_BL_METH_MAP() 

BEGIN_BL_PROP_MAP(CSettings)
END_BL_PROP_MAP()

IMPLEMENT_MY_CREATE_CONTEXT(CSettings, "SettingsManager", "���������������������");

LPCSTR CSettings::m_voidKey = "";

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// ��������� ������� 
LPCSTR CSettings::ResolveKey(LPCSTR key)
{
	if (!key)
		key = m_voidKey;

	return key;
}

LPCSTR CSettings::ResolveKey(CValue* pcvKey)
{
	LPCSTR key = NULL;

	if ( !pcvKey->IsEmpty() )
		key = (LPCSTR)pcvKey->GetString();
	else
		key = ResolveKey(key);

	return key;
}

// ������� �������
BOOL CSettings::funcGet(CValue &RetVal, CValue **ppValue)
{
	LPCSTR key = ResolveKey(ppValue[0]);

	BOOL flag = pMainAddIn->Property[key];
	RetVal = flag;
	return true;
}

void CSettings::Set(LPCSTR key, int iValue)
{
	BOOL flag = !iValue ? 0 : 1;
	pMainAddIn->Property[key] = flag;
}

BOOL CSettings::procSet(CValue **ppValue)
{
	Set(ResolveKey(ppValue[0]), ppValue[1]->GetNumeric().operator long());

	return true;
}

BOOL CSettings::procSetup(CValue **ppValue)
{
	Set(ResolveKey(ppValue[0]), 1);

	return true;
}

BOOL CSettings::procClear(CValue **ppValue)
{
	Set(ResolveKey(ppValue[0]), 0);

	return true;
}