#pragma once


// EntryDlg �Ի���

class EntryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EntryDlg)

public:
	EntryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EntryDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
