//===========================================================
//
//ポリゴンを出すやつ[game.cpp]
//Author 大原怜将
//
//===========================================================
#include "game.h"
#include "input.h"
#include "sound.h"
#include "camera.h"
#include "object.h"
#include "debugproc.h"
#include "player.h"
#include "field.h"
#include "edit.h"

//================================================================
//静的メンバ変数
//================================================================
CChibi *CGame::m_PlayerChibi = NULL;
CFoot *CGame::m_PlayerFoot = NULL;
CPlayer *CGame::m_Player = NULL;
CEnemy *CGame::m_Enemy = NULL;
CCollision *CGame::m_Collision = NULL;
CMap *CGame::m_Map = NULL;
CPause *CGame::m_Pause = NULL;
CEdit *CGame::m_Edit = NULL;
bool CGame::m_bPause = false;

//===========================================================
//コンストラクタ
//===========================================================
CGame::CGame()
{
	m_bUse = false;
}

//===========================================================
//コンストラクタ
//===========================================================
CGame::CGame(CScene::MODE mode)
{
	m_bUse = false;
}

//===========================================================
//デストラクタ
//===========================================================
CGame::~CGame()
{

}

//===========================================================
//デストラクタ
//===========================================================
CGame *CGame::Create(void)
{
	CGame *pGame = NULL;

	if (pGame == NULL)
	{
		pGame = new CGame;

		pGame->Init();
	}

	return pGame;
}

//===========================================================
//初期化処理
//===========================================================
HRESULT CGame::Init(void)
{
	//カメラ取得
	CCamera *pCamera = CManager::GetCamera();

	pCamera->SetType(CCamera::TYPE_GAME);

	CField::Create();

	//チビ----------------------------------------------------------
	if (m_PlayerChibi == NULL)
	{//使用されていなかったら

	    //プレイヤーの生成
		m_PlayerChibi = new CChibi({ 0.0f, 0.0f, 0.0f });

		//初期化処理
		m_PlayerChibi->Init();
	}

	//クソデブ-----------------------------------------------------
	if (m_PlayerFoot == NULL)
	{//使用されていなかったら

		//プレイヤーの生成
		m_PlayerFoot = new CFoot({ 0.0f, 0.0f, 0.0f });

		//初期化処理
		m_PlayerFoot->Init();
	}

	//if (m_Player == NULL)
	//{//使用されていなかったら

	//	//プレイヤーの生成
	//	m_Player = new CPlayer({ 0.0f, 0.0f, 0.0f });

	//	//初期化処理
	//	m_Player->Init();
	//}

	CSound *pSound = CManager::GetSound();

	return S_OK;
}

//===========================================================
//終了処理
//===========================================================
void CGame::Uninit(void)
{
	CSound *pSound = CManager::GetSound();

	pSound->Stop();

	//プレイヤー(チビ)の破棄
	if (m_PlayerChibi != NULL)
	{
		//プレイヤーの終了処理
		m_PlayerChibi->Uninit();

		//使用していない状態にする
		m_PlayerChibi = NULL;
	}

	//プレイヤー(クソデブ)の破棄
	if (m_PlayerFoot != NULL)
	{
		//プレイヤーの終了処理
		m_PlayerFoot->Uninit();

		//使用していない状態にする
		m_PlayerFoot = NULL;
	}

	//プレイヤーの破棄
	if (m_Player != NULL)
	{
		//プレイヤーの終了処理
		m_Player->Uninit();

		//使用していない状態にする
		m_Player = NULL;
	}

	//エディットの破棄
	if (m_Edit != NULL)
	{//使用されていたとき

		//終了処理
		m_Edit->Uninit();

		//使用していない状態にする
		m_Edit = NULL;
	}

	//すべてのオブジェクト破棄
	CObject::ReleaseAll();
}

//===========================================================
//更新処理
//===========================================================
void CGame::Update(void)
{
	//キーボードを取得
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	//すべての更新処理
	CObject::UpdateAll();

	if (InputKeyboard->GetTrigger(DIK_F11) == true)
	{//F11を押した

		//trueとfalseが切り替わるよ
		m_bUse = m_bUse ? false : true;
	}

	if (m_bUse == true)
	{//真のとき

		if (m_Edit == NULL)
		{//使用されていなかったら

			//生成
			m_Edit = new CEdit;
			
			//初期化処理
			m_Edit->Init();
		}
	}

	if (m_bUse == false)
	{//偽のとき

		if (m_Edit != NULL)
		{//使用されていたとき

			//終了処理
			m_Edit->Uninit();

			//使用していない状態にする
			m_Edit = NULL;

			m_bUse = false;
		}
	}

	if (m_Edit != NULL)
	{//使用されていたら

		//更新処理
		m_Edit->Update();
	}

	CDebugProc *pDebugProc = CManager::GetDebugProc();

	pDebugProc->Print("\nシーン：ゲーム");
}

//===========================================================
//描画処理
//===========================================================
void CGame::Draw(void)
{
	
}

//================================================================
//プレイヤーの取得(チビ)
//================================================================
CChibi *CGame::GetPlayerChibi(void)
{
	return m_PlayerChibi;
}

//================================================================
//プレイヤーの取得(クソデブ)
//================================================================
CFoot *CGame::GetPlayerFoot(void)
{
	return m_PlayerFoot;
}

//================================================================
//プレイヤーの取得
//================================================================
CPlayer *CGame::GetPlayer(void)
{
	return m_Player;
}

//================================================================
//ポーズの取得
//================================================================
CPause *CGame::GetPause(void)
{
	return m_Pause;
}