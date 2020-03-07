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
	DDX_Control(pDX, IDC_COMBO1, m_cbComBox);
}


BEGIN_MESSAGE_MAP(CAdmin, CDialogEx)
	ON_BN_CLICKED(IDC_del, &CAdmin::OnBnClickeddel)
	ON_BN_CLICKED(IDC_Add, &CAdmin::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_Modify, &CAdmin::OnBnClickedModify)

END_MESSAGE_MAP()


// CAdmin 消息处理程序

BOOL CAdmin::Check(LPCTSTR mStr)
{
	// TODO: 在此处添加实现代码.
	//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_ListMng);
	int i = 0, nCount = mAdminList.GetItemCount(); //获取该控件里面有多少行文字
	//CString mTmp = (mAdminList.GetItemText(i, 0));//获取第i行第0列的数据,再和传进来的对比
	//bool b=mTmp.CompareNoCase(mStr);//CompareNoCase为不区分大小写的对比,逻辑！匹配为FALSE
	
	while (i < nCount)
	{
		//if (mStr == mTmp )  		
		if (!mAdminList.GetItemText(i, 0).CompareNoCase(mStr))  //获取第i行第0列的数据,再和传进来的对比
			return  true;
		i++;
	}
	return FALSE;
}

void CAdmin::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码

	//////////////////////读出已有值//////////////////////////
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
	}
	CString nstr1, nstr2;
	nstr1.Format(L"%d", theApp.a.sNum+1);///???
	nstr2.Format(L"%d", theApp.a.Salary);
	//////////////////////////////////////////////////////////

	CString str,str1,str2,str3;
	GetDlgItemText(IDC_EDIT1, str);
	GetDlgItemText(IDC_EDIT2, str1);  //从密码的输入框获取
	
	int nIndex = m_cbComBox.GetCurSel();
	int workerNo = 0;
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
	int nRawCount = mAdminList.GetItemCount(); //获取该控件里面有多少行文字,第0行是编号0
	int nColumnCount = mAdminList.GetHeaderCtrl()->GetItemCount();
	mAdminList.InsertItem(
				LVIF_TEXT | LVIF_STATE, 0, str,
				LVIS_SELECTED, LVIS_SELECTED,
				0, 0);
	mAdminList.SetItemText(0,1,nstr1);  //从 
	mAdminList.SetItemText(0,2,str1);  //从密码的输入框获取
	mAdminList.SetItemText(0,3, str2);   
	mAdminList.SetItemText(0,4, nstr2);
	mAdminList.SetItemText(0,5, str3);

	m_bModifyA = true;
}

void CAdmin::OnBnClickeddel()
{
	// TODO: 在此添加控件通知处理程序代码
	if (AfxMessageBox(L"您确认要删除吗？？", MB_YESNOCANCEL) == IDYES)
	{
		POSITION pos = mAdminList.GetFirstSelectedItemPosition();
		if (!pos)
		{
			AfxMessageBox(L"请选择一个账号");
			return;
		}
		int nItem = mAdminList.GetNextSelectedItem(pos);
	//	CString str = mAdminList.GetItemText(nItem, 2);
		if (!mAdminList.GetItemText(nItem, 3).CompareNoCase(L"高级"))
		{
			AfxMessageBox(L"管理员账号不可删除！");
			return;
		}
		if (AfxMessageBox(L"最后的删除警告,确认删除用户 " + mAdminList.GetItemText(nItem, 0) + L" 吗？", MB_YESNOCANCEL) == IDYES)
		{
			m_bModifyA = TRUE;
			mAdminList.DeleteItem(nItem);
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

	m_bModifyA = true;
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


void CAdmin::LoadFile(bool prior)
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
	
		CString str1,str2;
		//int n = theApp.a.Salary;
		//str.Format(L"%d",n);
	
		str1.Format(L"%d", theApp.a.sNum);
		str2.Format(L"%d", theApp.a.Salary);


		mAdminList.InsertItem(LVIF_TEXT | LVIF_STATE,i, theApp.a.sName, 0, LVIS_SELECTED,
			0, 0);//账号

		//mAdminList.SetItemText(i, 1, theApp.a.sName);  
		mAdminList.SetItemText(i, 1, str1);  //工号
		mAdminList.SetItemText(i, 2, theApp.a.m_tm);  //入职时间
		if (prior)
		{
			mAdminList.SetItemText(i, 3, theApp.a.sCode);  //密码
			mAdminList.SetItemText(i, 4, theApp.a.nPrior ? L"普通" : L"高级");  //权限
			mAdminList.SetItemText(i, 5, str2);  //工资
		}
	}
}


BOOL CAdmin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_bModifyA = false;

	//根据保存到全局区的内容 给出窗口标题
	CString str = L"管理员信息设置界面 - ";
	str += theApp.a.sName;
	str += L" ( ";
	str += theApp.a.nPrior ? L"普通" : L"高级";
	str += L" )";
	SetWindowText(str);

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
	//HWND hWnd = ::GetDlgItem(m_hWnd, IDC_COMBO1);
	//m_cbComBox.Attach(hWnd);
	//m_cbComBox.InsertString(1, L"高级");
	//m_cbComBox.InsertString(0, L"普通");
	//m_cbComBox.SetCurSel(0);

	//m_cbComBox.SubclassDlgItem(IDC_COMBO1, this);
	//m_cbComBox.InsertString(0, L"普通");
	//m_cbComBox.InsertString(1, L"高级");

	//HWND hWnd = ::GetDlgItem(m_hWnd, IDC_COMBO1);
	//m_cbComBox.SubclassWindow(hWnd);

	////m_cbComBox.AddString(L"普通");
	////m_cbComBox.AddString(L"高级");
	//	m_cbComBox.InsertString(0, L"普通");
	//m_cbComBox.InsertString(1, L"高级");
/////////////////////////////////////////////////////////////////////////////
	//attach 、 SubclassDlgItem 和 SubclassWindow 不能用于CComboBox

	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pCombo->InsertString(0, _T("普通"));
	pCombo->InsertString(1, _T("高级"));
	//在ComBox属性选项的Data里面输入 普通;管理员
	pCombo->SetCurSel(0);  //给下拉复选框设置默认选择项


	//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_ListMng);
	//pList = (CListCtrl*)GetDlgItem(IDC_ListMng);

	//HWND hWnd = ::GetDlgItem(m_hWnd, IDC_ListMng);
	//mAdminList.Attach(hWnd);
	mAdminList.SubclassDlgItem(IDC_ListMng, this);

	//mAdminList.SubclassWindow(::GetDlgItem(hWnd,IDC_ListMng));

	mAdminList.InsertColumn(1, L"账户", LVCFMT_LEFT, 120,0);
	mAdminList.InsertColumn(2, L"工号", LVCFMT_CENTER, 120,0);
	mAdminList.InsertColumn(3, L"入职时间", LVCFMT_CENTER, 200,0);
	if (!theApp.a.nPrior) //为普通用户
	{
		mAdminList.InsertColumn(4, L"密码", LVCFMT_CENTER, 160, 0);
		mAdminList.InsertColumn(5, L"权限", LVCFMT_CENTER, 120, 0);
		mAdminList.InsertColumn(6, L"工资", LVCFMT_CENTER, 90, 0);
	}

	// TODO:  在此添加额外的初始化

	/////////////////////////////////////////////////////////////////
	if (theApp.a.nPrior) //为普通用户
	{
		GetDlgItem(IDC_Add)->DestroyWindow(); //使该按钮不能使用
		GetDlgItem(IDC_del)->EnableWindow(false); //使该按钮不能使用
		GetDlgItem(IDC_COMBO1)->DestroyWindow(); //使该按钮不能使用	
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE); //使该静态文本不能使用	
	}
	//////////////////////////////////////////////////////////
	LoadFile(!theApp.a.nPrior);


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


//void CAdmin::OnDestroy()
//{
//	CDialogEx::OnDestroy(); 
//}


void CAdmin::SaveData()  //
{
	// TODO: 在此处添加实现代码.
	//MyAdmData a;
	CFile f;
	if (! f.Open(L"MyAdmData.dat", CFile::modeCreate | CFile::modeReadWrite))
	{
		AfxMessageBox(L"保存文件失败！！");
		return;
	}
	int i = 0, nCount = mAdminList.GetItemCount();
	while (i < nCount)
	{
		CString str1,str2;
		str1.Format(L"%d", theApp.a.sNum);
		str2.Format(L"%d", theApp.a.Salary);

		mAdminList.GetItemText(i, 0, theApp.a.sName,_countof(theApp.a.sName));
		//mAdminList.GetItemText(i, 1, (PTSTR)(LPCTSTR)str1,sizeof(str1)); //这种或者下边的都可以
		mAdminList.GetItemText(i, 1, str1.GetBuffer(),sizeof(str1));
		mAdminList.GetItemText(i, 2, theApp.a.sCode,_countof(theApp.a.sCode));
		if (mAdminList.GetItemText(i, 3) == L"普通")
		{
			theApp.a.nPrior = 1;
		}
		else if (mAdminList.GetItemText(i, 3) == L"高级")
		{
			theApp.a.nPrior = 0;
		}
		mAdminList.GetItemText(i, 4, str2.GetBuffer(), sizeof(str2));
		mAdminList.GetItemText(i, 5, theApp.a.m_tm, _countof(theApp.a.m_tm));

		f.Write(&theApp.a, sizeof(theApp.a));  //结构体
		// _countof 只对数组有效

		i++;

	}

	f.Close();
}



void CAdmin::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	if (m_bModifyA)
	{
		int nRet = AfxMessageBox(L"是否将改到保存到文件？", MB_YESNOCANCEL);
		if (nRet == IDYES)
		{
			SaveData();
		}
		else
		{
			EndDialog(0);
		}
	}

	CDialogEx::OnCancel();
	//return;
}

