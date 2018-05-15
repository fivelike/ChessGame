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


Player gameplayer[100]; //定义为全局对象，由于可能存在有多个用户，所以定义100个对象
Player buffer[3];
int time_line=-1;