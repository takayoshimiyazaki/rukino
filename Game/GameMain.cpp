//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ���C���̃\�[�X�t�@�C��
//!
//! @date   2017/4/5	
//!
//! @author Yuhei.M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#define _GAMEMAIN_
#include "GameMain.h"
#include"GameClear.h"
#include"GameLogo.h"
#include"GameOver.h"
#include"GamePlay.h"
#include"GameTitle.h"
#include"GameSerect.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;


// �v���g�^�C�v�錾 ====================================================
void importData(string filename);

// �O���[�o���ϐ��̒�` ====================================================
GameLogo logo;
GameTitle title;
GamePlay play;
GameClear clear;
GameOver over;
GameBase* base;

// �֐��̒�` ==============================================================

//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void InitializeGame(void)
{
	base = new GameTitle();

	ADX2Le::Initialize("NewProject3.acf");
	ADX2Le::LoadAcb("CueSheet_0.acb", "CueSheet_0.awb");

	// �摜�̓ǂݍ��� 
	g_StageImage = new Texture(L"Resources\\Images\\StageImage.png");//�X�e�[�W�摜
	g_BlackImage = new Texture(L"Resources\\Images\\black.png");//�t�F�[�h�p���摜
	g_BackImage = new Texture(L"Resources\\Images\\back.png");//�w�i�摜
	g_BackImage2 = new Texture(L"Resources\\Images\\back2.png");//�w�i�摜
	g_PlayerImage = new Texture(L"Resources\\Images\\player.png");//�v���C���[�摜
	g_PlayerClothesPins = new Texture(L"Resources\\Images\\Clothes_pins.png");//�v���C���̐���΂��݉摜
	g_Spider = new Texture(L"Resources\\Images\\Spider.png");//�w偉摜
	g_RopeImage = new Texture(L"Resources\\Images\\long_rope.png");//���[�v�摜
	g_TitleImage = new Texture(L"Resources\\Images\\title.png");//�^�C�g���摜
	g_SpaceImage = new Texture(L"Resources\\Images\\PleaseSpace.png");//�X�y�[�X�{�^���N���b�N�摜
	g_TowerClearImage = new Texture(L"Resources\\Images\\Tower_Clear.png");//�N���A�摜
	g_ForestClearImage = new Texture(L"Resources\\Images\\Forest_Clear.png");//�N���A�摜
	g_LogoImage = new Texture(L"Resources\\Images\\logo.png");//���S�摜
	g_OverImage = new Texture(L"Resources\\Images\\OVER.png");//�N���A�摜

	//UI
	g_StateImage = new Texture(L"Resources\\Images\\state.png");//UI�摜
	g_SBImage = new Texture(L"Resources\\Images\\SB.png");//����΂��݉摜
	g_JumpImage = new Texture(L"Resources\\Images\\JumpImage.png");//����΂��݉摜
	g_FaceImage = new Texture(L"Resources\\Images\\Face.png");//�L������摜

	//�X�e�[�W�̃Z���N�g���̉摜
	g_ForestStageImage = new Texture(L"Resources\\Images\\ForestStage.png");//�X
	g_TowerStageImage = new Texture(L"Resources\\Images\\TowerStage.png");//��
	g_StageSerect = new Texture(L"Resources\\Images\\StageSerect.png");//�X�e�[�W�I�����

	// ���̓ǂݍ���



	g_init = 0;
}



//----------------------------------------------------------------------
//! @brief �Q�[���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void UpdateGame(void)
{
	ADX2Le::Update();

	// �V�[���Ǘ�
	if (g_scene != g_NextScene)
	{
		g_scene = g_NextScene;
		// �V�[���폜
		delete base;
		 // �V�[������
		switch (g_scene)
		{
		case LOGO:
			base = new GameLogo();
			break;
		case TITLE:
			base = new GameTitle();
			break;
		case SERECT:
			base = new GameSerect();
			break;
		case PLAY:
			base = new GamePlay();
			break;
		case CLEAR:
			base = new GameClear();
			break;
		case OVER:
			base = new GameOver();
			break;
		}
		g_init = 0;
	}


	base->Update();
}



//----------------------------------------------------------------------
//! @brief �Q�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void RenderGame(void)
{	
	wchar_t buf[256];

	base->Render();
}



//----------------------------------------------------------------------
//! @brief �Q�[���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void FinalizeGame(void)
{
	ADX2Le::Finalize();

	/*ADX2Le::Finalize();*/
}


//----------------------------------------------------------------------
//! @brief ���l�`�揈��
//!
//! @param[in] xy���W�C���lw
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void DrawNum(int x, int y, int n)
{
	int w = n;		// �v�Z�p
	int i = 0;		// ������

	if (w == 0)
	{
	}
	else
	{
		while (w)
		{
			w = w / 10;
			i++;
		}
	}

}


