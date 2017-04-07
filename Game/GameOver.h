//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameOver.h
//!
//! @brief  ゲームオーバーシーンのヘッダーファイル
//!
//! @date   2017/4/5
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "GameBase.h"

class GameOver :public GameBase
{
private:
	int cnt;		// カウンタ
public:
	GameOver();
	void Update();
	void Render();
	~GameOver();

private:

};
