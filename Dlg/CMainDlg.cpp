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

	EndDialog(IDC_Login);  //
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





BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	//根据保存到全局区的内容 给出窗口标题
	CString str = L"控制面板 - ";
	str += theApp.a.sName;
	str += L" ( ";
	str += theApp.a.nPrior ? L"普通":L"高级";
	str += L" )";
	SetWindowText(str);
	// 在这里判断，用户是普通的还是一般的，如果是一般的主对话框里面的按钮disable
	if (theApp.a.nPrior) //为普通用户
	{
		GetDlgItem(IDC_inforManager)->DestroyWindow(); //使该按钮不能使用
		//ShowWIndoe()
		//EnableWindow()
	}



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
