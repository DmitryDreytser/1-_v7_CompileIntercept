// CompileIntercept.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "CompileIntercept.h"
//#include <shlwapi.h>
//#include "adoint.h"
//#include "minhook.h"
//#include "traps.hpp"
#include "MethodsWrapper.h"
#include "atlctl.h"
#include "afxcview.h"
#include "APIHook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//#import "msado15.dll" no_namespace rename("EOF", "EndOfFile")

//

//{ATL::CStringT<wchar_t,class StrTraitMFC_DLL<wchar_t,class ATL::ChTraitsCRT<wchar_t>>> };
	
//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

#pragma once

#ifndef HEADER1C_PATH
	#define HEADER1C_PATH "1cheaders"
#endif
//typedef PCHAR CString;

//typedef class ATL::CStringT< TCHAR, StrTraitMFC_DLL< TCHAR > > CString;
// CCompileInterceptApp
#define IMPORT_1C __declspec(dllimport)

#pragma comment (lib,HEADER1C_PATH "/libs/basic.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/bkend.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/blang.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/br32.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/dbeng32.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/editr.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/frame.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/moxel.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/rgproc.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/seven.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/txtedt.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/type32.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/userdef.lib")


class IMPORT_1C CProfile7
{
public:
	 CProfile7(char const *,struct CProfileEntry7 const *);	//26
	virtual  ~CProfile7(void);	//89
	int  AddEntry(struct CProfileEntry7 const *);	//137
	virtual void  Attach(class CProfile7 *);	//170
protected:
	void  ConstructProp(int);	//207
	void  DestructProp(int);	//313
public:
	virtual void  Detach(class CProfile7 *);	//315
	int  FindEntry(char const *)const;	//427
	int  FindEntry(struct CProfileEntry7 const *)const;	//428
	class CProfile7 *  FindProfile(char const *);	//432
	class CNumeric const &  GetCNumericProp(int)const;	//468
protected:
	class CItemList *  GetChildList(class CItemList *,char const *);	//473
public:
	unsigned long  GetColorProp(int)const;	//475
	class CDate   GetDateProp(int)const;	//489
	double  GetDoubleProp(int)const;	//501
	struct CProfileEntry7 const *  GetEntryAt(int)const;	//507
	int  GetEntryCount(void)const;	//508
	struct __POSITION *  GetFirstProfile(void);	//519
	class CFont *  GetFontProp(int)const;	//527
	struct HFONT__ *  GetHFONTProp(int)const;	//529
	int  GetIntProp(int)const;	//545
	char const *  GetKey(void)const;	//574
	int  GetLOGFONTProp(int,struct tagLOGFONTA &)const;	//575
	long  GetLongProp(int)const;	//587
	class CProfile7 *  GetNextProfile(struct __POSITION * &);	//638
	class CProfile7 *  GetParentProfile(void);	//662
	void *  GetPointerProp(int)const;	//665
	CString const &  GetStringProp(int)const;	//718
protected:
	class CItem *  GetValueItem(class CItemList *,struct CProfileEntry7 const *);	//746
	static CString   LOGFONTtoString(struct tagLOGFONTA const &);	//842
	void  Load(class CItemList *,char const *);	//846
public:
	int  Load(char const *,char const *);	//847
protected:
	static CString   ProfileGetString(char const *,char const *,char const *);	//1205
	static int  ProfileWriteString(char const *,char const *,char const *);	//1206
	void  PropFromString(int,char const *);	//1207
	void  PropToString(int,CString &);	//1208
public:
	void  RemoveEntry(int);	//1242
	void  RemoveEntry(struct CProfileEntry7 const *);	//1243
	void  Reset(void);	//1267
protected:
	void  Save(class CItemList *,char const *);	//1270
public:
	int  Save(char const *,char const *);	//1271
	void  Serialize(class CArchive &);	//1307
	void  SetCNumericProp(int,class CNumeric const &);	//1320
	void  SetColorProp(int,unsigned long);	//1326
	void  SetDateProp(int,class CDate);	//1334
	void  SetDoubleProp(int,double);	//1341
	void  SetFontProp(int,class CFont *);	//1350
	void  SetHFONTProp(int,struct HFONT__ *);	//1353
	void  SetIntProp(int,int);	//1360
	void  SetKey(char const *);	//1379
	void  SetLOGFONTProp(int,struct tagLOGFONTA const &);	//1380
	void  SetLongProp(int,long);	//1386
	void  SetPointerProp(int,void *);	//1408
	void  SetStringProp(int,char const *);	//1424
protected:
	static int  StringtoLOGFONT(char const *,struct tagLOGFONTA &);	//1466
};


class IMPORT_1C CAppFrame:public CWinApp
{
public:
	void  AddMenu(struct HMENU__ *,int);	//142
	void  AddOptionsPage(struct _GUID const &,struct IUnknown *);	//145
	virtual int  DoMessageBox(char const *,unsigned int,unsigned int);	//327
	long  DoOptionsDialog(void);	//328
	int  FindOptionsPage(struct _GUID const &);	//431
	class CTBManager *  GetToolBarManager(void);	//736
	void  InitMenus(unsigned int,unsigned int);	//769
	int  IsWaiting(void);	//828
	virtual int  OnIdle(long);	//1021
	void  RemoveOptionsPage(struct _GUID const &);	//1248
	void  RemoveOptionsPage(struct _GUID const &,struct IUnknown *);	//1249
	int  SetNoSounds(int)const;	//1395
	int  StartWait(void);	//1461
	int  StopWait(unsigned int);	//1462
	int  StopWait(char const *);	//1463
	void  UpdateMainFrmMenu(void);	//1491
	int  WaitProc(unsigned int);	//1493
	int  WaitProc(char const *);	//1494

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CApp7:public CAppFrame //CWinApp
{
public:
	DWORD buf[0x300];
public:
	CApp7(void);	//7
	virtual  ~CApp7(void);	//122
	void  AdjustDirectories(void);	//367
	int  AttachAddInDLL(char const *);	//373
	void  BindAddInContext(char const *,class CAddInContext *);	//382
	int  CheckDirectories(void);	//406
	void  CloseDataBase(void);	//420
	void  DoPageSetupDialog(void);	//557
	int  FindSpecialFile(char const *,CString &,char const *)const;	//652
	class CUserCommandContaner *  GetCommandManager(void);	//684

	virtual char const *  GetDDFName(void);	//705
	virtual char const *  GetDDSQLFName(void);	//706
	virtual char const *  GetSQLAddrFName(void);	//1088
	virtual char const *  GetMDFName(void);	//779
	virtual char const *  GetConfigFName(void);	//686
	virtual char const *  GetLockFName(void);	//773
	virtual char const *  GetDefSpellingFName(void);	//716

	virtual void  ActivateMessageDevice(int,int);	//338
	virtual void  ClearMessageDevice(void);	//413

	int  GetExitCode(void)const;	//727
	class CAdminService *  GetLog(void);	//774
	class CRect GetMarginsRect(void);	//781
	class CMetaDataCont *  GetMetaData(void);	//829
	unsigned int  GetModeMask(void)const;	//857
	unsigned int  GetMouseScrollLines(int);	//861
	struct HFONT__ *  GetProfileFont(int);	//990
	void  GetProfileFont(int,struct tagLOGFONTA &)const;	//991
	class CProfile7 *  GetProps(void);	//1022
	CString   GetRegisteredUserCompany(void);	//1030
	CString   GetRegisteredUserName(void);	//1031
	class CRightsContainer *  GetRightsManager(void);	//1034
	unsigned int  GetToolBarPos(void)const;	//1122
	void  GetUserDefContainers(class CDocument * *,class CDocument * *);	//1132
	CString   GetUserSystemCaption(void);	//1133
	void  InitAddInService(void);	//1184
	int  InitDataBase(void);	//1186
	void  InitParamsPages(void);	//1189
	int  InitProps(void);	//1190
	int  IsExclusiveMode(void);	//1216
	int  IsGrantedToRecentList(void);	//1219
	int  IsModeEnabled(unsigned int)const;	//1223
	int  LoadAddInDLL(char const *);	//1293
	int  LoadMetaData(char const *);	//1298
	virtual void  LockMessageDevice(int);	//1305
	void  OnDBClosing(void);	//1388
	void  OnDBOpened(void);	//1389
	virtual int  OnIdle(long);	//1433
	int  OpenDataBase(int,int,int);	//1602
	void  ProcessAddinEvents(void);	//1626
protected:
	virtual long  ProcessWndProcException(class CException *,struct tagMSG const *);	//1632
public:
	CString ReadStatusLine(void)const;	//1641
	void  Register_UserDefContainers(class CDocument *,class CDocument *);	//1657
	int  Register_zlibEngine(void);	//1658
	int  SaveProps(void);	//1709
	void  SetExclusiveMode(int);	//1761
	void  SetExitCode(int);	//1762
	void  SetGrantedToRecentList(int);	//1771
	void  SetProfileFont(int,struct tagLOGFONTA const &);	//1799
	void  SetProfileFont(int,struct HFONT__ *);	//1800
	void  SetUserSystemCaption(CString,int);	//1825
	virtual void  ShowError(char const *,enum MessageMarker,char const *,long,int);	//1829
	int  StartNewProcess(enum CAppRunMode);	//1839
	void  StartTimer(void);	//1842
	void  StopTimer(void);	//1849
	void  TranslateCommandLine(char const *);	//1869
	void  UndoParamsPages(void);	//1880
	void  UnloadAddIns(void);	//1881
	void  Unregister_UserDefContainers(void);	//1884
	void  Unregister_zlibEngine(void);	//1885
	void  UpdateAppTitle(void);	//1891
	virtual void  WriteError(char const *,enum MessageMarker,char const *,long,int);	//1906
	virtual void  WriteMessageString(char const *,enum MessageMarker,char const *,long,int);	//1908
	virtual void  WriteMessageString(char const *,enum MessageMarker);	//1909
	void  WriteStatusLine(unsigned int);	//1912
	void  WriteStatusLine(char const *);	//1913
	struct IzlibEngine *  get_zlibEngine(void);	//2142
protected:
	static int  m_bAddToRecentGranted;	//2161
public:
	static unsigned int  m_uiExtCopyDataID;	//2172

	DECLARE_MESSAGE_MAP()
};

enum MessageMarker
{
	mmNone = 0,
	mmBlueTriangle,
	mmExclamation,
	mmExclamation2,
	mmExclamation3,
	mmInformation,
	mmBlackErr,
	mmRedErr,
	mmMetaData,
	mmUnderlinedErr,
	mmUnd
};

class IMPORT_1C CBkEndUI
{
public:
	CBkEndUI(CBkEndUI const &);	//37
	CBkEndUI(void);	//38
	CBkEndUI &  operator=(CBkEndUI const &);	//508
	virtual int  DoMessageBox(unsigned int,unsigned int,unsigned int);	//1238
	virtual int  DoMessageBox(char const *,unsigned int,unsigned int);	//1239
	virtual void  DoStatusLine(char const *);	//1241
	virtual void  DoMessageLine(char const *,enum MessageMarker);	//1240
	void  DoMessageLine(char const * pchMsg) {DoMessageLine(pchMsg, mmNone);}
	virtual CString   GetStatusLine(void)const;	//2445
};


IMPORT_1C class CMetaDataCont * __cdecl GetMetaData(void);
IMPORT_1C class CBkEndUI * __cdecl GetBkEndUI(void);

class IMPORT_1C CType
{
public:
	DWORD m_length;
	DWORD m_mdid;
	WORD type;
	BYTE m_prec;
	BYTE m_flags;	// Для чисел 1-разделять триады, 2 - неотрицательный
	 CType(class CType const &);	//299
	 CType(int);	//300
	 CType(int,int,int);	//301
	 CType(int,int,int,long);	//302
	 CType(int,long);	//303
	 ~CType(void);	//484
	class CType &  operator=(class CType const &);	//578
	int  operator==(class CType const &)const;	//610
	int  operator!=(class CType const &)const;	//617
//	void  `default constructor closure'(void);	//784
	void  AssignWithoutFormat(class CType const &);	//904
	static int  C2TypeCode(char);	//925
	char  GetCTypeCode(void)const;	//1491
	int  GetLength(void)const;	//1880
	int  GetPrecision(void)const;	//2153
	int  GetTypeCode(void)const;	//2500
	long  GetTypeID(void)const;	//2506
	CString GetTypeTitle(void);	//2516
	int  IsNumSeparated(void)const;	//2837
	int  IsObjReference(void);	//2845
	int  IsPositiveOnly(void)const;	//2861
	int  IsValid(void);	//2888
	void  LoadTypeFromList(class CItemList const &,int &);	//2963
	void  SaveTypeToList(class CItemList *)const;	//3299
	void  SetFormat(int,int);	//3590
	void  SetNumSeparated(int);	//3654
	void  SetPositiveOnly(int);	//3689
	void  SetTypeCode(int);	//3785
	void  SetTypeID(long);	//3787
};


class IMPORT_1C CDate
{
public:
	DWORD m_DateNum;
	 CDate(int,int,int);	//2
	CDate   AddMonth(int);	//37
	CDate   BegOfMonth(void)const;	//39
	CDate   BegOfQuart(void)const;	//40
	CDate   BegOfYear(void)const;	//41
	CDate   EndOfMonth(void)const;	//51
	CDate   EndOfQuart(void)const;	//52
	CDate   EndOfYear(void)const;	//53
	char const *  Format(enum CDateFormat,struct SDateFmtInfo const *)const;	//59
	static CDate   GetCurrentDate(void);	//62
	int  GetFormatted(enum CDateFormat,char const *);	//66
	int  GetFormatted(enum CDateFormat,char const *,int,int);	//67
	int  GetMonth(void)const;	//74
	int  GetMonthDay(void)const;	//75
	int  GetWeekDay(void)const;	//87
	int  GetYear(void)const;	//88
	int  GetYearDay(void)const;	//89
};


class IMPORT_1C CNumeric
{
public:
	 CNumeric(CNumeric const &);	//6
	 CNumeric(int);	//7
	 CNumeric(long);	//8
	 CNumeric(double);	//9
	 CNumeric(long double);	//10
	 CNumeric(void);	//11
	 ~CNumeric(void);	//20
	CNumeric &  operator=(CNumeric const &);	//24
	CNumeric &  operator=(int);	//25
	CNumeric &  operator=(long);	//26
	CNumeric &  operator=(double);	//27
	CNumeric &  operator=(long double);	//28
	 operator long(void)const;	//29
	CNumeric   operator*(CNumeric const &)const;	//30
	CNumeric   operator-(CNumeric const &)const;	//31
	CNumeric   operator+(CNumeric const &)const;	//32
	CNumeric   operator/(CNumeric const &)const;	//33
	CNumeric   Abs(void)const;	//35
	int  Compare(CNumeric const &)const;	//42
	int  CompareLong(long)const;	//43
	char *  Convert(char *,int,int)const;	//44
	CNumeric   Floor(void)const;	//58
	CNumeric &  FromString(char const *,char * *);	//60
	long double  GetDouble(void)const;	//64
	static int  GetRoundMode(void);	//84
	CNumeric   Negate(void)const;	//104
	CNumeric   Round(int)const;	//117
	static int  SetRoundMode(int);	//128
	int  Sign(void)const;	//131
protected:
	// 0x2C = 44
	int m_0;			// 4
	int m_nBufferLen;	// 4
	int m_nUsedLen;		// 4
	int m_nScaleLen;	// 4
	short m_Sign;		// 2 ? 4 align
	int m_ScaleFactor;	// 4
	UINT *m_pBuffer;	// 4
	UINT m_Buffer[4];	// 16
};

class IMPORT_1C CDBSign
{
public:
	char Sign[4];
	 CDBSign(char const *);	//87
	 CDBSign(char const *,int);	//88
	class CDBSign &  operator=(class CDBSign const &);	//518
	int  operator==(class CDBSign const &)const;	//605
	int  operator!=(class CDBSign const &)const;	//612
	 operator char const *(void)const;	//623
	int  operator<(class CDBSign const &)const;	//632
	int  operator>(class CDBSign const &)const;	//635
//	void  `default constructor closure'(void);	//763
	class CDBSign const &  Empty(void);	//1286
};


class IMPORT_1C CObjID
{
public:
	long ObjID;
	class CDBSign DBSign;
	 CObjID(class CObjID const &);	//190
	 CObjID(long,class CDBSign const &);	//191
	 CObjID(void);	//192
	class CObjID &  operator=(class CObjID const &);	//547
	int  operator==(class CObjID const &)const;	//609
	int  operator!=(class CObjID const &)const;	//616
	int  operator<(class CObjID const &)const;	//634
	int  operator>(class CObjID const &)const;	//637
	class CObjID const &  Empty(void);	//1287
	int  FromString(CString const &);	//1387
	class CDBSign const &  GetDBSign(void)const;	//1613
	static class CDBSign const &  GetDefDBSign(void);	//1638
	class CObjID   GetNextInSequence(void)const;	//2071
	class CObjID   GetPrevInSequence(void)const;	//2173
	CString GetString(void)const;	//2448
	long  GetlObjID(void)const;	//2556
	int  IsEmpty(void)const;	//2802
	void  SetDBSign(class CDBSign const &);	//3528
	static void  SetDefDBSign(class CDBSign const &);	//3543
	void  SetlObjID(long);	//3809
};


class IMPORT_1C CValue: public CType
{
public:
	// void** pVtable
	class CNumeric m_Number; // числовое значение // align 8
	CString m_String; // строковое значение
	class CDate m_Date; // значение даты
	int Flag6;
	void* m_Context; // значение контекста
	class CObjID m_ObjID; // значение в базе
	// total obj size = 84

	 CValue(class CValue const &);	//312
	 CValue(class CNumeric const &);	//313
	 CValue(class CType const &);	//314
	 CValue(long);	//315
	 CValue(char const *);	//316
	 CValue(class CDate);	//317
	 CValue(void);	//318
	virtual  ~CValue(void);	//489
	class CValue const &  operator=(class CValue const &);	//588
	class CValue const &  operator=(class CNumeric const &);	//589
	class CValue const &  operator=(long);	//590
	class CValue const &  operator=(char const *);	//591
	class CValue const &  operator=(class CDate);	//592
	int  operator==(class CValue const &)const;	//611
	int  operator!=(class CValue const &)const;	//618
	int  AssignContext(class CBLContext *);	//903
	int  CopyToClipboard(class CWnd *,char const *);	//1051
	int  CreateObject(char const *);	//1064
	int  FastSaveToString(CString &);	//1338
	char const *  Format(void)const;	//1380
	class CBLContext *  GetContext(void)const;	//1577
	class CDate   GetDate(void)const;	//1623
	static enum CDateFormat   GetDefDateFmt(void);	//1639
	class CNumeric const &  GetNumeric(void)const;	//2085
	class CObjID   GetObjID(void)const;	//2096
	long  GetRealTypeID(void)const;	//2286
	CString const &  GetString(void)const;	//2449
	char const *  GetTypeString(void)const;	//2515
	long  GetValTypeID(void)const;	//2537
protected:
	void  Init(void);	//2684
public:
	int  IsEmpty(void)const;	//2803
	int  IsExactValue(void)const;	//2809
protected:
	virtual int  IsTypeSafe(void)const;	//2881
public:
	void  Link(int,int);	//2894
	int  LinkContext(int);	//2907
	int  LoadFromString(char const *,int);	//2949
	int  LoadValueFromList(class CItemList *,int);	//2964
	void  MakeExactValueFrom(class CValue const *);	//2992
	int  PasteFromClipboard(class CWnd *);	//3089
	void  Reset(void);	//3232
	int  SaveToString(CString &);	//3297
	int  SaveValueToList(class CItemList *)const;	//3300
	static void  SetDefDateFmt(enum CDateFormat);	//3544
	void  SetObjID(class CObjID);	//3658
	void  SetType(class CType const &);	//3784
	void  SetValTypeID(long);	//3798
	void  UnlinkContext(void);	//3961
	void  ValidateType(void);	//4034
	static unsigned int  cfValueId;	//4193
};

class IMPORT_1C CBLContext:public CObject //32 Real - 4 VT = 28=0x1C
{
DECLARE_DYNCREATE(CBLContext)

public:
//Begin def
// +00 VTABLE
// +04 DWORD
	int m_RefCount;
// +08 DWORD param
	int m_FlagAutoDestroy;
// +0C CPtrArray
	CPtrArray m_Array;

//	char dump [0x50];
	virtual  ~CBLContext(void);	//352
	CBLContext(int Param = 1);	//24
//	void  `default constructor closure'(void);	//759
protected:
//	CBLContext();
	void  AddToValues(CValue const *);	//896
public:
	virtual void			IncrRef(void);	
	virtual void			DecrRef(void);	

	virtual int				GetDestroyUnRefd(void)const;

	virtual int				IsOleContext(void)const;

	virtual CType		GetValueType(void)const;	//2547
	virtual long			GetTypeID(void)const;	//2505
	virtual CObjID	GetID(void)const;	//1804
	virtual char const *	GetCode(void)const;	//1544
	
	virtual int				IsExactValue(void)const;	//2808

	virtual void			InitObject(CType const &);	//2721
	virtual void			InitObject(char const *);	//2722

	virtual void			SelectByID(CObjID,long);	//3350

	virtual char const *	GetTypeString(void)const;	//2513

	virtual int				GetNProps(void)const;	//2015
	virtual int				FindProp(char const *)const;	//1369
	virtual char const *	GetPropName(int,int)const;	//2187
	virtual int				GetPropVal(int,CValue &)const;	//2221
	virtual int				SetPropVal(int,CValue const &);	//3694
	virtual int				IsPropReadable(int)const;	//2863
	virtual int				IsPropWritable(int)const;	//2865

	virtual int				GetNMethods(void)const;	//2005
	virtual int				FindMethod(char const *)const;	//1366
	virtual char const *	GetMethodName(int,int)const;	//1964
	virtual int				GetNParams(int)const;	//2008
	virtual int				GetParamDefValue(int,int,CValue *)const;	//2122
	virtual int				HasRetVal(int)const;	//2657

	virtual int				CallAsProc(int,CValue * *);	//937
	virtual int				CallAsFunc(int,CValue &,CValue * *);	//935

	virtual int				IsSerializable(void);	//2874

	virtual int				SaveToString(CString &);	//3295
	virtual class			CBLContextInternalData *  GetInternalData(void);	//1826
	virtual void			GetExactValue(CValue &);	//1708

	static CBLContext *  CreateInstance(CType const &);	//1059
	static CBLContext *  CreateInstance(char const *);	//1060
	static unsigned long  GetFirstLoadedContextID(void);	//1751
	static CBLContext *  GetLoadedContext(unsigned long);	//1930
	unsigned long  GetLoadedID(void)const;	//1931
	static unsigned long  GetNextLoadedContextID(unsigned long);	//2072
	char const *  GetPresentMethodName(int)const;	//2170
	char const *  GetPresentPropName(int)const;	//2171
	void  HashMethods(int);	//2661
	void  HashProperties(int);	//2662
	void  Load(void)const;	//2924
	static void  RegisterContextClass(struct CRuntimeClass *,char const *,CType const &);	//3195
	static void  RegisterOleContextClass(struct CRuntimeClass *);	//3200
private:
	void  RemoveFromValues(CValue const *);	//3223
public:
	void  SetHashID(char const *);	//3605
	static void  UnRegisterContextClass(struct CRuntimeClass *);	//3945
	void  Unload(void)const;	//3962
};

class IMPORT_1C CBLSpeller
{

};


class IMPORT_1C CBLModuleInternals
{
public:
	class CBLModule* pModule;
	class CBLContext* pGeneralContext; //CGeneralContext
	int Flag3;
	CBLSpeller* pBLSpeller;
	int Flag5;
	PCHAR mSource;
	int* StartIDArray;
	int* EndIDArray1;
	int* EndIDArray2;
	class CCompiler* pCompiler;
	class CCompiledModule* pCompiledModule;
	class CExecutedModule* pExecutedModule;
	CString* strExecutingProc; 
};


class IMPORT_1C CBLModule //VF Table OK
{
public:
	 CBLModuleInternals* pIntInfo;
//	DWORD buff[0x0FF];
	 CBLModule(class CBLModule const &);	//1
	 CBLModule(class CBLContext *,char const *);	//2

	virtual					~CBLModule(void);	
	virtual int				GetKind(void)const;	
	virtual char const *	GetSyntaxMark(void);	
	virtual int				OnSyntaxError(void);	//128
	virtual int				OnRuntimeError(void);	//124
	virtual int				OnStartExecution(void);	//126
	virtual int				OnNextLine(void);	//123
	virtual void			OnEnterProc(int);	//119
	virtual void			OnExitProc(int);	//121
	virtual void			OnStopExecution(void);	//127
	virtual void			OnErrorMessage(char const *);	//120
	virtual void			OnSetSpeller(class CValue const &);	//125
	virtual int				OnDoMessageBox(char const *,unsigned int,unsigned int);	//118
	virtual void			OnGetErrorDescription(CString &);	//122

	static void  AddToKeywordColorList(char const *);	//21
	static void  AddToKeywordColorList(class CBLContext const *);	//22
	static int  ColorSourceLine(char const *,class CBLSyntaxColoring &);	//33
	static void  EnableDebugDump(int);	//36
	static class CBLModule *  GetExecutedModule(void);	//53
	static unsigned long  GetFirstLoadedModuleID(void);	//54
	static class CBLModule *  GetLoadedModule(unsigned long);	//59
	static unsigned long  GetNextLoadedModuleID(unsigned long);	//74
	static void  GetSyntaxErrDescr(int,CString &);	//93
	static int  IsDebugDumpEnabled(void);	//106
	static int  IsLeftAdjFormat(char const *);	//111
	static void  RaiseExtRuntimeError(char const *,int);	//130
	static void  RemoveFromKeywordColorList(char const *);	//131
	static void  RemoveFromKeywordColorList(class CBLContext const *);	//132
	static void  SetOnCommandExceptionHandler(void (__cdecl*)(class CException *,int &));	//136
	static int  TokenizeSourceLine(char const *,int &,CString *);	//139

	class CBLModule &  operator=(class CBLModule const &);	//11
//	void  `default constructor closure'(void);	//18
	void  AddSourceLine(char const *);	//20
	void  AssignCompiled(class CBLModule const &);	//23
	void  AssignContext(class CBLContext *);	//24
	void  AssignFriendModule(class CBLModule *);	//25
	void  AssignSource(class CBLModule const &);	//26
	void  AssignSource(char const *);	//27
	void  AssignSpeller(class CBLSpeller *);	//28
	int  CallAsFunc(int,class CValue &,int,class CValue * *);	//29
	int  CallAsProc(int,int,class CValue * *);	//31
	int  Compile(void);	//34
	CString GetFullName(void);
	int  EvalExpr(char const *,class CValue &,class CValue * *);	//37
	int  Execute(void);	//38
	int  ExecuteBatch(char const *,class CValue * *);	//39
	int  FindFunc(char const *)const;	//40
	int  FindProc(char const *,int)const;	//42
	int  FindStaticVar(char const *)const;	//44
	CString   FormatValue(class CValue const &,char const *);	//45
	int  GetCallLevelProcInfo(int,class CBLProcInfo &,int &)const;	//46
	int  GetCallStackDepth(void)const;	//47
	int  GetCurSourceLine(int,CString &)const;	//48
	class CBLModule const *  GetCurrentModule(void)const;	//49
	unsigned long  GetExecutedCmdAddr(void)const;	//51
	int  GetExecutedLineNum(void)const;	//52
	int  GetFirstSrcLineInfo(class CBLSrcLineInfo &)const;	//55
	class CBLModuleInternals *  GetInternalData(void)const;	//56
	unsigned long  GetLoadedID(void)const;	//58
	int  GetNCurSourceLines(void)const;	//63
	int  GetNProcs(void)const;	//67
	int  GetNSourceLines(void)const;	//69
	int  GetNStaticVars(void)const;	//70
	int  GetNextSrcLineInfo(class CBLSrcLineInfo &)const;	//75
	int  GetProcInfo(int,class CBLProcInfo &)const;	//76
	int  GetRuntimeErrCode(void)const;	//82
	void  GetRuntimeErrDescr(int,CString &)const;	//83
	char const *  GetRuntimeErrIdent(void)const;	//84
	int  GetRuntimeErrLineNum(void)const;	//85
	class CBLModule *  GetRuntimeErrModule(void)const;	//86
	void  GetRuntimeErrSourceLine(CString &)const;	//87
	int  GetSourceLine(int,CString &)const;	//88
	class CBLSpeller *  GetSpeller(void)const;	//89
	int  GetStaticVarDescr(int,class CBLVarInfo &)const;	//90
	int  GetStaticVarValue(int,class CValue &,int)const;	//91
	int  GetSyntaxErrCode(void)const;	//92
	char const *  GetSyntaxErrIdent(void)const;	//94
	int  GetSyntaxErrLineNum(void)const;	//95
	char const *  GetSyntaxErrMarkedLine(void)const;	//96
	int  HasSource(void)const;	//104
	int  IsCompiled(void)const;	//105
	int  IsExecuted(void)const;	//107
	int  IsInBatchMode(void)const;	//110
	int  IsLoaded(void)const;	//112
	int  IsValidObject(void)const;	//115
	int  Load(void);	//116
	int  LoadSource(char const *);	//117
	int  PrepareToLoad(void);	//129
	void  Reset(void);	//133
	void  ResetCompiled(void);	//134
	void  ResetExecuted(void);	//135
	int  SetStaticVarValue(int,class CValue const &,int);	//138
	void  Unload(void);	//141
};

typedef class CArray<CBLModule*,CBLModule*> CBLModuleArray;
class IMPORT_1C CBLModule7: public CBLModule
{
	friend class CBLModuleWrapper;
public:
	CStringA	m_strModulePath;		// 0x08
	DWORD	m_nID;					// 0x0C
	DWORD	m_nCounter;				// 0x10 счетчик?
	BOOL	m_bIsProcessBroken;		// 0x14
	BOOL	m_bProcNotFound;		// 0x18
	DWORD	m_Flag6;				// 0x1C
	int		m_nStatusCode;			// 0x20
	DWORD	m_Flag8;				// 0x24

	friend class CModuleContext;
	friend class CComponentClass;
	 CBLModule7(class CBLModule7 const &);	//11
	 CBLModule7(class CBLContext *,char const *);	//12
	class CBLModule7 &  operator=(class CBLModule7 const &);	//212

	virtual ~CBLModule7(void);	//125
	
	// пример использования следующих виртуальных функций смотри в файле CBLModuleWrapper.cpp
	virtual int GetKind(void) const;
	virtual int OnSyntaxError(void);
	virtual int OnRuntimeError(void);
	virtual int OnStartExecution(void);
	virtual int OnNextLine(void);
	virtual void OnEnterProc(int);
	virtual void OnExitProc(int);
	virtual void OnStopExecution(void);
	virtual void OnErrorMessage(LPCSTR);
	virtual void OnSetSpeller(CValue const &);
	virtual void OnGetErrorDescription(CString &);
	virtual int OnDoMessageBox(LPCSTR, unsigned int);
	virtual void OnErrorMessageEx(LPCSTR, long, LPCSTR, int);

	int  EvalDebugExpr(char const *,CValue &);	//590
	int  EvalWatchExpr(char const *,CValue &);	//591
	
	// данная функция вызывается для отработки предопределенных процедур модулей форм и глобального модуля
	// например, ПриОткрытии, ПриНачалеРаботыСистемы и т.д.
	//
	//	iStringResourceId - числовой ID строкового ресурса из 1crrus.dll, указывающий на имя метода в виде "OnOpen,ПриОткрытии"
	//	bFlagNotShowErrorIfNotFoundProcFunc - не показывать ошибки, если нужной процедуры не найдено
	int  ExecProc(unsigned int iStringResourceId,int bFlagNotShowErrorIfNotFoundProcFunc,CValue *,int iParamsCount,CValue * * params,int,int);	//592
	
	CString   GetFullName(void)const;	//743
	void  GetID(CString &,long &)const;	//752
	int  GetProcNotFound(void)const;	//988
	int  GetStatusCode(void)const;	//1099
	int  IsConditionSucc(unsigned int);	//1211
	int  IsProcessBroken(void)const;	//1235
	int  ModifyBreakPoints(void)const;	//1318
	void  OnGetCallStackInfo(class CTraceDataMap *);	//1425
	void  SetID(char const *,long);	//1772
	void  SetStatusCode(int);	//1810
	void  StartLevelProfile(void);	//1836
	void  StartLineProfile(void);	//1837
	void  StopLevelProfile(void);	//1844
	void  StopLineProfile(void);	//1845
	int  TryEvalExpr(char const *,CValue &,CValue * *);	//1870
	int  TryExecuteBatch(char const *,CValue * *,int,int);	//1871

	static int  BeginTrans(void);	//381
	static int  Commit(void);	//421
	static void  DecrNTransStarted(void);	//525
	static void  IncrNTransStarted(void);	//1181
	static int  GetNTransStarted(void);	//940
	static void  ProcessDBException7(class CDBException7 *);	//1627
	static void  ProcessOnCommandDBException7(class CException *,int &);	//1630
	static int  Rollback(void);	//1688
	static void  RollbackAll(void);	//1689
	static void  StopProfileOnExit(void);	//1847
private:
//	static class CArray<class CBLModule7 *,class CBLModule7 *>  m_BLMod7Stack;	//2154
	static CBLModuleArray m_BLMod7Stack;	//2154
public:
	static CStringArray  m_BreakPointConditions;	//2155
	static class CBLProfileInfo  m_ProfileInfo;	//2159
private:
	static class CDWordArray  m_TransStartedStack;	//2160
	static int  m_bDbgExprEvaluating;	//2162
};

class IMPORT_1C COleStorage:public CObject
{
DECLARE_DYNAMIC(COleStorage)

public:
	IStorage*		m_pStorage;
	CString			m_strPath;
	COleStorage*	m_pParent;
	CPtrList		m_list1;
	CPtrList		m_list2;
	
	 COleStorage(class COleStorage *);	//19
	virtual  ~COleStorage(void);	//83
	void  Commit(void);	//205
	int  Create(char const *,unsigned long,class CFileException *);	//216
	class COleStreamFile *  CreateStream(char const *,unsigned long,class CFileException *);	//282
	int  DestroyElement(char const *);	//309
	static class COleStorage *  FindStorage(char const *);	//435
	class COleStorage *  FindSubStorage(char const *)const;	//437
	static class CFile *  GetFile(char const *,unsigned int,class CFileException *);	//510
	int  Open(char const *,unsigned long,class CFileException *);	//1178
	class COleStreamFile *  OpenStream(char const *,unsigned long,class CFileException *);	//1181
	void  Release(int);	//1232
	static int  ReleaseFile(class CFile *,int);	//1236
	void  ReleaseStream(class COleStreamFile *,int);	//1237
	int  RenameElement(char const *,char const *);	//1255
	void  SetParentStorage(class COleStorage *);	//1403
};

class IMPORT_1C CContainer:public CDocument
{
DECLARE_DYNCREATE(CContainer)

protected:
	 CContainer(void);	//6
public:
	COleStorage* m_pStorage;
	CObArray m_objArray;
	char bufer[32];
	
	virtual  ~CContainer(void);	//73
	void  AddTemplate(unsigned int,char const *);	//155
protected:
	void  ClearContents(void);	//197
public:
	virtual void  DeleteContents(void);	//301
	void  DeletePage(int);	//305
	int  FreePage(int,int);	//445
	static char const *  GetContentsStreamName(void);	//483
protected:
	virtual class CFile *  GetFile(char const *,unsigned int,class CFileException *);	//509
	CString   GetPagePathName(int)const;	//650
public:
	int  GetPagePos(char const *)const;	//651
	int  GetPagePos(class CContainerPage const *)const;	//652
	int  GetPagePos(class CDocument const *)const;	//653
	int  GetPagePosFromFileName(char const *)const;	//654
	int  InsertNewPage(unsigned int,int,char const *,char const *);	//784
	virtual int  IsModified(void);	//812
	int  IsValidType(unsigned int)const;	//826
	void  MovePage(int,int);	//880
	virtual void  OnCloseDocument(void);	//960
protected:
	virtual int  OnLoadInternal(void);	//1061
	virtual int  OnNewDocument(void);	//1076
public:
	virtual int  OnOpenDocument(char const *);	//1086
	virtual int  OnSaveDocument(char const *);	//1112
protected:
	virtual int  OnSaveInternal(void);	//1113
public:
	int  ReadPage(int);	//1219
protected:
	virtual void  ReleaseFile(class CFile *,int);	//1235
public:
	void  RenameFileName(int,char const *);	//1256
	void  RenamePage(int,char const *);	//1257
	virtual void  Serialize(class CArchive &);	//1302
	virtual void  SetModifiedFlag(int);	//1393
	void  SetReadOnlyMode(int);	//1413
	int  WritePage(int);	//1495

	DECLARE_MESSAGE_MAP()
};

class IMPORT_1C CTypedCont:public CContainer
{
DECLARE_DYNCREATE(CTypedCont)

protected:
	 CTypedCont(void);	//104
public:
	virtual  ~CTypedCont(void);	//201
	class CDocument *  FindDocument(char const *,int *);	//645
	class CDocument *  GetDEditDocument(void);	//707
	class CDocument *  GetMoxelDocument(char const *,int *);	//862
	int  GetTablesName(CStringArray &);	//1108
	class CDocument *  GetTextDocument(void);	//1116
	class CWorkBookDoc *  GetWorkBook(void);	//1137
	virtual int  OnLoadInternal(void);	//1467
	virtual int  OnNewDocument(void);	//1498
	virtual int  OnOpenDocument(char const *);	//1513
	virtual int  OnSaveDocument(char const *);	//1535
	virtual int  OnSaveInternal(void);	//1538
	virtual int  SaveModified(void);	//1703
	void  ShowDocument(int);	//1828

	DECLARE_MESSAGE_MAP()
};

class IMPORT_1C CConfigCont:public CContainer
{
DECLARE_DYNCREATE(CConfigCont)
public:
	char buf[20];
	
	enum ConvertMode {cmOne};
protected:
	 CConfigCont(void);	//25
public:
	virtual  ~CConfigCont(void);	//137
private:
	static int  AddTxtPage(struct IStorage *,long,char const *);	//361
	static int  AddWBPage(struct IStorage *,long,char const *);	//363
public:
	int  CompressAll(int);	//423
	int  ConvertAllCJForms(void);	//424
	int  ConvertAllDocModule(int (__cdecl*)(class CDocument *,class CDocument *,class CDocument *,class CMetaDataObj *));	//425
	static int  CopyTxtPage(struct IStorage *,long,long,char const *);	//431
	static int  CopyWBPage(struct IStorage *,long,long,char const *,char const *);	//432
	static int  DeleteTxtPage(long,char const *);	//537
	static int  DeleteWBPage(long,char const *);	//538
	virtual int  DoFileSave(void);	//554
	int  DoFileSaveToPath(char const *,int);	//556
	static unsigned int  DocID;	//560
	static long  DocumentToID(class CDocument *,CString &);	//569
	static void  DocumentToPath(class CDocument *,CString &);	//570
	static struct IStorage *  ExtractFolders(class CMetaDataObj *);	//595
	static int  FastSave(class CContainer *,int);	//628
	int  FirstInit(int);	//656
	static void  FreeFacedPage(void);	//659
	static void  GetAllDescr(int (__cdecl*)(CString &,long,long,enum PageType),long,int);	//667
	static void  GetAllTypedItem(int (__cdecl*)(CString &,long,long,enum PageType),long,enum PageType,int);	//668
	static class CConfigCont *  GetContainer(void);	//687
	enum CConfigCont::ConvertMode   GetConvertMode(void);	//694
	int  GetEncriptVer(void);	//726
	class CContainer *  GetFolder(char const *);	//740
	static void  GetLastUUID(struct _GUID &);	//771
	static class CDocument *  GetOpenDocument(char const *,long,char const *,int,int &);	//946
	static int  IDToPath(long,char const *,CString &,class CTypedCont * *,int);	//1178
	static int  IDToTextModule(long,char const *,CString &,class CModuleCont * *,int);	//1179
private:
	static class CContainer *  InsertDummyTxtPage(long,char const *);	//1195
	static class CContainer *  InsertDummyWBPage(long,char const *);	//1196
public:
//!	static int  InsertNewAndConvert(struct IStorage *,class CMetaDataObj *,class CMap<class CMetaDataObj *,class CMetaDataObj *,long,long> *,int);	//1198
//!	static int  InsertNewFolders(struct IStorage *,class CMetaDataObj *,class CMap<class CMetaDataObj *,class CMetaDataObj *,long,long> *);	//1199
	static int  IsFolderPresent(char const *,long);	//1217
	int  IsNeedEncrypt(void);	//1224
	int  IsNeenFullRevert(void);	//1225
	int  IsPasswordCrypt(void);	//1232
	int  IsSpecialCrypt(void);	//1276
	static int  LoadConfigContainer(void);	//1295
	static int  LoadMetaData(void);	//1299
	static class CDocument *  PathToDocument(CString const &);	//1604
	static long  PathToID(CString const &);	//1605
	static unsigned char *  ReadStream(char const *,long,unsigned long &,int);	//1642
	static int  ReplaceWBFolder(struct IStorage *,int,char const *,long,int);	//1680
	virtual int  SaveModified(void);	//1694
	void  SetEncriptVer(int);	//1757
	void  SetNeedEncrypt(int);	//1788
	void  SetNeedFullRevert(int);	//1789
	static int  TestCanExist(char const *,long,long &);	//1860
private:
	static class CContainerPage *  TryToMakeConvertion(long,char const *,class CContainer *);	//1872
public:
	static void  ValidateOleFile(class CMetaDataCont *);	//1903
	static CString  m_FullTempPath;	//2158

	DECLARE_MESSAGE_MAP()
};

class IMPORT_1C CMetaDataCont
{
public:
	 CMetaDataCont(void);	//165
	 ~CMetaDataCont(void);	//416
	int  Accept(void);	//789
	int  AcceptOnLoad(void);	//793
	int  AddAlgorithmDef(class CAlgorithmDef *);	//804
	int  AddCJDef(class CCJDef *);	//805
	int  AddCalcVarDef(class CCalcVarDef *);	//807
	int  AddCalendarTypeDef(class CCalendarTypeDef *);	//808
	int  AddConstDef(class CConstDef *);	//810
	int  AddDocDef(class CDocDef *);	//815
	int  AddEnumDef(class CEnumDef *);	//816
	int  AddGroupDef(class CGroupDef *);	//819
	int  AddJournalDef(class CJournalDef *);	//826
	int  AddRecalcRuleDef(class CRecalcRuleDef *);	//842
	int  AddRegDef(class CRegDef *);	//847
	int  AddReportDef(class CReportDef *);	//850
	int  AddSTypeDef(class CSbCntTypeDef *);	//852
	unsigned long  ConvertRightCodFromLoad(unsigned long);	//1041
	unsigned long  ConvertRightCodToStore(unsigned long);	//1042
	unsigned int  ConvertRightTypeFromLoad(unsigned int);	//1043
	unsigned int  ConvertRightTypeToStore(unsigned int);	//1044
	void  DelAlgorithmDef(int,int);	//1095
	void  DelAlgorithmDef(class CAlgorithmDef *,int);	//1096
	void  DelAllAlgorithmDefs(int);	//1100
	void  DelAllCJDefs(int);	//1101
	void  DelAllCalcVarDefs(int);	//1102
	void  DelAllCalendarTypeDefs(int);	//1103
	void  DelAllConstDefs(int);	//1104
	void  DelAllDocDefs(int);	//1106
	void  DelAllEnumDefs(int);	//1107
	void  DelAllGroupDefs(int);	//1108
	void  DelAllJournalDefs(int);	//1109
	void  DelAllRecalcRuleDefs(int);	//1111
	void  DelAllRegDefs(int);	//1113
	void  DelAllReportDefs(int);	//1114
	void  DelAllSTypeDefs(int);	//1115
	void  DelCJDef(int,int);	//1117
	void  DelCJDef(class CCJDef *,int);	//1118
	void  DelCalcVarDef(int,int);	//1121
	void  DelCalcVarDef(class CCalcVarDef *,int);	//1122
	void  DelCalendarTypeDef(int,int);	//1123
	void  DelCalendarTypeDef(class CCalendarTypeDef *,int);	//1124
	void  DelConstDef(int,int);	//1125
	void  DelConstDef(class CConstDef *,int);	//1126
	void  DelDocDef(int,int);	//1128
	void  DelDocDef(class CDocDef *,int);	//1129
	void  DelEnumDef(int,int);	//1131
	void  DelEnumDef(class CEnumDef *,int);	//1132
	void  DelGroupDef(int,int);	//1137
	void  DelGroupDef(class CGroupDef *,int);	//1138
	void  DelJournalDef(int,int);	//1142
	void  DelJournalDef(class CJournalDef *,int);	//1143
	void  DelRecalcRuleDef(int,int);	//1151
	void  DelRecalcRuleDef(class CRecalcRuleDef *,int);	//1152
	void  DelRegDef(int,int);	//1156
	void  DelRegDef(class CRegDef *,int);	//1157
	void  DelReportDef(int,int);	//1158
	void  DelReportDef(class CReportDef *,int);	//1159
	void  DelSTypeDef(int,int);	//1160
	void  DelSTypeDef(class CSbCntTypeDef *,int);	//1161
	void  DeleteAllData(int);	//1197
	void  DescribeMDCont(CString &);	//1221
	int  ExistAcc(void);	//1314
	class CSbCntTypeDef *  FindAnySTypeDefChild(long);	//1353
	class CSbCntTypeDef *  FindAnySTypeDefChild(char const *);	//1354
	class CSbCntTypeDef *  FindAnySTypeDefChild(class CSbCntTypeDef const *);	//1355
	class CMetaDataObj *  FindObject(long)const;	//1367
//	CMetaDataObjArrayTemplate<class CDocNumDef> *  GenDocNumDefs(void)const;	//1388
//DmitrO: GenDocNumDefs
//	CMetaDataObjArrayTemplate<class CDocSelRefDef> *  GenDocSelRefs(void)const;	//1389
//DmitrO: GenDocSelRefs
	class CAlgorithmDef *  GetAlgorithmDef(long)const;	//1439
	class CAlgorithmDef *  GetAlgorithmDef(char const *)const;	//1440
	class CAlgorithmDef *  GetAlgorithmDefAt(int)const;	//1441
	int  GetAlgorithmDefIdx(long)const;	//1442
	int  GetAlgorithmDefIdx(class CAlgorithmDef *)const;	//1443
	int  GetAlgorithmDefIdx(char const *)const;	//1444
	class CMetaDataObjArray *  GetAlgorithmDefs(void);	//1445
	class CBuhDef *  GetBuhDef(void)const;	//1474
	class CCJDef *  GetCJDef(long)const;	//1477
	class CCJDef *  GetCJDef(char const *)const;	//1478
	class CCJDef *  GetCJDefAt(int)const;	//1479
	int  GetCJDefIdx(long)const;	//1480
	int  GetCJDefIdx(class CCJDef *)const;	//1481
	int  GetCJDefIdx(char const *)const;	//1482
	class CMetaDataObjArray *  GetCJDefs(void);	//1483
	int  GetCalcMaxDocNumLen(void);	//1493
	int  GetCalcMaxNumCodeLen(void);	//1494
	class CCalcVarDef *  GetCalcVarDef(long)const;	//1496
	class CCalcVarDef *  GetCalcVarDef(char const *)const;	//1497
	class CCalcVarDef *  GetCalcVarDefAt(int)const;	//1498
	int  GetCalcVarDefIdx(long)const;	//1499
	int  GetCalcVarDefIdx(class CCalcVarDef *)const;	//1500
	int  GetCalcVarDefIdx(char const *)const;	//1501
	class CMetaDataObjArray *  GetCalcVarDefs(void);	//1502
	class CCalendarTypeDef *  GetCalendarTypeDef(long)const;	//1503
	class CCalendarTypeDef *  GetCalendarTypeDef(char const *)const;	//1504
	class CCalendarTypeDef *  GetCalendarTypeDefAt(int)const;	//1505
	int  GetCalendarTypeDefIdx(long)const;	//1506
	int  GetCalendarTypeDefIdx(class CCalendarTypeDef *)const;	//1507
	int  GetCalendarTypeDefIdx(char const *)const;	//1508
	class CMetaDataObjArray *  GetCalendarTypeDefs(void);	//1509
	class CConstDef *  GetConstDef(long)const;	//1566
	class CConstDef *  GetConstDef(char const *)const;	//1567
	class CConstDef *  GetConstDefAt(int)const;	//1568
	int  GetConstDefIdx(long)const;	//1569
	int  GetConstDefIdx(class CConstDef *)const;	//1570
	int  GetConstDefIdx(char const *)const;	//1571
	class CMetaDataObjArray *  GetConstDefs(void);	//1572
	class CDocDef *  GetDocDef(long)const;	//1665
	class CDocDef *  GetDocDef(char const *)const;	//1666
	class CDocDef *  GetDocDefAt(int)const;	//1667
	int  GetDocDefIdx(long)const;	//1669
	int  GetDocDefIdx(class CDocDef *)const;	//1670
	int  GetDocDefIdx(char const *)const;	//1671
	class CMetaDataObjArray *  GetDocDefs(void);	//1672
	class CDocSelRefHolder *  GetDocSelRefHolder(void)const;	//1677
//	CMetaDataObjArrayTemplate<class CDocStreamDef> *  GetDocStreamDefs(void)const;	//1681
	class CEnumDef *  GetEnumDef(long)const;	//1694
	class CEnumDef *  GetEnumDef(char const *)const;	//1695
	class CEnumDef *  GetEnumDefAt(int)const;	//1696
	int  GetEnumDefIdx(long)const;	//1697
	int  GetEnumDefIdx(class CEnumDef *)const;	//1698
	int  GetEnumDefIdx(char const *)const;	//1699
	class CMetaDataObjArray *  GetEnumDefs(void);	//1700
	int  GetExistDocEditSubcFlds(void)const;	//1710
	char const *  GetFullName(long,long *,int)const;	//1768
//	class CTypedFldDefsArray<class CGenJrnlFldDef> *  GetGenJrnlFlds(void)const;	//1771
	int  GetGenJrnlFldsIndexCnt(void)const;	//1772
	class CGroupDef *  GetGroupDef(long)const;	//1776
	class CGroupDef *  GetGroupDef(char const *)const;	//1777
	class CGroupDef *  GetGroupDefAt(int)const;	//1778
	int  GetGroupDefIdx(long)const;	//1779
	int  GetGroupDefIdx(class CGroupDef *)const;	//1780
	int  GetGroupDefIdx(char const *)const;	//1781
	class CMetaDataObjArray *  GetGroupDefs(void);	//1782
	class CHolidaysDef *  GetHolidaysDef(void)const;	//1803
	class CJournalDef *  GetJournalDef(long)const;	//1846
	class CJournalDef *  GetJournalDef(char const *)const;	//1847
	class CJournalDef *  GetJournalDefAt(int)const;	//1848
	int  GetJournalDefIdx(long)const;	//1849
	int  GetJournalDefIdx(class CJournalDef *)const;	//1850
	int  GetJournalDefIdx(char const *)const;	//1851
	class CMetaDataObjArray *  GetJournalDefs(void);	//1852
protected:
	static char const *  GetListFunctor(void);	//1911
public:
	char const *  GetLongCopyright(void);	//1935
	static int  GetMDListVersion(class CItemList const &);	//1938
	int  GetMDObjRights(class CDWordArray *,int,class CMetaDataObj *);	//1939
	class CMetaDataObj *  GetMDObject(int,char const *,char const *)const;	//1941
	int  GetMaxDocHeadFldsCnt(void)const;	//1949
	int  GetMaxDocNumLen(void)const;	//1950
	int  GetMaxDocTblFldsCnt(void)const;	//1951
	int  GetMaxFigureCnt(void)const;	//1952
	int  GetMaxPropCnt(void)const;	//1955
	int  GetMaxRegFldCnt(void)const;	//1956
	int  GetMaxSbLevelsLimit(void)const;	//1957
	class CMetaDataObjDistr *  GetMetaDataObjDistr(long);	//1963
	int  GetNAlgorithmDefs(void)const;	//1975
	int  GetNCJDefs(void)const;	//1976
	int  GetNCalcVarDefs(void)const;	//1978
	int  GetNCalendarTypeDefs(void)const;	//1979
	int  GetNConstDefs(void)const;	//1995
	int  GetNDocDefs(void)const;	//1996
	int  GetNEnumDefs(void)const;	//1997
	int  GetNGroupDefs(void)const;	//2000
	int  GetNJournalDefs(void)const;	//2004
	int  GetNRecalcRuleDefs(void)const;	//2046
	int  GetNRegDefs(void)const;	//2048
	int  GetNReportDefs(void)const;	//2049
	int  GetNSTypeDefs(void)const;	//2050
	int  GetNewDBVersion(void)const;	//2062
	long  GetNewID(void);	//2065
	int  GetNewVersion(void)const;	//2069
	int  GetOldDBVersion(void)const;	//2098
	int  GetOldVersion(void)const;	//2101
	class CRecalcRuleDef *  GetRecalcRuleDef(long)const;	//2287
	class CRecalcRuleDef *  GetRecalcRuleDef(char const *)const;	//2288
	class CRecalcRuleDef *  GetRecalcRuleDefAt(int)const;	//2289
	int  GetRecalcRuleDefIdx(long)const;	//2290
	int  GetRecalcRuleDefIdx(class CRecalcRuleDef *)const;	//2291
	int  GetRecalcRuleDefIdx(char const *)const;	//2292
	class CMetaDataObjArray *  GetRecalcRuleDefs(void);	//2293
	class CRegDef *  GetRegDef(long)const;	//2307
	class CRegDef *  GetRegDef(char const *)const;	//2308
	class CRegDef *  GetRegDefAt(int)const;	//2311
	int  GetRegDefIdx(long)const;	//2312
	int  GetRegDefIdx(class CRegDef *)const;	//2313
	int  GetRegDefIdx(char const *)const;	//2314
	class CMetaDataObjArray *  GetRegDefs(void);	//2315
	class CReportDef *  GetReportDef(long)const;	//2328
	class CReportDef *  GetReportDef(char const *)const;	//2329
	class CReportDef *  GetReportDefAt(int)const;	//2330
	int  GetReportDefIdx(long)const;	//2331
	int  GetReportDefIdx(class CReportDef *)const;	//2332
	int  GetReportDefIdx(char const *)const;	//2333
	class CMetaDataObjArray *  GetReportDefs(void);	//2334
	int  GetRightID(char const *);	//2338
	CString   GetRightName(int,int,int);	//2339
	class CSbCntTypeDef *  GetSTypeDef(long)const;	//2382
	class CSbCntTypeDef *  GetSTypeDef(char const *)const;	//2383
	class CSbCntTypeDef *  GetSTypeDefAt(int)const;	//2384
	int  GetSTypeDefIdx(long)const;	//2385
	int  GetSTypeDefIdx(class CSbCntTypeDef *)const;	//2386
	int  GetSTypeDefIdx(char const *)const;	//2387
	class CSbCntTypeDef *  GetSTypeDefParent(long);	//2388
	class CSbCntTypeDef *  GetSTypeDefParent(char const *);	//2389
	class CSbCntTypeDef *  GetSTypeDefParent(class CSbCntTypeDef const *);	//2390
	class CMetaDataObjArray *  GetSTypeDefs(void);	//2391
	char const *  GetShortCopyright(void);	//2434
	class CTaskDef *  GetTaskDef(void)const;	//2467
	void  GetUUID(struct _GUID &)const;	//2520
	int  InsertAlgorithmDef(int,class CAlgorithmDef *);	//2745
	int  InsertCJDef(int,class CCJDef *);	//2747
	int  InsertCalcVarDef(int,class CCalcVarDef *);	//2749
	int  InsertCalendarTypeDef(int,class CCalendarTypeDef *);	//2750
	int  InsertConstDef(int,class CConstDef *);	//2753
	int  InsertDocDef(int,class CDocDef *);	//2754
	int  InsertEnumDef(int,class CEnumDef *);	//2755
	int  InsertGroupDef(int,class CGroupDef *);	//2758
	int  InsertJournalDef(int,class CJournalDef *);	//2762
	int  InsertRecalcRuleDef(int,class CRecalcRuleDef *);	//2766
	int  InsertRegDef(int,class CRegDef *);	//2769
	int  InsertReportDef(int,class CReportDef *);	//2770
	int  InsertSTypeDef(int,class CSbCntTypeDef *);	//2771
	int  LoadAlgorithmDefs(class CItemList const &);	//2925
	int  LoadBuhDef(class CItemList const &);	//2926
	int  LoadCJParamDefs(class CItemList const &);	//2927
	int  LoadCalcVarDefs(class CItemList const &);	//2928
	int  LoadCalendarTypeDefs(class CItemList const &);	//2929
	int  LoadConstDefs(class CItemList const &);	//2930
	int  LoadData(char const *);	//2932
	int  LoadDocDefs(class CItemList const &);	//2933
	int  LoadDocStreamDefs(class CItemList const &);	//2934
	int  LoadEnumDefs(class CItemList const &);	//2935
	int  LoadFromList(class CItemList const &);	//2939
	int  LoadGenJrnlDefs(class CItemList const &);	//2952
	int  LoadGroupDefs(class CItemList const &);	//2953
	int  LoadJournalDefs(class CItemList const &);	//2954
protected:
	int  LoadMainDefs(class CItemList const &);	//2955
public:
	int  LoadRecalcRuleDefs(class CItemList const &);	//2958
	int  LoadRegDefs(class CItemList const &);	//2959
	int  LoadReportDefs(class CItemList const &);	//2960
	int  LoadSTypeDefs(class CItemList const &);	//2961
	int  LoadTaskDefs(class CItemList const &);	//2962
	int  MoveConstDef(class CConstDef *,int);	//3008
	int  MoveDocDef(class CDocDef *,int);	//3009
	int  MoveEnumDef(class CEnumDef *,int);	//3010
	int  MoveJournalDef(class CJournalDef *,int);	//3014
	int  MoveRegDef(class CRegDef *,int);	//3019
	int  MoveReportDef(class CReportDef *,int);	//3020
	int  MoveSTypeDef(class CSbCntTypeDef *,int);	//3022
	void  SaveAlgorithmDefs(class CItemList &)const;	//3263
	void  SaveBuhDef(class CItemList &)const;	//3264
	void  SaveCJParamDefs(class CItemList &)const;	//3265
	void  SaveCalcVarDefs(class CItemList &)const;	//3266
	void  SaveCalendarTypeDefs(class CItemList &)const;	//3267
	void  SaveConstDefs(class CItemList &)const;	//3268
	int  SaveData(char const *)const;	//3269
	void  SaveDocDefs(class CItemList &)const;	//3270
	void  SaveDocStreamDefs(class CItemList &)const;	//3271
	void  SaveEnumDefs(class CItemList &)const;	//3272
	void  SaveGenJrnlDefs(class CItemList &)const;	//3273
	void  SaveGroupDefs(class CItemList &)const;	//3274
	void  SaveJournalDefs(class CItemList &)const;	//3275
protected:
	void  SaveMainDefs(class CItemList &)const;	//3276
public:
	void  SaveRecalcRuleDefs(class CItemList &)const;	//3278
	void  SaveRegDefs(class CItemList &)const;	//3279
	void  SaveReportDefs(class CItemList &)const;	//3280
	void  SaveSTypeDefs(class CItemList &)const;	//3281
	void  SaveTaskDefs(class CItemList &)const;	//3282
	void  SaveToList(class CItemList &)const;	//3287
	void  ScanMDObjects(class SScanMDObjects *);	//3309
	void  SetLongCopyright(char const *);	//3630
	void  SetShortCopyright(char const *);	//3767
	void  SetUUID(struct _GUID const &);	//3790
	int  SortConstDefs(void);	//3821
	int  SortDocDefs(void);	//3823
	int  SortEnumDefs(void);	//3824
	int  SortJournalDefs(void);	//3828
	int  SortRegDefs(void);	//3835
	int  SortReportDefs(void);	//3836
	int  SortSTypeDefs(void);	//3837
	void  SyncVerison(void);	//3886
	int  TestRefers(long,class CArray<CMetaDataObj*,CMetaDataObj*>&)const;	//3901
	void  TestRefersForOne(long,class CArray<CMetaDataObj*,CMetaDataObj*>&)const;	//3902
	int  TestValidRight(int,int,class CMetaDataObj *);	//3930
	void  UpdateDBVersion(void);	//4000
};

class IMPORT_1C CGetCtrl:public CCmdTarget //CObject
{
DECLARE_DYNAMIC(CGetCtrl)

public:
	char buffer[512];
};

class IMPORT_1C CGetDoc:public CDocument // CObject //
{
DECLARE_DYNCREATE(CGetDoc)

public:
	//DWORD buf[0x013];//(A0h - 54h) / 4
	DWORD m_Attr_01h_54h;
	//DWORD m_Attr_02h_58h; CObArray
	//DWORD m_Attr_03h_5Ch;
	//DWORD m_Attr_04h_60h;
	//DWORD m_Attr_05h_64h;
	//DWORD m_Attr_06h_68h;
	CObArray m_CtrlArray;
	DWORD m_Attr_07h_6Ch;
	//DWORD m_Attr_08h_70h;
	CGetCtrl * m_ActiveCtrl;
	DWORD m_Attr_09h_74h;
	//DWORD m_Attr_0Ah_78h;
	UINT m_BrowseID;
	DWORD m_Attr_0Bh_7Ch;
	DWORD m_Attr_0Ch_80h;
	DWORD m_Attr_0Dh_84h;
	DWORD m_Attr_0Eh_88h;
	//DWORD m_Attr_0Fh_8Ch;
	UINT m_SavePromptResNum;
	//DWORD m_Attr_10h_90h;
	UINT m_DeletePromptResNum;
	DWORD m_Attr_11h_94h;
	DWORD m_Attr_12h_98h;
	DWORD m_Attr_13h_9Ch;

protected:
	 CGetDoc(void);	//23
public:
	virtual  ~CGetDoc(void);	//41
	void  AddGet(class CGetCtrl *);	//53
	virtual int  BufferExchange(int);	//57
protected:
	virtual int  CanCloseFrame(class CFrameWnd *);	//58
	virtual int  DataExchange(class CGetExchange *);	//83
public:
	void  DeleteColumn(int);	//87
	virtual int  DeleteCurrent(void);	//88
	class CGetCtrl *  GetActiveCtl(void);	//117
	class CBrowse *  GetBrowse(void);	//120
	unsigned int  GetBrowseID(void);	//122
	class CGetCtrl *  GetCtrl(unsigned int);	//133
	int  GetCtrlN(class CGetCtrl *);	//134
protected:
	unsigned int  GetDefFormCommand(void);	//144
public:
	virtual void  GetDeletePrompt(CString &);	//145
	static int  GetFlag(enum GetDocFlags);	//151
	virtual class CWnd *  GetForm(void);	//153
	virtual void  GetSavePrompt(CString &);	//188
	virtual void  GetStringData(CString &,unsigned int);	//191
	int  IsLast(class CGetCtrl *);	//212
	static int  LoadColumnWidth(class CGetDoc *);	//215
	virtual void  OnAbortUse(void);	//221
	virtual void  OnActivateCtrl(unsigned int);	//222
protected:
	void  OnBeginUse(void);	//224
	void  OnBrowseAppendStart(void);	//229
	void  OnBrowseChPos(void);	//230
	void  OnBrowseDoubleClick(void);	//231
	void  OnBrowseFillCurrent(void);	//232
	void  OnBrowseFillRow(void);	//233
	void  OnBrowseWantChPos(void);	//234
	void  OnBrowseWantHScroll(void);	//235
	void  OnBrowseWantRefresh(void);	//236
	void  OnBrowseWantVScroll(void);	//237
	void  OnCancel(void);	//238
public:
	virtual int  OnCancelEdit(void);	//239
protected:
	void  OnCmdDoUse(void);	//246
	void  OnCmdGetUse(void);	//247
public:
	virtual int  OnCmdMsg(unsigned int,int,void *,struct AFX_CMDHANDLERINFO *);	//252
protected:
	void  OnCopy(void);	//254
public:
	virtual void  OnCopyRec(long);	//255
protected:
	void  OnDefFileCommand(void);	//260
	void  OnDelete(void);	//261
public:
	virtual int  OnDeleteRec(void);	//262
protected:
	void  OnEdit(void);	//266
public:
	virtual int  OnGetUse(unsigned int,unsigned int,long);	//274
protected:
	virtual void  OnIdle(void);	//277
public:
	virtual unsigned int  OnMakeUse(unsigned int);	//290
protected:
	void  OnNew(void);	//308
	virtual int  OnNewDocument(void);	//309
public:
	virtual void  OnNewRec(void);	//310
protected:
	void  OnNext(void);	//311
public:
	void  OnNextCtl(int);	//312
	virtual void  OnRead(int);	//318
	virtual int  OnStoreRec(void);	//329
protected:
	void  OnUpdateCmdButtons(class CCmdUI *);	//333
	void  OnWrite(void);	//339
	virtual void  PreCloseFrame(class CFrameWnd *);	//347
public:
	virtual int  PreTranslateMessage(struct tagMSG *);	//352
	static int  SaveColumnWidth(class CGetDoc *);	//365
	virtual int  SaveModified(void);	//367
	void  SetActiveCtl(unsigned int);	//372
	void  SetActiveCtl(class CGetCtrl *);	//373
	void  SetBrowseID(unsigned int);	//377
	void  SetDefCommand(unsigned int);	//388
protected:
	void  SetDefFormCommand(unsigned int);	//389
public:
	static void  SetDeletePromptID(unsigned int);	//390
	static void  SetFlag(enum GetDocFlags,int);	//392
	virtual void  SetModify(int);	//397
	void  SetReadOnly(int);	//401
	static void  SetSavePromptID(unsigned int);	//403
	virtual int  UpdateData(int,unsigned int);	//411
protected:
	virtual void  UpdateDefCommand(void);	//412

	DECLARE_MESSAGE_MAP()
};

class IMPORT_1C CRightListView:public CObject
{
DECLARE_DYNCREATE(CRightListView)

protected:
	 CRightListView(void);	//3
	virtual  ~CRightListView(void);	//10
public:
	class CRightDoc *  GetDocument(void);	//68
protected:
	virtual class CPropertySchema *  GetMySchema(void);	//88
public:
	virtual void  InsertNewItem(int,int);	//115
protected:
	int  OnCreate(struct tagCREATESTRUCTA *);	//145
	void  OnDblclk(struct tagNMHDR *,long *);	//146
	void  OnDestroy(void);	//148
	virtual void  OnEnter(void);	//152
public:
	virtual void  OnInitialUpdate(void);	//154
protected:
	void  OnRightEdt(void);	//170
	void  OnUpdateUserHelpEdit(class CCmdUI *);	//186
	void  OnUserHelpEdit(void);	//187
	void  OnUsrDelr(void);	//190
	void  OnUsrSetr(void);	//192
public:
	virtual void  ReplaceItem(int,unsigned int);	//210

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CCompileInterceptApp, CWinApp)
END_MESSAGE_MAP()
// The one and only CCompileInterceptApp object

CCompileInterceptApp theApp;
// CCompileInterceptApp initialization

char *IniRead(char *filename, char *section, char *key){
 char *out = new char[512];
 if (GetPrivateProfileStringA(
 (LPCSTR)section,
 (LPCSTR)key,
 NULL,
 out,
 200,
 (LPCSTR)filename
 ))return out;
 return NULL;
}

BOOL IniWrite(char *filename, char *section, char *key, char *data){
 return (BOOL)WritePrivateProfileStringA(
 (LPCSTR)section,
 (LPCSTR)key,
 (LPCSTR)data,
 (LPCSTR)filename
 );
}


typedef int (__thiscall *FPCOMPILE)(CBLModule*);
CDllMethodWrapper<FPCOMPILE> fpCompileModule;

FARPROC GetFullName = NULL;
FARPROC GetID = NULL;

CApp7*          MainApp = NULL;
CBkEndUI*		pBkEndUI		= NULL;
CMetaDataCont*	pMetaDataCont	= NULL;
HINSTANCE		h1CResource		= NULL;
PCHAR csAppName = GetCommandLineA();
PCHAR IniFullPath = (PCHAR)malloc(sizeof(CHAR)*255);
PCHAR IBCatalog = NULL;
PCHAR ConnectionString = NULL;
CDatabase ConfigDB;
PCHAR ttt;
void DoMsgLine(const char* format, MessageMarker marker=mmNone,...)
{
	pBkEndUI->DoMessageLine(format,marker);
}
void DoStsLine(const char* format,...)
{
	pBkEndUI->DoStatusLine(format);
}
CString GetErrorDescription(DWORD err/*=0*/)
{
	if(!err)
		err=GetLastError();
	CString errMsg;
	errMsg.Format(L"Код ошибки Windows: 0x%X",err);
	LPTSTR lpMsgBuf;
	if(FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,err,MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpMsgBuf,0,NULL))
	{
		errMsg=errMsg+L"\r\n"+lpMsgBuf;
		LocalFree(lpMsgBuf);
	}
	return errMsg;
}

class CStringEx:public CString
{
public:
	char* ToPCHAR();
	CStringEx() : CString( ){};
	CStringEx( const CString& stringSrc) : CString( stringSrc ){};
	CStringEx( const CStringEx& stringSrc) : CString( stringSrc ){};
	CStringEx( TCHAR ch, int nRepeat = 1 ) : CString( ch, nRepeat ){};
	CStringEx( LPCTSTR lpch, int nLength ) : CString( lpch, nLength ){};
	CStringEx( const unsigned char* psz ) : CString( psz ){};
	CStringEx( LPCWSTR lpsz ) : CString( lpsz ){};
	CStringEx( LPCSTR lpsz ) : CString( lpsz ){};
};
			
PCHAR WideToChar(PWCHAR res) {
		int res_len = WideCharToMultiByte(
				CP_THREAD_ACP,            // Code page
				0,						  // No flags
				res,					  // Multibyte characters string
				-1,						  // The string is NULL terminated
				NULL,					  // No buffer yet, allocate it later
				0,						  // No buffer
				0,
				0
				);

		CHAR* NewModule = (CHAR*)calloc(sizeof(CHAR), res_len);

		int err = WideCharToMultiByte(
				CP_THREAD_ACP,            // Code page
				0,                  // No flags
				res,        // Multibyte characters string
				-1,                 // The string is NULL terminated
				NewModule,                // Output buffer
				res_len,		// buffer size
				0,
				0
				);
		return NewModule;
};

PCHAR CStringEx::ToPCHAR() 
{
	return WideToChar(GetBuffer());
};

PWCHAR CharToWide(PCHAR res) {
		int res_len = MultiByteToWideChar(
				CP_THREAD_ACP,            // Code page
				0,						  // No flags
				res,			  // Multibyte characters string
				-1,						  // The string is NULL terminated
				NULL,					  // No buffer yet, allocate it later
				0						  // No buffer
				);

		WCHAR* NewModule = (WCHAR*)calloc(sizeof(WCHAR), res_len);

		int err = MultiByteToWideChar(
				CP_THREAD_ACP,            // Code page
				0,                  // No flags
				res,        // Multibyte characters string
				-1,                 // The string is NULL terminated
				NewModule,                // Output buffer
				res_len		// buffer size
				);
		return NewModule;
};

PCHAR GetModuleFullName(CBLModule7 *Module) {
	PCHAR ModuleName=(CHAR*)calloc(sizeof(CHAR), 512);
	_asm
	{   
		PUSHAD
		MOV ECX, Module 
		LEA EAX, ModuleName
		PUSH eax
		call GetFullName
		POPAD
	};
	return ModuleName;
};

PCHAR GetModuleID(CBLModule7 *Module) 
{
	PCHAR ModuleID = (CHAR*)calloc(sizeof(CHAR), 255);
	int ModuleID_int = (int)calloc(sizeof(int), 2);
	_asm	
	{	
		PUSHAD
		MOV ECX, Module
		LEA EDX,ModuleID_int
		LEA EAX,ModuleID
		PUSH EDX
		PUSH EAX
		CALL GetID
		POPAD
	};
	ModuleID_int = NULL;
	return ModuleID;
}

PCHAR GetBasePath()
{
	DWORD MyHandle = (DWORD)GetModuleHandle(NULL);
	PCHAR path = (PCHAR)(*(DWORD*)(MyHandle + 0x3EC44) + 0x190);
	return path;
}

PCHAR Get1CUserName()
{
	DWORD MyHandle = (DWORD)GetModuleHandle(NULL);
	DWORD hSeven = (DWORD)GetModuleHandle(L"seven.dll");
	PCHAR path = (PCHAR)(*(DWORD*)(MyHandle + 0x3E3F4));
	ttt = (PCHAR)(*(DWORD*)(hSeven + 0xFE04)+0x30C);
	return path;
}

PCHAR Get1CUserFullName()
{
	DWORD MyHandle = (DWORD)GetModuleHandle(NULL);
	PCHAR path = (PCHAR)(*(DWORD*)(MyHandle + 0x3E3F4));
	return path;
}

BOOL ModuleInit = FALSE;
PCHAR message = (PCHAR)malloc(sizeof(CHAR)*2048);
SQLHDBC hdbc;
SQLHSTMT hstmt;
BOOL PostMessages=FALSE;
HMODULE MyHandle = NULL;
BOOL upload_module_texts;
IMPORT_1C CString  __cdecl GetModuleFullName(long,CString &,int,class CMetaDataCont *);
IMPORT_1C class CMetaDataCont * __cdecl GetMetaData(void);
const BYTE cPushOpCode = 0x68;
PVOID sm_pvMaxAppAddr = NULL;

typedef HMODULE (WINAPI *pLoadLibraryA)(LPCSTR);
//typedef BOOL (WINAPI *pDllMAin)();
CDllMethodWrapper<pLoadLibraryA> fpDBInit;
CDllMethodWrapper<pLoadLibraryA> fpHookDll;
typedef HMODULE (_fastcall *pInsertNewItem)(CRightListView*, int,int);
typedef BOOL (WINAPI h_dllmain)(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved);
DWORD addr,addr1;
NOTIFYICONDATAA niData; 

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam);
DWORD v7pid;
HWND  v7hWnd = GetDesktopWindow();


HICON Getv7Icon()
{
	HICON hIcon1;       // дескриптор значка
	HINSTANCE hExe;     // дескриптор загружаемого .EXE файла
	HRSRC hResource;    // дескриптор FindResource
	HRSRC hMem;         // дескриптор  LoadResource
	LPVOID lpResource;   // указатель на данные ресурса
	int nID;            // идентификатор (ID) ресурса, который лучше всего подходит текущему экрану
	hExe = GetModuleHandle(NULL);
	hResource = FindResource(hExe,  MAKEINTRESOURCE(1),  MAKEINTRESOURCE(RT_ICON));
	hMem =  (HRSRC)LoadResource(hExe, hResource);
	lpResource = LockResource(hMem);
	hIcon1 = CreateIconFromResourceEx((PBYTE) lpResource, SizeofResource(hExe, hResource), TRUE, 0x00030000, 32, 32, LR_DEFAULTCOLOR);
	return hIcon1; 
}

void Baloon(PCHAR Message, int init = NULL)
{
	if(init==1) 
	{   
		v7hWnd = GetDesktopWindow();
		ZeroMemory(&niData,sizeof(NOTIFYICONDATAA));
		niData.cbSize = sizeof(NOTIFYICONDATAA);
		niData.uID = 1;
		niData.uFlags = NIF_ICON;
		niData.hIcon =Getv7Icon(); // LoadIcon(0, IDI_QUESTION);
		niData.hWnd = v7hWnd;
		//niData.uTimeout=50;
		Shell_NotifyIconA(NIM_DELETE,&niData);
		Shell_NotifyIconA(NIM_ADD,&niData);
		return;
	}

	if(init==-1) 
	{
		Baloon("1C Завершила работу.");
		Sleep(500);
		Shell_NotifyIconA(NIM_DELETE,&niData);
		ZeroMemory(&niData,sizeof(NOTIFYICONDATAA));
		return;
	}

//	if (PostMessages)pBkEndUI->DoStatusLine(Message);
	niData.uFlags = NIF_INFO;
	ZeroMemory(niData.szInfo,strlen(niData.szInfo));
	CopyMemory(niData.szInfo,Message,strlen(Message));
	Shell_NotifyIconA(NIM_MODIFY,&niData);
}

BOOL Init()
{
	PostMessages = FALSE;
	MyHandle = (*((CWinApp*)(&(theApp)))).m_hInstance;
	if (pBkEndUI == NULL) pBkEndUI = GetBkEndUI();
	if (pBkEndUI == NULL) 
	{
		AfxMessageBox(L"Ошибка определения контекста приложения.");
		return NULL;
	}
	pBkEndUI->DoMessageLine("Начата инициализация", mmInformation);
	if (IBCatalog==NULL) IBCatalog = GetBasePath();
	char* MDPAth = (char*)malloc(260*sizeof(char));
	wsprintfA(MDPAth,"%s1cv7.md",IBCatalog);
	CharUpperA(MDPAth);
	pBkEndUI->DoMessageLine(MDPAth, mmInformation);
	if (!PathFileExistsA(MDPAth)) 
	{
		pBkEndUI->DoMessageLine("Ошибка определения каталога конфигурации. Модуль отключен", mmBlackErr);
		return FALSE;
	}
	wsprintfA(IniFullPath, "%smodules.ini", IBCatalog);

	if (!PathFileExistsA(IniFullPath))
	{
		IniWrite(IniFullPath,"MAIN","IBCatalog",IBCatalog);
		IniWrite(IniFullPath,"SQLConnection","ConnectionString","Driver={SQL Server};Server=[SERVER_NAME];Database=[DB_NAME];Trusted_Connection=Yes;");
		wsprintfA(message,"Cоздан файл %s .\n В нем необходимо указать параметры подключения к базе данных.",IniFullPath);
		pBkEndUI->DoMessageLine(message, mmBlackErr);
		return FALSE;
	}

	PCHAR iniIBCatalog = IniRead(IniFullPath,"MAIN","IBCatalog");
	if(*iniIBCatalog!=*IBCatalog)
	{
		wsprintfA(message,"Путь к каталогу конфигурации указанный в файле %s указан некорректно.",IniFullPath);
		pBkEndUI->DoMessageLine(message, mmBlackErr);	
		return FALSE;
	}

	ConnectionString = IniRead(IniFullPath,"SQLConnection","ConnectionString");
	if (ConnectionString==NULL)
	{
		wsprintfA(message,"В файле %s не указана строка подключения к базе модулей.",IniFullPath);
		pBkEndUI->DoMessageLine(message, mmBlackErr);	
		return FALSE;
	}


	 SQLCHAR *       InConnectionString = (SQLCHAR*)ConnectionString;
	 SQLHENV henv;
     SQLRETURN retcode;
     SQLCHAR OutConnStr[255];
     SQLSMALLINT OutConnStrLen;

      HWND desktopHandle = GetDesktopWindow();   // desktop's window handle


	  SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
      SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER*)SQL_OV_ODBC3, 0); 
      SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc); 
      SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0);
      retcode = SQLDriverConnectA( 
               hdbc, 
               desktopHandle, 
               InConnectionString, 
               255,
               OutConnStr,
               255, 
               &OutConnStrLen,
               SQL_DRIVER_NOPROMPT);

	  if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {               
              SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt); 
	  }
	  else 
	  {
		wsprintfA(message,"Не удалось подключитсья к базе модулей",IniFullPath);
		pBkEndUI->DoMessageLine(message, mmBlackErr);	
		return FALSE;
	  }

	  SQLCHAR* res = (SQLCHAR*)LockResource(LoadResource(MyHandle,FindResourceA(MyHandle,"SQL_CREATE_TABLE","TEXT"))); 
	  retcode = SQLExecDirectA(hstmt,res,strlen((PCHAR)res));
	  FreeResource(res);
	  upload_module_texts = atoi(IniRead(IniFullPath,"MAIN","upload_module_texts"));

	  //pMetaDataCont = GetMetaData();
	  //pMetaDataCont->LoadData("Main ");
	 // AFX_MODULE_STATE* ms = AfxGetModuleState();
	 //if (ms!=NULL) AfxMessageBox(ms->m_pCurrentWinApp->m_lpCmdLine);
	PostMessages = TRUE;
	return TRUE;
}

BOOL _stdcall Hook_DllMain(h_dllmain InitRoutine, HINSTANCE DllBAse, DWORD fdwReason, LPVOID lpvReserved)
{
	OutputDebugStringA("Сейчас вызовем DllMain");
	char* message = (char*)malloc(sizeof(char)*_MAX_PATH*1000);
	LPSTR LibName = (char*)malloc(sizeof(char)*_MAX_PATH*100);
	GetModuleFileNameA(DllBAse,LibName,sizeof(char)*_MAX_PATH*100);
	PathStripPathA(LibName);
	AnsiUpperBuff(LibName,strlen(LibName));
	switch( fdwReason ){
		case DLL_PROCESS_ATTACH:
			wsprintfA(message,"Загружена библиотека %s",LibName);
			break;
		case DLL_THREAD_ATTACH:         
			wsprintfA(message,"Поток подключил библиотеку %s",LibName);
			break;
		case DLL_THREAD_DETACH:
			wsprintfA(message,"Поток отключил библиотеку %s",LibName);
			break;
		case DLL_PROCESS_DETACH:
			wsprintfA(message,"Выгружена библиотека %s",LibName);
			break;
	} ;
	PCHAR PUserName=NULL;
	BOOL Res;
	if ((lstrcmpA(LibName,"USERDEF.DLL")==0)&&(fdwReason==DLL_PROCESS_ATTACH))
	{
		OutputDebugStringA("Загружена SPFLEXLOCKS.DLL");
		Res = InitRoutine(DllBAse,fdwReason,lpvReserved); 
		OutputDebugStringA("Проинициализирована SPFLEXLOCKS.DLL");
	}
	else
	{
		Res = InitRoutine(DllBAse,fdwReason,lpvReserved); 
	}
	//Baloon(message);
	
	return  Res;

}


//void _fastcall Hook_initDB(CRightListView* ListView,int p1, int p2)
//HANDLE Hook_initDB(LPCSTR filename, DWORD Access, DWORD ShareMode, LPSECURITY_ATTRIBUTES SecurituAttributes, DWORD CDisp,DWORD Flags, HANDLE Temp)
//HMODULE Hook_LoadLibraryA(PCHAR libname)
//{
//	HMODULE Result;
//	char* ttt = (char*)malloc(sizeof(char)*512);
//	if (lstrcmpA(libname,"USERDEF.DLL")==0)
//	{
//		//if (!fpHookDll.IsActive())
//		Result = LoadLibraryExA(libname,NULL,NULL);
//	}
//	else
//	{
//	Result = LoadLibraryExA(libname,NULL,NULL);
//	}
//	//wsprintfA(ttt,"Загружена библиотека %s",libname);
//	//if(pBkEndUI)pBkEndUI->DoMessageLine(ttt, mmInformation);
//	return Result;
//}

int _fastcall Hook_CompileModule(CBLModule7 *Module)
{

	if (!ModuleInit) ModuleInit = Init();
	if (!ModuleInit)
	{
		if(pBkEndUI!=NULL)pBkEndUI->DoMessageLine("Перехват отключен", mmInformation);
		fpCompileModule.RestoreOrigAddress(); 
		return Module->Compile();
	}

	fpCompileModule.RestoreOrigAddress(); 
	CDllMethodWrapperGuard<FPCOMPILE> wrapper(fpCompileModule);

	CStringEx ModuleText = CStringEx(Module->pIntInfo->mSource);
	PCHAR ModuleName=GetModuleFullName(Module);
	PCHAR ModuleID = GetModuleID(Module);
	CStringEx NewM = ModuleText;
	ModuleText.Replace(L"\'",L"&apo&");
	//NewM = "Сообщить(КаталогИБ());";
	if(strlen(ModuleID))
	{
		wsprintfA(message, "UTL: Модуль \"%s\" перехвачен. Тип модуля: \"%s\"", ModuleName,ModuleID);
		
		pBkEndUI->DoMessageLine(message, mmInformation);

		if(upload_module_texts)
		{
			PCHAR c_ModuleTExt = ModuleText.ToPCHAR();
			//CHAR* res = (CHAR*)LockResource(LoadResource(MyHandle,FindResourceA(MyHandle,"SQL_INSERT_MODULE","TEXT")));
			PCHAR res = "Declare @ModuleName VARCHAR(255)\r\nSET @ModuleName='%s' \r\nIF NOT EXISTS (SELECT * FROM Modules WHERE ModuleName=@ModuleName)\r\n BEGIN INSERT INTO [dbo].[modules]([ModuleName],[ModuleText],[FormText],[ModuleID])VALUES(@ModuleName,'%s','','%s') END";
			PCHAR param = (PCHAR)malloc(sizeof(SQLCHAR)*(strlen(res)+strlen(c_ModuleTExt)+strlen(ModuleName)+strlen(ModuleID))+100);
			wsprintfA(param,res,ModuleName,c_ModuleTExt,ModuleID); //
			SQLINTEGER paramlen = strlen(param)*sizeof(SQLCHAR);
			SQLRETURN retcode;
			retcode = SQLExecDirectA(hstmt,(SQLCHAR*)param,paramlen);
			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
			{
				sprintf_s(message,sizeof(CHAR)*255, "UTL: Модуль \"%s\" сохранен в базу.", ModuleName);
				pBkEndUI->DoMessageLine(message, mmInformation);
			}
			else
			{
	/*			LPTSTR Err=NULL;
				CDatabase db;
				db.m_hdbc = hdbc;
				CDBException* pException = new CDBException(retcode); 
				pException->BuildErrorString(&db, hstmt); */

				wsprintfA(message, "UTL: Ошибка сохранения модуля \"%s\" :%s", ModuleName,"");
				pBkEndUI->DoMessageLine(message, mmRedErr);
			}
			//free(param);
			//FreeResource(res);
		}
	}
	//pBkEndUI->DoMessageLine(NewM.ToPCHAR(), mmInformation);
	//free(message);

	//	if(strcmp(ModuleName,"Справочник") == 1) 
	//	{
		//MessageBoxW(NULL,CString(NewModule), CString(ModuleName),NULL);
		//PCHAR NewModule = NewM.ToPCHAR();
		//Module->AssignSource(NewModule);
	//	}
	int ret = Module->Compile();
	fpCompileModule.RestoreWrapAddress();
	
	return ret;
}

const GUID CLSID_MSDASQL = {0xC8B522CBL,0x5CF3,0x11CE,{0xAD,0xE5,0x00,0xAA,0x00,0x44,0x77,0x3D}};
// CCompileInterceptApp construction

CCompileInterceptApp::CCompileInterceptApp()
{
	Baloon(NULL, 1);
}

//CCompileInterceptApp::~()
//{
//	Shell_NotifyIcon(NIM_DELETE,&niData);
//}

DWORD find_LdrpCallInitRoutine(HMODULE ImageBase)
{
	DWORD XXX = NULL;
	DWORD CodeBase;
	DWORD CodeSize;
	DWORD m_dwProtection;
	BOOL Found = FALSE;
	//уроним OllyDebug
	//OutputDebugStringA("%s%s%s%s%s%s%s");
	
	// Возьмем начало секции кода и ее размер из PE-заголовка

	_asm
	{	
		mov eax, ImageBase
		mov edx, dword ptr [eax+3Ch] 
		add edx, eax 
		mov ebx, dword ptr [edx+2Ch] 
		add ebx, eax
		mov CodeBase,ebx
		mov ecx, dword ptr [edx+1Ch] 
		mov CodeSize,ecx
	}
	VirtualProtect((BYTE*)CodeBase, CodeSize, PAGE_EXECUTE_READWRITE, &m_dwProtection);

	// и пробежимся по всей секции в поисках "сигнатуры" LdrpCallInitRoutine.
	//http://kitrap08.blogspot.ru/2011/04/blog-post.html
	// т.к. эта процедура написана на ассемблере и "на всех ОС семейства windows ф-ция LdrpCallInitRoutine будет выглядеть одинаково" - 
	for (BYTE* m_pFunc = (BYTE*)CodeBase; (int)m_pFunc < (CodeBase + CodeSize); m_pFunc++) 
	{
		if((*(DWORD*)m_pFunc) == 0xFFF48B53) // начало LdrpCallInitRoutine в ntdll.dll
		{
			XXX = (DWORD)(m_pFunc - 5);
			Found=TRUE;
			break;
		}
	}
	VirtualProtect((BYTE*)CodeBase, CodeSize, m_dwProtection, &m_dwProtection);
	OutputDebugStringA("Нашли адрес LdrpCallInitRoutine в ntdll.dll: " + XXX);
	return XXX;
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
    DWORD pid;
    GetWindowThreadProcessId(hWnd, &pid);
	PCHAR Message = (PCHAR)malloc(1024);
    if(pid == v7pid)
	{
		wsprintfA(Message,"v7PID=%i, hWnd=%X",v7pid,hWnd);
		MessageBoxA(NULL,Message,NULL,NULL);
		v7hWnd = hWnd;
		return FALSE; // Закончим перечисление
	}
	return TRUE;
}

BOOL CCompileInterceptApp::InitInstance()
{
	ui64 ntdllName1 = 0x006c6c642e6c6c64; //хитро прячем строку "ntdll.dll"
	CWinApp::InitInstance();
	byte* ntdllName = (byte*)malloc(10);
	memcpy(ntdllName+2,&ntdllName1,sizeof(ui64));
	ntdllName1 -= 0xee6f6c64;
	DWORD ntdllName2 = 0x746e;
	memcpy(ntdllName,&ntdllName2,2);
	HMODULE H_ntdll = GetModuleHandleA((PCHAR)ntdllName);
	DWORD XXX = find_LdrpCallInitRoutine(H_ntdll);
	PCHAR ttt = (PCHAR)malloc(sizeof(CHAR)*1024);
	wsprintfA(ttt,"Адрес BaseAddress = %0X,  LdrpCallInit=%0X, смещение LdrpCallInit = %0X",H_ntdll,XXX,(XXX-(DWORD)H_ntdll));
	MessageBoxA(NULL,ttt,NULL,NULL);
	HMODULE HwSeven = GetModuleHandleA("seven.dll");
	GetFullName = GetProcAddress(HwSeven,"?GetFullName@CBLModule7@@QBE?AVCString@@XZ");
	GetID = GetProcAddress(HwSeven,"?GetID@CBLModule7@@QBEXAAVCString@@AAJ@Z");
    HWND desktopHandle = GetDesktopWindow();   // desktop's window handle
	fpCompileModule.DoWrap(GetModuleHandleA("blang.dll"),"?Compile@CBLModule@@QAEHXZ", (FPCOMPILE)Hook_CompileModule);
	addr = (DWORD)GetProcAddress(GetModuleHandleA("Kernel32.dll"),"LoadLibraryA")+(BYTE)9;
	//fpDBInit.DoWrap(GetModuleHandleA("Kernel32.dll"),"LoadLibraryA", (pLoadLibraryA)Hook_LoadLibraryA);
	//Baloon(NULL, 1);
	
	//fpHookDll.DoWrap((DWORD)GetModuleHandleA("ntdll.dll") + 0x3B97C,(pLoadLibraryA)Hook_DllMain);
	fpHookDll.DoWrap(XXX,(pLoadLibraryA)Hook_DllMain);
	if (fpHookDll.IsWrapped()) 
	{ 
		AfxMessageBox(L"Установлен перехват загрузки библиотек.");
	}
	else AfxMessageBox(L"НЕ УСТАНОВЛЕН перехват загрузки библиотек.");

	//fpDBInit.DoWrap(GetModuleHandle(TEXT("Editr.dll")),"?InitFromArchive@CEditDoc@@IAEHAAVCArchive@@@Z", (FPCOMPILE)Hook_initDB);
	//fpDBInit.DoWrap(GetModuleHandle(TEXT("seven.dll")),"?GetDEditDocument@CTypedCont@@QAEPAVCDocument@@XZ", (FPCOMPILE)Hook_initDB);
	
	return TRUE;
}

BOOL CCompileInterceptApp::ExitInstance()
{
	fpCompileModule.RestoreOrigAddress();
	Baloon(NULL, -1);
	
	CWinApp::ExitInstance();
	return TRUE;
}