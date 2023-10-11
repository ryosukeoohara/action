//===========================================================
//
//ポリゴンを出すやつ[player.cpp]
//Author 大原怜将
//
//===========================================================
#include "main.h"
#include "player.h"
#include "renderer.h"
#include "manager.h"
#include "input.h"
#include "sound.h"
#include "debugproc.h"
#include "texture.h"
#include "motion.h"
#include "camera.h"
#include "game.h"
#include "fade.h"
#include "character.h"
#include "bullet.h"
#include "effect.h"
#include "particl.h"
#include "map.h"
#include "collision.h"

#include<stdio.h>
#include<time.h>
#include<string.h>

//静的メンバ変数
//bool CChibi::m_bDisp = false;
//bool CChibi::m_bAppr = false;
//
//bool CFoot::m_bDisp = false;
//bool CFoot::m_bAppr = false;

//================================================================
//マクロ定義
//================================================================
#define MAX_LIFE    (10)                                          //プレイヤーの体力
#define REST_BULLET (6)                                           //保持できる弾の数
#define MUTEKITIME  (30)                                          //無敵時間
#define PLAYER_X    (40.0f)                                       //プレイヤーのX軸の幅
#define PLAYER_Z    (10.0f)                                       //プレイヤーのZ軸の幅
#define FRIST       (21)                                          //攻撃判定発生開始
#define FINISH      (31)                                          //攻撃判定終了
#define PLAYER01_TEXT ("data\\TEXT\\motion_set_player.txt")       //プレイヤーのテキストファイル
#define PLAYER02_TEXT ("data\\TEXT\\motion_set_player2.txt")      //プレイヤーのテキストファイル

//================================================================
//静的メンバ変数宣言
//================================================================
//MODEL *CPlayer::m_Player = NULL;

//================================================================
//コンストラクタ
//================================================================
CPlayer::CPlayer()
{
	/*ZeroMemory(m_Chibi, sizeof(CChibi));
	ZeroMemory(m_Foot, sizeof(CFoot));*/
	m_move = { 0.0f, 0.0f, 0.0f };  //移動量
	m_Readpos = { 0.0f, 0.0f, 0.0f };
	m_Readrot = { 0.0f, 0.0f, 0.0f };
	//m_rot = { 0.0f, 0.0f, 0.0f };
	
	m_nCnterMotion = 0;
	m_nCntMotion = 0;
	m_nCntEff = 0;
	m_nCntDuration = 0;
	m_nCntDie = 0;
	m_nCntSound = 0;
	m_nIdxTexture = -1;
	m_nIdxShaadow = -1;
	m_nLifeGage = -1;
	m_RestBullet = 0;
	m_ApprCharcter = 0;
	m_motion = NULL;
	m_fDiff = 0.0f;
	m_fDest = 0.0f;
	m_bDash = false;
	m_bJump = false;
	m_bAction = false;
	/*m_bDisp = false;
	m_bAppr = false;*/
	m_bEncounter = false;
	m_bIconDisp = false;
	m_bAcFir = false;
	m_bAcSec = false;
	m_bAcThr = false;

	m_bPushW = false;
	m_bPushA = false;
	m_bPushS = false;
	m_bPushD = false;
	m_bAttack = false;
	m_bAvoi = false;
	m_bWhee = false;
}

//================================================================
//コンストラクタ(オーバーロード)
//================================================================
CPlayer::CPlayer(D3DXVECTOR3 pos)
{
	/*ZeroMemory(m_Chibi, sizeof(CChibi));
	ZeroMemory(m_Foot, sizeof(CFoot));*/
	SetPos(&pos);  //位置
	SetRot(&D3DXVECTOR3(0.0f, 1.57f, 0.0f));
	m_move = {0.0f, 0.0f, 0.0f};  //移動量
	m_Readpos = { 0.0f, 0.0f, 0.0f };
	m_Readrot = { 0.0f, 0.0f, 0.0f };
	m_nCnterMotion = 0;
	m_nCntMotion = 0;
	m_nCntEff = 0;
	m_nCntDuration = 0;
	m_nCntDie = 0;
	m_nCntSound = 0;
	m_nIdxTexture = -1;
	m_nIdxShaadow = -1;
	m_nLifeGage = -1;
	m_RestBullet = 0;
	m_ApprCharcter = 0;
	m_motion = NULL;
	m_fDiff = 0.0f;
	m_fDest = 0.0f;
	m_bDash = false;
	m_bJump = false;
	m_bAction = false;
	/*m_bDisp = false;
	m_bAppr = false;*/
	m_bEncounter = false;
	m_bIconDisp = false;
	m_bAcFir = false;
	m_bAcSec = false;
	m_bAcThr = false;

	m_bPushW = false;
	m_bPushA = false;
	m_bPushS = false;
	m_bPushD = false;
	m_bAttack = false;
	m_bAvoi = false;
	m_bWhee = false;
}

//================================================================
//デストラクタ
//================================================================
CPlayer::~CPlayer()
{

}

//================================================================
//生成処理
//================================================================
CPlayer *CPlayer::Create(D3DXVECTOR3 pos)
{
	//オブジェクト2Dのポインタ
	CPlayer *pPlayer = NULL;

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pPlayer == NULL)
		{
			//オブジェクト2Dの生成
			pPlayer = new CPlayer(pos);

			//初期化処理
			pPlayer->Init();
		}
	}

	return pPlayer;
}

//================================================================
//プレイヤーの初期化処理
//================================================================
HRESULT CPlayer::Init(void)
{
	//テクスチャの情報取得
	CTexture *pTexture = CManager::GetTexture();

	//シーンの情報を取得
	CScene *pScene = CManager::GetScene();

	//影の情報を取得
	//CShadow *pShadow = CGame::GetShadow();

	D3DXVECTOR3 pos = Getpos();

	//種類設定
	SetType(TYPE_PLAYER);

	//if (m_pShadow == NULL)
	//{
	//	m_pShadow = new CShadow(pos);

	//	//初期化処理
	//	m_pShadow->Init();
	//}

	SetLife(MAX_LIFE);

	m_RestBullet = REST_BULLET;

	m_fDest = 1.57f;

	return S_OK;
}

//================================================================
//プレイヤーの終了処理
//================================================================
void CPlayer::Uninit(void)
{
	//サウンドの情報を取得
	CSound *pSound = CManager::GetSound();

	//サウンドストップ
	pSound->Stop();

	if (m_motion != NULL)
	{
		//終了処理
		m_motion->Uninit();

		delete m_motion;

		m_motion = NULL;
	}

	//if (m_pShadow != NULL)
	//{
	//	//終了処理
	//	m_pShadow->Uninit();

	//	m_pShadow = NULL;
	//}

	//プレイヤー(チビ)の破棄
	if (m_Chibi != NULL)
	{
		//使用していない状態にする
		m_Chibi = NULL;
	}

	//プレイヤー(クソデブ)の破棄
	if (m_Foot != NULL)
	{
		//使用していない状態にする
		m_Foot = NULL;
	}

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{//使用していたら

			m_apModel[nCount]->Uninit();  //終了処理
			//delete m_apModel[nCount];  //メモリを開放
			m_apModel[nCount] = NULL;  //使用していない状態にする
		}
	}

	CObject::Release();
}

//================================================================
//プレイヤーの更新処理
//================================================================
void CPlayer::Update(void)
{
	//キーボードの情報を取得
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	//フェードの情報を取得
	CFade *pFade = CManager::GetFade();

	//シーンの情報を取得
	CScene *pScene = CManager::GetScene();

	//プレイヤー(クソデブ)の情報を取得
	CFoot *pFoot = CGame::GetPlayerFoot();

	//プレイヤー(チビデブ)の情報を取得
	CChibi *pChibi = CGame::GetPlayerChibi();

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		m_apModel[nCount]->Update();
	}

	if (m_motion != NULL)
	{
		//初期化処理
		m_motion->Update();
	}

	if (InputKeyboard->GetTrigger(DIK_SPACE) == true && pFoot->GetState() != CFoot::STATE_APPR && pChibi->GetState() != CChibi::STATE_APPR
	 && pFoot->GetState() != CFoot::STATE_JUMP && pChibi->GetState() != CChibi::STATE_JUMP)
	{//SPACEキーが押された

		if (pChibi->GetbAppr() == false)
		{
			pChibi->SetbDisp(true);
		}

		if (pFoot->GetbAppr() == false)
		{
			pFoot->SetbDisp(true);
		}

		pChibi->SetState(STATE_APPR);
		pFoot->SetState(STATE_APPR);

		m_ApprCharcter = m_ApprCharcter ? 0 : 1;

   		Appear();

		if (m_ApprCharcter == 0)
		{
			pChibi->SetbDisp(false);
			pChibi->SetbAppr(false);

			pFoot->SetbAppr(true);

			pFoot->SetPos(&pChibi->Getpos());
			pFoot->SetRot(&pChibi->GetRot());
		}
		else
		{
			pFoot->SetbDisp(false);
			pFoot->SetbAppr(false);

			pChibi->SetbAppr(true);

			pChibi->SetPos(&pFoot->Getpos());
			pChibi->SetRot(&pFoot->GetRot());
		}

		//pChibi->SetState(STATE_NONE);
		//pFoot->SetState(STATE_NONE);

 		CParticl::Create(pFoot->Getpos(), { 0.0f,0.0f,0.0f }, { 1.0f,1.0f,1.0f,1.0f }, 10.0f, CParticl::TYPEPAR_CIRCLE);
	}
}

//================================================================
//プレイヤーの描画処理
//================================================================
void CPlayer::Draw(void)
{
	CTexture *pTexture = CManager::GetTexture();
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	D3DXVECTOR3 pos = Getpos();
	D3DXVECTOR3 rot = GetRot();

	//計算用マトリックス
	D3DXMATRIX m_mtxRot, m_mtxTrans;

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&m_mtxRot, rot.y, rot.x, rot.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &m_mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&m_mtxTrans, pos.x, pos.y, pos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &m_mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		//描画処理
		m_apModel[nCount]->Draw();
	}
}

//================================================================
//プレイヤーの制御処理
//================================================================
void CPlayer::ControlPlayer(void)
{
	//プレイヤー(クソデブ)の情報を取得
	CFoot *pFoot = CGame::GetPlayerFoot();

	//プレイヤー(チビデブ)の情報を取得
	CChibi *pChibi = CGame::GetPlayerChibi();

	if (pChibi->GetbAppr() == true)
	{
		//チビデブの制御
		pChibi->Control();
	}

	if (pFoot->GetbAppr() == true)
	{
		//クソデブの制御
		pFoot->Control();
	}
}

//================================================================
//プレイヤーの制御処理(チビデブ)
//================================================================
void CChibi::Control(void)
{
	//デバッグプロックの情報を取得
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	//キーボードを取得
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	//マウスを取得
	CInputMouse *pInputMouse = CManager::GetInputMouse();

	//マウスの位置を取得
	D3DXVECTOR2 MousePos = pInputMouse->GetMouseMove();

	//サウンドを取得
	CSound *pSound = CManager::GetSound();

	//カメラ取得
	CCamera *pCamera = CManager::GetCamera();

	//カメラの向き取得
	D3DXVECTOR3 CameraRot = pCamera->GetRot();

	//プレイヤー(チビデブ)の情報を取得
	CChibi *pChibi = CGame::GetPlayerChibi();

	//プレイヤー(クソデブ)の情報を取得
	CFoot *pFoot = CGame::GetPlayerFoot();

	//位置と向きを取得
	D3DXVECTOR3 Playerpos = pChibi->Getpos();
	D3DXVECTOR3 PlayerRot = pChibi->GetRot();

	m_posOld = Playerpos;  //位置を代入
	m_move.y -= 1.5f;   //重力

	//走っていない状態
	m_bDash = false;

	//float fHeight;

	if (m_State != STATE_ATTACK && m_State != STATE_APPR)
	{
		//上に移動----------------------------------------------
		if (InputKeyboard->GetPress(DIK_W) == true)
		{//Wキーが押された

		}
		//下に移動----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_S) == true)
		{//Sキーが押された

		}
		//右に移動----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_D) == true)
		{//Dキーだけ押した

		 //移動量
			m_move.x += sinf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;
			m_move.z += cosf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;

			//向き
			m_fDest = (CameraRot.y + (D3DX_PI * -0.5f));

			//走っている状態にする
			m_bDash = true;
		}
		//左に移動----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_A) == true)
		{//Aキーだけ押した

		 //移動量
			m_move.x -= sinf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;
			m_move.z -= cosf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;

			//向き
			m_fDest = (CameraRot.y + (D3DX_PI * 0.5f));

			//走っている状態にする
			m_bDash = true;
		}

		m_fDiff = m_fDest - PlayerRot.y;

		//角度の値を修正する
		if (m_fDiff >= D3DX_PI)
		{
			m_fDiff -= D3DX_PI * 2;
		}
		else if (m_fDiff <= -D3DX_PI)
		{
			m_fDiff += D3DX_PI * 2;
		}

		//移動方向(角度)の補正------------------------------------------------
		PlayerRot.y += m_fDiff * 0.15f;

		//角度の値を修正する--------------------------------------------------
		if (PlayerRot.y > D3DX_PI)
		{
			PlayerRot.y = -D3DX_PI;
		}
		else if (PlayerRot.y < -D3DX_PI)
		{
			PlayerRot.y = D3DX_PI;
		}

		if (InputKeyboard->GetTrigger(DIK_J) == true && m_bJump == false)
		{//SPACEキーが押された

			m_bJump = true;

			m_move.y += 20.0f;
		}

		//位置に移動量加算----------------------------------------------------
		Playerpos.x += m_move.x;
		Playerpos.y += m_move.y;
		//m_pos.y = fHeight + 18.0f;

		//移動量を更新(減衰させる)--------------------------------------------
		m_move.x += (0.0f - m_move.x) * 0.1f;

		if (InputKeyboard->GetPress(DIK_K) == true)
		{//Kキーが押された

			m_State = STATE_ATTACK;

			CBullet::Create(D3DXVECTOR3(Playerpos.x, Playerpos.y + 60.0f, Playerpos.z), D3DXVECTOR3(0.0f, m_fDest, 0.0f), CBullet::TYPE_PLAYER);
		}

		if (m_bDash == true && m_State != STATE_MOVE && m_State != STATE_ATTACK)
		{
			//モーションをセット(移動)
			m_motion->Set(MOTIONTYPE_MOVE);

			m_State = STATE_MOVE;

			m_bAction = false;
		}

		if (m_bDash == false && m_State != STATE_NEUTRAL && m_State != STATE_ATTACK && m_State != STATE_APPR)
		{
			//モーションをセット(移動)
			m_motion->Set(MOTIONTYPE_NEUTRAL);

			m_State = STATE_NEUTRAL;

			m_bAction = false;
		}

		if (m_bJump == true && m_State != STATE_JUMP)
		{
			//モーションをセット(移動)
			m_motion->Set(MOTIONTYPE_JUMP);

			m_State = STATE_JUMP;
		}

		if (m_bAction == false && m_State == STATE_ATTACK)
		{
			//モーションをセット(攻撃)
			m_motion->Set(MOTIONTYPE_ATTACK);

			m_bAction = true;
		}
	}
	
	if (m_State == STATE_APPR && m_WaitApper == false)
	{
		//モーションをセット(出現待ち)
		m_motion->Set(MOTIONTYPE_APPR);

		PlayerRot.y = 0.0f;

		m_WaitApper = true;
	}

	if (m_motion->IsFinish() == true)
	{
		m_nCntEff = 0;
		m_nCntColi = 0;
		m_bAction = false;

		if (m_State == STATE_APPR)
		{
			m_WaitApper = false;

			pChibi->SetState(STATE_NONE);
			pFoot->SetState(STATE_NONE);
		}
		else
		{
			m_State = STATE_NONE;
		}
	}

	if (Playerpos.y <= 0.0f)
	{
		Playerpos.y = 0.0f;

		m_move.y = 0.0f;

		m_bJump = false;
	}

	SetPos(&Playerpos);
	SetRot(&PlayerRot);

	pDebugProc->Print("プレイヤーの位置：%f,%f,%f\n", Playerpos.x, Playerpos.y, Playerpos.z);
	pDebugProc->Print("プレイヤーの向き：%f,%f,%f\n", PlayerRot.x, PlayerRot.y, PlayerRot.z);
	pDebugProc->Print("プレイヤーの移動量：%f,%f,%f", m_move.x, m_move.y, m_move.z);
}

//================================================================
//プレイヤーの制御処理(クソデブ)
//================================================================
void CFoot::Control(void)
{
	//デバッグプロックの情報を取得
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	//キーボードを取得
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	//マウスを取得
	CInputMouse *pInputMouse = CManager::GetInputMouse();

	//マウスの位置を取得
	D3DXVECTOR2 MousePos = pInputMouse->GetMouseMove();

	//サウンドを取得
	CSound *pSound = CManager::GetSound();

	//カメラ取得
	CCamera *pCamera = CManager::GetCamera();

	//カメラの向き取得
	D3DXVECTOR3 CameraRot = pCamera->GetRot();

	//プレイヤー(チビデブ)の情報を取得
	CFoot *pFoot = CGame::GetPlayerFoot();

	//プレイヤー(チビデブ)の情報を取得
	CChibi *pChibi = CGame::GetPlayerChibi();

	//位置と向きを取得
	D3DXVECTOR3 Playerpos = pFoot->Getpos();
	D3DXVECTOR3 PlayerRot = pFoot->GetRot();

	m_posOld = Playerpos;  //位置を代入
	m_move.y -= 1.5f;	   //重力

	//走っていない状態
	m_bDash = false;

	//float fHeight;

	if (m_State != STATE_ATTACK && m_State != STATE_APPR)
	{
		//上に移動----------------------------------------------
		if (InputKeyboard->GetPress(DIK_W) == true)
		{//Wキーが押された

		}
		//下に移動----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_S) == true)
		{//Sキーが押された

		}
		//右に移動----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_D) == true)
		{//Dキーだけ押した

		 //移動量
			m_move.x += sinf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;
			m_move.z += cosf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;

			//向き
			m_fDest = (CameraRot.y + (D3DX_PI * -0.5f));

			//走っている状態にする
			m_bDash = true;
		}
		//左に移動----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_A) == true)
		{//Aキーだけ押した

		 //移動量
			m_move.x -= sinf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;
			m_move.z -= cosf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;

			//向き
			m_fDest = (CameraRot.y + (D3DX_PI * 0.5f));

			//走っている状態にする
			m_bDash = true;
		}

		m_fDiff = m_fDest - PlayerRot.y;

		//角度の値を修正する
		if (m_fDiff >= D3DX_PI)
		{
			m_fDiff -= D3DX_PI * 2;
		}
		else if (m_fDiff <= -D3DX_PI)
		{
			m_fDiff += D3DX_PI * 2;
		}

		//移動方向(角度)の補正------------------------------------------------
		PlayerRot.y += m_fDiff * 0.15f;

		//角度の値を修正する--------------------------------------------------
		if (PlayerRot.y > D3DX_PI)
		{
			PlayerRot.y = -D3DX_PI;
		}
		else if (PlayerRot.y < -D3DX_PI)
		{
			PlayerRot.y = D3DX_PI;
		}

		if (InputKeyboard->GetTrigger(DIK_J) == true && m_bJump == false)
		{//SPACEキーが押された

			m_bJump = true;

			m_move.y += 20.0f;
		}

		//位置に移動量加算----------------------------------------------------
		Playerpos.x += m_move.x;
		Playerpos.y += m_move.y;
		//m_pos.y = fHeight + 18.0f;

		//移動量を更新(減衰させる)--------------------------------------------
		m_move.x += (0.0f - m_move.x) * 0.1f;
		m_move.z += (0.0f - m_move.z) * 0.1f;

		if (InputKeyboard->GetTrigger(DIK_K) == true)
		{//Kキーが押された

			m_State = STATE_ATTACK;
		}

		if (m_bDash == true && m_State != STATE_MOVE && m_State != STATE_ATTACK)
		{
			//モーションをセット(移動)
			m_motion->Set(MOTIONTYPE_MOVE);

			m_State = STATE_MOVE;

			m_bAction = false;
		}

		if (m_bDash == false && m_State != STATE_NEUTRAL && m_State != STATE_ATTACK && m_State != STATE_APPR)
		{
			//モーションをセット(移動)
			m_motion->Set(MOTIONTYPE_NEUTRAL);

			m_State = STATE_NEUTRAL;

			m_bAction = false;
		}

		if (m_bJump == true && m_State != STATE_JUMP)
		{
			//モーションをセット(移動)
			m_motion->Set(MOTIONTYPE_JUMP);

			m_State = STATE_JUMP;
		}

		if (m_bAction == false && m_State == STATE_ATTACK)
		{
			//モーションをセット(攻撃)
			m_motion->Set(MOTIONTYPE_ATTACK);

			m_bAction = true;
		}
	}

	if (m_State == STATE_APPR && m_WaitApper == false)
	{
		//モーションをセット(出現待ち)
		m_motion->Set(MOTIONTYPE_APPR);

		PlayerRot.y = 0.0f;

		m_WaitApper = true;
	}

	if (m_motion->IsFinish() == true)
	{
		m_nCntEff = 0;
		m_nCntColi = 0;
		m_bAction = false;

		if (m_State == STATE_APPR)
		{
			m_WaitApper = false;

			pChibi->SetState(STATE_NONE);
			pFoot->SetState(STATE_NONE);
		}
		else
		{
			m_State = STATE_NONE;
		}
	}

	if (Playerpos.y <= 0.0f)
	{
		Playerpos.y = 0.0f;

		m_move.y = 0.0f;

		m_bJump = false;
	}

	SetPos(&Playerpos);
	SetRot(&PlayerRot);

	pDebugProc->Print("プレイヤーの位置：%f,%f,%f\n", Playerpos.x, Playerpos.y, Playerpos.z);
	pDebugProc->Print("プレイヤーの向き：%f,%f,%f\n", PlayerRot.x, PlayerRot.y, PlayerRot.z);
	pDebugProc->Print("プレイヤーの移動量：%f,%f,%f", m_move.x, m_move.y, m_move.z);
}

//================================================================
//出現処理
//================================================================
void CPlayer::Appear(void)
{
	//プレイヤー(クソデブ)の情報を取得
	CFoot *pFoot = CGame::GetPlayerFoot();

	//プレイヤー(チビデブ)の情報を取得
	CChibi *pChibi = CGame::GetPlayerChibi();

	//それぞれの位置取得
	D3DXVECTOR3 Chibipos = pChibi->Getpos();
	D3DXVECTOR3 Footpos = pFoot->Getpos();

	if (pChibi->GetState() == STATE_APPR && pChibi->GetbAppr() == true)
	{
		pChibi->SetMove({ -0.1f, 0.0f , 0.0f });
	}
	else if (pChibi->GetState() == STATE_APPR && pChibi->GetbAppr() == false)
	{
		pChibi->SetMove({ 0.1f, 0.0f , 0.0f });
	}

	if (pFoot->GetState() == STATE_APPR && pFoot->GetbAppr() == false)
	{
		pFoot->SetMove({ 0.1f, 0.0f , 0.0f });
	}
	else if (pFoot->GetState() == STATE_APPR && pFoot->GetbAppr() == true)
	{
		pFoot->SetMove({ -0.1f, 0.0f , 0.0f });
	}

	Chibipos.x += pChibi->GetMove().x;
	Footpos.x += pFoot->GetMove().x;

	pChibi->SetPos(&Chibipos);
	pFoot->SetPos(&Footpos);
}

//================================================================
//チュートリアルのプレイヤーの制御処理
//================================================================
void CPlayer::ControlTutorial(void)
{
	
}

//================================================================
//攻撃くらった時の処理
//================================================================
void CPlayer::Hit(void)
{
	
}

//================================================================
//外部ファイル読み込み
//================================================================
void CPlayer::ReadText(const char *fliename)
{
	char aString[128] = {};
	char aComment[128] = {};
	int nCntParts = 0, nCntParts2 = 0, nCntParts3 = 0;
	int nCntMotion = 0;
	int nCntKeySet = 0;
	int nCntKey = 0;
	int nCntModel = 0;
	int nCntMotionIdx = 0;

	//テクスチャの情報取得
	CTexture *pTexture = CManager::GetTexture();

	FILE *pFile;   //ファイルポインタを宣言

	pFile = fopen(fliename, "r");

	if (pFile != NULL)
	{//ファイルを開けた場合

		fscanf(pFile, "%s", &aString[0]);

		if (strcmp("SCRIPT", aString) == 0)
		{
			while (strcmp("END_SCRIPT", aString) != 0)
			{
				fscanf(pFile, "%s", &aString[0]);

				if (strcmp("NUM_MODEL", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%d", &m_nNumModel);  //モデルの総数

				}  //NUM_MODELのかっこ

				if (strcmp("MODEL_FILENAME", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%s", &m_filename[0]);  //モデルの名前

					m_apModel[nCntModel] = CCharacter::Create(m_filename);
					nCntModel++;

					nCntParts++;

				}  //MODEL_LILENAMEのかっこ


				if (strcmp("CHARACTERSET", aString) == 0)
				{
					while (strcmp("END_CHARACTERSET", aString) != 0)
					{
						fscanf(pFile, "%s", &aString);

						if (strcmp("PARTSSET", aString) == 0)
						{
							while (strcmp("END_PARTSSET", aString) != 0)
							{
								fscanf(pFile, "%s", &aString);

								if (strcmp("INDEX", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);          //=
									fscanf(pFile, "%d", &m_nIdx);  //モデルの番号
								}

								if (strcmp("PARENT", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);          //=
									fscanf(pFile, "%d", &m_nParent);  //親モデルの番号

									if (m_nParent > -1 && m_nNumModel > m_nParent)
									{
										m_apModel[nCntParts2]->SetParent(m_apModel[m_nParent]);
									}
									else
									{
										m_apModel[nCntParts2]->SetParent(NULL);
									}
								}

								if (strcmp("POS", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);      //=
									fscanf(pFile, "%f", &m_Readpos.x);  //モデルの総数
									fscanf(pFile, "%f", &m_Readpos.y);  //モデルの総数
									fscanf(pFile, "%f", &m_Readpos.z);  //モデルの総数

									m_apModel[nCntParts2]->SetPositionOri(m_Readpos);

									m_apModel[nCntParts2]->SetPosition(m_Readpos);
								}

								if (strcmp("ROT", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);      //=
									fscanf(pFile, "%f", &m_Readrot.x);  //モデルの総数
									fscanf(pFile, "%f", &m_Readrot.y);  //モデルの総数
									fscanf(pFile, "%f", &m_Readrot.z);  //モデルの総数

									m_apModel[nCntParts2]->SetRotOrigin(m_Readrot);

									m_apModel[nCntParts2]->SetRot(m_Readrot);
								}

							}//END_PARTSSETのかっこ

							nCntParts2++;

						}//PARTSSETのかっこ

					}//END_CHARACTERSETのかっこ 

				}//CHARACTERSETのかっこ 
			}
		}

		//ファイルを閉じる
		fclose(pFile);
	}
	else
	{
		return;
	}

	if (m_motion != NULL)
	{
		//モデルの設定
		m_motion->SetModel(&m_apModel[0], m_nNumModel);

		//初期化処理
		m_motion->ReadText(fliename);
	}
}

//******************************************************************************************************************************************************
//チビデブ
//******************************************************************************************************************************************************
//=======================================================
//コンストラクタ
//=======================================================
CChibi::CChibi()
{
	m_State = STATE_NONE;
	m_move = { 0.0f,0.0f,0.0f };
}

//=======================================================
//コンストラクタ
//=======================================================
CChibi::CChibi(D3DXVECTOR3 pos)
{
	SetPos(&pos);  //位置
	SetRot(&D3DXVECTOR3(0.0f, 1.57f, 0.0f));
	m_move = { 0.0f,0.0f,0.0f };
	m_State = STATE_NONE;
}

//=======================================================
//デストラクタ
//=======================================================
CChibi::~CChibi()
{

}

//=======================================================
//初期化処理
//=======================================================
HRESULT CChibi::Init(void)
{
	CPlayer::Init();

	if (m_motion == NULL)
	{
		m_motion = new CMotion;

		//初期化処理
		m_motion->Init();
	}

	CPlayer::ReadText(PLAYER02_TEXT);

	SetbDisp(false);
	SetbAppr(false);

	return S_OK;
}

//=======================================================
//終了処理
//=======================================================
void CChibi::Uninit(void)
{
	CPlayer::Uninit();
}

//=======================================================
//更新処理
//=======================================================
void CChibi::Update(void)
{
	//マップモデルの情報を取得
	CObjectX **pMap = CMap::GetX();

	//当たり判定の情報取得
	CCollision *pCollision = CGame::GetCollsion();

	CPlayer::Update();

	if (m_bAppr == true)
	{
		Control();

		if (pCollision != NULL && pMap != NULL)
		{
			if (pCollision->Map(&Getpos(), &m_posOld, pMap) == true)
			{
				m_bJump = false;
				m_move.y = 0.0f;
			}
		}
	}
}

//=======================================================
//描画処理
//=======================================================
void CChibi::Draw(void)
{
	if (m_bDisp == true)
	{
		CPlayer::Draw();
	}
}
//******************************************************************************************************************************************************
//クソデブ
//******************************************************************************************************************************************************
//=======================================================
//コンストラクタ
//=======================================================
CFoot::CFoot()
{
	m_move = { 0.0f,0.0f,0.0f };
	m_State = STATE_NONE;
}

//=======================================================
//コンストラクタ
//=======================================================
CFoot::CFoot(D3DXVECTOR3 pos)
{
	SetPos(&pos);  //位置
	SetRot(&D3DXVECTOR3(0.0f, 1.57f, 0.0f));
	m_move = { 0.0f,0.0f,0.0f };
	m_State = STATE_NONE;
}

//=======================================================
//デストラクタ
//=======================================================
CFoot::~CFoot()
{

}

//=======================================================
//初期化処理
//=======================================================
HRESULT CFoot::Init(void)
{
	CPlayer::Init();

	if (m_motion == NULL)
	{
		m_motion = new CMotion;

		//初期化処理
		m_motion->Init();
	}

	CPlayer::ReadText(PLAYER01_TEXT);

	SetbDisp(true);
	SetbAppr(true);
	
	return S_OK;
}

//=======================================================
//終了処理
//=======================================================
void CFoot::Uninit(void)
{
	CPlayer::Uninit();
}

//=======================================================
//更新処理
//=======================================================
void CFoot::Update(void)
{
	//マップモデルの情報を取得
	CObjectX **pMap = CMap::GetX();

	//当たり判定の情報取得
	CCollision *pCollision = CGame::GetCollsion();

	CPlayer::Update();

	if (m_bAppr == true)
	{
		Control();

		if (pCollision != NULL && pMap != NULL)
		{
			if (pCollision->Map(&Getpos(), &m_posOld, pMap) == true)
			{
				m_bJump = false;
				m_move.y = 0.0f;
			}
		}
	}
}

//=======================================================
//描画処理
//=======================================================
void CFoot::Draw(void)
{
	if (m_bDisp == true)
	{
		CPlayer::Draw();
	}
}