// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#define _ATL_APARTMENT_THREADED

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
//#include ".\\1cheaders\\1cheaders.h"
//#include ".\\1cheaders\\ext_header.h"


#if !defined(AFX_STDAFX_H__FC223DD4_F108_11D0_A459_004095E1DAEA__INCLUDED_)
	#define AFX_STDAFX_H__FC223DD4_F108_11D0_A459_004095E1DAEA__INCLUDED_

//template class __declspec(dllimport) CStringT<TCHAR, StrTraitMFC<TCHAR, ChTraitsCRT<TCHAR>>>;
//template class __declspec(dllimport) CSimpleStringT<TCHAR>;
#endif