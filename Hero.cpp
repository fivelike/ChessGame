// Hero.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChessGame.h"
#include "Hero.h"
#include "afxdialogex.h"


// CHero �Ի���

IMPLEMENT_DYNAMIC(CHero, CDialogEx)

CHero::CHero(CWnd* pParent /*=NULL*/)
	: CDialogEx(325, pParent)
{

}

CHero::~CHero()
{
}

void CHero::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//��ʼ����Ӧ�Ŀؼ���������ʾ
	DDX_Text(pDX, 1011, m_strName[0]);
	DDX_Text(pDX, 1013, m_strName[1]);
	DDX_Text(pDX, 1015, m_strName[2]);
	DDX_Text(pDX, 1012, m_strNum[0]);
	DDX_Text(pDX, 1014, m_strNum[1]);
	DDX_Text(pDX, 1016, m_strNum[2]);
}


BEGIN_MESSAGE_MAP(CHero, CDialogEx)
END_MESSAGE_MAP()


// CHero ��Ϣ�������
