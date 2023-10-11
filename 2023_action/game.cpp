//===========================================================
//
//�|���S�����o�����[game.cpp]
//Author �匴�叫
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
bool CGame::m_bPause = false;

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
	CCamera *pCamera = CManager::GetCamera();

	pCamera->SetType(CCamera::TYPE_GAME);

	CField::Create();

	//�`�r----------------------------------------------------------
	if (m_PlayerChibi == NULL)
	{//�g�p����Ă��Ȃ�������

	    //�v���C���[�̐���
		m_PlayerChibi = new CChibi({ 0.0f, 0.0f, 0.0f });

		//����������
		m_PlayerChibi->Init();
	}

	//�N�\�f�u-----------------------------------------------------
	if (m_PlayerFoot == NULL)
	{//�g�p����Ă��Ȃ�������

		//�v���C���[�̐���
		m_PlayerFoot = new CFoot({ 0.0f, 0.0f, 0.0f });

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

	CSound *pSound = CManager::GetSound();

	return S_OK;
}

//===========================================================
//�I������
//===========================================================
void CGame::Uninit(void)
{
	CSound *pSound = CManager::GetSound();

	pSound->Stop();

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

	//���ׂẴI�u�W�F�N�g�j��
	CObject::ReleaseAll();
}

//===========================================================
//�X�V����
//===========================================================
void CGame::Update(void)
{
	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

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
	}

	if (m_Edit != NULL)
	{//�g�p����Ă�����

		//�X�V����
		m_Edit->Update();
	}

	CDebugProc *pDebugProc = CManager::GetDebugProc();

	pDebugProc->Print("\n�V�[���F�Q�[��");
}

//===========================================================
//�`�揈��
//===========================================================
void CGame::Draw(void)
{
	
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
	return m_Player;
}

//================================================================
//�|�[�Y�̎擾
//================================================================
CPause *CGame::GetPause(void)
{
	return m_Pause;
}