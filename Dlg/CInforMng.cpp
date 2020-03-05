// CInforMng.cpp: 实现文件
//

#include "pch.h"
#include "Dlg.h"
#include "CInforMng.h"
#include "CAdmin.h"
#include "afxdialogex.h"

#include "CDataInput.h"

// CInforMng 对话框

IMPLEMENT_DYNAMIC(CInforMng, CDialogEx)

CInforMng::CInforMng(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Infor, pParent)
{

}

CInforMng::~CInforMng()
{
}

void CInforMng::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInforMng, CDialogEx)
	ON_BN_CLICKED(IDC_Input, &CInforMng::OnClkInforInpur)
	ON_BN_CLICKED(IDC_ADMIN, &CInforMng::OnAdminClk)
	ON_BN_CLICKED(IDC_GetInfor, &CInforMng::OnBnClickedGetinfor)
END_MESSAGE_MAP()


// CInforMng 消息处理程序


void CInforMng::OnClkInforInpur()
{
	// TODO: 在此添加控件通知处理程序代码
	//EndDialog(IDC_inforManager);
	CDataInput dlg;
	dlg.DoModal();

}


void CInforMng::OnAdminClk()
{
	// TODO: 在此添加控件通知处理程序代码
	//EndDialog(IDC_inforManager);
	CAdmin dlg;
	dlg.DoModal();

}




void CInforMng::OnBnClickedGetinfor()
{
	// TODO: 在此添加控件通知处理程序代码

	CString str;
	//GetDlgItemText(IDC_EDIT1,str);
	//MessageBox(L"您输入的信息是：\r\n" + str);
	//SetDlgItemText(IDC_EDIT2, str);

	//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_ListMng);
	//int i = pList->GetItemCount();//获取行数

	//pList->InsertItem(i, str);
	//GetDlgItemText(IDC_EDIT1, str);
	//pList->SetItemText(i, 1, str);
	//GetDlgItemText(IDC_EDIT2, str);
	//pList->SetItemText(i, 2, str);
	//GetDlgItemText(IDC_EDIT3, str);
	//pList->SetItemText(i, 3, str);
	//int n = str.Find(L' '); //Index
	//pList->SetItemText(i, 3, str.Left(n));
	//m_bModify = TRUE;


	//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_ListInfor);
	//pList->InsertColumn(1, L"工号", 0, 120);
	//pList->InsertColumn(2, L"姓名", 0, 160);
	//pList->InsertColumn(3, L"入职时间", 0, 200);

	//GetDlgItemText(IDC_EDIT1, str);
	////if (Check(str))  //已经存在！
	////{
	////	AfxMessageBox(L"用户已经存在，请重新输入");
	////	return;
	////}

	//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_ListMng);
	//int i = 0;
	//if (pList->GetItemCount()) //获取该控件里面有多少行文字,第0行是编号0
	//	i = pList->GetItemCount();
	//pList->InsertColumn(i, str, 0, 0, 140);
	//GetDlgItemText(IDC_EDIT2, str);  //从密码的输入框获取
	//pList->SetItemText(i, 1, str); //将密码放到插入列的第二行编号是1
	//GetDlgItemText(IDC_EDIT3, str);  //从密码的输入框获取
	//pList->SetItemText(i, 2, str); //将密码放到插入列的第二行编号是1

	//CTime time;
	//time = CTime::GetCurrentTime();
	//str = time.Format("%Y-%m-%d %A %H:%M:%S");
	//pList->SetItemText(i, 3, str); //获取当前修改时间



}





