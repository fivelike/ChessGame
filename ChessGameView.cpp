
// ChessGameView.cpp : CChessGameView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ChessGame.h"
#endif

#include "ChessGameDoc.h"
#include "ChessGameView.h"
#include "DoubleCenter.h"
#include "Hero.h"
#include "Managers.h"
#include "Player.h"
#include "Rule.h"
#include "Operation.h"
#include "Author.h"
#include "EntryDlg.h"
#include<time.h>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern Managers manager;
extern Player gameplayer[100];
extern Player buffer[3];
extern int time_line;
extern CString cur_entry;
// CChessGameView

IMPLEMENT_DYNCREATE(CChessGameView, CView)

BEGIN_MESSAGE_MAP(CChessGameView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32771, &CChessGameView::OnClickDouble)
	ON_COMMAND(32776, &CChessGameView::OnClickHero)
	ON_WM_TIMER()
	ON_COMMAND(ID_32773, &CChessGameView::On32773)
	ON_COMMAND(ID_32774, &CChessGameView::On32774)
	ON_COMMAND(ID_32775, &CChessGameView::On32775)
	ON_COMMAND(ID_32777, &CChessGameView::On32777)

	ON_COMMAND(ID_32778, &CChessGameView::On32778)
	ON_COMMAND(ID_32779, &CChessGameView::On32779)
END_MESSAGE_MAP()

// CChessGameView 构造/析构

CChessGameView::CChessGameView()
{
	// TODO: 在此处添加构造代码
	gameplayer[0].name = "玩家1";
	gameplayer[1].name = "玩家2";
	ReadScore();
}

CChessGameView::~CChessGameView()
{
	WriteScore();
}

BOOL CChessGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CChessGameView 绘制

void CChessGameView::OnDraw(CDC* pDC)
{
	CChessGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	static int i = 0;
	//将位图加载到程序中，初始化各个CDC
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


// CChessGameView 诊断

#ifdef _DEBUG
void CChessGameView::AssertValid() const
{
	CView::AssertValid();
}

void CChessGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChessGameDoc* CChessGameView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChessGameDoc)));
	return (CChessGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CChessGameView 消息处理程序


void CChessGameView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//获取当前光标的横纵坐标，同时进行转换
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
			//记录棋手此步步骤；
			WriteEntry();
			if (manager.Game_state > 2)
				GamePlayer();
		}
		
	}
	CView::OnLButtonDown(nFlags, point);
}


void CChessGameView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//获取光标当前所指的点的坐标
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
	//0为黑子，1为白子
	if (type == 0) {
		//还原为实际坐标
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
	//画背景以及棋盘
	pDC->BitBlt(0, 0, 600, 600, &Chessboard, 0, 0, SRCCOPY);
	int nWid = 120;
	CDC *cd = CWnd::GetDC();
	for (int i = 1; i < 5; ++i)
	{
		//横线
		cd->MoveTo(nWid, i * nWid);
		cd->LineTo(4 * nWid, i * nWid);

		//竖线
		cd->MoveTo(i * nWid, nWid);
		cd->LineTo(i * nWid, 4 * nWid);
	}

	//打印当前游戏状态
	PrintState(pDC);

	//画出之前通过DoMsg存储在manager.map里面的棋子的情况
	for (x = 0;x < 4;x++) {
		for (y = 0;y < 4;y++) {
			if (manager.map[x][y] >=0) {
				PrintPart(x,y,manager.map[x][y],pDC);
			}
		}
	}

	//如果游戏正在进行设置计时器
	if ((manager.Game_state == 1 || manager.Game_state == 2)&&time_line!=-1 )
	{
		SetTimer(1, 1000, NULL);
		temp_time = time_line;
	}



}


void CChessGameView::PrintState(CDC* pDC)
{
	CString st;
	//对当前游戏的状态Game_State进行判断，做出对应的响应
	if (manager.Game_state == 1) {
		st.Format("黑子走棋");
	}
	else if (manager.Game_state == 2) {
		st.Format("白子走棋");
	}
	//4黑子胜利，3白子胜利
	else if (manager.Game_state == 3) {
		st = "黑子："+gameplayer[manager.Game_state - 3].name + "胜利";
	}
	else if (manager.Game_state == 4) {
		st ="白子："+ gameplayer[manager.Game_state - 3].name + "胜利";
	}
	else
		st.Format("游戏未开始");

	//打印游戏状态
	pDC->TextOut(250,5,st);
	pDC->TextOut(110, 30, "黑子：");
	pDC->TextOut(150, 30, gameplayer[0].name);
	pDC->TextOut(420, 30, "白子：");
	pDC->TextOut(460, 30, gameplayer[1].name);
	st.ReleaseBuffer();
}


void CChessGameView::GamePlayer() {
	int i;
	//对胜利方进行判断，例如黑方胜利时，winer为0
	int winer = manager.Game_state - 3;//胜利玩家
	int loser = (manager.Game_state - 2) % 2;
	//gameplayer[100]前两个元素用来记录用户当前的输入情况，所以记录从[2]开始
	//当一轮棋下完后，将后来输入的用户名称同所有的gameplay[i].name进行比较
	for (i = 2;i < 100;i++) {
		if (gameplayer[i].name == gameplayer[winer].name) {
			gameplayer[i].num++;
			break;
		}
		else if (gameplayer[i].name == "") //如果名称不存在，则将其名称赋给此时i对应的name，同时num++
		{
			gameplayer[i].name = gameplayer[winer].name;
			gameplayer[i].num++;
			break;
		}
	}
}


void CChessGameView::WriteScore() {
	int i, t;
	//将所有存在的gameplayer[i].num同读取的buffer[i].num进行比较
	for (i = 2;gameplayer[i].name != ""; i++) {
		//在文档中buffer[i].num是按照降序排列的
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

	//用CFile中的Open函数进行打开，如果在指定路径不存在文件，则自动创建文件
	mFile.Open(".\\hero.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
	CArchive ar(&mFile, CArchive::store);//创建一个CArchive ar用于存储工作
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
		for (k = 0;k < 3;k++) //文件不存在，创建后进行初始化
		{
			buffer[k].name = "玩家";
			buffer[k].num = 3 - k;
		}
		WriteScore();
	}
	else
	{
		CArchive ar(&mFile1, CArchive::load);
		for (k = 0;k < 3;k++)
		{
			//把读出来的数据进行加工，去掉存储时加上去的“ ”
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
	// TODO: 在此添加命令处理程序代码
	//游戏开始，如果当前仍在游戏中，弹出对话框确定是否要重新开始，并由k取得用户点击情况
	int k=10;
	if(manager.Game_state==1||manager.Game_state==2)
		k = MessageBox("您的游戏未结束，是否重新开始？", "game", MB_OKCANCEL);
		//当k值不为IDCANCEL，弹出登陆对话框
	if (k != IDCANCEL) {
		DoubleCenter enter;
		enter.editor1.Format("%s", gameplayer[0].name);
		enter.editor2.Format("%s", gameplayer[1].name);
		enter.time.Format("%d", time_line);
		enter.DoModal();
		manager.GameStart();
		cur_entry = "";
		CDC *pDC = GetDC();
		PrintAll(pDC);
		pDC->DeleteDC();

		//为本局棋谱按时间命名，以避免文件名重复
		GetEntryName();
	}


	

}


void CChessGameView::OnClickHero()
{
	// TODO: 在此添加命令处理程序代码
	ReadScore();
	CHero hero;
	for (int i = 0;i < 3;i++)
	{
		hero.m_strName[i] = buffer[i].name;
		hero.m_strNum[i].Format("%d", buffer[i].num);
	}
	hero.DoModal();
}


void CChessGameView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC = GetDC();
	CString st;
	
	st.Format("倒计时：%d 秒", temp_time--);
	pDC->TextOut(270, 550, st);
	if (manager.Game_state > 2) {
		KillTimer(1);
	}
	if (temp_time == -1) {
		KillTimer(1);
		if (manager.Game_state == 1)//黑子超时，白子胜
			manager.Game_state = 4;
		else if (manager.Game_state == 2)
			manager.Game_state = 3;

		if (manager.Game_state > 2)
		{
			PrintState(pDC);
			GamePlayer();
		}
	}
	CView::OnTimer(nIDEvent);
}


void CChessGameView::On32773()
{
	// TODO: 在此添加命令处理程序代码
	Rule rule;
	rule.DoModal();
}


void CChessGameView::On32774()
{
	// TODO: 在此添加命令处理程序代码
	Operation operation;
	operation.DoModal();
}


void CChessGameView::On32775()
{
	// TODO: 在此添加命令处理程序代码
	Author author;
	author.DoModal();
}


void CChessGameView::On32777()
{
	// TODO: 在此添加命令处理程序代码
	EntryDlg entrydlg;
	//entrydlg.DoModal();
	if (entrydlg.DoModal()==IDOK)
	{
		ReadEntry();
	}
}


void CChessGameView::WriteEntry()
{
	CStdioFile file;
	file.Open(".\\entry-" + entryName + ".txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
		CString str;
		for (int x = 0;x < 4;x++)
		{
			for (int y = 0;y < 4;y++) {
				if (manager.map[x][y] == -1) {
					str = "3";
				}
				else {
					str.Format("%d", manager.map[x][y]);
				}
				file.SeekToEnd();
				file.Write(str, str.GetLength());
			}
		}
		file.Close();
	
}


void CChessGameView::GetEntryName()
{
	CTime current_time = CTime::GetCurrentTime();
	entryName = current_time.Format("%Y%m%d%H%M%S");
}


void CChessGameView::ReadEntry()
{
	CStdioFile file;
	file.Open( cur_entry , CFile::modeRead );
	CString s;

	while (file.ReadString(s))
	{
		temp_entry += s;
	}
}




void CChessGameView::Next()
{
	// TODO: 在此添加控件通知处理程序代码
	CDC *pDC = GetDC();
	int k = 0;
	if ((index + 1) >= temp_entry.GetLength() / 16) {
		MessageBox("没有下一步了", "game");
		return;
	}
	index++;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0;y < 4;y++) {
			if (temp_entry.GetAt(index * 16 + k) == '0') {
				manager.map[x][y] = 0;
			}
			else if (temp_entry.GetAt(index * 16 + k) == '1')
			{
				manager.map[x][y] = 1;
			}
			else  if (temp_entry.GetAt(index * 16 + k) == '3')
			{
				manager.map[x][y] = -1;
			}
			k++;
		}
	}
	PrintAll(pDC);
}


void CChessGameView::Pre()
{

	// TODO: 在此添加控件通知处理程序代码
	CDC *pDC = GetDC();
	int k = 0;
	if ((index + 1) ==0 || index==0) {
		MessageBox("没有上一步了", "game");
		return;
	}
	index--;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0;y < 4;y++) {
			if (temp_entry.GetAt(index * 16 + k) == '0') {
				manager.map[x][y] = 0;
			}
			else if (temp_entry.GetAt(index * 16 + k) == '1')
			{
				manager.map[x][y] = 1;
			}
			else  if (temp_entry.GetAt(index * 16 + k) == '3')
			{
				manager.map[x][y] = -1;
			}
			k++;
		}
	}

	PrintAll(pDC);
}

//浏览棋谱操作，上一步
void CChessGameView::On32778()
{
	// TODO: 在此添加命令处理程序代码
	if (cur_entry != "") {
			Pre();
	}
	else
		MessageBox("此按钮仅在载入棋谱后可使用！", "game");
}

//下一步
void CChessGameView::On32779()
{
	// TODO: 在此添加命令处理程序代码
	if (cur_entry != "") {
		Next();
	}
	else
	{
		MessageBox("此按钮仅在载入棋谱后可使用！", "game");

	}
}
