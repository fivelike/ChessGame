#pragma once


// DoubleCenter �Ի���

class DoubleCenter : public CDialogEx
{
	DECLARE_DYNAMIC(DoubleCenter)

public:
	DoubleCenter(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DoubleCenter();

	CString editor1;
	CString editor2;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOUBLECENTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

	virtual void OnOK();
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
};
