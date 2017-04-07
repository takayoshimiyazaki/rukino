//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   ObjectBase.cpp
//!
//! @brief  オブジェクトののソースファイル
//!
//! @date   2017/4/5
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "ObjectBase.h"
#include<iostream>

//using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;



ObjectBase::ObjectBase()
{
}

void ObjectBase::SetHandle(Texture* h)
{
	handle = h;

}

Texture* ObjectBase::GetHandle()
{
	return handle;

}

void ObjectBase::SetPosX(float x)
{
	pos_x = x;
}

float ObjectBase::GetPosX()
{
	return pos_x;
}
void ObjectBase::SetPosY(float y)
{
	pos_y = y;

}
float ObjectBase::GetPosY()
{
	return pos_y;
}


void ObjectBase::SetGrpX(int x)
{
	grp_x = x;
}
int ObjectBase::GetGrpX()
{
	return grp_x;
}


void ObjectBase::SetGrpY(int y)
{
	grp_y = y;
}
int ObjectBase::GetGrpY()
{
	return grp_y;
}


void ObjectBase::SetGrpW(int w)
{
	grp_w = w;

}
int ObjectBase::GetGrpW()
{

	return grp_w;
}

void ObjectBase::SetGrpH(int h)
{
	grp_h = h;
}
int ObjectBase::GetGrpH()
{
	return grp_h;
}


void ObjectBase::SetSpdX(float x)
{
	spd_x = x;
}
float ObjectBase::GetSpdX()
{
	return spd_x;
}

void ObjectBase::SetSpdY(float y)
{
	spd_y = y;
}
float ObjectBase::GetSpdY()
{
	return spd_y;
}

void ObjectBase::SetState(int s)
{
	state = s;
}
int ObjectBase::GetState()
{

	return state;
}


void  ObjectBase::SetJumpPower(float y)
{
	jumpPower = y;
}
float  ObjectBase::GetJumpPower()
{
	return jumpPower;
}


void  ObjectBase::SetJump(int s)
{
	jump = s;
}
int  ObjectBase::GetJump()
{
	return jump;
}

void ObjectBase::SetClimb(int s)
{
	climb = s;
}
int ObjectBase::GetClimb()
{
	return climb;
}

void ObjectBase::SetHold(int s)
{
	hold = s;
}
int ObjectBase::GetHold()
{

	return hold;
}


void ObjectBase::UpData()
{
	GetPosX();
	GetPosY();
	GetGrpX();
	GetGrpY();
	GetGrpW();
	GetGrpH();
	GetSpdX();
	GetSpdY();
	GetState();
	GetJump();
	GetClimb();
	GetHold();
}

void ObjectBase::Render()
{


}

ObjectBase::~ObjectBase()
{


}

