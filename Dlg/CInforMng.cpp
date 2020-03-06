﻿// CInforMng.cpp: 实现文件
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
	ON_BN_CLICKED(IDC_del, &CInforMng::OnBnClickeddel)
	ON_BN_CLICKED(IDC_Modify, &CInforMng::OnBnClickedModify)
END_MESSAGE_MAP()


// CInforMng 消息处理程序


void CInforMng::OnClkInforInpur()
{
	// 详细信息添加按钮==》信息录入界面
	//EndDialog(IDC_inforManager);
	CDataInput dlg;
	dlg.DoModal();

}


void CInforMng::OnAdminClk()
{
	//账号管理按钮==》账号管理界面
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




BOOL CInforMng::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//根据保存到全局区的内容 给出窗口标题
	CString str = L"信息管理面板 - ";
	str += theApp.a.sName;
	str += L" ( ";
	str += theApp.a.nPrior ? L"普通" : L"高级";
	str += L" )";
	SetWindowText(str);


	// TODO:  在此添加额外的初始化
	pList = (CListCtrl*)GetDlgItem(IDC_ListInfor);
	pList->InsertColumn(1, L"工号", LVCFMT_LEFT, 120, 0);
	pList->InsertColumn(2, L"姓名", LVCFMT_LEFT, 160);
	pList->InsertColumn(3, L"入职日期", LVCFMT_LEFT, 200);
	pList->InsertColumn(4, L"工资", LVCFMT_LEFT, 120);


	//////////////////////////////////////////////////////////
//LoadFile();

/////////////////////////////////////////////////////////////////
	if (theApp.a.nPrior) //为普通用户
	{
		GetDlgItem(IDC_GetInfor)->DestroyWindow(); //使该按钮不能使用
		GetDlgItem(IDC_Modify)->DestroyWindow(); //使该按钮不能使用
		GetDlgItem(IDC_del)->DestroyWindow(); //使该按钮不能使用
		GetDlgItem(IDC_Input)->DestroyWindow(); //使该按钮不能使用
		GetDlgItem(IDC_ADMIN)->DestroyWindow(); //使该按钮不能使用
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CInforMng::OnBnClickeddel()
{
	// TODO: 在此添加控件通知处理程序代码
	if (AfxMessageBox(L"您确认要删除吗？？", MB_YESNOCANCEL) == IDYES)
	{
		POSITION pos = pList->GetFirstSelectedItemPosition();
		if (!pos)
		{
			AfxMessageBox(L"请选择一个账号");
			return;
		}
		int nItem = pList->GetNextSelectedItem(pos);
		//	CString str = pList->GetItemText(nItem, 2);
		if (!pList->GetItemText(nItem, 2).CompareNoCase(L"高级"))
		{
			AfxMessageBox(L"管理员账号不可删除！");
			return;
		}
		if (AfxMessageBox(L"最后的删除警告,确认删除用户 " + pList->GetItemText(nItem, 0) + L" 吗？", MB_YESNOCANCEL) == IDYES)
		{
			m_bModify = TRUE;
			pList->DeleteItem(nItem);
		}
		return;
	}

}


void CInforMng::OnBnClickedModify()
{
	/*
		先读取内容，然后在新的对话框里面修改
		而由于内容已经是全局的，故在新的对话框里面读取，然后进行修改
		注意：需要重新设置对话框的标题！！！！
	*/

	// 详细信息添加按钮==》信息录入界面
	CDataInput dlg;
	dlg.DoModal();
}
