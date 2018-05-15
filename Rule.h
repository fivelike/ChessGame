#pragma once


// Rule 对话框

class Rule : public CDialogEx
{
	DECLARE_DYNAMIC(Rule)

public:
	Rule(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Rule();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
