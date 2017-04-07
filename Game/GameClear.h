//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameClear.h
//!
//! @brief  クリアシーンのヘッダーファイル
//!
//! @date   2017/4/5
//!
//! @author Yuhei M
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "GameBase.h"

class GameClear :public GameBase
{
private:
	int m_cnt;		// カウンタ
public:
	GameClear();
	void Update();
	void Render();
	~GameClear();

private:

};
