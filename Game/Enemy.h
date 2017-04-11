#pragma once
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   player.h
//!
//! @brief  �v���C���[�֘A�̃w�b�_�t�@�C��
//!
//! @date   2017/4/5
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̃C���N���[�h
#include <iostream>
#include "ObjectBase.h"
#include "../Texture.h"
// Player�N���X
class Enemy :public ObjectBase
{
private:
	int m_cnt;

	int actCnt;

public:
	Enemy();//�R���X�g���N�^
	~Enemy();//�f�X�g���N�^
	void UpData();//�X�V
	void Render();//�`��




	void SetHandle(Texture* h);//�摜�Z�b�g
	Texture* GetHandle();//�摜�擾

	void SetPosX(float x);//X���W�Z�b�g
	float GetPosX();//X���W�擾

	void SetPosY(float y);//Y���W�Z�b�g
	float GetPosY();//Y���W�Z�b�g


    //�摜�֘A�i�R�����g�ɂ���܂���...�j
	void SetGrpX(int x);
	int GetGrpX();

	void SetGrpY(int y);
	int GetGrpY();

	void SetGrpW(int w);
	int GetGrpW();

	void SetGrpH(int h);
	int GetGrpH();

	void SetSpdX(float x);
	float GetSpdX();

	void SetSpdY(float y);
	float GetSpdY();

	void SetJumpPower(float y);//�W�����v�͂̃Z�b�g
	float GetJumpPower();//�W�����v�͎擾

	void SetState(int s);//��Ԃ̃Z�b�g
	int GetState();//��Ԏ擾

	void SetJump(int s);//�W�����v��ԃZ�b�g
	int GetJump();//�W�����v��Ԏ擾


	void SetClimb(int s);
	int GetClimb();

	void SetHold(int s);
	int GetHold();

	void SetDir(int s);
	int GetDir();

	
	void Control(void);//����
};


