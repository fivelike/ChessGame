
// ChessGame.h : ChessGame Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CChessGameApp:
// �йش����ʵ�֣������ ChessGame.cpp
//

class CChessGameApp : public CWinApp
{
public:
	CChessGameApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CChessGameApp theApp;
