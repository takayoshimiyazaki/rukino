//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameOver.cpp
//!
//! @brief  �Q�[���I�[�o�[�V�[���̃\�[�X�t�@�C��
//!
//! @date   2017/4/5	
//!
//! @author Yuhei M		
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameOver.h"

#include "..\ADX2Le.h"
#include "..\CueSheet_0.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;


GameOver::GameOver()
{
	ADX2Le::Stop();
	m_cnt = 0;
	m_fade = 0;
	m_flag = 0;
	ADX2Le::Play(BGM_OVER);
}

void GameOver::Update()
{
	// �X�y�[�X�L�[�Ń^�C�g���ɑJ��
	if (g_keyTracker->pressed.Space)
	{
		m_flag = 1;
		
	}


	if (m_flag == 1)
	{
		m_cnt++;
		m_fade += 0.01f;
	}

	if (m_cnt >= 120)
	{
		g_NextScene = TITLE;
	}

}

void GameOver::Render()
{
	RECT rect;			// �G�̍���̍��W�ƉE���̍��W�ҏW�p
	wchar_t buf[256];	//������ҏW�p


	rect = { 0, 0,640,480 };
	g_spriteBatch->Draw(g_OverImage->m_pTexture,
		Vector2(0, 0));

	//�Ó]�p���w�i
	g_spriteBatch->Draw(g_BlackImage->m_pTexture, Vector2(0, 0), Vector4(255, 255, 255, m_fade));


}

GameOver::~GameOver()
{
}
