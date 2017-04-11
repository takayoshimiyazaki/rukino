//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.h
//!
//! @brief  �v���C�V�[���̃w�b�_�[�t�@�C��
//!
//! @date   2017/4/5
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "GameBase.h"
#include "ObjectBase.h"
#include "../Game/Player.h"
#include "../Game/Gimmik.h"
#include "../Game/Enemy.h"
#include <string>
class GamePlay :public GameBase
{
private:
	Player* player;//�v���C���[�|�C���^
	Gimmik* lift;//���t�g�|�C���^

	Enemy* enemy[15];//�G�|�C���^

	float gimmikPosAX = 0;//�M�~�b�N���͈�AX���W
	float gimmikPosAY = 0;//�M�~�b�N���͈�AY���W

	float gimmikPosBX = 0;//�M�~�b�N���͈�BX���W
	float gimmikPosBY = 0;//�M�~�b�N���͈�BY���W

	int enemyCnt = 0;
	int enemyNum = 0;
	int gimmikFlag = 0;
	int gimmikCnt = 0;
	bool mouseState = 0;
	int m_timeCount = 0;	//	�J�E���g
	int cnt = 0;			//	����

	int soundFlag = 0;
	int soundSet = 0;
	int soundCnt = 0;

public:
	GamePlay();
	void Initialize();//������
	void Update();//�X�V
	void Render();//�`��
	void importData(std::string f);//�}�b�v�ǂݍ���
	void Collisionfloor(ObjectBase* obj);//���Ƃ̔���
	void timeOver();//	��������
	void GamePlay::SetSpeadToAsaaignedPosition(ObjectBase* obj, float AposX, float AposY, float Time);//�w����W�ړ��֐�
	void GamePlay::ScrollMap(void);
	bool GamePlay::Collision(ObjectBase* obj1, ObjectBase*obj2);
	//�}�b�v�X�N���[���ʌ��o
	~GamePlay();

};
