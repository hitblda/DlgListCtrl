// CLogin.cpp: 实现文件
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
END_MESSAGE_MAP()


// CLogin 消息处理程序


void CLogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	GetDlgItemText(IDC_NUM, str);




	CDialogEx::OnOK();
}
