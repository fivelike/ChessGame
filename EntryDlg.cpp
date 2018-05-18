// EntryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ChessGame.h"
#include "EntryDlg.h"
#include "afxdialogex.h"
#include <string>
extern CString cur_entry;
using namespace std;

// EntryDlg 对话框

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


// EntryDlg 消息处理程序


void EntryDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPath, strText = _T("");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("txt记事本(*.txt)|*.txt|ini文档(*.ini)|*.ini|pem文档(*.pem)|*.pem||"), AfxGetMainWnd());
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
	// TODO: 在此添加控件通知处理程序代码

	GetDlgItem(IDC_EDIT1)->GetWindowText(cur_entry);
	CDialogEx::OnOK();
}


