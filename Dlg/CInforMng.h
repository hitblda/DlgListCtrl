#pragma once


// CInforMng 对话框

class CInforMng : public CDialogEx
{
	DECLARE_DYNAMIC(CInforMng)

public:
	CInforMng(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CInforMng();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Infor };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bModify;
	afx_msg void OnClkInforInpur();
	afx_msg void OnAdminClk();
	afx_msg void OnBnClickedGetinfor();

};
