// Rule.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChessGame.h"
#include "Rule.h"
#include "afxdialogex.h"


// Rule �Ի���

IMPLEMENT_DYNAMIC(Rule, CDialogEx)

Rule::Rule(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Rule::~Rule()
{
}

void Rule::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Rule, CDialogEx)
END_MESSAGE_MAP()


// Rule ��Ϣ�������
