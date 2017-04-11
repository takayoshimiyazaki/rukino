//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameClear.cpp
//!
//! @brief  �N���A�V�[���̃\�[�X�t�@�C��
//!
//! @date   2017/4/5	
//!
//! @author Yuhei M		
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameClear.h"


using namespace DirectX::SimpleMath;
using namespace DirectX;


GameClear::GameClear()
{

	
}

void GameClear::Update()
{
	if (g_init == 0)
	{
		g_init = 1;
		m_cnt = 0;
	}


	// �X�y�[�X�L�[�������ꂽ��
	if (g_keyTracker->pressed.Space)
	{
		//�^�C�g���֍s��
		g_NextScene = TITLE;

	}
}

void GameClear::Render()
{
	RECT rect;			// �G�̍���̍��W�ƉE���̍��W�ҏW�p

	//�N���A�摜�̕`��
	rect = { 0, 0,640,480 };
	if (serectMap == 1)
	{
		g_spriteBatch->Draw(g_TowerClearImage->m_pTexture, Vector2(0, 0));
	}
	else if (serectMap == 2)
	{
		g_spriteBatch->Draw(g_ForestClearImage->m_pTexture, Vector2(0, 0));
	}
	
}

GameClear::~GameClear()
{
}
