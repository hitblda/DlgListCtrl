// CDataInput.cpp: 实现文件
//

#include "pch.h"
#include "Dlg.h"
#include "CDataInput.h"
#include "afxdialogex.h"


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
