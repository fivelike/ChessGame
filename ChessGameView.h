
// ChessGameView.h : CChessGameView ��Ľӿ�
//

#pragma once

class CChessGameView : public CView
{
protected: // �������л�����
	CChessGameView();
	DECLARE_DYNCREATE(CChessGameView)

// ����
public:
	CChessGameDoc* GetDocument() const;

// ����
public:
	CDC Chessboard;
	CDC Blackchess;
	CDC Whitechess;
	CBitmap m_chessboard;
	CBitmap m_blackchess;
	CBitmap m_whitechess;
	CFile mFile;
	CString entryName;
	CString temp_entry;
	CButton next_button,pre_button;
	int temp_time;
	int index=-1;



// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CChessGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void PrintPart(int mx, int my, int type, CDC* pDC);
	void PrintAll(CDC* pDC);
	void PrintState(CDC* pDC);
	void GamePlayer();
	void WriteScore();
	void ReadScore();
	afx_msg void OnClickDouble();
	afx_msg void OnClickHero();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void On32777();
	void WriteEntry();
	void GetEntryName();
	void ReadEntry();
	void Next();
	void Pre();
	afx_msg void On32778();
	afx_msg void On32779();
};

#ifndef _DEBUG  // ChessGameView.cpp �еĵ��԰汾
inline CChessGameDoc* CChessGameView::GetDocument() const
   { return reinterpret_cast<CChessGameDoc*>(m_pDocument); }
#endif

