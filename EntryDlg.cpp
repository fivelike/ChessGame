// EntryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChessGame.h"
#include "EntryDlg.h"
#include "afxdialogex.h"
#include <string>
extern CString cur_entry;
using namespace std;

// EntryDlg �Ի���

IMPLEMENT_DYNAMIC(EntryDlg, CDialogEx)

EntryDlg::EntryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

EntryDlg::~EntryDlg()
{
}

void EntryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EntryDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &EntryDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &EntryDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// EntryDlg ��Ϣ�������


void EntryDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strPath, strText = _T("");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("txt���±�(*.txt)|*.txt|ini�ĵ�(*.ini)|*.ini|pem�ĵ�(*.pem)|*.pem||"), AfxGetMainWnd());
	if (IDOK == dlg.DoModal())
	{
		strPath = dlg.GetPathName();
		SetDlgItemText(IDC_EDIT1, strPath);

		string sPath = strPath.GetBuffer(strPath.GetLength() + 1);

		FILE* pFile = nullptr;        //pFile = fopen(sPath.c_str(), "r+t");  
		fopen_s(&pFile, sPath.c_str(), "rb");

		if (pFile)
		{
			fseek(pFile, 0, SEEK_END);
			int nFileLen = ftell(pFile);
			char* buf = new char[nFileLen];

			fseek(pFile, 0, SEEK_SET);
			fread(buf, sizeof(char), nFileLen, pFile);
			fclose(pFile);

			strText.Format(_T("%s"), buf);
			delete[] buf;
			SetDlgItemText(IDC_EDIT2, strText);
		}
	}

}


void EntryDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	GetDlgItem(IDC_EDIT1)->GetWindowText(cur_entry);
	CDialogEx::OnOK();
}


