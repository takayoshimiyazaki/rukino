//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameSerect.h
//!
//! @brief  �X�e�[�W�Z���N�g�V�[���̃w�b�_�[�t�@�C��
//!
//! @date   2017/4/7
//!
//! @author Yuga Yamamoto	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "GameBase.h"

class GameSerect :public GameBase
{
private:
	int m_cnt;
	int m_flashCnt;
	float m_fade;
	bool serectCheck;

	bool forestCheck;
	bool towerCheck;

	//�I��p�̐X�X�e�[�W�Ɠ��X�e�[�W�̉摜�̏ꏊ
	DirectX::SimpleMath::Vector2 SerectForestPos;
	DirectX::SimpleMath::Vector2 SerectTowerPos;

	RECT forestRect;
	RECT towerRect;
public:
	//�R���X�g���N�^
	GameSerect();

	//�f�X�g���N�^
	~GameSerect();

	//�X�V����
	void Update();

	//�`�揈��
	void Render();

private:

	//bool CheckVecMouse(DirectX::SimpleMath::Vector2 pos, RECT rect, DirectX::Mouse::State mouse);
};
