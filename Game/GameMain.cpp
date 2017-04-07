//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  メインのソースファイル
//!
//! @date   2017/4/5	
//!
//! @author Yuhei.M	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#define _GAMEMAIN_
#include "GameMain.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
//#include "..\ADX2Le.h"
//#include "..\CueSheet_0.h"
#include"GameClear.h"
#include"GameLogo.h"
#include"GameOver.h"
#include"GamePlay.h"
#include"GameTitle.h"
#include"GameSerect.h"

#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;



// プロトタイプ宣言 ====================================================
void importData(string filename);


// グローバル変数の定義 ====================================================
GameLogo logo;
GameTitle title;
GamePlay play;
GameClear clear;
GameOver over;
GameBase* base;

// 関数の定義 ==============================================================

//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void InitializeGame(void)
{
	base = new GameLogo();
	

	// 画像の読み込み 
	g_StageImage = new Texture(L"Resources\\Images\\StageImage.png");//ステージ画像
	g_BlackImage = new Texture(L"Resources\\Images\\black.png");//フェード用黒画像
	g_BackImage = new Texture(L"Resources\\Images\\back.png");//背景画像
	g_PlayerImage = new Texture(L"Resources\\Images\\player.png");//プレイヤー画像
	g_TitleImage = new Texture(L"Resources\\Images\\title.png");//タイトル画像
	g_ClearImage = new Texture(L"Resources\\Images\\CLEAR.png");//クリア画像
	g_LogoImage = new Texture(L"Resources\\Images\\logo.png");//ロゴ画像
	g_OverImage = new Texture(L"Resources\\Images\\OVER.png");//クリア画像

	g_SerectForestImage = new Texture(L"Resources\\Images\\Serect_Forest.png");
	g_SerectTowerImage = new Texture(L"Resources\\Images\\Serect_Tower.png");

	g_ForestStageImage = new Texture(L"Resources\\Images\\ForestStage.png");
	g_TowerStageImage = new Texture(L"Resources\\Images\\TowerStage.png");

	// 音の読み込み
	
	

	

	g_NextScene = g_scene;//シーン遷移
	g_init = 0;
}



//----------------------------------------------------------------------
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void UpdateGame(void)
{
	// シーン管理
	if (g_scene != g_NextScene)
	{
		g_scene = g_NextScene;
		// シーン削除
		delete base;
		 // シーン生成
		switch (g_scene)
		{
		case LOGO:
			base = new GameLogo();
			break;
		case TITLE:
			base = new GameTitle();
			break;
		case SERECT:
			base = new GameSerect();
			break;
		case PLAY:
			base = new GamePlay();
			break;
		case CLEAR:
			base = new GameClear();
			break;
		case OVER:
			base = new GameOver();
			break;
		}
		g_init = 0;
	}


	base->Update();
}



//----------------------------------------------------------------------
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void RenderGame(void)
{	
	wchar_t buf[256];

	base->Render();
}



//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void FinalizeGame(void)
{
	/*ADX2Le::Finalize();*/
}


//----------------------------------------------------------------------
//! @brief 数値描画処理
//!
//! @param[in] xy座標，数値w
//!
//! @return なし
//----------------------------------------------------------------------
void DrawNum(int x, int y, int n)
{
	int w = n;		// 計算用
	int i = 0;		// 文字数

	if (w == 0)
	{
	}
	else
	{
		while (w)
		{
			w = w / 10;
			i++;
		}
	}

}


//test1