// Author.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChessGame.h"
#include "Author.h"
#include "afxdialogex.h"


// Author �Ի���

IMPLEMENT_DYNAMIC(Author, CDialogEx)

Author::Author(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

Author::~Author()
{
}

void Author::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Author, CDialogEx)
END_MESSAGE_MAP()


// Author ��Ϣ�������
