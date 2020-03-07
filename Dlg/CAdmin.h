#pragma once


// CAdmin 对话框



class CAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(CAdmin)

public:
	bool m_bModifyA;
	CAdmin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAdmin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Admin };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickeddel();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedModify();
	virtual BOOL OnInitDialog();
	afx_msg BOOL Check(LPCTSTR mStr);

	//CListCtrl* pList;
	CListCtrl  mAdminList;

	CComboBox m_cbComBox;
	void SaveData();
	void LoadFile(bool prior);
	virtual void OnCancel();
};
