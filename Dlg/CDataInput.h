#pragma once


// CDataInput 对话框

class CDataInput : public CDialogEx
{
	DECLARE_DYNAMIC(CDataInput)

public:
	CDataInput(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDataInput();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Entrance };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
