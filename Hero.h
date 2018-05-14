#pragma once


// CHero 对话框

class CHero : public CDialogEx
{
	DECLARE_DYNAMIC(CHero)

public:
	CHero(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHero();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HERO };
#endif
	CString m_strName[3];
	CString m_strNum[3];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
