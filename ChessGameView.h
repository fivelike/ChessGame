
// ChessGameView.h : CChessGameView 类的接口
//

#pragma once

class CChessGameView : public CView
{
protected: // 仅从序列化创建
	CChessGameView();
	DECLARE_DYNCREATE(CChessGameView)

// 特性
public:
	CChessGameDoc* GetDocument() const;

// 操作
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



// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CChessGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // ChessGameView.cpp 中的调试版本
inline CChessGameDoc* CChessGameView::GetDocument() const
   { return reinterpret_cast<CChessGameDoc*>(m_pDocument); }
#endif

