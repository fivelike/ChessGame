#pragma once


// EntryDlg 对话框

class EntryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EntryDlg)

public:
	EntryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EntryDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
