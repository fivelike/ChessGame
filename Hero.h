#pragma once


// CHero �Ի���

class CHero : public CDialogEx
{
	DECLARE_DYNAMIC(CHero)

public:
	CHero(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHero();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HERO };
#endif
	CString m_strName[3];
	CString m_strNum[3];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
