//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.cpp
//!
//! @brief  �^�C�g���̃\�[�X�t�@�C��
//!
//! @date   2017/4/5	
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameTitle.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;



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
		// �X�y�[�X�L�[�Ńv���C�ɑJ��
		if (g_keyTracker->pressed.Space)
		{
			m_Serect = true;
			m_cnt = 0;
		}
	}


	m_cnt++;

}
void GameTitle::Render()
{
	wchar_t buf[256];	// ������ҏW�p
	
	// �^�C�g���摜
	g_spriteBatch->Draw(g_TitleImage->m_pTexture, Vector2(0, 0));

	if (FlashCheck == true)
	{
		g_spriteBatch->Draw(g_SpaceImage->m_pTexture, Vector2(0, 0));
	}


}
GameTitle::GameTitle()
{
	if (g_init == 0)
	{
		g_init = 1;
	}

	m_cnt = 0;
	flag = 0;
	FlashCheck = true;
	m_Serect = false;
}

GameTitle::~GameTitle()
{
}