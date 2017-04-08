//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameSerect.h
//!
//! @brief  ステージセレクトシーンのヘッダーファイル
//!
//! @date   2017/4/7
//!
//! @author Yuga Yamamoto	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "GameBase.h"

class GameSerect :public GameBase
{
private:
	int m_cnt;
	bool serectCheck;
	

	bool forestCheck;
	bool towerCheck;

	//選択用の森ステージと塔ステージの画像の場所
	DirectX::SimpleMath::Vector2 SerectForestPos;
	DirectX::SimpleMath::Vector2 SerectTowerPos;

	RECT forestRect;
	RECT towerRect;
public:
	//コンストラクタ
	GameSerect();

	//デストラクタ
	~GameSerect();

	//更新処理
	void Update();

	//描画処理
	void Render();

private:

	bool CheckVecMouse(DirectX::SimpleMath::Vector2 pos, RECT rect, DirectX::Mouse::State mouse);
};