// CompileIntercept.h : main header file for the CompileIntercept DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCompileInterceptApp
// See CompileIntercept.cpp for the implementation of this class
//

class CCompileInterceptApp : public CWinApp
{
public:
	CCompileInterceptApp();
// Overrides
public:
	virtual BOOL InitInstance();
	virtual BOOL ExitInstance();

	DECLARE_MESSAGE_MAP()
};
