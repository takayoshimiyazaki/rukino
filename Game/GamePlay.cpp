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


using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;

void Initialize();
void Update();


//	コンストラクタ
GamePlay::GamePlay()
{
	//プレイヤー作成
	player = new Player;
	
	// マップの設定

	importData("map.csv");//マップデータの読み込み
	// マップの設定
	for (int i = 0; i < MAX_TIP; i++)
	{
		
		if (g_map[i / 20][i % 20] == 0)//空白指定マップチップ
		{
			g_tip[i].state = 0;
		}
		else
		{
			g_tip[i].grp_x = CHIP_SIZE * g_map[i / 20][i % 20];
			g_tip[i].grp_y = 0;
			g_tip[i].grp_w = CHIP_SIZE;
			g_tip[i].grp_h = CHIP_SIZE;
			g_tip[i].pos_x = (i % 20) * g_tip[i].grp_w;
			g_tip[i].pos_y = (i / 20) * g_tip[i].grp_h;
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
	player->UpData();
	////////////////////  キー入力  //////////////////	


	//床との判定
	Collisionfloor(player);

	// マウスクリックで
	if (g_mouse.leftButton)
	{
		SetSpeadToAsaaignedPosition(player, 200.0f, 200.0f, 3.0f);//指定位置に移動関数テスト
	}

	mouseState = g_mouse.leftButton;
	
}



//描画
void GamePlay::Render()
{
	//マウスカーソル隠し
	ShowCursor(FALSE);

	RECT rect;			// 絵の左上の座標と右下の座標編集用
						wchar_t buf[256];	// 文字列編集用
						wchar_t buf2[256];	// 文字列編集用

	rect = { 0, 0,640,480 };
	g_spriteBatch->Draw(g_BackImage->m_pTexture,
		Vector2(0, 0));

	//ステージ描画
	for (int i = 0; i < MAX_TIP; i++)
	{
		//マップチップ毎の設定
		/*if (g_map[i / 20][i % 20] == 1)
		{
		
		}*/

		if (g_tip[i].state)
		{
			rect = { g_tip[i].grp_x, g_tip[i].grp_y,
				g_tip[i].grp_x + g_tip[i].grp_w,
				g_tip[i].grp_y + g_tip[i].grp_h };


			g_spriteBatch->Draw(g_StageImage->m_pTexture,
				Vector2(g_tip[i].pos_x, g_tip[i].pos_y),
				&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);
		}
	}



	//	 プレイヤー
	player->Render();

	//デバッグ用文字
	/*swprintf_s(buf, 16, L"", );
	swprintf_s(buf2, 32, L"", );
	g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(0, 0));
	g_spriteFont->DrawString(g_spriteBatch.get(), buf2, Vector2(0, 32));*/
	
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
			g_map[i / 20][i % 20] = 0;
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
			g_map[i / 20][i % 20] = atoi(token.c_str());
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
	int map_x, map_y, map_y2;

	// プレイヤーの左足の位置
	map_x = (int)floor(left / CHIP_SIZE + 0.5f);
	map_y = (int)floor(bottom / CHIP_SIZE);


	// 床壁だったら
	if (g_map[map_y][map_x] == 1 )
	{
		if (bottom > -map_y * CHIP_SIZE + obj->GetGrpH())
		{
			if (obj->GetJump() == TRUE)
			{
				// プレイヤーの位置を床の上に移動させる
				if (obj->GetState() == 1)
				{
					if (obj->GetGrpH() == 64)
					{
						obj->SetPosY((map_y - 1) * CHIP_SIZE - 32);
					}
					else
					{
						obj->SetPosY((map_y - 1) * CHIP_SIZE);
					}
				}
				else
				{
					obj->SetPosY((map_y - 1) * CHIP_SIZE - 32);
				}
			}
			// 速度を0にする
			obj->SetSpdY(0.0f);
			obj->SetJump(FALSE);
			obj->SetJumpPower(0);
			obj->SetState(1);
			
		}
	}
	else
	{
		//足元が床で無ければ飛んでいる
		obj->SetJump(TRUE);
	}

	map_y = (int)floor(head / CHIP_SIZE);
	// 天井だったら
	if (g_map[map_y][map_x] == 1  )
	{
		if (bottom > -map_y * CHIP_SIZE + obj->GetGrpH())
		{
			// 落とす
			obj->SetSpdY(10.0f);
		}
	}


	map_y = (int)floor(bottom / CHIP_SIZE);

	// プレイヤーの右足の位置
	map_x = (int)floor(right / CHIP_SIZE);
	// 床だったら
	if (g_map[map_y][map_x] == 1)
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
						obj->SetPosY((map_y - 1) * CHIP_SIZE - 32);
					}
					else
					{
						obj->SetPosY((map_y - 1) * CHIP_SIZE);
					}
				}
			}
			// 速度を0にする
			obj->SetSpdY(0.0f);
			obj->SetJump(FALSE);
			obj->SetJumpPower(0);
			obj->SetState(1);
		}
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
			// 落とす
			obj->SetSpdY(10.0f);
		}
	}
}


GamePlay::~GamePlay()
{
	//delete player;
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
		if (moveCnt / 60 == Time)
		{
			obj->SetPosX(AposX);
			obj->SetPosY(AposY);
		}
	}
	obj->SetPosX(obj->GetPosX() + obj->GetSpdX());
	obj->SetPosY(obj->GetPosY() + obj->GetSpdY());
}

