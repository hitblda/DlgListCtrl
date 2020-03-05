// CAdmin.cpp: 实现文件
//

#include "pch.h"
#include "Dlg.h"
#include "CAdmin.h"
#include "afxdialogex.h"
#include "CDataInput.h"


// CAdmin 对话框

IMPLEMENT_DYNAMIC(CAdmin, CDialogEx)

CAdmin::CAdmin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Admin, pParent)
{

}

CAdmin::~CAdmin()
{
}

void CAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdmin, CDialogEx)
	ON_BN_CLICKED(IDC_del, &CAdmin::OnBnClickeddel)
	ON_BN_CLICKED(IDC_Add, &CAdmin::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_Modify, &CAdmin::OnBnClickedModify)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CAdmin 消息处理程序

BOOL CAdmin::Check(LPCTSTR mStr)
{
	// TODO: 在此处添加实现代码.
	//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_ListMng);
	int i = 0, nCount = pList->GetItemCount(); //获取该控件里面有多少行文字
	//CString mTmp = (pList->GetItemText(i, 0));//获取第i行第0列的数据,再和传进来的对比
	//bool b=mTmp.CompareNoCase(mStr);//CompareNoCase为不区分大小写的对比,逻辑！匹配为FALSE
	
	while (i < nCount)
	{
		//if (mStr == mTmp )  		
		if (!pList->GetItemText(i, 0).CompareNoCase(mStr))  //获取第i行第0列的数据,再和传进来的对比
			return  true;
		i++;
	}
	return FALSE;
}

void CAdmin::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str,str1,str2,str3;
	GetDlgItemText(IDC_EDIT1, str);
	GetDlgItemText(IDC_EDIT2, str1);  //从密码的输入框获取
	GetDlgItemText(IDC_EDIT3, str2);  //从密码的输入框获取
	CTime time;
	time = CTime::GetCurrentTime();
	str3 = time.Format("%Y-%m-%d %A %H:%M:%S");


	if (Check(str))  //已经存在！
	{
		AfxMessageBox(L"用户已经存在，请重新输入");
		return;
	}
	
	//CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_ListMng);
	int nRawCount = pList->GetItemCount(); //获取该控件里面有多少行文字,第0行是编号0
	int nColumnCount = pList->GetHeaderCtrl()->GetItemCount();
	int i = 0;
	pList->InsertItem(
				LVIF_TEXT | LVIF_STATE, i, str,
				(i % 2) == 0 ? LVIS_SELECTED : 0, LVIS_SELECTED,
				0, 0);
	pList->SetItemText(0,1,str1);  //从密码的输入框获取
	pList->SetItemText(0,2, str2);  //从密码的输入框获取
	pList->SetItemText(0, 3, str3);
}

void CAdmin::OnBnClickeddel()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox(L"您确认要删除吗？？");
}

void CAdmin::OnBnClickedModify()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CAdmin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	//pCombo->AddString(L"普通?? 管理员");    //如果在控件里面没有给定选项，那么这里通过该方式给
	//在ComBox属性选项的Data里面输入 普通;管理员  
	pCombo->SetCurSel(0);  //给下拉复选框设置默认选择项

	//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_ListMng);
	pList = (CListCtrl*)GetDlgItem(IDC_ListMng);
	pList->InsertColumn(1, L"账户", LVCFMT_LEFT, 120,0);
	pList->InsertColumn(2, L"密码", LVCFMT_LEFT, 160);
	pList->InsertColumn(3, L"权限", LVCFMT_LEFT, 120);
	pList->InsertColumn(4, L"修改日期", LVCFMT_LEFT, 200);

	//failed
	//pList->SetItemText(1, 1, L"StrNameIs"); //将StrNameIs放到插入列的第二行编号是1
	//pList->SetItemText(1, 2, L"StrCodeIs"); //将StrNameIs放到插入列的第二行编号是1

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
/*
int InsertColumn(int nCol,const LVCOLUMN* pColumn );
int InsertColumn(int nCol,LPCTSTR lpszColumnHeading,int nFormat = LVCFMT_LEFT,int nWidth = -1,int nSubItem = -1 );
   这两个函数用于在报表式列表视图控件中插入列。
   第一个函数中，nCol参数为插入列的索引，pColumn参数指向LVCOLUMN结构，其中包含了插入列的属性。
   第二个函数中，nCol参数也是插入列的索引，lpszColumnHeading参数为列标题字符串，nFormat参数为列中文本的对齐方式，可以是LVCFMT_LEFT、LVCFMT_RIGHT或LVCFMT_CENTER，nWidth参数为列宽，nSubItem为插入列对应列表子项的索引。两个函数在成功时都返回新列的索引，失败都返回-1。

BOOL SetItemText(int nItem,int nSubItem,LPCTSTR lpszText);
   设置指定列表项或列表子项的显示文本。参数nItem和nSubItem同GetItemText。参数lpszText为要设置的显示文本字符串。如果设置成功则返回TRUE，否则返回FALSE。

*/


void CAdmin::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码

	 
}
