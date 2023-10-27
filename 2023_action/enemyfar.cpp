//=============================================================================
//
// �G�̏��� [enemyfar.h]
// Author : �匴�@�叫
//
//=============================================================================

//*============================================================================
//�C���N���[�h�t�@�C��
//*============================================================================
#include "enemyfar.h"

////================================================================
////�R���X�g���N�^
////================================================================
//CEnemyFar::CEnemyFar()
//{
//	m_state = STATE_NONE;
//	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
//	m_rot = { 0.0f, 0.0f, 0.0f };   //����
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
////�R���X�g���N�^(�I�[�o�[���[�h)
////================================================================
//CEnemyFar::CEnemyFar(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
//{
//	SetPos(&pos);  //�ʒu�ݒ�
//	SetRot(&rot);  //�����ݒ�
//	m_state = STATE_NONE;
//	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
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
////�f�X�g���N�^
////================================================================
//CEnemyFar::~CEnemyFar()
//{
//
//}
//
////================================================================
////��������
////================================================================
//CEnemyFar *CEnemyFar::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
//{
//	//�I�u�W�F�N�g2D�̃|�C���^
//	CEnemyFar *pEnemy = NULL;
//
//	if (CObject::GetNumAll() < MAX_OBJECT)
//	{
//		if (pEnemy == NULL)
//		{
//			//�I�u�W�F�N�g2D�̐���
//			pEnemy = new CEnemyFar(pos, rot);
//
//			//����������
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
////����������
////================================================================
//HRESULT CEnemyFar::Init(void)
//{
//	CTexture *pTexture = CManager::GetTexture();
//
//	D3DXVECTOR3 pos = Getpos();
//
//	//�e�̏����擾
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
//		//����������
//		m_motion->Init();
//	}
//
//	//�̗�
//	SetLife(ENEMY_LIFE);
//
//	CEnemy::Init();
//
//	//�e�L�X�g�t�@�C���ǂݍ���
//	CEnemy::ReadText(ENEMYFAR_TEXT);
//
//	//�e�L�X�g�t�@�C���ǂݍ���
//	m_motion->ReadText(ENEMYFAR_TEXT);
//
//	//���f���̐ݒ�
//	m_motion->SetModel(&m_apModel[0], m_nNumModel);
//
//	return S_OK;
//}
//
////================================================================
////�I������
////================================================================
//void CEnemyFar::Uninit(void)
//{
//	CEnemy::Uninit();
//
//	//CObject::Release();
//}
//
////================================================================
////�X�V����
////================================================================
//void CEnemyFar::Update(void)
//{
//	Control();
//
//	CEnemy::Update();
//}
//
////================================================================
////�`�揈��
////================================================================
//void CEnemyFar::Draw(void)
//{
//	//�f�o�C�X�̎擾
//	CRenderer *pRenderer = CManager::GetRenderer();
//	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();
//
//	//�ʒu�擾
//	D3DXVECTOR3 EnemyPos = Getpos();
//
//	//�����擾
//	D3DXVECTOR3 EnemyRot = GetRot();
//
//	//�v�Z�p�}�g���b�N�X
//	D3DXMATRIX m_mtxRot, m_mtxTrans;
//
//	//���[���h�}�g���b�N�X�̏�����
//	D3DXMatrixIdentity(&m_mtxWorld);
//
//	//�����𔽉f
//	D3DXMatrixRotationYawPitchRoll(&m_mtxRot, EnemyRot.y, EnemyRot.x, EnemyRot.z);
//
//	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &m_mtxRot);
//
//	//�ʒu�𔽉f
//	D3DXMatrixTranslation(&m_mtxTrans, EnemyPos.x, EnemyPos.y, EnemyPos.z);
//
//	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &m_mtxTrans);
//
//	//���[���h�}�g���b�N�X�̐ݒ�
//	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
//
//	if (m_bBom != true)
//	{//�U�����Ă��Ȃ��Ƃ�
//
//		for (int nCount = 0; nCount < m_nNumModel; nCount++)
//		{
//			if (m_apModel[nCount] != NULL)
//			{//�g�p���Ă�����
//
//			 //�`�揈��
//				m_apModel[nCount]->Draw();
//			}
//		}
//	}
//	else
//	{
//		for (int nCount = 0; nCount < m_nNumModel - 1; nCount++)
//		{
//			if (m_apModel[nCount] != NULL)
//			{//�g�p���Ă�����
//
//			 //�`�揈��
//				m_apModel[nCount]->Draw();
//			}
//		}
//	}
//}
//
////================================================================
////����
////================================================================
//void CEnemyFar::Control(void)
//{
//	//�f�o�b�O�v���b�N�̏��擾
//	CDebugProc *pDebugProc = CManager::GetDebugProc();
//
//	//�����蔻��̏��擾
//	CCollision *pCollision = CManager::GetCollsion();
//
//	//�v���C���[�̏��擾
//	CPlayer *pPlayer = CGame::GetPlayer();
//
//	CSound *pSound = CManager::GetSound();
//
//	//�ʒu�擾
//	D3DXVECTOR3 EnemyPos = Getpos();
//	D3DXVECTOR3 EnemyRot = GetRot();
//
//	m_state = GetState();
//
//	if (GetState() != STATE_DEATH && GetState() != STATE_END)
//	{
//		if ((pCollision->CollisionCircle(&EnemyPos, 400.0f, pPlayer) == true))
//		{//�~�̒��Ƀv���C���[���������܂��́A��Ԃ��_���[�W�̂Ƃ�
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
//			//�p�x�̒l���C������--------------------------------------------------
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
//			//�p�x�̒l���C������--------------------------------------------------
//			if (EnemyRot.y > D3DX_PI)
//			{
//				EnemyRot.y = -D3DX_PI;
//			}
//			else if (EnemyRot.y < -D3DX_PI)
//			{
//				EnemyRot.y = D3DX_PI;
//			}
//
//			//�ړ��ʂ��X�V(����������)
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
//						//���[�V�������Z�b�g(�j���[�g����)
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
//						//���[�V�������Z�b�g(�ړ�)
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
//							//���[�V�������Z�b�g(�U��)
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
//							//���[�V�������Z�b�g(�U��)
//							m_motion->Set(MOTIONTYPE_REROAD);
//
//							m_bBom = false;
//							m_nCntReload = 0;
//						}
//					}
//
//					if (m_state == STATE_DAMEGE && m_state != STATE_STAGGER)
//					{
//						//���[�V�������Z�b�g(�j���[�g����)
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
//						//���[�V�������Z�b�g(�ړ�)
//						m_motion->Set(MOTIONTYPE_MOVE);
//
//						m_state = STATE_MOVE;
//
//						m_bAction = false;
//					}
//
//					if (m_state == STATE_DAMEGE && m_state != STATE_STAGGER)
//					{
//						//���[�V�������Z�b�g(�j���[�g����)
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
//				//���[�V�������Z�b�g(�j���[�g����)
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
//				//���[�V�������Z�b�g(�j���[�g����)
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
//		//���[�V�������Z�b�g(���S)
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
//	//�ʒu�ݒ�
//	SetPos(&EnemyPos);
//	SetRot(&EnemyRot);
//}