﻿#pragma once


// CAdmin 对话框
//struct MyAdmData
//{
//	TCHAR sName[16];
//	TCHAR sNum[6];
//	TCHAR sCode[16];
//	int nPrior;
//	TCHAR m_tm[30];
//	int Salary;
//};


class CAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(CAdmin)

public:
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
	afx_msg void OnDestroy();
	CListCtrl* pList;

	CComboBox m_cbComBox;
	void SaveData();
	void LoadFile();
	BOOL m_bModify;
};
