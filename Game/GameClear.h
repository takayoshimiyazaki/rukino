//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameClear.h
//!
//! @brief  �N���A�V�[���̃w�b�_�[�t�@�C��
//!
//! @date   2017/4/5
//!
//! @author Yuhei M
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "GameBase.h"

class GameClear :public GameBase
{
private:
	int m_cnt;		// �J�E���^
	float m_fade;
	int m_flag;
public:
	GameClear();
	void Update();
	void Render();
	~GameClear();

private:

};
