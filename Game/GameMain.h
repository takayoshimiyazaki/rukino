//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  ゲーム関連のヘッダファイル
//!
//! @date   2017/4/5
//!
//! @author Yuhei M
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif

#define MAP_H 45
#define MAP_W 45

#define CHIP_SIZE 32
#define GRAVITY 0.98

#include <windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include "..\DirectXTK.h"
#include "..\Texture.h"

#include "..\ADX2Le.h"
#include "../CueSheet_0.h"

#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")

// 定数の定義 ==============================================================

// ゲームタイトル
#define GAME_TITLE "ゆめ☆ぴん"

// ゲーム画面
#define SCREEN_WIDTH  640    // 幅[pixel]
#define SCREEN_HEIGHT 480    // 高さ[pixel]

//マップチップの最大数
#define MAX_TIP 2025

//　構造体宣言
typedef struct tag_object
{
	Texture *handle;		//グラフィックハンドル 
	int grp_x;				//元画像のx座標 
	int grp_y;				//元画像のy座標 
	int grp_w;				//元画像の幅 
	int grp_h;				//元画像の高さ 
	float pos_x;			//座標x 
	float pos_y;			//座標y 
	float spd_x;			//速度x 
	float spd_y;			//速度y 
	int state;				//状態

}OBJECT;					//オブジェクト用

//　列挙型宣言
enum SCENE
{
	LOGO,
	TITLE,
	SERECT,
	PLAY,
	CLEAR,
	OVER
};

enum DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

// 関数の宣言 ==============================================================
// ゲームの初期化処理
void InitializeGame(void);

// ゲームの更新処理
void UpdateGame(void);

// ゲームの描画処理
void RenderGame(void);

// ゲームの終了処理
void FinalizeGame(void);

//　数値描画処理
void DrawNum(int x, int y, int n);



// グローバル変数の定義 ===================================================
EXTERN Texture *g_StageImage;			//　ステージ画像
EXTERN Texture *g_BlackImage;			// フェード用黒画像
EXTERN Texture *g_BackImage;			// 塔背景用画像
EXTERN Texture *g_BackImage2;			// 森背景用画像

// ステージセレクト用画像

EXTERN Texture *g_ForestStageImage;		//ステージイメージ（森）画像
EXTERN Texture *g_TowerStageImage;		//ステージイメージ（塔）画像

EXTERN Texture *g_StageSerect;			//ステージ選択画像

EXTERN Texture *g_PlayerImage;			//プレイヤー画像
EXTERN Texture *g_PlayerClothesPins;	//プレイヤの持つ洗濯ばさみ画像
EXTERN Texture *g_SBImage;			//ばさみ画像
EXTERN Texture *g_Spider;			//蜘蛛画像
EXTERN Texture *g_TitleImage;			// タイトル画面
EXTERN Texture *g_TowerClearImage;			//クリア画像
EXTERN Texture *g_ForestClearImage;			//クリア画像
EXTERN Texture *g_LogoImage;			//ロゴ画像
EXTERN Texture *g_OverImage;			//ゲームオーバー画像
EXTERN Texture *g_StateImage;			//状態画像
EXTERN Texture *g_JumpImage;
EXTERN Texture *g_YumePinImage;
EXTERN Texture *g_DreamSelectImage;




EXTERN Texture *g_FaceImage;			//クリア画像
EXTERN Texture *g_RopeImage ;			//ロープ画像
EXTERN Texture *g_SpaceImage;			//スペースボタンクリック画像
EXTERN Texture *g_TimeImage;//残り時間

EXTERN int g_map[MAP_H][MAP_W];			//	マップデータ// 塔[*5][等倍]
EXTERN OBJECT g_tip[MAX_TIP];		//　マップチップ
EXTERN OBJECT g_trap[MAX_TIP];		//　マップチップ

EXTERN int g_scene;					//シーン管理
EXTERN int g_NextScene;				//次のシーン
EXTERN int g_init;					//初期化管理
EXTERN int g_mousePoint;

EXTERN int serectMap;				//洗濯マップ
EXTERN int g_ScrollMap_x;			//画面スクロール量（X）
EXTERN int g_ScrollMap_y;			//画面スクロール量（Y）
