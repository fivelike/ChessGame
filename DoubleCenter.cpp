// DoubleCenter.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChessGame.h"
#include "DoubleCenter.h"
#include "afxdialogex.h"
#include "Player.h"

extern Player gameplayer[100];
extern int time_line;

// DoubleCenter �Ի���

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

	//��ȷ�϶Ի�������ݷ����ı�ʱ���ֱ�Cstring editor12��������ʾ��IDC_TEXTBOX12��
	DDX_Text(pDX, IDC_EDIT1, editor1);
	DDX_Text(pDX, IDC_EDIT2, editor2);
	DDX_Text(pDX, IDC_EDIT3, time);
}


BEGIN_MESSAGE_MAP(DoubleCenter, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &DoubleCenter::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &DoubleCenter::OnEnChangeEdit2)
END_MESSAGE_MAP()


// DoubleCenter ��Ϣ�������



void DoubleCenter::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void DoubleCenter::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
