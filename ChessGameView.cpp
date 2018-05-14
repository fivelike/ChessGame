
// ChessGameView.cpp : CChessGameView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ChessGame.h"
#endif

#include "ChessGameDoc.h"
#include "ChessGameView.h"

#include "DoubleCenter.h"
#include "Hero.h"
#include "Managers.h"
#include "Player.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern Managers manager;
extern Player gameplayer[100];
extern Player buffer[3];
// CChessGameView

IMPLEMENT_DYNCREATE(CChessGameView, CView)

BEGIN_MESSAGE_MAP(CChessGameView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32771, &CChessGameView::OnClickDouble)
	ON_COMMAND(32776, &CChessGameView::OnClickHero)
END_MESSAGE_MAP()

// CChessGameView ����/����

CChessGameView::CChessGameView()
{
	// TODO: �ڴ˴���ӹ������
	gameplayer[0].name = "���1";
	gameplayer[1].name = "���2";
	ReadScore();
}

CChessGameView::~CChessGameView()
{
	WriteScore();
}

BOOL CChessGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CChessGameView ����

void CChessGameView::OnDraw(CDC* pDC)
{
	CChessGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	static int i = 0;
	//��λͼ���ص������У���ʼ������CDC
	if (i == 0) {
		m_chessboard.LoadBitmap(310);
		Chessboard.CreateCompatibleDC(pDC);
		Chessboard.SelectObject(m_chessboard);

		m_blackchess.LoadBitmap(320);
		Blackchess.CreateCompatibleDC(pDC);
		Blackchess.SelectObject(m_blackchess);

		m_whitechess.LoadBitmap(321);
		Whitechess.CreateCompatibleDC(pDC);
		Whitechess.SelectObject(m_whitechess);
		i = 1;
	}


	PrintAll(pDC);

}


// CChessGameView ���

#ifdef _DEBUG
void CChessGameView::AssertValid() const
{
	CView::AssertValid();
}

void CChessGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChessGameDoc* CChessGameView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChessGameDoc)));
	return (CChessGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CChessGameView ��Ϣ�������


void CChessGameView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//��ȡ��ǰ���ĺ������꣬ͬʱ����ת��
	int mx = (point.x-60)/120;
	int my = (point.y -60) / 120;

	if (mx >= 0 && mx <4 && my >= 0 && my <= 4) {
		CDC *pDC = GetDC();

		//CString st;
		//st.Format(("(%d,%d)"), mx, my);
		//pDC->TextOut(500, 500, st);

		if (manager.DoMsg(mx, my, 1)) {
			//PrintPart(mx, my, 0, pDC);
			PrintAll(pDC);

			if (manager.Game_state > 2)
				GamePlayer();
		}
		
	}
	CView::OnLButtonDown(nFlags, point);
}


void CChessGameView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//��ȡ��굱ǰ��ָ�ĵ������
	int x = point.x;
	int y = point.y;
	CString st;
	st.Format(("(%d,%d)"), x, y);
	CDC *pDC = GetDC();
	pDC->TextOut(50, 50, st);
	ReleaseDC(pDC);
	SetCursor(LoadCursor(NULL, IDC_CROSS));
	CView::OnMouseMove(nFlags, point);
}


void CChessGameView::PrintPart(int mx, int my, int type, CDC* pDC)
{
	//0Ϊ���ӣ�1Ϊ����
	if (type == 0) {
		//��ԭΪʵ������
		pDC->BitBlt(120 + 120 * mx - 45, 120 + 120 * my - 45, 90, 90, &Blackchess, 0, 0, SRCCOPY);
	}
	else if (type == 1) {
		pDC->BitBlt(120 + 120 * mx - 45, 120 + 120 * my - 45, 90, 90, &Whitechess, 0, 0, SRCCOPY);
	}
}


void CChessGameView::PrintAll(CDC* pDC)
{
	int x;
	int y;
	//�������Լ�����
	pDC->BitBlt(0, 0, 600, 600, &Chessboard, 0, 0, SRCCOPY);
	int nWid = 120;
	CDC *cd = CWnd::GetDC();
	for (int i = 1; i < 5; ++i)
	{
		//����
		cd->MoveTo(nWid, i * nWid);
		cd->LineTo(4 * nWid, i * nWid);

		//����
		cd->MoveTo(i * nWid, nWid);
		cd->LineTo(i * nWid, 4 * nWid);
	}

	//��ӡ��ǰ��Ϸ״̬
	PrintState(pDC);

	//����֮ǰͨ��DoMsg�洢��manager.map��������ӵ����
	for (x = 0;x < 4;x++) {
		for (y = 0;y < 4;y++) {
			if (manager.map[x][y] >=0) {
				PrintPart(x,y,manager.map[x][y],pDC);
			}
		}
	}
}


void CChessGameView::PrintState(CDC* pDC)
{
	CString st;
	//�Ե�ǰ��Ϸ��״̬Game_State�����жϣ�������Ӧ����Ӧ
	if (manager.Game_state == 1) {
		st.Format("��������");
	}
	else if (manager.Game_state == 2) {
		st.Format("��������");
	}
	//3����ʤ����4����ʤ��
	else if (manager.Game_state == 3) {
		st = "���ӣ�"+gameplayer[manager.Game_state - 3].name + "ʤ��";
	}
	else if (manager.Game_state == 4) {
		st ="���ӣ�"+ gameplayer[manager.Game_state - 3].name + "ʤ��";
	}
	else
		st.Format("��Ϸδ��ʼ");

	//��ӡ��Ϸ״̬
	pDC->TextOut(250,5,st);
	pDC->TextOut(110, 30, "���ӣ�");
	pDC->TextOut(150, 30, gameplayer[0].name);
	pDC->TextOut(420, 30, "���ӣ�");
	pDC->TextOut(460, 30, gameplayer[1].name);
	st.ReleaseBuffer();
}


void CChessGameView::GamePlayer() {
	int i;
	//��ʤ���������жϣ�����ڷ�ʤ��ʱ��winerΪ0
	int winer = manager.Game_state - 3;//ʤ�����
	int loser = (manager.Game_state - 2) % 2;
	//gameplayer[100]ǰ����Ԫ��������¼�û���ǰ��������������Լ�¼��[2]��ʼ
	//��һ��������󣬽�����������û�����ͬ���е�gameplay[i].name���бȽ�
	for (i = 2;i < 100;i++) {
		if (gameplayer[i].name == gameplayer[winer].name) {
			gameplayer[i].num++;
			break;
		}
		else if (gameplayer[i].name == "") //������Ʋ����ڣ��������Ƹ�����ʱi��Ӧ��name��ͬʱnum++
		{
			gameplayer[i].name = gameplayer[winer].name;
			gameplayer[i].num++;
			break;
		}
	}
}


void CChessGameView::WriteScore() {
	int i, t;
	//�����д��ڵ�gameplayer[i].numͬ��ȡ��buffer[i].num���бȽ�
	for (i = 2;gameplayer[i].name != ""; i++) {
		//���ĵ���buffer[i].num�ǰ��ս������е�
		if (gameplayer[i].num > buffer[1].num)
		{
			buffer[2] = buffer[1];
			if (gameplayer[i].num > buffer[0].num)
			{
				buffer[1] = buffer[0];
				buffer[0].num = gameplayer[i].num;
				buffer[0].name = gameplayer[i].name;
			}
			else {
				buffer[1].num = gameplayer[i].num;
				buffer[1].name = gameplayer[i].name;
			}
		}
		else if (gameplayer[i].num > buffer[2].num&&gameplayer[i].num < buffer[1].num)
		{
			buffer[2].num = gameplayer[i].num;
			buffer[2].name = gameplayer[i].name;
		}
	}

	//��CFile�е�Open�������д򿪣������ָ��·���������ļ������Զ������ļ�
	mFile.Open(".\\hero.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
	CArchive ar(&mFile, CArchive::store);//����һ��CArchive ar���ڴ洢����
	for (i = 0;i < 3;i++) {
		if ((t = buffer[i].name.GetLength() <= 20))
		{
			for (;t <= 20;t++)
				buffer[i].name = buffer[i].name + " ";
		}
		CString st;
		st.Format("%s%d", buffer[i].name, buffer[i].num);
		ar << st;
	}
	ar.Close();
	mFile.Close();
}

void CChessGameView::ReadScore() {
	int k;
	CFile mFile1;
	CString temp;
	if (mFile1.Open(".\\hero.txt", CFile::modeRead) == 0)
	{
		for (k = 0;k < 3;k++) //�ļ������ڣ���������г�ʼ��
		{
			buffer[k].name = "���";
			buffer[k].num = 3 - k;
		}
		WriteScore();
	}
	else
	{
		CArchive ar(&mFile1, CArchive::load);
		for (k = 0;k < 3;k++)
		{
			//�Ѷ����������ݽ��мӹ���ȥ���洢ʱ����ȥ�ġ� ��
			ar >> temp;
			buffer[k].name = temp.Left(20);
			temp.Delete(0, 20);
			buffer[k].num = atoi(temp.GetBuffer(temp.GetLength()));  //num-->int
		}
		ar.Close();
		mFile1.Close();
	}
}
void CChessGameView::OnClickDouble()
{
	// TODO: �ڴ���������������
	//��Ϸ��ʼ�������ǰ������Ϸ�У������Ի���ȷ���Ƿ�Ҫ���¿�ʼ������kȡ���û�������
	int k=10;
	if(manager.Game_state==1||manager.Game_state==2)
		k = MessageBox("������Ϸδ�������Ƿ����¿�ʼ��", "������", MB_OKCANCEL);
		//��kֵ��ΪIDCANCEL��������½�Ի���
	if (k != IDCANCEL) {
		DoubleCenter enter;
		enter.editor1.Format("%s", gameplayer[0].name);
		enter.editor2.Format("%s", gameplayer[1].name);
		enter.DoModal();
		manager.GameStart();
		CDC *pDC = GetDC();
		PrintAll(pDC);
		pDC->DeleteDC();
	}


	

}


void CChessGameView::OnClickHero()
{
	// TODO: �ڴ���������������
	ReadScore();
	CHero hero;
	for (int i = 0;i < 3;i++)
	{
		hero.m_strName[i] = buffer[i].name;
		hero.m_strNum[i].Format("%d", buffer[i].num);
	}
	hero.DoModal();
}
