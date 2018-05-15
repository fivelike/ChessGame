// DoubleCenter.cpp : 实现文件
//

#include "stdafx.h"
#include "ChessGame.h"
#include "DoubleCenter.h"
#include "afxdialogex.h"
#include "Player.h"

extern Player gameplayer[100];
extern int time_line;

// DoubleCenter 对话框

IMPLEMENT_DYNAMIC(DoubleCenter, CDialogEx)

DoubleCenter::DoubleCenter(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DOUBLECENTER, pParent)
{

}

DoubleCenter::~DoubleCenter()
{
}

void DoubleCenter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//当确认对话框的数据发生改变时，分别将Cstring editor12的内容显示到IDC_TEXTBOX12中
	DDX_Text(pDX, IDC_EDIT1, editor1);
	DDX_Text(pDX, IDC_EDIT2, editor2);
	DDX_Text(pDX, IDC_EDIT3, time);
}


BEGIN_MESSAGE_MAP(DoubleCenter, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &DoubleCenter::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &DoubleCenter::OnEnChangeEdit2)
END_MESSAGE_MAP()


// DoubleCenter 消息处理程序



void DoubleCenter::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	char ch1[20];
	char ch2[20];
	CString str;

	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1, 20);
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch2, 20);
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);

	gameplayer[0].name.Format("%s", ch1);
	gameplayer[1].name.Format("%s", ch2);
	if (_ttoi(str) >0)
	{
		time_line = _ttoi(str);
	}
	CDialogEx::OnOK();
}


void DoubleCenter::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void DoubleCenter::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
