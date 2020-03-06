
// Dlg.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CDlgApp:
// 有关此类的实现，请参阅 Dlg.cpp
//

class CDlgApp : public CWinApp
{
public:
	CDlgApp();
	///////////////////////////////////////////////
	/*
		放到这里，然后，通过 theApp.a来引用
	*/
	MyAdmData a;

	///////////////////////////////////////////////
// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
	int tryTimes;

};

extern CDlgApp theApp;
