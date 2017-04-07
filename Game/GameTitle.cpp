//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.cpp
//!
//! @brief  タイトルのソースファイル
//!
//! @date   2017/4/5	
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GameTitle.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;


//----------------------------------------------------------------------
//! @brief タイトル処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameTitle(void)
{
}

//----------------------------------------------------------------------
//! @brief タイトル描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void RenderTitle(void)
{
}
void GameTitle::Update()
{
	if (g_init == 0)
	{
		g_init = 1;

	}

	// スペースキーでプレイに遷移
	if (g_keyTracker->pressed.Space)
	{
		g_NextScene = SERECT;

	}

}
void GameTitle::Render()
{
	RECT rect;			// 絵の左上の座標と右下の座標編集用
	wchar_t buf[256];	// 文字列編集用
	
	// タイトル画像
	rect = { 0,0,640,480 };
	g_spriteBatch->Draw(g_TitleImage->m_pTexture, Vector2(0, 0));

	

}
GameTitle::GameTitle()
{
	
}

GameTitle::~GameTitle()
{
}