//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   player.cpp
//!
//! @brief  プレイヤー関連のソースファイル
//!
//! @date   2017/4/5
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#include"GameMain.h"
#include "Enemy.h"
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
//#include "..ADX2Le.h"
//#include "..\CueSheet_0.h"



using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;



Enemy::Enemy()
{
	SetHandle(g_PlayerImage);
	SetGrpX(0);
	SetGrpY(0);
	SetGrpW(32);
	SetGrpH(32);
	SetPosX(32);
	SetPosY(32);
	SetSpdX(0.0f);
	SetSpdY(0.0f);
	SetState(1);
	SetJump(FALSE);
	SetClimb(FALSE);
	SetHold(FALSE);
}


Enemy::~Enemy()
{
}


void Enemy::SetHandle(Texture* h)
{
	handle = h;

}

Texture* Enemy::GetHandle()
{
	return handle;

}


void Enemy::SetPosX(float x)
{
	pos_x = x;
}

float Enemy::GetPosX()
{
	return pos_x;
}
void Enemy::SetPosY(float y)
{
	pos_y = y;

}
float Enemy::GetPosY()
{
	return pos_y;
}


void Enemy::SetGrpX(int x)
{
	grp_x = x;
}
int Enemy::GetGrpX()
{
	return grp_x;
}


void Enemy::SetGrpY(int y)
{
	grp_y = y;
}
int Enemy::GetGrpY()
{
	return grp_y;
}


void Enemy::SetGrpW(int w)
{
	grp_w = w;

}
int Enemy::GetGrpW()
{

	return grp_w;
}

void Enemy::SetGrpH(int h)
{
	grp_h = h;
}
int Enemy::GetGrpH()
{
	return grp_h;
}


void Enemy::SetSpdX(float x)
{
	spd_x = x;
}
float Enemy::GetSpdX()
{
	return spd_x;
}

void Enemy::SetSpdY(float y)
{
	spd_y = y;
}
float Enemy::GetSpdY()
{
	return spd_y;
}

void Enemy::SetState(int s)
{
	state = s;
}
int Enemy::GetState()
{

	return state;
}


void  Enemy::SetJumpPower(float y)
{
	jumpPower = y;
}
float  Enemy::GetJumpPower()
{
	return jumpPower;
}


void  Enemy::SetJump(int s)
{
	jump = s;
}
int  Enemy::GetJump()
{
	return jump;
}


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
