// Operation.cpp : 实现文件
//

#include "stdafx.h"
#include "ChessGame.h"
#include "Operation.h"
#include "afxdialogex.h"


// Operation 对话框

IMPLEMENT_DYNAMIC(Operation, CDialogEx)

Operation::Operation(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Operation::~Operation()
{
}

void Operation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Operation, CDialogEx)
END_MESSAGE_MAP()


// Operation 消息处理程序
