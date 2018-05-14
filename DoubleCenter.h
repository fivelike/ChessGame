#pragma once


// DoubleCenter 对话框

class DoubleCenter : public CDialogEx
{
	DECLARE_DYNAMIC(DoubleCenter)

public:
	DoubleCenter(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DoubleCenter();

	CString editor1;
	CString editor2;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOUBLECENTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	virtual void OnOK();
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
};
