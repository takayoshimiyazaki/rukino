//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.h
//!
//! @brief  プレイシーンのヘッダーファイル
//!
//! @date   2017/4/5
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "GameBase.h"
#include "ObjectBase.h"
#include "../Game/Player.h"

#include <string>
class GamePlay :public GameBase
{
private:
	Player* player;//プレイヤーポインタ
	bool mouseState = 0;
	int m_timeCount = 0;	//	カウント
	int cnt = 0;			//	時間
public:
	GamePlay();
	void Initialize();//初期化
	void Update();//更新
	void Render();//描画
	void importData(std::string f);//マップ読み込み
	void Collisionfloor(ObjectBase* obj);//床との判定
	void GamePlay::SetSpeadToAsaaignedPosition(ObjectBase* obj, float AposX, float AposY, float Time);//指定座標移動関数
	void GamePlay::ScrollMap(void);
	void Collisiontrup(ObjectBase * obj);
	//マップスクロール量検出
	~GamePlay();

};
