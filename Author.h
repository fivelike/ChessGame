#pragma once


// Author �Ի���

class Author : public CDialogEx
{
	DECLARE_DYNAMIC(Author)

public:
	Author(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Author();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
