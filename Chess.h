#pragma once
class Chess
{
public:
	Chess();
	virtual ~Chess();
	int x, y;//棋子在棋盘中的坐标
	int type;//1为黑棋，0为白棋
};

