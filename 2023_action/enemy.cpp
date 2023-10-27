//==============================================================================
//
// �G�̏��� [enemy.cpp]
// Author : �匴�@�叫
//
//==============================================================================

//*=============================================================================
//�C���N���[�h�t�@�C��
//*=============================================================================
#include "enemy.h"
#include "texture.h"
#include "manager.h"
#include "renderer.h"
#include "motion.h"
#include "sound.h"
#include "collision.h"
#include "player.h"
#include "game.h"
#include "map.h"
#include "debugproc.h"
#include "score.h"
#include "player.h"
#include <assert.h>

//*=============================================================================
//�}�N����`
//*=============================================================================
#define ENEMY_TEXT   ("data\\TEXT\\enemy00.txt")   //�G�̃e�L�X�g�t�@�C��
#define ENEMYMOVE    (2.0f)                        //�ړ���

//*=============================================================================
//�ÓI�����o�ϐ�
//*=============================================================================
CEnemy *CEnemy::m_pEnemy[64] = {};
int CEnemy::m_nNumAll = 0;

//==============================================================================
//�R���X�g���N�^
//==============================================================================
CEnemy::CEnemy()
{
	m_state = (STATE)0;
	m_nidxID = -1;
}

//==============================================================================
//�R���X�g���N�^
//==============================================================================
CEnemy::CEnemy(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nlife)
{
	SetPos(&pos);
	SetRot(&rot);
	SetLife(nlife);
	m_state = (STATE)0;
	m_nidxID = -1;
}

//==============================================================================
//�f�X�g���N�^
//==============================================================================
CEnemy::~CEnemy()
{

}

//==============================================================================
//��������
//==============================================================================
CEnemy * CEnemy::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nlife)
{
	CEnemy *pEnemy = NULL;

	if (pEnemy == NULL)
	{
		pEnemy = new CEnemy(pos, rot, nlife);

		pEnemy->Init();
	}

	for (int nCount = 0; nCount < 64; nCount++)
	{
		if (m_pEnemy[nCount] == NULL)
		{
			m_pEnemy[nCount] = pEnemy;

			m_pEnemy[nCount]->m_nidxID = nCount;

			m_nNumAll++;

			break;
		}
	}

	return pEnemy;
}

//==============================================================================
//����������
//==============================================================================
HRESULT CEnemy::Init(void)
{
	if (m_motion == NULL)
	{//�g�p����Ă��Ȃ�������

		//����
		m_motion = new CMotion;

		//����������
		m_motion->Init();
	}

	ReadText(ENEMY_TEXT);

	return S_OK;
}

//==============================================================================
//�I������
//==============================================================================
void CEnemy::Uninit(void)
{
	//�T�E���h�̏����擾
	CSound *pSound = CManager::Getinstance()->GetSound();

	//�T�E���h�X�g�b�v
	//pSound->Stop();

	if (m_motion != NULL)
	{
		//�I������
		m_motion->Uninit();

		delete m_motion;

		m_motion = NULL;
	}

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{//�g�p���Ă�����

			m_apModel[nCount]->Uninit();  //�I������
			m_apModel[nCount] = NULL;  //�g�p���Ă��Ȃ���Ԃɂ���
		}
	}

	if (m_pEnemy[m_nidxID] != NULL)
	{
		m_pEnemy[m_nidxID] = NULL;

		m_nNumAll--;
	}
	
	CObject::Release();
}

//==============================================================================
//�X�V����
//==============================================================================
void CEnemy::Update(void)
{
	CMap *pmap = CGame::GetMap();

	//�����蔻��̏��擾
	CCollision *pCollision = CGame::GetCollsion();

	CFoot *pPlayerFoot = CGame::GetPlayerFoot();
	CChibi *pPlayerChibi = CGame::GetPlayerChibi();

	if (GetLife() <= 0)
	{
		int n = CGame::GetCounter();

		n++;

		CGame::SetCounter(n);

		CScore::AddScore(500);

		Uninit();
	}
	else
	{
		if (pPlayerFoot->GetState() != CFoot::STATE_APPR && pPlayerChibi->GetState() != CChibi::STATE_APPR)
		{
			for (int nCount = 0; nCount < m_nNumModel; nCount++)
			{
				m_apModel[nCount]->Update();
			}

			if (m_motion != NULL)
			{
				//����������
				m_motion->Update();
			}

			//���䏈��
			Controll();
		}
	}
}

//==============================================================================
//�`�揈��
//==============================================================================
void CEnemy::Draw(void)
{
	CTexture *pTexture = CManager::Getinstance()->GetTexture();
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	D3DXVECTOR3 pos = Getpos();
	D3DXVECTOR3 rot = GetRot();

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX m_mtxRot, m_mtxTrans;

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&m_mtxRot, rot.y, rot.x, rot.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &m_mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&m_mtxTrans, pos.x, pos.y, pos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &m_mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		//�`�揈��
		m_apModel[nCount]->Draw();
	}
}

//==============================================================================
//���䏈��
//==============================================================================
void CEnemy::Controll(void)
{
	CMap *pmap = CGame::GetMap();

	//�����蔻��̏��擾
	CCollision *pCollision = CGame::GetCollsion();

	//�v���C���[�̏��擾
	CPlayer *pPlayer = CGame::GetPlayer();

	//�ʒu�ƌ����擾
	D3DXVECTOR3 EnemyPos = Getpos();
	D3DXVECTOR3 EnemyRot = GetRot();

	m_posOld = EnemyPos;  //�ʒu����

	m_move.y -= 0.9f;

	pCollision->MapEnemy(&Getpos(), &m_posOld, pmap->GetX(), m_pEnemy[m_nidxID]);

	if ((pCollision->Circle(&EnemyPos, 400.0f, pPlayer) == true))
	{//�~�̒��Ƀv���C���[���������܂��́A��Ԃ��_���[�W�̂Ƃ�

		D3DXVECTOR3 fDest, pos = pPlayer->Getpos();

		float fDiffmove, fDestmove;

		fDest = EnemyPos - pos;

		fDestmove = atan2f(fDest.x, fDest.y);
		fDiffmove = fDestmove - EnemyRot.y;

		//�p�x�̒l���C������--------------------------------------------------
		if (fDiffmove >= D3DX_PI)
		{
			fDiffmove = -D3DX_PI;
		}
		else if (fDiffmove <= -D3DX_PI)
		{
			fDiffmove = D3DX_PI;
		}

		EnemyRot.y += fDiffmove * 0.05f;

		//�p�x�̒l���C������--------------------------------------------------
		if (EnemyRot.y > D3DX_PI)
		{
			EnemyRot.y = -D3DX_PI;
		}
		else if (EnemyRot.y < -D3DX_PI)
		{
			EnemyRot.y = D3DX_PI;
		}

		//�ړ��ʂ��X�V(����������)
		m_move.x = sinf(EnemyRot.y + D3DX_PI) * ENEMYMOVE;
		//m_move.z = cosf(EnemyRot.y + D3DX_PI) * ENEMYMOVE;

		//�ړ��ʂ��ʒu�ɉ��Z
		EnemyPos.x += m_move.x;
		

		if (m_state != STATE_MOVE)
		{
			//���[�V�������Z�b�g(�ړ�)
			m_motion->Set(MOTIONTYPE_MOVE);

			m_state = STATE_MOVE;

			//m_bAction = false;
		}
	}
	else
	{
		if (m_state != STATE_NEUTRAL)
		{
			m_motion->Set(MOTIONTYPE_NEUTRAL);

			m_state = STATE_NEUTRAL;
		}

	}
	
	if (m_motion->IsFinish() == true)
	{
		m_state = STATE_NEUTRAL;
	}

	EnemyPos.y += m_move.y;

	if (EnemyPos.y <= 0.0f)
	{
		EnemyPos.y = 0.0f;

		m_move.y = 0.0f;
	}

	//�ʒu�ݒ�
	SetPos(&EnemyPos);
	SetRot(&EnemyRot);

	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();

	pDebugProc->Print("\n�G�̈ʒu�F%f,%f,%f\n", EnemyPos.x, EnemyPos.y, EnemyPos.z);
	pDebugProc->Print("�G�̌����F%f,%f,%f\n", EnemyRot.x, EnemyRot.y, EnemyRot.z);
	pDebugProc->Print("�G�̈ړ��ʁF%f,%f,%f", m_move.x, m_move.y, m_move.z);
}

//==============================================================================
//�e�L�X�g�t�@�C���ǂݍ���
//==============================================================================
void CEnemy::ReadText(char *fliename)
{
	char aString[128] = {};
	char aComment[128] = {};
	int nCntParts = 0, nCntParts2 = 0, nCntParts3 = 0;
	int nCntMotion = 0;
	int nCntKeySet = 0;
	int nCntKey = 0;
	int nCntModel = 0;
	int nCntMotionIdx = 0;

	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	FILE *pFile;   //�t�@�C���|�C���^��錾

	pFile = fopen(fliename, "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		fscanf(pFile, "%s", &aString[0]);

		if (strcmp("SCRIPT", aString) == 0)
		{
			while (strcmp("END_SCRIPT", aString) != 0)
			{
				fscanf(pFile, "%s", &aString[0]);

				if (strcmp("NUM_MODEL", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%d", &m_nNumModel);  //���f���̑���

				}  //NUM_MODEL�̂�����

				if (strcmp("MODEL_FILENAME", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%s", &m_filename[0]);  //���f���̖��O

					m_apModel[nCntModel] = CCharacter::Create(m_filename);
					nCntModel++;

					nCntParts++;

				}  //MODEL_LILENAME�̂�����


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
									fscanf(pFile, "%d", &m_nIdx);  //���f���̔ԍ�
								}

								if (strcmp("PARENT", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);          //=
									fscanf(pFile, "%d", &m_nParent);  //�e���f���̔ԍ�

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
									fscanf(pFile, "%f", &m_Readpos.x);  //���f���̑���
									fscanf(pFile, "%f", &m_Readpos.y);  //���f���̑���
									fscanf(pFile, "%f", &m_Readpos.z);  //���f���̑���

									m_apModel[nCntParts2]->SetPositionOri(m_Readpos);

									m_apModel[nCntParts2]->SetPosition(m_Readpos);
								}

								if (strcmp("ROT", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);      //=
									fscanf(pFile, "%f", &m_Readrot.x);  //���f���̑���
									fscanf(pFile, "%f", &m_Readrot.y);  //���f���̑���
									fscanf(pFile, "%f", &m_Readrot.z);  //���f���̑���

									m_apModel[nCntParts2]->SetRotOrigin(m_Readrot);

									m_apModel[nCntParts2]->SetRot(m_Readrot);
								}

							}//END_PARTSSET�̂�����

							nCntParts2++;

						}//PARTSSET�̂�����

					}//END_CHARACTERSET�̂����� 

				}//CHARACTERSET�̂����� 
			}
		}

		//�t�@�C�������
		fclose(pFile);
	}
	else
	{
		return;
	}

	if (m_motion != NULL)
	{
		//���f���̐ݒ�
		m_motion->SetModel(&m_apModel[0], m_nNumModel);

		//����������
		m_motion->ReadText(fliename);
	}
}


