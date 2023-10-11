//===========================================================
//
//�|���S�����o�����[player.cpp]
//Author �匴�叫
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

//�ÓI�����o�ϐ�
//bool CChibi::m_bDisp = false;
//bool CChibi::m_bAppr = false;
//
//bool CFoot::m_bDisp = false;
//bool CFoot::m_bAppr = false;

//================================================================
//�}�N����`
//================================================================
#define MAX_LIFE    (10)                                          //�v���C���[�̗̑�
#define REST_BULLET (6)                                           //�ێ��ł���e�̐�
#define MUTEKITIME  (30)                                          //���G����
#define PLAYER_X    (40.0f)                                       //�v���C���[��X���̕�
#define PLAYER_Z    (10.0f)                                       //�v���C���[��Z���̕�
#define FRIST       (21)                                          //�U�����蔭���J�n
#define FINISH      (31)                                          //�U������I��
#define PLAYER01_TEXT ("data\\TEXT\\motion_set_player.txt")       //�v���C���[�̃e�L�X�g�t�@�C��
#define PLAYER02_TEXT ("data\\TEXT\\motion_set_player2.txt")      //�v���C���[�̃e�L�X�g�t�@�C��

//================================================================
//�ÓI�����o�ϐ��錾
//================================================================
//MODEL *CPlayer::m_Player = NULL;

//================================================================
//�R���X�g���N�^
//================================================================
CPlayer::CPlayer()
{
	/*ZeroMemory(m_Chibi, sizeof(CChibi));
	ZeroMemory(m_Foot, sizeof(CFoot));*/
	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
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
//�R���X�g���N�^(�I�[�o�[���[�h)
//================================================================
CPlayer::CPlayer(D3DXVECTOR3 pos)
{
	/*ZeroMemory(m_Chibi, sizeof(CChibi));
	ZeroMemory(m_Foot, sizeof(CFoot));*/
	SetPos(&pos);  //�ʒu
	SetRot(&D3DXVECTOR3(0.0f, 1.57f, 0.0f));
	m_move = {0.0f, 0.0f, 0.0f};  //�ړ���
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
//�f�X�g���N�^
//================================================================
CPlayer::~CPlayer()
{

}

//================================================================
//��������
//================================================================
CPlayer *CPlayer::Create(D3DXVECTOR3 pos)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CPlayer *pPlayer = NULL;

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pPlayer == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pPlayer = new CPlayer(pos);

			//����������
			pPlayer->Init();
		}
	}

	return pPlayer;
}

//================================================================
//�v���C���[�̏���������
//================================================================
HRESULT CPlayer::Init(void)
{
	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::GetTexture();

	//�V�[���̏����擾
	CScene *pScene = CManager::GetScene();

	//�e�̏����擾
	//CShadow *pShadow = CGame::GetShadow();

	D3DXVECTOR3 pos = Getpos();

	//��ސݒ�
	SetType(TYPE_PLAYER);

	//if (m_pShadow == NULL)
	//{
	//	m_pShadow = new CShadow(pos);

	//	//����������
	//	m_pShadow->Init();
	//}

	SetLife(MAX_LIFE);

	m_RestBullet = REST_BULLET;

	m_fDest = 1.57f;

	return S_OK;
}

//================================================================
//�v���C���[�̏I������
//================================================================
void CPlayer::Uninit(void)
{
	//�T�E���h�̏����擾
	CSound *pSound = CManager::GetSound();

	//�T�E���h�X�g�b�v
	pSound->Stop();

	if (m_motion != NULL)
	{
		//�I������
		m_motion->Uninit();

		delete m_motion;

		m_motion = NULL;
	}

	//if (m_pShadow != NULL)
	//{
	//	//�I������
	//	m_pShadow->Uninit();

	//	m_pShadow = NULL;
	//}

	//�v���C���[(�`�r)�̔j��
	if (m_Chibi != NULL)
	{
		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Chibi = NULL;
	}

	//�v���C���[(�N�\�f�u)�̔j��
	if (m_Foot != NULL)
	{
		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Foot = NULL;
	}

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{//�g�p���Ă�����

			m_apModel[nCount]->Uninit();  //�I������
			//delete m_apModel[nCount];  //���������J��
			m_apModel[nCount] = NULL;  //�g�p���Ă��Ȃ���Ԃɂ���
		}
	}

	CObject::Release();
}

//================================================================
//�v���C���[�̍X�V����
//================================================================
void CPlayer::Update(void)
{
	//�L�[�{�[�h�̏����擾
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::GetFade();

	//�V�[���̏����擾
	CScene *pScene = CManager::GetScene();

	//�v���C���[(�N�\�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�v���C���[(�`�r�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		m_apModel[nCount]->Update();
	}

	if (m_motion != NULL)
	{
		//����������
		m_motion->Update();
	}

	if (InputKeyboard->GetTrigger(DIK_SPACE) == true && pFoot->GetState() != CFoot::STATE_APPR && pChibi->GetState() != CChibi::STATE_APPR
	 && pFoot->GetState() != CFoot::STATE_JUMP && pChibi->GetState() != CChibi::STATE_JUMP)
	{//SPACE�L�[�������ꂽ

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
//�v���C���[�̕`�揈��
//================================================================
void CPlayer::Draw(void)
{
	CTexture *pTexture = CManager::GetTexture();
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

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

//================================================================
//�v���C���[�̐��䏈��
//================================================================
void CPlayer::ControlPlayer(void)
{
	//�v���C���[(�N�\�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�v���C���[(�`�r�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	if (pChibi->GetbAppr() == true)
	{
		//�`�r�f�u�̐���
		pChibi->Control();
	}

	if (pFoot->GetbAppr() == true)
	{
		//�N�\�f�u�̐���
		pFoot->Control();
	}
}

//================================================================
//�v���C���[�̐��䏈��(�`�r�f�u)
//================================================================
void CChibi::Control(void)
{
	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	//�}�E�X���擾
	CInputMouse *pInputMouse = CManager::GetInputMouse();

	//�}�E�X�̈ʒu���擾
	D3DXVECTOR2 MousePos = pInputMouse->GetMouseMove();

	//�T�E���h���擾
	CSound *pSound = CManager::GetSound();

	//�J�����擾
	CCamera *pCamera = CManager::GetCamera();

	//�J�����̌����擾
	D3DXVECTOR3 CameraRot = pCamera->GetRot();

	//�v���C���[(�`�r�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	//�v���C���[(�N�\�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�ʒu�ƌ������擾
	D3DXVECTOR3 Playerpos = pChibi->Getpos();
	D3DXVECTOR3 PlayerRot = pChibi->GetRot();

	m_posOld = Playerpos;  //�ʒu����
	m_move.y -= 1.5f;   //�d��

	//�����Ă��Ȃ����
	m_bDash = false;

	//float fHeight;

	if (m_State != STATE_ATTACK && m_State != STATE_APPR)
	{
		//��Ɉړ�----------------------------------------------
		if (InputKeyboard->GetPress(DIK_W) == true)
		{//W�L�[�������ꂽ

		}
		//���Ɉړ�----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_S) == true)
		{//S�L�[�������ꂽ

		}
		//�E�Ɉړ�----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_D) == true)
		{//D�L�[����������

		 //�ړ���
			m_move.x += sinf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;
			m_move.z += cosf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;

			//����
			m_fDest = (CameraRot.y + (D3DX_PI * -0.5f));

			//�����Ă����Ԃɂ���
			m_bDash = true;
		}
		//���Ɉړ�----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_A) == true)
		{//A�L�[����������

		 //�ړ���
			m_move.x -= sinf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;
			m_move.z -= cosf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;

			//����
			m_fDest = (CameraRot.y + (D3DX_PI * 0.5f));

			//�����Ă����Ԃɂ���
			m_bDash = true;
		}

		m_fDiff = m_fDest - PlayerRot.y;

		//�p�x�̒l���C������
		if (m_fDiff >= D3DX_PI)
		{
			m_fDiff -= D3DX_PI * 2;
		}
		else if (m_fDiff <= -D3DX_PI)
		{
			m_fDiff += D3DX_PI * 2;
		}

		//�ړ�����(�p�x)�̕␳------------------------------------------------
		PlayerRot.y += m_fDiff * 0.15f;

		//�p�x�̒l���C������--------------------------------------------------
		if (PlayerRot.y > D3DX_PI)
		{
			PlayerRot.y = -D3DX_PI;
		}
		else if (PlayerRot.y < -D3DX_PI)
		{
			PlayerRot.y = D3DX_PI;
		}

		if (InputKeyboard->GetTrigger(DIK_J) == true && m_bJump == false)
		{//SPACE�L�[�������ꂽ

			m_bJump = true;

			m_move.y += 20.0f;
		}

		//�ʒu�Ɉړ��ʉ��Z----------------------------------------------------
		Playerpos.x += m_move.x;
		Playerpos.y += m_move.y;
		//m_pos.y = fHeight + 18.0f;

		//�ړ��ʂ��X�V(����������)--------------------------------------------
		m_move.x += (0.0f - m_move.x) * 0.1f;

		if (InputKeyboard->GetPress(DIK_K) == true)
		{//K�L�[�������ꂽ

			m_State = STATE_ATTACK;

			CBullet::Create(D3DXVECTOR3(Playerpos.x, Playerpos.y + 60.0f, Playerpos.z), D3DXVECTOR3(0.0f, m_fDest, 0.0f), CBullet::TYPE_PLAYER);
		}

		if (m_bDash == true && m_State != STATE_MOVE && m_State != STATE_ATTACK)
		{
			//���[�V�������Z�b�g(�ړ�)
			m_motion->Set(MOTIONTYPE_MOVE);

			m_State = STATE_MOVE;

			m_bAction = false;
		}

		if (m_bDash == false && m_State != STATE_NEUTRAL && m_State != STATE_ATTACK && m_State != STATE_APPR)
		{
			//���[�V�������Z�b�g(�ړ�)
			m_motion->Set(MOTIONTYPE_NEUTRAL);

			m_State = STATE_NEUTRAL;

			m_bAction = false;
		}

		if (m_bJump == true && m_State != STATE_JUMP)
		{
			//���[�V�������Z�b�g(�ړ�)
			m_motion->Set(MOTIONTYPE_JUMP);

			m_State = STATE_JUMP;
		}

		if (m_bAction == false && m_State == STATE_ATTACK)
		{
			//���[�V�������Z�b�g(�U��)
			m_motion->Set(MOTIONTYPE_ATTACK);

			m_bAction = true;
		}
	}
	
	if (m_State == STATE_APPR && m_WaitApper == false)
	{
		//���[�V�������Z�b�g(�o���҂�)
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

	pDebugProc->Print("�v���C���[�̈ʒu�F%f,%f,%f\n", Playerpos.x, Playerpos.y, Playerpos.z);
	pDebugProc->Print("�v���C���[�̌����F%f,%f,%f\n", PlayerRot.x, PlayerRot.y, PlayerRot.z);
	pDebugProc->Print("�v���C���[�̈ړ��ʁF%f,%f,%f", m_move.x, m_move.y, m_move.z);
}

//================================================================
//�v���C���[�̐��䏈��(�N�\�f�u)
//================================================================
void CFoot::Control(void)
{
	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	//�}�E�X���擾
	CInputMouse *pInputMouse = CManager::GetInputMouse();

	//�}�E�X�̈ʒu���擾
	D3DXVECTOR2 MousePos = pInputMouse->GetMouseMove();

	//�T�E���h���擾
	CSound *pSound = CManager::GetSound();

	//�J�����擾
	CCamera *pCamera = CManager::GetCamera();

	//�J�����̌����擾
	D3DXVECTOR3 CameraRot = pCamera->GetRot();

	//�v���C���[(�`�r�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�v���C���[(�`�r�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	//�ʒu�ƌ������擾
	D3DXVECTOR3 Playerpos = pFoot->Getpos();
	D3DXVECTOR3 PlayerRot = pFoot->GetRot();

	m_posOld = Playerpos;  //�ʒu����
	m_move.y -= 1.5f;	   //�d��

	//�����Ă��Ȃ����
	m_bDash = false;

	//float fHeight;

	if (m_State != STATE_ATTACK && m_State != STATE_APPR)
	{
		//��Ɉړ�----------------------------------------------
		if (InputKeyboard->GetPress(DIK_W) == true)
		{//W�L�[�������ꂽ

		}
		//���Ɉړ�----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_S) == true)
		{//S�L�[�������ꂽ

		}
		//�E�Ɉړ�----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_D) == true)
		{//D�L�[����������

		 //�ړ���
			m_move.x += sinf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;
			m_move.z += cosf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;

			//����
			m_fDest = (CameraRot.y + (D3DX_PI * -0.5f));

			//�����Ă����Ԃɂ���
			m_bDash = true;
		}
		//���Ɉړ�----------------------------------------------
		else if (InputKeyboard->GetPress(DIK_A) == true)
		{//A�L�[����������

		 //�ړ���
			m_move.x -= sinf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;
			m_move.z -= cosf(CameraRot.y + (D3DX_PI * 0.5f)) * PLAYERMOVE;

			//����
			m_fDest = (CameraRot.y + (D3DX_PI * 0.5f));

			//�����Ă����Ԃɂ���
			m_bDash = true;
		}

		m_fDiff = m_fDest - PlayerRot.y;

		//�p�x�̒l���C������
		if (m_fDiff >= D3DX_PI)
		{
			m_fDiff -= D3DX_PI * 2;
		}
		else if (m_fDiff <= -D3DX_PI)
		{
			m_fDiff += D3DX_PI * 2;
		}

		//�ړ�����(�p�x)�̕␳------------------------------------------------
		PlayerRot.y += m_fDiff * 0.15f;

		//�p�x�̒l���C������--------------------------------------------------
		if (PlayerRot.y > D3DX_PI)
		{
			PlayerRot.y = -D3DX_PI;
		}
		else if (PlayerRot.y < -D3DX_PI)
		{
			PlayerRot.y = D3DX_PI;
		}

		if (InputKeyboard->GetTrigger(DIK_J) == true && m_bJump == false)
		{//SPACE�L�[�������ꂽ

			m_bJump = true;

			m_move.y += 20.0f;
		}

		//�ʒu�Ɉړ��ʉ��Z----------------------------------------------------
		Playerpos.x += m_move.x;
		Playerpos.y += m_move.y;
		//m_pos.y = fHeight + 18.0f;

		//�ړ��ʂ��X�V(����������)--------------------------------------------
		m_move.x += (0.0f - m_move.x) * 0.1f;
		m_move.z += (0.0f - m_move.z) * 0.1f;

		if (InputKeyboard->GetTrigger(DIK_K) == true)
		{//K�L�[�������ꂽ

			m_State = STATE_ATTACK;
		}

		if (m_bDash == true && m_State != STATE_MOVE && m_State != STATE_ATTACK)
		{
			//���[�V�������Z�b�g(�ړ�)
			m_motion->Set(MOTIONTYPE_MOVE);

			m_State = STATE_MOVE;

			m_bAction = false;
		}

		if (m_bDash == false && m_State != STATE_NEUTRAL && m_State != STATE_ATTACK && m_State != STATE_APPR)
		{
			//���[�V�������Z�b�g(�ړ�)
			m_motion->Set(MOTIONTYPE_NEUTRAL);

			m_State = STATE_NEUTRAL;

			m_bAction = false;
		}

		if (m_bJump == true && m_State != STATE_JUMP)
		{
			//���[�V�������Z�b�g(�ړ�)
			m_motion->Set(MOTIONTYPE_JUMP);

			m_State = STATE_JUMP;
		}

		if (m_bAction == false && m_State == STATE_ATTACK)
		{
			//���[�V�������Z�b�g(�U��)
			m_motion->Set(MOTIONTYPE_ATTACK);

			m_bAction = true;
		}
	}

	if (m_State == STATE_APPR && m_WaitApper == false)
	{
		//���[�V�������Z�b�g(�o���҂�)
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

	pDebugProc->Print("�v���C���[�̈ʒu�F%f,%f,%f\n", Playerpos.x, Playerpos.y, Playerpos.z);
	pDebugProc->Print("�v���C���[�̌����F%f,%f,%f\n", PlayerRot.x, PlayerRot.y, PlayerRot.z);
	pDebugProc->Print("�v���C���[�̈ړ��ʁF%f,%f,%f", m_move.x, m_move.y, m_move.z);
}

//================================================================
//�o������
//================================================================
void CPlayer::Appear(void)
{
	//�v���C���[(�N�\�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�v���C���[(�`�r�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	//���ꂼ��̈ʒu�擾
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
//�`���[�g���A���̃v���C���[�̐��䏈��
//================================================================
void CPlayer::ControlTutorial(void)
{
	
}

//================================================================
//�U������������̏���
//================================================================
void CPlayer::Hit(void)
{
	
}

//================================================================
//�O���t�@�C���ǂݍ���
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

	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::GetTexture();

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

//******************************************************************************************************************************************************
//�`�r�f�u
//******************************************************************************************************************************************************
//=======================================================
//�R���X�g���N�^
//=======================================================
CChibi::CChibi()
{
	m_State = STATE_NONE;
	m_move = { 0.0f,0.0f,0.0f };
}

//=======================================================
//�R���X�g���N�^
//=======================================================
CChibi::CChibi(D3DXVECTOR3 pos)
{
	SetPos(&pos);  //�ʒu
	SetRot(&D3DXVECTOR3(0.0f, 1.57f, 0.0f));
	m_move = { 0.0f,0.0f,0.0f };
	m_State = STATE_NONE;
}

//=======================================================
//�f�X�g���N�^
//=======================================================
CChibi::~CChibi()
{

}

//=======================================================
//����������
//=======================================================
HRESULT CChibi::Init(void)
{
	CPlayer::Init();

	if (m_motion == NULL)
	{
		m_motion = new CMotion;

		//����������
		m_motion->Init();
	}

	CPlayer::ReadText(PLAYER02_TEXT);

	SetbDisp(false);
	SetbAppr(false);

	return S_OK;
}

//=======================================================
//�I������
//=======================================================
void CChibi::Uninit(void)
{
	CPlayer::Uninit();
}

//=======================================================
//�X�V����
//=======================================================
void CChibi::Update(void)
{
	//�}�b�v���f���̏����擾
	CObjectX **pMap = CMap::GetX();

	//�����蔻��̏��擾
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
//�`�揈��
//=======================================================
void CChibi::Draw(void)
{
	if (m_bDisp == true)
	{
		CPlayer::Draw();
	}
}
//******************************************************************************************************************************************************
//�N�\�f�u
//******************************************************************************************************************************************************
//=======================================================
//�R���X�g���N�^
//=======================================================
CFoot::CFoot()
{
	m_move = { 0.0f,0.0f,0.0f };
	m_State = STATE_NONE;
}

//=======================================================
//�R���X�g���N�^
//=======================================================
CFoot::CFoot(D3DXVECTOR3 pos)
{
	SetPos(&pos);  //�ʒu
	SetRot(&D3DXVECTOR3(0.0f, 1.57f, 0.0f));
	m_move = { 0.0f,0.0f,0.0f };
	m_State = STATE_NONE;
}

//=======================================================
//�f�X�g���N�^
//=======================================================
CFoot::~CFoot()
{

}

//=======================================================
//����������
//=======================================================
HRESULT CFoot::Init(void)
{
	CPlayer::Init();

	if (m_motion == NULL)
	{
		m_motion = new CMotion;

		//����������
		m_motion->Init();
	}

	CPlayer::ReadText(PLAYER01_TEXT);

	SetbDisp(true);
	SetbAppr(true);
	
	return S_OK;
}

//=======================================================
//�I������
//=======================================================
void CFoot::Uninit(void)
{
	CPlayer::Uninit();
}

//=======================================================
//�X�V����
//=======================================================
void CFoot::Update(void)
{
	//�}�b�v���f���̏����擾
	CObjectX **pMap = CMap::GetX();

	//�����蔻��̏��擾
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
//�`�揈��
//=======================================================
void CFoot::Draw(void)
{
	if (m_bDisp == true)
	{
		CPlayer::Draw();
	}
}