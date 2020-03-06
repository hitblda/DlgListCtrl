#pragma once


// CLogin 对话框

class CLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLogin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Login };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnOK();
	bool Createfile(MyAdmData& a);
	bool LoginJudge(const CString& szNum, const CString& szName, const CString& szCode);
	bool CkeckPasswd;

};
