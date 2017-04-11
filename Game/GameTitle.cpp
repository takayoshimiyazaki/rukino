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

#include "../ADX2Le.h"
#include "../CueSheet_0.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

GameTitle::GameTitle()
{

	ADX2Le::LoadAcb("Resources\\Sounds\\CueSheet_0.acb");

	ADX2Le::Play(BGM_TITLE);
	if (g_init == 0)
	{
		g_init = 1;
	}


	m_cnt = 0;
	flag = 0;
	FlashCheck = true;
	m_Serect = false;
}

void GameTitle::Update()
{
	if (m_Serect == true)
	{
		if (((m_cnt / 10) % 2) == 0)
		{
			FlashCheck = true;
		}
		else
		{
			FlashCheck = false;
		}

		if (m_cnt == 129)
		{
			g_NextScene = SERECT;
		}
	}
	else
	{
		if (((m_cnt / 20) % 2) == 0)
		{
			FlashCheck = true;
		}
		else
		{
			FlashCheck = false;
		}
	}

	if (m_Serect == false)
	{
		// スペースキーでプレイに遷移
		if (g_keyTracker->pressed.Space)
		{
			ADX2Le::Play(Enter);
			m_Serect = true;
			m_cnt = 0;
		}

	}


	m_cnt++;

}
void GameTitle::Render()
{
	wchar_t buf[256];	// 文字列編集用
	
	// タイトル画像
	g_spriteBatch->Draw(g_TitleImage->m_pTexture, Vector2(0, 0));

	if (FlashCheck == true)
	{
		g_spriteBatch->Draw(g_SpaceImage->m_pTexture, Vector2(0, 0));
	}


}


GameTitle::~GameTitle()
{
 }