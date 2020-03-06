// CDataInput.cpp: 实现文件
//

#include "pch.h"
#include "Dlg.h"
#include "CDataInput.h"
#include "afxdialogex.h"
#include "CDataInput.h"


// CDataInput 对话框

IMPLEMENT_DYNAMIC(CDataInput, CDialogEx)

CDataInput::CDataInput(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Entrance, pParent)
{

}

CDataInput::~CDataInput()
{
}

void CDataInput::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDataInput, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDataInput::OnBnClickedOk)
END_MESSAGE_MAP()


// CDataInput 消息处理程序


void CDataInput::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类	{
	NextDlgCtrl();
	CWnd* p = GetFocus();
	if (p->GetDlgCtrlID() == IDOK)
	{

	}

	CDialogEx::OnOK();
}


void CDataInput::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//MyAdmData a;
	CFile f;
	if (!f.Open(L"MyAdmData.dat", CFile::modeCreate | CFile::modeReadWrite))
	{
		AfxMessageBox(L"保存文件失败！！");
		return;
	}
	CString str;
	//GetDlgItemText(IDC_NAME, a.sName);
	GetDlgItemText(IDC_NAME, str);
	//str.GetBuffer(sizeof(theApp.a.sName)); //CString转TCHAR


	//int i = 0, nCount = pList->GetItemCount();
	//while (i < nCount)
	//{
	//	pList->GetItemText(i, 0, a.sName, _countof(a.sName));
	//	pList->GetItemText(i, 1, a.sCode, _countof(a.sCode));
	//	if (pList->GetItemText(i, 2) == L"普通")
	//	{
	//		a.nPrior = 1;
	//	}
	//	else if (pList->GetItemText(i, 2) == L"高级")
	//	{
	//		a.nPrior = 0;
	//	}
	//	pList->GetItemText(i, 3, a.m_tm, _countof(a.m_tm));

	//	f.Write(&a, sizeof(a));  //结构体
	//	// _countof 只对数组有效

	//	i++;

	//}

	f.Close();

	CDialogEx::OnOK();
}


BOOL CDataInput::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	//根据保存到全局区的内容 给出窗口标题
	CString str = L"信息输入 修改面板 - ";
	str += theApp.a.sName;
	str += L" ( ";
	str += theApp.a.nPrior ? L"普通" : L"高级";
	str += L" )";
	SetWindowText(str);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
