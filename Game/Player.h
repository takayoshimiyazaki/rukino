//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   player.h
//!
//! @brief  プレイヤー関連のヘッダファイル
//!
//! @date   2017/4/5
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#include <iostream>
#include "ObjectBase.h"
#include "../Texture.h"
class Player :public ObjectBase
{
private:
	
public:
	Player();//コンストラクタ
	~Player();//デストラクタ
	void UpData();//更新
	void Render();//描画

	void SetHandle(Texture* h);//画像セット
	Texture* GetHandle();//画像取得

	void SetPosX(float x);//X座標セット
	float GetPosX();//X座標取得

	void SetPosY(float y);//Y座標セット
	float GetPosY();//Y座標セット


	//画像関連（コメントにつかれました...）
	void SetGrpX(int x);
	int GetGrpX();

	void SetGrpY(int y);
	int GetGrpY();

	void SetGrpW(int w);
	int GetGrpW();

	void SetGrpH(int h);
	int GetGrpH();

	void SetSpdX(float x);
	float GetSpdX();

	void SetSpdY(float y);
	float GetSpdY();

	void SetJumpPower(float y);//ジャンプ力のセット
	float GetJumpPower();//ジャンプ力取得

	void SetState(int s);//状態のセット
	int GetState();//状態取得

	void SetJump(int s);//ジャンプ状態セット
	int GetJump();//ジャンプ状態取得

	void PlayerControl(void);//プレイヤー操作
};

