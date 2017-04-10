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

void  Enemy::Control()
{
	


	float spd = 1.0f;
	float jumpPower = -12.0f;

	//カウントで簡易操作
	actCnt++;

	if (serectMap == 2)
	{
		spd = 2.0f;
	}


	int index_x = (int)GetPosX() / CHIP_SIZE;//マップに対するプレイヤーのX座標

	int index_y = ((int)GetPosY() + (int)GetGrpH()) / CHIP_SIZE;//マップに対するプレイヤーのY座標


	if (GetState() != 0)
	{
		if (actCnt <= 90)
		{
			SetDir(RIGHT);

			int* mapdata = &g_map[index_y - 1][index_x + 1];//プレイヤーの右側のマップチップ
			if (*mapdata == 0 || *mapdata == 2 || *mapdata == 4 || *mapdata == 6 || *mapdata == 8 || *mapdata == 13)//移動可能マップチップ
			{
				SetSpdX(spd);
			}
		}
		else
		{
			SetDir(LEFT);
			int* mapdata = &g_map[index_y - 1][index_x];//プレイヤーの左のマップチップ判定
			if (*mapdata == 0 || *mapdata == 2 || *mapdata == 4 || *mapdata == 6 || *mapdata == 8 || *mapdata == 13)//移動可能マップチップ
			{

				SetSpdX(-spd);
			}
		}

		if (actCnt <= 90)
		{
			SetSpdX(spd);
		}
		else
		{
			SetSpdX(-spd);
		}

		if (actCnt >= 190)
		{
			actCnt = 0;
		}

		//座標変更処理/////////////////////////////
		SetPosX(GetPosX() + GetSpdX());
		SetPosY(GetPosY() + GetSpdY() + GetJumpPower());


		//移動してない場合両手をもとに戻す
		if (GetSpdX() == 0)
		{
			SetGrpX(32);
		}

		//状態による変更
		switch (GetState())
		{
		case 1:
			break;
		default:
			break;

		}
	}




}

void Enemy::UpData()
{

	Control();
}


void Enemy::Render()
{
	RECT rect;			// 絵の左上の座標と右下の座標編集用


						//方向検出
	switch (GetDir())
	{
	case LEFT:
		SetGrpY(0);
		break;
	case RIGHT:
		SetGrpY(32);
		break;
	}



	//左右に移動している場合
	if (GetSpdX() != 0)
	{
		//移動してる場合歩く
		switch (m_cnt / 15 % 4)
		{
		case 0:
			SetGrpX(0);
			break;
		case 1:
		case 3:
			SetGrpX(32);
			break;
		case 2:
			SetGrpX(64);
			break;
		}
	}

	//上下に動いているなら（ジャンプを除く）
	if (GetClimb() == TRUE)
	{
		SetGrpY(96);

		//移動してる場合歩く
		switch (m_cnt / 15 % 4)
		{
		case 0:
			SetGrpX(0);
			break;
		case 1:
		case 3:
			SetGrpX(32);
			break;
		case 2:
			SetGrpX(64);
			break;
		}
	}

	if (GetState() == 1)
	{
		rect =
		{
			GetGrpX(),
			GetGrpY(),
			GetGrpX() + GetGrpW() ,
			GetGrpY() + GetGrpH()
		};

		float sx = GetPosX() - g_ScrollMap_x;
		float sy = GetPosY() - g_ScrollMap_y;


		g_spriteBatch->Draw(g_Spider->m_pTexture,
			Vector2(sx, sy),
			&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);

	}


}


void Enemy::SetClimb(int s)
{
	climb = s;
}
int Enemy::GetClimb()
{
	return climb;
}

void Enemy::SetHold(int s)
{
	hold = s;
}
int Enemy::GetHold()
{

	return hold;
}



void Enemy::SetDir(int s)
{
	dir = s;
}
int Enemy::GetDir()
{
	return dir;
}