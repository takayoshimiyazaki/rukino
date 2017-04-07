//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameOver.cpp
//!
//! @brief  ゲームオーバーシーンのソースファイル
//!
//! @date   2017/4/5	
//!
//! @author Yuhei M		
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GameOver.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;


GameOver::GameOver()
{
}

void GameOver::Update()
{
	if (g_init == 0)
	{
		g_init = 1;
	
	}

	// スペースキーでタイトルに遷移
	if (g_keyTracker->pressed.Space)
	{
		g_NextScene = TITLE;
	}
}

void GameOver::Render()
{
	RECT rect;			// 絵の左上の座標と右下の座標編集用
	wchar_t buf[256];	//文字列編集用


	rect = { 0, 0,640,480 };
	g_spriteBatch->Draw(g_OverImage->m_pTexture,
		Vector2(0, 0));
}

GameOver::~GameOver()
{
}
