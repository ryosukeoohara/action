//=============================================================================
//
// 敵の処理 [enemyfar.h]
// Author : 大原　怜将
//
//=============================================================================

//*============================================================================
//インクルードファイル
//*============================================================================
#include "enemyfar.h"

////================================================================
////コンストラクタ
////================================================================
//CEnemyFar::CEnemyFar()
//{
//	m_state = STATE_NONE;
//	m_move = { 0.0f, 0.0f, 0.0f };  //移動量
//	m_rot = { 0.0f, 0.0f, 0.0f };   //向き
//	m_nNumModel = 0;
//	m_nNumPatrol = 0;
//	m_nCurrentpos = 0;
//	m_nCntAction = 0;
//	m_nNumAll = 0;
//	m_nCntDeath = 0;
//	m_nCntReload = 0;
//	m_DeathEnemyIdx = 0;
//	m_nIdxTexture = -1;
//	m_Tracking = false;
//	m_bAction = false;
//	m_bBom = false;
//}
//
////================================================================
////コンストラクタ(オーバーロード)
////================================================================
//CEnemyFar::CEnemyFar(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
//{
//	SetPos(&pos);  //位置設定
//	SetRot(&rot);  //向き設定
//	m_state = STATE_NONE;
//	m_move = { 0.0f, 0.0f, 0.0f };  //移動量
//	m_nNumModel = 0;
//	m_nNumPatrol = 0;
//	m_nCurrentpos = 0;
//	m_nCntAction = 0;
//	m_nNumAll = 0;
//	m_nCntDeath = 0;
//	m_nCntReload = 0;
//	m_DeathEnemyIdx = 0;
//	m_nIdxTexture = -1;
//	m_Tracking = false;
//	m_bAction = false;
//	m_bBom = false;
//}
//
////================================================================
////デストラクタ
////================================================================
//CEnemyFar::~CEnemyFar()
//{
//
//}
//
////================================================================
////生成処理
////================================================================
//CEnemyFar *CEnemyFar::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
//{
//	//オブジェクト2Dのポインタ
//	CEnemyFar *pEnemy = NULL;
//
//	if (CObject::GetNumAll() < MAX_OBJECT)
//	{
//		if (pEnemy == NULL)
//		{
//			//オブジェクト2Dの生成
//			pEnemy = new CEnemyFar(pos, rot);
//
//			//初期化処理
//			pEnemy->Init();
//
//			for (int nCount = 0; nCount < MAX_ENEMY; nCount++)
//			{
//				if (m_Enemy[nCount] == NULL)
//				{
//					m_Enemy[nCount] = pEnemy;
//
//					m_Enemy[nCount]->SetType(TYPE_FAR);
//
//					m_Enemy[nCount]->SetNumber(nCount);
//
//					int nNumEnemyWeak = CEnemyManager::GetNumEneWeak();
//
//					nNumEnemyWeak++;
//
//					CEnemyManager::SetNumEneWeak(nNumEnemyWeak);
//
//					int nNumAll = CEnemyManager::GetNumAll();
//
//					nNumAll++;
//
//					CEnemyManager::SetNumAll(nNumAll);
//
//					break;
//				}
//			}
//		}
//	}
//
//	return pEnemy;
//}
//
////================================================================
////初期化処理
////================================================================
//HRESULT CEnemyFar::Init(void)
//{
//	CTexture *pTexture = CManager::GetTexture();
//
//	D3DXVECTOR3 pos = Getpos();
//
//	//影の情報を取得
//	CShadow *pShadow = CGame::GetShadow();
//
//	//m_nIdxShaadow = pShadow->Set(pos);
//
//	m_type = TYPE_FAR;
//
//	if (m_motion == NULL)
//	{
//		m_motion = new CMotion;
//
//		//初期化処理
//		m_motion->Init();
//	}
//
//	//体力
//	SetLife(ENEMY_LIFE);
//
//	CEnemy::Init();
//
//	//テキストファイル読み込み
//	CEnemy::ReadText(ENEMYFAR_TEXT);
//
//	//テキストファイル読み込み
//	m_motion->ReadText(ENEMYFAR_TEXT);
//
//	//モデルの設定
//	m_motion->SetModel(&m_apModel[0], m_nNumModel);
//
//	return S_OK;
//}
//
////================================================================
////終了処理
////================================================================
//void CEnemyFar::Uninit(void)
//{
//	CEnemy::Uninit();
//
//	//CObject::Release();
//}
//
////================================================================
////更新処理
////================================================================
//void CEnemyFar::Update(void)
//{
//	Control();
//
//	CEnemy::Update();
//}
//
////================================================================
////描画処理
////================================================================
//void CEnemyFar::Draw(void)
//{
//	//デバイスの取得
//	CRenderer *pRenderer = CManager::GetRenderer();
//	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();
//
//	//位置取得
//	D3DXVECTOR3 EnemyPos = Getpos();
//
//	//向き取得
//	D3DXVECTOR3 EnemyRot = GetRot();
//
//	//計算用マトリックス
//	D3DXMATRIX m_mtxRot, m_mtxTrans;
//
//	//ワールドマトリックスの初期化
//	D3DXMatrixIdentity(&m_mtxWorld);
//
//	//向きを反映
//	D3DXMatrixRotationYawPitchRoll(&m_mtxRot, EnemyRot.y, EnemyRot.x, EnemyRot.z);
//
//	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &m_mtxRot);
//
//	//位置を反映
//	D3DXMatrixTranslation(&m_mtxTrans, EnemyPos.x, EnemyPos.y, EnemyPos.z);
//
//	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &m_mtxTrans);
//
//	//ワールドマトリックスの設定
//	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
//
//	if (m_bBom != true)
//	{//攻撃していないとき
//
//		for (int nCount = 0; nCount < m_nNumModel; nCount++)
//		{
//			if (m_apModel[nCount] != NULL)
//			{//使用していたら
//
//			 //描画処理
//				m_apModel[nCount]->Draw();
//			}
//		}
//	}
//	else
//	{
//		for (int nCount = 0; nCount < m_nNumModel - 1; nCount++)
//		{
//			if (m_apModel[nCount] != NULL)
//			{//使用していたら
//
//			 //描画処理
//				m_apModel[nCount]->Draw();
//			}
//		}
//	}
//}
//
////================================================================
////動き
////================================================================
//void CEnemyFar::Control(void)
//{
//	//デバッグプロックの情報取得
//	CDebugProc *pDebugProc = CManager::GetDebugProc();
//
//	//当たり判定の情報取得
//	CCollision *pCollision = CManager::GetCollsion();
//
//	//プレイヤーの情報取得
//	CPlayer *pPlayer = CGame::GetPlayer();
//
//	CSound *pSound = CManager::GetSound();
//
//	//位置取得
//	D3DXVECTOR3 EnemyPos = Getpos();
//	D3DXVECTOR3 EnemyRot = GetRot();
//
//	m_state = GetState();
//
//	if (GetState() != STATE_DEATH && GetState() != STATE_END)
//	{
//		if ((pCollision->CollisionCircle(&EnemyPos, 400.0f, pPlayer) == true))
//		{//円の中にプレイヤーが入ったまたは、状態がダメージのとき
//
//			D3DXVECTOR3 fDest, pos = pPlayer->Getpos();
//
//			float fDiffmove, fDestmove;
//
//			fDest = EnemyPos - pos;
//
//			fDestmove = atan2f(fDest.x, fDest.z);
//			fDiffmove = fDestmove - EnemyRot.y;
//
//			//角度の値を修正する--------------------------------------------------
//			if (fDiffmove >= D3DX_PI)
//			{
//				fDiffmove = -D3DX_PI;
//			}
//			else if (fDiffmove <= -D3DX_PI)
//			{
//				fDiffmove = D3DX_PI;
//			}
//
//			EnemyRot.y += fDiffmove * 0.05f;
//
//			//角度の値を修正する--------------------------------------------------
//			if (EnemyRot.y > D3DX_PI)
//			{
//				EnemyRot.y = -D3DX_PI;
//			}
//			else if (EnemyRot.y < -D3DX_PI)
//			{
//				EnemyRot.y = D3DX_PI;
//			}
//
//			//移動量を更新(減衰させる)
//			m_move.x = sinf(EnemyRot.y + D3DX_PI) * ENEMYMOVE;
//			m_move.z = cosf(EnemyRot.y + D3DX_PI) * ENEMYMOVE;
//
//			if (fDest.x <= 200.0f && fDest.x >= -200.0f && fDest.z <= 200.0f && fDest.z >= -200.0f)
//			{
//				if (m_state == STATE_DAMEGE || m_state == STATE_STAGGER)
//				{
//					EnemyPos.x -= m_move.x * 0.5f;
//					EnemyPos.z -= m_move.z * 0.5f;
//
//					if (m_state == STATE_DAMEGE && m_state != STATE_STAGGER)
//					{
//						//モーションをセット(ニュートラル)
//						m_motion->Set(MOTIONTYPE_DAMEGE);
//
//						m_state = STATE_STAGGER;
//					}
//
//					if (m_motion->IsFinish() == true)
//					{
//						m_state = STATE_NONE;
//
//						m_bAction = false;
//					}
//				}
//				else
//				{
//					if (m_state != STATE_ACTIONNEUTRAL && m_bAction == false)
//					{
//						//モーションをセット(移動)
//						m_motion->Set(MOTIONTYPE_ACTIONNEUTRAL);
//
//						m_state = STATE_ACTIONNEUTRAL;
//					}
//
//					if (m_state == STATE_ACTIONNEUTRAL)
//					{
//						m_nCntAction++;
//					}
//
//					if (m_motion->IsFinish() == true)
//					{
//						m_state = STATE_NONE;
//
//						m_bAction = false;
//					}
//
//					if (m_nCntAction % 120 == 0)
//					{
//						if (m_state != STATE_ACTION && m_bBom == false)
//						{
//							//モーションをセット(攻撃)
//							m_motion->Set(MOTIONTYPE_ACTION);
//
//							m_state = STATE_ACTION;
//
//							CBullet::Create(D3DXVECTOR3(EnemyPos.x, EnemyPos.y + 60.0f, EnemyPos.z), D3DXVECTOR3(0.0f, EnemyRot.y, 0.0f), CBullet::TYPE_ENEMY);
//
//							pSound->Play(CSound::SOUND_LABEL_SE07);
//
//							m_bAction = true;
//							m_bBom = true;
//						}
//					}
//
//					if (m_bBom == true)
//					{
//						m_nCntReload++;
//					}
//
//					if (m_nCntReload % 150 == 0)
//					{
//						if (m_bBom == true)
//						{
//							//モーションをセット(攻撃)
//							m_motion->Set(MOTIONTYPE_REROAD);
//
//							m_bBom = false;
//							m_nCntReload = 0;
//						}
//					}
//
//					if (m_state == STATE_DAMEGE && m_state != STATE_STAGGER)
//					{
//						//モーションをセット(ニュートラル)
//						m_motion->Set(MOTIONTYPE_DAMEGE);
//
//						m_state = STATE_STAGGER;
//					}
//
//					if (m_state == STATE_STAGGER)
//					{
//						EnemyPos.x -= m_move.x;
//						EnemyPos.z -= m_move.z;
//					}
//				}
//
//				if (fDest.x <= 50.0f && fDest.x >= -50.0f && fDest.z <= 50.0f && fDest.z >= -50.0f)
//				{
//
//				}
//			}
//			else
//			{
//				if (m_state != STATE_STAGGER && m_state != STATE_DAMEGE)
//				{
//					EnemyPos.x += m_move.x;
//					EnemyPos.z += m_move.z;
//
//					if (m_state != STATE_MOVE)
//					{
//						//モーションをセット(移動)
//						m_motion->Set(MOTIONTYPE_MOVE);
//
//						m_state = STATE_MOVE;
//
//						m_bAction = false;
//					}
//
//					if (m_state == STATE_DAMEGE && m_state != STATE_STAGGER)
//					{
//						//モーションをセット(ニュートラル)
//						m_motion->Set(MOTIONTYPE_DAMEGE);
//
//						m_state = STATE_STAGGER;
//					}
//				}
//				else
//				{
//					if (m_motion->IsFinish() == true)
//					{
//						m_state = STATE_NONE;
//
//						m_bAction = false;
//					}
//				}
//			}
//		}
//		else
//		{
//			if (m_state != STATE_NONE)
//			{
//				//モーションをセット(ニュートラル)
//				m_motion->Set(MOTIONTYPE_NONE);
//
//				m_state = STATE_NONE;
//			}
//		}
//
//		if (m_state == STATE_NONE)
//		{
//			EnemyPos.y = -10.0f;
//		}
//		else
//		{
//			EnemyPos.y = 0.0f;
//		}
//	}
//
//	if (m_state != STATE_DEATH || m_state != STATE_END)
//	{
//		if (m_state == STATE_DAMEGE || m_state == STATE_STAGGER)
//		{
//			EnemyPos.x -= m_move.x * 0.5f;
//			EnemyPos.z -= m_move.z * 0.5f;
//
//			if (m_state == STATE_DAMEGE && m_state != STATE_STAGGER)
//			{
//				//モーションをセット(ニュートラル)
//				m_motion->Set(MOTIONTYPE_DAMEGE);
//
//				m_state = STATE_STAGGER;
//			}
//
//			if (m_motion->IsFinish() == true)
//			{
//				m_state = STATE_NONE;
//
//				m_bAction = false;
//			}
//		}
//	}
//
//
//	if (m_state == STATE_DEATH && m_state != STATE_END && m_motion->GetType() != MOTIONTYPE_DEATH)
//	{
//		//モーションをセット(死亡)
//		m_motion->Set(MOTIONTYPE_DEATH);
//	}
//
//	if (m_motion->IsFinish() == true && m_state != STATE_DEATH)
//	{
//		m_state = STATE_NONE;
//
//		m_bAction = false;
//	}
//
//	if (m_motion->IsFinish() == true && m_state == STATE_DEATH)
//	{
//		m_state = STATE_END;
//
//		m_bAction = false;
//	}
//
//	//位置設定
//	SetPos(&EnemyPos);
//	SetRot(&EnemyRot);
//}