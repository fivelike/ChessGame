// Rule.cpp : 实现文件
//

#include "stdafx.h"
#include "ChessGame.h"
#include "Rule.h"
#include "afxdialogex.h"


// Rule 对话框

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


// Rule 消息处理程序
