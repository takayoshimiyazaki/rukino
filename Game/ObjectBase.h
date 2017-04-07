//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   ObjectBase.h
//!
//! @brief  オブジェクトのヘッダファイル
//!
//! @date   2017/4/5
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "../DirectXTK.h"
#include "../Texture.h"

class ObjectBase
{
public:
	ObjectBase();
	~ObjectBase();


	//情報のセット及び取得の仮想関数

	virtual void UpData() = 0;
	virtual void Render() = 0;

	virtual void SetHandle(Texture* h) = 0;
	virtual Texture* GetHandle() = 0;
	virtual void SetPosX(float x) = 0;
	virtual float GetPosX() = 0;

	virtual void SetPosY(float y) = 0;
	virtual float GetPosY() = 0;

	virtual void SetGrpX(int x) = 0;
	virtual int GetGrpX() = 0;

	virtual void SetGrpY(int y) = 0;
	virtual int GetGrpY() = 0;

	virtual void SetGrpW(int w) = 0;
	virtual int GetGrpW() = 0;

	virtual void SetGrpH(int h) = 0;
	virtual int GetGrpH() = 0;

	virtual void SetSpdX(float x) = 0;
	virtual float GetSpdX() = 0;

	virtual void SetSpdY(float y) = 0;
	virtual float GetSpdY() = 0;

	virtual void SetJumpPower(float y) = 0;
	virtual float GetJumpPower() = 0;

	virtual void SetState(int s) = 0;
	virtual int GetState() = 0;

	virtual void SetJump(int s) = 0;
	virtual int GetJump() = 0;


	
protected:
	

	Texture* handle; //テクスチャハンドル
	int grp_x;//元画像のx座標 
	int grp_y;//元画像のy座標 
	int grp_w;//元画像の幅 
	int grp_h;//元画像の高さ 
	float pos_x;//座標x
	float pos_y;//座標y 
	float spd_x;//速度x 
	float spd_y;//速度y 
	float jumpPower;//ジャンプ力
	int state;//状態
	int jump;//飛んでるか？
	
};