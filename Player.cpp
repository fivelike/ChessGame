#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	name = "";
	num = 0;
}


Player::~Player()
{
}


Player gameplayer[100]; //����Ϊȫ�ֶ������ڿ��ܴ����ж���û������Զ���100������
Player buffer[3];
int time_line=-1;