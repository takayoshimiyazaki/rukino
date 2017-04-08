//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  プレイシーンのソースファイル
//!
//! @date   2017/4/5	
//!
//! @author Yuhei M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GamePlay.h"
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
//#include "..ADX2Le.h"
//#include "..\CueSheet_0.h"

#include <time.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;

//	コンストラクタ
GamePlay::GamePlay()
{
	//デバッグ用ステージ設定
	//serectMap = 1;//塔

	serectMap = 2;//森

	if (g_init == 0)
	{
		g_init = 1;
	}

	//プレイヤー作成
	player = new Player;

	//リフト（ギミック）作成
	lift = new Gimmik;

	// マップの設定
	if(serectMap == 1)importData("map1.csv");//マップデータの読み込み
	if(serectMap == 2)importData("map2.csv");//マップデータの読み込み
	

	// マップの設定
	for (int i = 0; i < MAX_TIP; i++)
	{

		if (g_map[i / MAP_H][i % MAP_W] == 0)//空白指定マップチップ
		{
			g_tip[i].state = 0;
		}
		else if (g_map[i / MAP_H][i % MAP_W] == 3)
		{
			lift->SetPosX((float)(i % MAP_W) * lift->GetGrpW());
			gimmikPosAX = lift->GetPosX();

			lift->SetPosY((float)(i / MAP_H) * lift->GetGrpH());
			gimmikPosAY = lift->GetPosY();
		}
		else if (g_map[i / MAP_H][i % MAP_W] == 4)
		{
			player->SetPosX((float)(i % MAP_W) * player->GetGrpW());
			player->SetPosY((float)(i / MAP_H) * player->GetGrpH());
		}
		else if (g_map[i / MAP_H][i % MAP_W] == 5)
		{
			gimmikPosBX = (i % MAP_W)* lift->GetGrpW();
			gimmikPosBY = (i / MAP_H)* lift->GetGrpH();
		}
		else
		{
			g_tip[i].grp_x = CHIP_SIZE * g_map[i / MAP_H][i %MAP_W];
			g_tip[i].grp_y = 0;
			g_tip[i].grp_w = CHIP_SIZE;
			g_tip[i].grp_h = CHIP_SIZE;
			g_tip[i].pos_x = (i % MAP_W) * g_tip[i].grp_w;
			g_tip[i].pos_y = (i / MAP_H) * g_tip[i].grp_h;
			g_tip[i].pos_x = (float)(i % MAP_W) * g_tip[i].grp_w;
			g_tip[i].pos_y = (float)(i / MAP_H) * g_tip[i].grp_h;
			g_tip[i].spd_x = 0.0f;
			g_tip[i].spd_y = 0.0f;
			g_tip[i].state = 1;
		}
	}
}



//更新
void GamePlay::Update()
{

	////////////////////  更新処理  //////////////////
	
	//速度リセット
	player->SetSpdX(0);
	if (player->GetJump() == TRUE&& player->GetClimb() == FALSE)
	{
		player->SetSpdY(player->GetSpdY() + GRAVITY);
	}
	else
	{
		player->SetSpdY(0);
	}

	//床との判定
	Collisionfloor(player);

	if (Collision(player, lift)&&player->GetHold()==TRUE)
	{
		player->SetJump(FALSE);
		player->SetJumpPower(0.0f);
		player->SetPosX(lift->GetPosX()+player->GetGrpW());
		player->SetPosY(lift->GetPosY());
	}

	player->UpData();

	if (gimmikFlag == 0)
	{
		gimmikCnt++;
		SetSpeadToAsaaignedPosition(lift, gimmikPosAX, gimmikPosAY, 2.0f);
		if (gimmikCnt == 180)
		{
			gimmikCnt = 0;
			gimmikFlag = 1;
		}
	}

	if (gimmikFlag == 1)
	{
		gimmikCnt++;
		SetSpeadToAsaaignedPosition(lift, gimmikPosBX, gimmikPosBY, 2.0f);
		if (gimmikCnt == 180)
		{
			gimmikCnt = 0;
			gimmikFlag = 0;
		}
	}
	
	lift->UpData();

	ScrollMap();

	m_timeCount++;	//	時間のカウント


	////////////////////  キー入力  //////////////////	


	// マウスクリックで
	//if (g_mouse.leftButton)
	//{
	//	SetSpeadToAsaaignedPosition(player, 200.0f, 200.0f, 3.0f);//指定位置に移動関数テスト
	//}

	mouseState = g_mouse.leftButton;
}


//描画
void GamePlay::Render()
{
	//マウスカーソル隠し
	/*ShowCursor(FALSE);*/

	RECT rect;			// 絵の左上の座標と右下の座標編集用
	wchar_t buf[256];	// 文字列編集用						
	wchar_t buf2[256];	// 文字列編集用
	wchar_t buf3[256];	// 文字列編集用

	rect = { 0, 0,640,480 };
	switch (serectMap)
	{
	case 2:
		g_spriteBatch->Draw(g_BackImage->m_pTexture,
			Vector2(0, 0));
		break;
	case 1:
		g_spriteBatch->Draw(g_BackImage2->m_pTexture,
			Vector2(0, 0));
		break;
	}
	

	//ステージ描画
	for (int i = 0; i < MAX_TIP; i++)
	{
		if (g_tip[i].state)
		{
			rect = { g_tip[i].grp_x, g_tip[i].grp_y,
				g_tip[i].grp_x + g_tip[i].grp_w,
				g_tip[i].grp_y + g_tip[i].grp_h };

			float sx = g_tip[i].pos_x - g_ScrollMap_x;
			float sy = g_tip[i].pos_y - g_ScrollMap_y;

			g_spriteBatch->Draw(g_StageImage->m_pTexture,
				Vector2(sx, sy),
				&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);
		}
	}

	lift->Render();

	//	 プレイヤー
	player->Render();

	rect = { 0, 0,680,96};
	g_spriteBatch->Draw(g_StateImage->m_pTexture,
		Vector2(0, 480-96),
		&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);

	rect = { 0, 0,64,84 };
	g_spriteBatch->Draw(g_SBImage->m_pTexture,
		Vector2(40, 480 - 84),
		&rect, Colors::White, 0.0f, Vector2(0, 0), 0.8f);

	//	時間表示
	if (m_timeCount % 60 == 1)
	{
		cnt++;
	}

	//デバッグ用文字
	swprintf_s(buf, 16, L"X ,%d", (int)player->GetPosX());
	swprintf_s(buf2, 16, L"Y ,%d", (int)player->GetPosY());
	swprintf_s(buf3, 16, L"T ,%d", cnt);

	g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(0, 0));
	g_spriteFont->DrawString(g_spriteBatch.get(), buf2, Vector2(0, 16));
	g_spriteFont->DrawString(g_spriteBatch.get(), buf3, Vector2(0, 32));
}

//マップの読み込み
void GamePlay::importData(string filename)
{
	ifstream ifs(filename);
	string str;
	int i;

	if (!ifs) {
		for (i = 0; i < MAX_TIP; i++)
		{
			g_map[i / MAP_H][i % MAP_W] = 0;
		}
		return;
	}

	i = 0;
	while (getline(ifs, str)) {
		string token;
		istringstream stream(str);

		// 1行のうち、文字列とコンマを分割する
		while (getline(stream, token, ',')) {
			// すべて文字列として読み込まれるため
			// 数値は変換が必要
			g_map[i / MAP_H][i % MAP_W] = atoi(token.c_str());
			i++;
		}
	}
}

//床、天井の判定
void  GamePlay::Collisionfloor(ObjectBase* obj)
{
	//プレイヤーの左右座標を求める
	float left = obj->GetPosX() + 0.01f;
	float right = obj->GetPosX() + (obj->GetGrpW() - 0.01f);

	// プレイヤーの足元の座標を求める
	float bottom = obj->GetPosY() + (obj->GetGrpH() + 0.01f);
	//プレイヤーの頭の判定
	float head = obj->GetPosY();
	//プレイヤーの胴体判定
	float body = obj->GetPosY() + (obj->GetGrpH() / 2);
	// マップの配列の位置　
	int map_x, map_y;

	// プレイヤーの左足の位置
	map_x = (int)floor(left / CHIP_SIZE + 0.5f);
	map_y = (int)floor(bottom / CHIP_SIZE);


	
	// 床壁だったら
	if (g_map[map_y][map_x] == 1||g_map[map_y][map_x] == 9)
	{
		if (bottom > -map_y * CHIP_SIZE + obj->GetGrpH())
		{
			if (obj->GetJump() == TRUE|| obj->GetClimb() == TRUE)
			{
				// プレイヤーの位置を床の上に移動させる
				if (obj->GetState() == 1)
				{
					if (obj->GetGrpH() == 64)
					{

						obj->SetPosY((map_y - 1) * CHIP_SIZE - 32.0f);
					}
					else
					{
						obj->SetPosY((map_y - 1) * (float)CHIP_SIZE);
					}
				}
				else
				{
					obj->SetPosY((map_y - 1) * CHIP_SIZE - 32.0f);
				}
			}
			// 速度を0にする
			obj->SetSpdY(0.0f);
			obj->SetJump(FALSE);
			obj->SetJumpPower(0);
			obj->SetState(1);

		}
	}
	else if (g_map[map_y][map_x] == 6)
	{
		obj->SetSpdY(0.0f);
		obj->SetJump(TRUE);
		obj->SetJumpPower(0);
	}
	else if (g_map[map_y][map_x] == 10)
	{
		obj->SetSpdY(0.0f);
		obj->SetJump(TRUE);
		obj->SetJumpPower(20.0f);
	}
	else
	{
		//足元が床で無ければ飛んでいる
		obj->SetJump(TRUE);
	}

	map_y = (int)floor(head / CHIP_SIZE);
	// 天井だったら
	if (g_map[map_y][map_x] == 1)
	{
		if (bottom > -map_y * CHIP_SIZE + obj->GetGrpH())
		{
			{// 落とす
				obj->SetJumpPower(0.0f);
				obj->SetSpdY(10.0f);
			}
		} 
	}
	//頭上にロープかつ掴み状態
	if (g_map[map_y][map_x] == 7 && player->GetHold() == TRUE)
	{
		obj->SetJumpPower(0.0f);
		obj->SetJump(FALSE);
		obj->SetSpdY(0.0f);
		obj->SetSpdX(3.0f);
	}
	
	

	map_y = (int)floor(bottom / CHIP_SIZE);

	// プレイヤーの右足の位置
	map_x = (int)floor(right / CHIP_SIZE-0.5f);
	// 床だったら
	if (g_map[map_y][map_x] == 1|| g_map[map_y][map_x] == 9)
	{
		if (bottom > -map_y * CHIP_SIZE + obj->GetGrpH())
		{
			if (obj->GetJump() == TRUE)
			{
				// プレイヤーの位置を床の上に移動させる
				if (obj->GetState())
				{
					if (obj->GetGrpH() == 64)
					{
						obj->SetPosY((map_y - 1) * CHIP_SIZE - 32.0f);
					}
					else
					{
						obj->SetPosY((map_y - 1) * (float)CHIP_SIZE);
					}
				}
				else
				{
					obj->SetPosY((map_y - 1) * CHIP_SIZE - 32.0f);
				}
			}
			// 速度を0にする
			obj->SetSpdY(0.0f);
			obj->SetJump(FALSE);
			obj->SetJumpPower(0.0f);
			obj->SetState(1);
		}
	}
	else if (g_map[map_y][map_x] == 6)
	{
		obj->SetSpdY(0.0f);
		obj->SetJump(TRUE);
		obj->SetJumpPower(0);
	}
	else if (g_map[map_y][map_x] == 10)
	{
		obj->SetSpdY(0.0f);
		obj->SetJump(TRUE);
		obj->SetJumpPower(20.0f);
	}
	else
	{
		//足元が床で無ければ飛んでいる
		obj->SetJump(TRUE);
	}


	map_y = (int)floor(head / CHIP_SIZE);
	// 天井だったら
	if (g_map[map_y][map_x] == 1)
	{
		if (bottom > -map_y * CHIP_SIZE + obj->GetGrpH())
		{
			{// 落とす
				obj->SetJumpPower(0.0f);
				obj->SetSpdY(10.0f);
			}
		}
	}
	//頭上にロープかつ掴み状態
	if (g_map[map_y][map_x] == 7&&player->GetHold()==TRUE)
	{
		obj->SetJumpPower(0.0f);
		obj->SetJump(FALSE);
		obj->SetSpdY(0.0f);
		obj->SetSpdX(3.0f);
	}
	
}

//罠とキャラクターの当たり判定
//void  GamePlay::Collisiontrup(ObjectBase* obj)
//{
//	//プレイヤーの左右座標を求める
//	float left = obj->GetPosX() + 0.01f;
//	float right = obj->GetPosX() + (obj->GetGrpW() - 0.01f);
//
//	// プレイヤーの足元の座標を求める
//	float bottom = obj->GetPosY() + (obj->GetGrpH() + 0.01f);
//	//プレイヤーの頭の判定
//	float head = obj->GetPosY();
//	//プレイヤーの胴体判定
//	float body = obj->GetPosY() + (obj->GetGrpH() / 2);
//	// マップの配列の位置　
//	int map_x, map_y;
//
//	// プレイヤーの左足の位置
//	map_x = (int)floor(left / CHIP_SIZE + 0.5f);
//	map_y = (int)floor(bottom / CHIP_SIZE);
//}

GamePlay::~GamePlay()
{
	delete player;
}

void GamePlay::Initialize()
{
	

	
}


////////////////////////////////////////////////////////////////////////////////////
//オブジェクトの現在地と目的地の差を求め、速度を倍率をかけて設定する関数
//戻り値:なし
//引数:(OBJECT型オブジェクト名,float型 目的座標X,float型 目的座標Y,float型　到達までの時間(0.0で瞬間到達)）
////////////////////////////////////////////////////////////////////////////////////
void GamePlay::SetSpeadToAsaaignedPosition(ObjectBase* obj, float AposX, float AposY, float Time)
{
	//目的ポイントとの差を記憶する変数
	float disX = 0.0f;
	float disY = 0.0f;
	int moveFlag = 0;
	int moveCnt = 0;


	//変数にオブジェクトと目的ポイントとの差を入れる
	disX = AposX - obj->GetPosX();
	disY = AposY - obj->GetPosY();

	//オブジェクトの速度設定
	//X方向
	//オブジェクトのポジションと目的ポイントに差があった場合
	if (disX != 0.0f)
	{
		obj->SetSpdX(disX / Time / 60.0f);

	}
	else if (disX == 0.0f)
	{
		obj->SetSpdX(0.0f);
	}
	//目的ポイントを過ぎたら
	if ((obj->GetSpdX() > 0 && obj->GetPosX() >= AposX) || (obj->GetSpdX() < 0 && obj->GetPosX() <= AposX))
	{
		obj->SetSpdX(0);
		obj->SetPosX(AposX);
	}
	//Y方向
	//オブジェクトのポジションと目的ポイントに差があった場合
	if (disY != 0.0f)
	{
		obj->SetSpdY(disY / Time / 60.0f);

	}
	else if (disY == 0.0f)
	{
		obj->SetSpdY(0.0f);
	}
	//目的ポイントを過ぎたら
	if ((obj->GetSpdY() > 0.0f && obj->GetPosY() >= AposY) || (obj->GetSpdY() < 0.0f && obj->GetPosY() <= AposY))
	{
		obj->SetSpdY(0.0f);
		obj->SetPosY(AposY);
	}
	//オブジェクトが動いている場合秒数をカウントする
	if (obj->GetSpdY() != 0 || obj->GetSpdY() != 0)
	{
		moveFlag = 1;
	}
	if (moveFlag == 1)
	{
		moveCnt++;
		if (moveCnt / 60 == Time)//指定時間になったら指定ポジションに強制移動
		{
			obj->SetPosX(AposX);
			obj->SetPosY(AposY);
		}
	}
	obj->SetPosX(obj->GetPosX() + obj->GetSpdX());
	obj->SetPosY(obj->GetPosY() + obj->GetSpdY());
}


//スクロール量検出
void GamePlay::ScrollMap(void)
{

	g_ScrollMap_x = player->GetPosX() + player->GetGrpW() / 2 - SCREEN_WIDTH / 2;

	if (g_ScrollMap_x < 0|| serectMap == 1)
	{
		g_ScrollMap_x = 0;
	}
	else if (g_ScrollMap_x >(MAP_W * CHIP_SIZE - SCREEN_WIDTH))
	{
		g_ScrollMap_x = (MAP_W * CHIP_SIZE - SCREEN_WIDTH);
	}


	g_ScrollMap_y = player->GetPosY() + player->GetGrpH() / 2 - SCREEN_HEIGHT / 2;

	if (g_ScrollMap_y < 0 )
	{
		g_ScrollMap_y = 0;
	}
	//else if (g_ScrollMap_y >(MAP_H  * CHIP_SIZE - SCREEN_HEIGHT) || serectMap == 2)
	else if (g_ScrollMap_y >(MAP_H  * CHIP_SIZE - SCREEN_HEIGHT) )
	{
		g_ScrollMap_y = (MAP_H * CHIP_SIZE - SCREEN_HEIGHT);
	}
}

bool GamePlay::Collision(ObjectBase* obj1, ObjectBase*obj2)
{
	/*四角形の当たり判定*/
	if ((obj1->GetPosX() /*- g_ScrollMap_x */ <= (obj2->GetPosX() + obj2->GetGrpW())) &&
		((obj1->GetPosX() /*- g_ScrollMap_x */+ obj1->GetGrpW()) >= obj2->GetPosX()) &&
		(obj1->GetPosY() <= (obj2->GetPosY() + obj2->GetGrpH())) &&
		((obj1->GetPosY() + obj1->GetGrpH() >= obj2->GetPosY())))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}