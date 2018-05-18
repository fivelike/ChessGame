#include "stdafx.h"
#include "Managers.h"


Managers::Managers()
{
	int x, y;
	for (x = 0;x < 4;x++) {
		for (y = 0;y < 4;y++) {
			if (y == 0) map[x][y] = 0;
			else if (y == 3) map[x][y] = 1;
			else map[x][y] = -1;
		}
	}
	choosed = false;
}


Managers::~Managers()
{
}


// �ı���Ϸ��Gameinfo
void Managers::GameType(int t)
{

}


// ��ʼ����ʼ
void Managers::GameStart()
{
	int x, y;
	for (x = 0;x < 4;x++) {
		for (y = 0;y < 4;y++) {
			if (y == 0) map[x][y] = 0;
			else if (y == 3) map[x][y] = 1;
			else map[x][y] = -1;
			}
		}
	Game_state = 1;
}

//action=1��Ӧ������
bool Managers::DoMsg(int x, int y, int action)
{
	if (Game_state > 2 || Game_state < 1)
		return false;
	if (action == 1) {
		//�������
		if (Game_state == 1&& Choose(x,y,0)) {
			choosed = true;
			return false;
		}
		//�������
		if (Game_state == 2 && Choose(x, y, 1)) {
			choosed = true;
			return false;
		}
		//�����λ��
		if ( (map[x][y]==-1)&& choosed&&canMove(ChooseChess.x, ChooseChess.y, x, y)) {
			//�ƶ�����
			MoveChess(ChooseChess.x, ChooseChess.y, x, y);
			choosed = false;
			return true;
		}
	}
	return false;
}

// ѡ��λ��
bool Managers::Choose(int x, int y, int type)
{
	if (map[x][y] == type) {
		ChooseChess.x = x;
		ChooseChess.y = y;
		ChooseChess.type = type;
		return true;
	}
	else
		return false;
}

bool Managers::MoveChess(int x1, int y1, int x2, int y2) {
	map[x2][y2] = map[x1][y1];
	map[x1][y1] = -1;
	EatChess();
	Update();
	return true;
}

bool Managers::canMove(int x1, int y1, int x2, int y2) {
	//����
	if (  ( (x2 == (x1 - 1)) || (x2 == (x1 + 1))  ) &&(y2 == y1)  ) {
		return true;
	}
	else if (((y2 == (y1 - 1)) || (y2 == (y1 + 1))) && (x2 == x1)) {
		return true;
	}
	else
		return false;
}

bool Managers::EatChess() {
	int x, y;
	for (x = 0;x < 4;x++) {
		nearChess(map[x][0], map[x][1], map[x][2], map[x][3]);
		nearChess(map[0][x], map[1][x], map[2][x], map[3][x]);
	}
	return true;
}

bool Managers::Update() {
	int k=0; //�ݴ���º����Ϸ״̬
	k = CheckState();
	if (k == 0) {
		Game_state = Game_state % 2 + 1;
	}
	else if (k < 0) {
		//�׷�Ӯ
		Game_state = 3;
	}
	else if (k > 0) {
		//�ڷ�Ӯ
		Game_state = 4;
	}
	return true;
}

int Managers::CheckState() {
	int x, y;
	int bnum = 0;
	int wnum = 0;
	for (x = 0;x < 4;x++) {
		for (y = 0;y < 4;y++) {
			if (map[x][y] == 1) bnum++;
			if (map[x][y] == 0) wnum++;
		}
	}
	if (bnum < 2) return -1;
	if (wnum < 2) return 1;
	return 0;
}


void Managers::nearChess(int &x1, int &x2, int &x3, int &x4)
{
	int other = Game_state == 1 ? Game_state : Game_state - 2;
	int cur = Game_state - 1;
	if (x1 == other&&x2 == cur&&x3 == cur&&x4 == -1) x1 = -1;
	if (x1 == -1 && x2 == other&&x3 == cur&&x4 == cur) x2 = -1;
	if (x1 == cur && x2 == cur&&x3 == other&&x4 == -1) x3 = -1;
	if (x1 == -1 && x2 == cur&&x3 == cur&&x4 == other) x4 = -1;
}


Managers manager;