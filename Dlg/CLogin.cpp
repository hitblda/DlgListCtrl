﻿// CLogin.cpp: 实现文件
//

#include "pch.h"
#include "Dlg.h"
#include "CLogin.h"
#include "afxdialogex.h"


// CLogin 对话框

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Login, pParent)
{
	CkeckPasswd = FALSE;
}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLogin::OnBnClickedOk)
	ON_WM_TIMER()
END_MESSAGE_MAP()



bool CLogin::Createfile(MyAdmData& a)
{
	// TODO: 在此处添加实现代码.
	CFile f;
	if (!f.Open(L"MyAdmData.dat", CFile::modeCreate | CFile::modeWrite))
		return false;
	
	f.Write(&a, sizeof(a));
	f.Close();

	return true;
}

// CLogin 消息处理程序
bool CLogin::LoginJudge(int szNum, const CString& szName, const CString& szCode)
{
	// TODO: 在此处添加实现代码.
	CFile f;
	MyAdmData a= { L"admin", 100000, L"123456", 0, L"2020-03-08" , 54321 };

	if (!f.Open(L"MyAdmData.dat", CFile::modeRead))
	{
		//if (szName.CompareNoCase(L"admin") || szNum.CompareNoCase(L"123456"))
		if (!szName.CompareNoCase(L"admin") )
		//if(L"admin"==szName)
		{
			//a = { L"admin",L"100000" ,L"123456" ,0 ,L"2020-03-08",54321 };
			Createfile(a);
			StrCpy(a.sName, L"admin");
			a.nPrior = 0;

			theApp.a = a;
			return true;
		}
		else
		{
			return false;
			EndDialog(0);
		}
	}
	else  //文件存在才能够以普通用户账号登录
	{
		if (!szName.CompareNoCase(L"admin"))  //文件存在，是admin
		{
			StrCpy(a.sName, L"admin");
			a.nPrior = 0;

			theApp.a = a;
			return true;

		}
		/*else if (!szNum.CompareNoCase(L"123456"))
		{
			StrCpy(a.sName, L"normal");
			a.nPrior = 1;

			theApp.a = a;
			return true;
		}*/
		else if (szNum == 123456)
		{
			StrCpy(a.sName, L"normal");
			a.nPrior = 1;

			theApp.a = a;
			return true;
		}
		else
			return false;
	}

	while (f.Read(&a, sizeof(a)) == sizeof(a))
	{
		if (!(szName.CompareNoCase(a.sName)))   //发现有这么个账号
		{
			if (szCode == a.sCode)
			{
				AfxMessageBox(L"欢迎！");
				theApp.a = a;

				return true;
			}
			else
			{
				SetDlgItemText(IDC_NUM, L"");
				SetDlgItemText(IDC_NAME, L"");
				SetDlgItemText(IDC_Pass, L"");
				AfxMessageBox(L"用户名或者密码错误，请重新输入！");
				return false;
			}
		}
	}

	return false;
}

void CLogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString szNum, szName, szPass;
	int num = 0;
	GetDlgItemText(IDC_NUM, szNum);
	GetDlgItemText(IDC_NAME, szName);
	GetDlgItemText(IDC_Pass, szPass);
	if (szNum == L"")
	{
		num = 0;
	}
	else
	{
		num = _ttoi(szNum);
	}
	//szNum.Format(L"%d", num);


	if (FALSE == LoginJudge(num,szName, szPass))
	{
		CkeckPasswd = false;
		EndDialog(IDC_Login);
		return;
	}
	else
		CkeckPasswd = true;

	//if (szName.CompareNoCase(L"admin") || szPass != L"123456")	   	  

	CDialogEx::OnOK();
}


void CLogin::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnCancel();

	//如果取消输入密码，则关闭本系统，该怎么实现？
	//EndDialog(IDC_Login);
}


void CLogin::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
}


void CLogin::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnOK();
}


