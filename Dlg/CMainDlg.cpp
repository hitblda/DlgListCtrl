// CMainDlg.cpp: 实现文件
//

#include "pch.h"
#include "Dlg.h"
#include "CMainDlg.h"
#include "afxdialogex.h"
#include "CLogin.h"
#include "CInforMng.h"
#include "CAdmin.h"


// CMainDlg 对话框

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_mainDlg, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Login, &CMainDlg::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_inforManager, &CMainDlg::OnBnClickedinformanager)
	ON_BN_CLICKED(IDC_ADMIN, &CMainDlg::OnBnClickedAdmin)
END_MESSAGE_MAP()


// CMainDlg 消息处理程序


void CMainDlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	GetDlgItemText(IDC_NUM, str);

	EndDialog(IDC_Login);
}


void CMainDlg::OnBnClickedinformanager()
{
	// TODO: 在此添加控件通知处理程序代码


	EndDialog(IDC_inforManager);

}


void CMainDlg::OnBnClickedAdmin()
{
	// TODO: 在此添加控件通知处理程序代码


	EndDialog(IDC_ADMIN);

}



