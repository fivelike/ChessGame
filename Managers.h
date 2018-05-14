#pragma once
#include "Chess.h"

class Managers
{
public:
	Managers();
	~Managers();
	
	// 改变游戏的Gameinfo
	void GameType(int t);
	
	//检查是否有胜利或失败，为0什么也不发生，负数白色赢，正数黑色赢
	int CheckState();

	// 初始化开始
	void GameStart();

	int map[4][4];

	/*
	1，游戏中，Player1黑子走棋
	2，游戏中，Player2白子走棋
	3，游戏结束，白子赢
	4，游戏结束，黑子赢
	5，游戏结束，平局
	other number，未开始
	*/
	int Game_state;

	//存储选中棋子的信息
	Chess ChooseChess;

	bool DoMsg(int x, int y, int action);

private:
	// 检查棋子黑白色
	bool Choose(int x, int y, int type);
	bool choosed;
	bool MoveChess(int x1, int y1, int x2, int y2);
	bool canMove(int x1, int y1, int x2, int y2);
	bool Update();
	bool EatChess();
};

