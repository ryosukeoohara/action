//===========================================================
//
//�|���S�����o�����[game.cpp]
//Author �匴�叫
//
//===========================================================

//*==========================================================
//�C���N���[�h�t�@�C��
//*==========================================================
#include "game.h"
#include "input.h"
#include "sound.h"
#include "camera.h"
#include "object.h"
#include "debugproc.h"
#include "player.h"
#include "field.h"
#include "edit.h"
#include "map.h"
#include "collision.h"
#include "enemy.h"
#include "enemymanager.h"
#include "sky.h"
#include "fade.h"

//================================================================
//�ÓI�����o�ϐ�
//================================================================
CChibi *CGame::m_PlayerChibi = NULL;
CFoot *CGame::m_PlayerFoot = NULL;
CPlayer *CGame::m_Player = NULL;
CEnemy *CGame::m_Enemy = NULL;
CCollision *CGame::m_Collision = NULL;
CMap *CGame::m_Map = NULL;
CPause *CGame::m_Pause = NULL;
CEdit *CGame::m_Edit = NULL;
CEnemyManager *CGame::m_EnemyManager = NULL;
bool CGame::m_bPause = false;
int CGame::m_nCounter = 0;

//===========================================================
//�R���X�g���N�^
//===========================================================
CGame::CGame()
{
	m_bUse = false;
}

//===========================================================
//�R���X�g���N�^
//===========================================================
CGame::CGame(CScene::MODE mode)
{
	m_bUse = false;
}

//===========================================================
//�f�X�g���N�^
//===========================================================
CGame::~CGame()
{

}

//===========================================================
//�f�X�g���N�^
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
//����������
//===========================================================
HRESULT CGame::Init(void)
{
	//�J�����擾
	CCamera *pCamera = CManager::Getinstance()->GetCamera();

	pCamera->SetType(CCamera::TYPE_GAME);

	CSky::Create({0.0f,0.0f,0.0f});

	CField::Create();

	if (m_Map == NULL)
	{//�g�p����Ă��Ȃ�������

		//�}�b�v�𐶐�
		m_Map = new CMap;

		//����������
		m_Map->Init();
	}

	if (m_Collision == NULL)
	{//�g�p����Ă��Ȃ�������

		//�����蔻��𐶐�
		m_Collision = new CCollision;

		//����������
		m_Collision->Init();
	}

	//�`�r----------------------------------------------------------
	if (m_PlayerChibi == NULL)
	{//�g�p����Ă��Ȃ�������

	    //�v���C���[�̐���
		m_PlayerChibi = new CChibi({ -1180.0f, 50.0f, 0.0f });

		//����������
		m_PlayerChibi->Init();
	}

	//�N�\�f�u-----------------------------------------------------
	if (m_PlayerFoot == NULL)
	{//�g�p����Ă��Ȃ�������

		//�v���C���[�̐���
		m_PlayerFoot = new CFoot({ -1180.0f, 50.0f, 0.0f });

		//����������
		m_PlayerFoot->Init();
	}

	//if (m_Player == NULL)
	//{//�g�p����Ă��Ȃ�������

	//	//�v���C���[�̐���
	//	m_Player = new CPlayer({ 0.0f, 0.0f, 0.0f });

	//	//����������
	//	m_Player->Init();
	//}

	//if (m_EnemyManager == NULL)
	//{//�g�p����Ă��Ȃ�������

	//	//����
	//	m_EnemyManager = new CEnemyManager;

	//	//����������
	//	m_EnemyManager->Init();
	//}

	CEnemy::Create({ 0.0f,0.0f,0.0f }, { 0.0f,0.0f,0.0f }, 1);
	CEnemy::Create({ 3600.0f,105.0f,0.0f }, { 0.0f,0.0f,0.0f }, 1);
	CEnemy::Create({ 3000.0f,445.0f,0.0f }, { 0.0f,0.0f,0.0f }, 1);
	CEnemy::Create({ 4800.0f,300.0f,0.0f }, { 0.0f,0.0f,0.0f }, 1);

	CSound *pSound = CManager::Getinstance()->GetSound();

	return S_OK;
}

//===========================================================
//�I������
//===========================================================
void CGame::Uninit(void)
{
	CSound *pSound = CManager::Getinstance()->GetSound();

	pSound->Stop();

	//�}�b�v�̔j��
	if (m_Map != NULL)
	{//�g�p����Ă��Ȃ�������

		//�}�b�v�̏I������
		m_Map->Uninit();

		//���������J��
		delete m_Map;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Map = NULL;
	}

	//�����蔻��̔j��
	if (m_Collision != NULL)
	{
		//�}�b�v�̏I������
		m_Collision->Uninit();

		//���������J��
		delete m_Collision;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Collision = NULL;
	}

	//�v���C���[(�`�r)�̔j��
	if (m_PlayerChibi != NULL)
	{
		//�v���C���[�̏I������
		m_PlayerChibi->Uninit();

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_PlayerChibi = NULL;
	}

	//�v���C���[(�N�\�f�u)�̔j��
	if (m_PlayerFoot != NULL)
	{
		//�v���C���[�̏I������
		m_PlayerFoot->Uninit();

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_PlayerFoot = NULL;
	}

	//�v���C���[�̔j��
	if (m_Player != NULL)
	{
		//�v���C���[�̏I������
		m_Player->Uninit();

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Player = NULL;
	}

	//�G�f�B�b�g�̔j��
	if (m_Edit != NULL)
	{//�g�p����Ă����Ƃ�

		//�I������
		m_Edit->Uninit();

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Edit = NULL;
	}

	//�G�̃}�l�[�W���̔j��
	if (m_EnemyManager != NULL)
	{//�g�p����Ă����Ƃ�

		//�I������
		m_EnemyManager->Uninit();

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_EnemyManager = NULL;
	}

	m_nCounter = 0;

	//���ׂẴI�u�W�F�N�g�j��
	CObject::ReleaseAll();
}

//===========================================================
//�X�V����
//===========================================================
void CGame::Update(void)
{
	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::Getinstance()->GetKeyBoard();

	//�J�����擾
	CCamera *pCamera = CManager::Getinstance()->GetCamera();

	CFade *pFade = CManager::Getinstance()->GetFade();

	//���ׂĂ̍X�V����
	CObject::UpdateAll();

	if (InputKeyboard->GetTrigger(DIK_F11) == true)
	{//F11��������

		//true��false���؂�ւ���
		m_bUse = m_bUse ? false : true;
	}

	if (m_bUse == true)
	{//�^�̂Ƃ�

		if (m_Edit == NULL)
		{//�g�p����Ă��Ȃ�������

			//����
			m_Edit = new CEdit;
			
			//����������
			m_Edit->Init();
		}

		pCamera->SetType(CCamera::TYPE_EDIT);
	}

	if (m_bUse == false)
	{//�U�̂Ƃ�

		if (m_Edit != NULL)
		{//�g�p����Ă����Ƃ�

			//�I������
			m_Edit->Uninit();

			//�g�p���Ă��Ȃ���Ԃɂ���
			m_Edit = NULL;

			m_bUse = false;
		}

		pCamera->SetType(CCamera::TYPE_GAME);
	}

	if (m_nCounter >= 4)
	{
		if (pFade->Get() != pFade->FADE_OUT)
		{
			//�V�[�����^�C�g���ɑJ��
			pFade->Set(CScene::MODE_RESULT);
		}
	}

	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();

	pDebugProc->Print("\n�V�[���F�Q�[��");
}

//===========================================================
//�`�揈��
//===========================================================
void CGame::Draw(void)
{
	//if (m_EnemyManager != NULL)
	//{//�g�p����Ă����Ƃ�

	//	//�`�揈��
	//	m_EnemyManager->Draw();
	//}
}

//================================================================
//�����蔻��̎擾
//================================================================
CCollision *CGame::GetCollsion(void)
{
	return m_Collision;
}

//================================================================
//�}�b�v�̎擾
//================================================================
CMap *CGame::GetMap(void)
{
	return m_Map;
}

//================================================================
//�v���C���[�̎擾(�`�r)
//================================================================
CChibi *CGame::GetPlayerChibi(void)
{
	return m_PlayerChibi;
}

//================================================================
//�v���C���[�̎擾(�N�\�f�u)
//================================================================
CFoot *CGame::GetPlayerFoot(void)
{
	return m_PlayerFoot;
}

//================================================================
//�v���C���[�̎擾
//================================================================
CPlayer *CGame::GetPlayer(void)
{
	if (m_PlayerChibi->GetbAppr() == true)
	{
		return m_PlayerChibi;
	}
	else if (m_PlayerFoot->GetbAppr() == true)
	{
		return m_PlayerFoot;
	}
	else
	{
		return false;
	}
}

//================================================================
//�|�[�Y�̎擾
//================================================================
CPause *CGame::GetPause(void)
{
	return m_Pause;
}

//================================================================
//�G�l�~�[�}�l�[�W���̎擾
//================================================================
CEnemyManager *CGame::GetEnemyManager(void)
{
	return m_EnemyManager;
}
