﻿// CAdmin.cpp: 实现文件
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
	DDX_Control(pDX, IDC_COMBO1, m_cbComBox);
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
	
	int nIndex = m_cbComBox.GetCurSel();
	m_cbComBox.GetLBText(nIndex, str2);
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
	pList->InsertItem(
				LVIF_TEXT | LVIF_STATE, 0, str,
				LVIS_SELECTED, LVIS_SELECTED,
				0, 0);
	pList->SetItemText(0,1,L"");  //从 
	pList->SetItemText(0,2,str1);  //从密码的输入框获取
	pList->SetItemText(0,3, str2);   
	pList->SetItemText(0,4, L"");
	pList->SetItemText(0,5, str3);

	m_bModify = true;
}

void CAdmin::OnBnClickeddel()
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

void CAdmin::OnBnClickedModify()
{
	// 只修改密码和权限，不能修改用户名
	// 即，普通用户不能只能修改密码；高级用户可以修改密码和其他用户的权限
#if 0
	//屏蔽是因为，实现上还有欠缺
	//1，方法1，通过点击CListCtrl里面的用户名，然后将其获取到CEdit控件，该知识欠缺，最后点击修改按钮修改
	//2，方法2，点击修改按钮将CListCtrl里面的东西获取到弹出一个框里面，然后在这个里面修改，该知识欠缺

	m_bModify = true;
#endif

	/*
		先读取内容，然后在新的对话框里面修改
		而由于内容已经是全局的，故在新的对话框里面读取，然后进行修改
		注意：需要重新设置对话框的标题！！！！
	*/

	// 详细信息添加按钮==》信息录入界面
	CDataInput dlg;
	dlg.DoModal();
}


void CAdmin::LoadFile()
{
	// TODO: 在此处添加实现代码.
	CFile f;
	if (!f.Open(L"MyAdmData.dat", CFile::modeRead))
	{
		AfxMessageBox(L"UserSettingSave.dat文件不存在!");
		return;
	}
	//MyAdmData a;
	int i = 0;

	while (f.Read(&theApp.a, sizeof(theApp.a)) == sizeof(theApp.a))
	{
		//pList->InsertItem(
		//	LVIF_TEXT | LVIF_STATE, i, a.sName,
		//	(i % 2) == 0 ? LVIS_SELECTED : 0, LVIS_SELECTED,
		//	0, 0);
		pList->InsertItem(i, theApp.a.sName);

		pList->SetItemText(i, 1, theApp.a.sCode);  //从密码的输入框获取
		pList->SetItemText(i, 2, theApp.a.nPrior?L"普通":L"高级");  //从密码的输入框获取
		pList->SetItemText(i, 3, theApp.a.m_tm);

	}
}


BOOL CAdmin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//根据保存到全局区的内容 给出窗口标题
	CString str = L"管理员信息设置界面 - ";
	str += theApp.a.sName;
	str += L" ( ";
	str += theApp.a.nPrior ? L"普通" : L"高级";
	str += L" )";
	SetWindowText(str);

	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	 //如果在控件里面没有给定选项，那么这里通过该方式给
	/*
有两种方式，第一种我把它成为盲插，为什么呢？因为它不指定行进行插入，利用函数AddString,
m_cbcombox.AddString(_T("北京"));
m_cbcombox.AddString(_T("上海"));
m_cbcombox.AddString(_T("广州"));
这种一般不能按照自己意愿顺序先后插入，可能顺序是错乱的。需要在其属性sort中，修改为false。
第二种我要告诉大家的是可以按照行号进行插入，它所用的的API是InsertString,
m_cbcombox.InsertString(0 ,_T("北京") );
m_cbcombox.InsertString(1 ,_T("上海") );
m_cbcombox.InsertString(2 ,_T("广州") );
————————————————
版权声明：本文为CSDN博主「裂风龙隼」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/leiyang2014/article/details/53980555
	*/
	pCombo->InsertString(0, _T("普通"));
	pCombo->InsertString(1, _T("高级"));
//	pCombo->InsertString(3, _T("超级"));

	//在ComBox属性选项的Data里面输入 普通;管理员  
	pCombo->SetCurSel(0);  //给下拉复选框设置默认选择项

	//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_ListMng);
	pList = (CListCtrl*)GetDlgItem(IDC_ListMng);
	pList->InsertColumn(1, L"账户", LVCFMT_CENTER, 120,0);
	pList->InsertColumn(1, L"工号", LVCFMT_CENTER, 120,0);
	pList->InsertColumn(2, L"密码", LVCFMT_CENTER, 160);
	pList->InsertColumn(3, L"权限", LVCFMT_CENTER, 120);
	pList->InsertColumn(4, L"入职时间", LVCFMT_CENTER, 200);
	pList->InsertColumn(4, L"工资", LVCFMT_CENTER, 90);

	//////////////////////////////////////////////////////////
	LoadFile();
	   
	// TODO:  在此添加额外的初始化

	/////////////////////////////////////////////////////////////////
	if (theApp.a.nPrior) //为普通用户
	{
		GetDlgItem(IDC_Add)->DestroyWindow(); //使该按钮不能使用
		GetDlgItem(IDC_del)->DestroyWindow(); //使该按钮不能使用
		GetDlgItem(IDC_COMBO1)->DestroyWindow(); //使该按钮不能使用	}
	}

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

	if (m_bModify)
	{
		int nRet = AfxMessageBox(L"是否将改到保存到文件？", MB_YESNOCANCEL);
		if ( nRet==IDYES)
		{
			SaveData();
		}
		else
			return;
	}

	CDialogEx::OnDestroy();

	 
}


void CAdmin::SaveData()
{
	// TODO: 在此处添加实现代码.
	//MyAdmData a;
	CFile f;
	if (! f.Open(L"MyAdmData.dat", CFile::modeCreate | CFile::modeReadWrite))
	{
		AfxMessageBox(L"保存文件失败！！");
		return;
	}
	int i = 0, nCount = pList->GetItemCount();
	while (i < nCount)
	{
		pList->GetItemText(i, 0, theApp.a.sName,_countof(theApp.a.sName));
		pList->GetItemText(i, 1, theApp.a.sCode,_countof(theApp.a.sCode));
		if (pList->GetItemText(i, 2) == L"普通")
		{
			theApp.a.nPrior = 1;
		}
		else if (pList->GetItemText(i, 2) == L"高级")
		{
			theApp.a.nPrior = 0;
		}
		pList->GetItemText(i, 3, theApp.a.m_tm, _countof(theApp.a.m_tm));

		f.Write(&theApp.a, sizeof(theApp.a));  //结构体
		// _countof 只对数组有效

		i++;

	}

	f.Close();
}

