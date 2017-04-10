//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.h
//!
//! @brief  タイトルシーンのヘッダーファイル
//!
//! @date   2017/4/5
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "GameBase.h"
class GameTitle:public GameBase
{
private:
	int flag;
	int m_cnt;		// カウンタ
	float m_fade;
	float m_anime;
	int m_animeFlag;
	bool FlashCheck;//点滅
	bool m_Serect;//選択
public:
	GameTitle();
	void Update();
	void Render();
	~GameTitle();
};
