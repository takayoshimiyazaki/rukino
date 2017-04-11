//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  �Q�[���֘A�̃w�b�_�t�@�C��
//!
//! @date   2017/4/5
//!
//! @author Yuhei M
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif

#define MAP_H 45
#define MAP_W 45

#define CHIP_SIZE 32
#define GRAVITY 0.98

#include <windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include "..\DirectXTK.h"
#include "..\Texture.h"

#include "..\ADX2Le.h"
#include "../CueSheet_0.h"

#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")

// �萔�̒�` ==============================================================

// �Q�[���^�C�g��
#define GAME_TITLE "��߁��҂�"

// �Q�[�����
#define SCREEN_WIDTH  640    // ��[pixel]
#define SCREEN_HEIGHT 480    // ����[pixel]

//�}�b�v�`�b�v�̍ő吔
#define MAX_TIP 2025

//�@�\���̐錾
typedef struct tag_object
{
	Texture *handle;		//�O���t�B�b�N�n���h�� 
	int grp_x;				//���摜��x���W 
	int grp_y;				//���摜��y���W 
	int grp_w;				//���摜�̕� 
	int grp_h;				//���摜�̍��� 
	float pos_x;			//���Wx 
	float pos_y;			//���Wy 
	float spd_x;			//���xx 
	float spd_y;			//���xy 
	int state;				//���

}OBJECT;					//�I�u�W�F�N�g�p

//�@�񋓌^�錾
enum SCENE
{
	LOGO,
	TITLE,
	SERECT,
	PLAY,
	CLEAR,
	OVER
};

enum DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

// �֐��̐錾 ==============================================================
// �Q�[���̏���������
void InitializeGame(void);

// �Q�[���̍X�V����
void UpdateGame(void);

// �Q�[���̕`�揈��
void RenderGame(void);

// �Q�[���̏I������
void FinalizeGame(void);

//�@���l�`�揈��
void DrawNum(int x, int y, int n);



// �O���[�o���ϐ��̒�` ===================================================
EXTERN Texture *g_StageImage;			//�@�X�e�[�W�摜
EXTERN Texture *g_BlackImage;			// �t�F�[�h�p���摜
EXTERN Texture *g_BackImage;			// ���w�i�p�摜
EXTERN Texture *g_BackImage2;			// �X�w�i�p�摜

// �X�e�[�W�Z���N�g�p�摜

EXTERN Texture *g_ForestStageImage;		//�X�e�[�W�C���[�W�i�X�j�摜
EXTERN Texture *g_TowerStageImage;		//�X�e�[�W�C���[�W�i���j�摜

EXTERN Texture *g_StageSerect;			//�X�e�[�W�I���摜

EXTERN Texture *g_PlayerImage;			//�v���C���[�摜
EXTERN Texture *g_PlayerClothesPins;	//�v���C���̎�����΂��݉摜
EXTERN Texture *g_SBImage;			//�΂��݉摜
EXTERN Texture *g_Spider;			//�w偉摜
EXTERN Texture *g_TitleImage;			// �^�C�g�����
EXTERN Texture *g_TowerClearImage;			//�N���A�摜
EXTERN Texture *g_ForestClearImage;			//�N���A�摜
EXTERN Texture *g_LogoImage;			//���S�摜
EXTERN Texture *g_OverImage;			//�Q�[���I�[�o�[�摜
EXTERN Texture *g_StateImage;			//��ԉ摜
EXTERN Texture *g_JumpImage;
EXTERN Texture *g_YumePinImage;
EXTERN Texture *g_DreamSelectImage;




EXTERN Texture *g_FaceImage;			//�N���A�摜
EXTERN Texture *g_RopeImage ;			//���[�v�摜
EXTERN Texture *g_SpaceImage;			//�X�y�[�X�{�^���N���b�N�摜
EXTERN Texture *g_TimeImage;//�c�莞��

EXTERN int g_map[MAP_H][MAP_W];			//	�}�b�v�f�[�^// ��[*5][���{]
EXTERN OBJECT g_tip[MAX_TIP];		//�@�}�b�v�`�b�v
EXTERN OBJECT g_trap[MAX_TIP];		//�@�}�b�v�`�b�v

EXTERN int g_scene;					//�V�[���Ǘ�
EXTERN int g_NextScene;				//���̃V�[��
EXTERN int g_init;					//�������Ǘ�
EXTERN int g_mousePoint;

EXTERN int serectMap;				//����}�b�v
EXTERN int g_ScrollMap_x;			//��ʃX�N���[���ʁiX�j
EXTERN int g_ScrollMap_y;			//��ʃX�N���[���ʁiY�j
