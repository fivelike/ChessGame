#pragma once
#include "Chess.h"

class Managers
{
public:
	Managers();
	~Managers();
	
	// �ı���Ϸ��Gameinfo
	void GameType(int t);
	
	//����Ƿ���ʤ����ʧ�ܣ�Ϊ0ʲôҲ��������������ɫӮ��������ɫӮ
	int CheckState();

	// ��ʼ����ʼ
	void GameStart();

	int map[4][4];

	/*
	1����Ϸ�У�Player1��������
	2����Ϸ�У�Player2��������
	3����Ϸ����������Ӯ
	4����Ϸ����������Ӯ
	5����Ϸ������ƽ��
	other number��δ��ʼ
	*/
	int Game_state;

	//�洢ѡ�����ӵ���Ϣ
	Chess ChooseChess;

	bool DoMsg(int x, int y, int action);

private:
	// ������Ӻڰ�ɫ
	bool Choose(int x, int y, int type);
	bool choosed;
	bool MoveChess(int x1, int y1, int x2, int y2);
	bool canMove(int x1, int y1, int x2, int y2);
	bool Update();
	bool EatChess();
};

