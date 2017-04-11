#pragma once
#include <iostream>
#include "./ObjectBase.h"
#include "../Texture.h"

class Gimmik :public ObjectBase
{
private:


public:
	Gimmik();
	~Gimmik();
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

	void SetClimb(int s);//�o���ԃZ�b�g
	int GetClimb();//�o���Ԏ擾

	void SetHold(int s);//�͂ݏ�ԃZ�b�g
	int GetHold();//�͂ݏ�Ԏ擾

	void SetDir(int s);//�����Z�b�g
	int GetDir() ;//�����擾

	void GimmikControl(void);//�M�~�b�N�̓���
};

