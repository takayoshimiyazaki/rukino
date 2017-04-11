//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameOver.h
//!
//! @brief  �Q�[���I�[�o�[�V�[���̃w�b�_�[�t�@�C��
//!
//! @date   2017/4/5
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "GameBase.h"

class GameOver :public GameBase
{
private:
	int m_cnt;		// �J�E���^
	float m_fade;
	int m_flag;
public:
	GameOver();
	void Update();
	void Render();
	~GameOver();

private:

};
