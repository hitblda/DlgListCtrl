
// Dlg.cpp: 定义应用程序的类行为。
//

#include "pch.h"
#include "framework.h"
#include "Dlg.h"
#include "DlgDlg.h"
#include "CMainDlg.h"
#include "CAdmin.h"
#include "CInforMng.h"
#include "CLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlgApp

BEGIN_MESSAGE_MAP(CDlgApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDlgApp 构造

CDlgApp::CDlgApp()
{
	tryTimes = 0;
	//MyAdmData a;
	//CLogin lg;
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CDlgApp 对象

CDlgApp theApp;

// CDlgApp 初始化

BOOL CDlgApp::InitInstance()
{
	CWinApp::InitInstance();
	
	CLogin lg;

	while( (tryTimes <3)&&(lg.CkeckPasswd == FALSE))
		//while( (tryTimes <3) )
	{
		tryTimes++;
		if (IDCANCEL == lg.DoModal())
			return false;

		if (lg.CkeckPasswd == false)
		{
			if (tryTimes >= 3)
			{
				AfxMessageBox(L"拒绝恶意登录！");
				return false;
			}
			else
				AfxMessageBox(L"用户名/工号 与密码不对应，请重新输入！");
		}		
	}		

	while (true)
	{
		CMainDlg dlg;
		int idNum = dlg.DoModal();
		if (idNum == IDCANCEL)
		{
			//AfxMessageBox(L"You have pressed CANCEL!\r\n退出中，请确定");
			return FALSE;//表示退出
		}			
		else if (idNum == IDC_ADMIN)
		{
			CAdmin dlg1;
			dlg1.DoModal();
		}
		else if (idNum == IDC_Login)
		{
			CLogin dlg2;
			dlg2.DoModal();

		}
		else if (idNum == IDC_inforManager)
		{
			CInforMng dlg3;
			dlg3.DoModal();

		}
	}

	return FALSE;
}

