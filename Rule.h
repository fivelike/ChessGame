#pragma once


// Rule �Ի���

class Rule : public CDialogEx
{
	DECLARE_DYNAMIC(Rule)

public:
	Rule(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Rule();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
