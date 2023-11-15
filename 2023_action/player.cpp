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
#include "enemy.h"
#include "UImanager.h"

#include<stdio.h>
#include<time.h>
#include<string.h>

//================================================================
//�}�N����`
//================================================================
#define MAX_LIFECHIBI (10)                                        //�`�r�̗̑�
#define MAX_LIFEFOOT  (6)                                         //�f�u�̗̑�
#define REST_BULLET   (30)                                        //�ێ��ł���e�̐�
#define BULLETWAIT    (15)                                        //�ˌ��̊Ԋu
#define MUTEKITIME    (30)                                        //���G����
#define PLAYER_X      (40.0f)                                     //�v���C���[��X���̕�
#define PLAYER_Z      (10.0f)                                     //�v���C���[��Z���̕�
#define CHIBISPEED    (0.9f)                                      //�`�r�f�u�̑��鑬��
#define FOOTSPEED     (1.1f)                                      //�N�\�f�u�̑��鑬��
#define CHIBIJUMP     (20.0f)                                     //�`�r�f�u�̃W�����v��
#define FOOTJUMP      (22.0f)                                     //�N�\�f�u�̃W�����v��
#define CHIBIGRAVITY  (0.7f)                                      //�`�r�f�u�̏d��
#define FOOTGRAVITY   (0.9f)                                      //�N�\�f�u�̏d��
#define FRIST         (21)                                        //�U�����蔭���J�n
#define FINISH        (31)                                        //�U������I��
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
	
	m_fDiff = 0.0f;
	m_fDest = 0.0f;
	m_bDash = false;
	m_bJump = false;
	m_bAction = false;
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
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	//�V�[���̏����擾
	CScene *pScene = CManager::Getinstance()->GetScene();

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
	CSound *pSound = CManager::Getinstance()->GetSound();

	//�T�E���h�X�g�b�v
	pSound->Stop();

	CObject::Release();
}

//================================================================
//�v���C���[�̍X�V����
//================================================================
void CPlayer::Update(void)
{
	//�L�[�{�[�h�̏����擾
	CInputKeyboard *InputKeyboard = CManager::Getinstance()->GetKeyBoard();

	//�Q�[���p�b�h���擾
	CInputJoyPad *pInputJoyPad = CManager::Getinstance()->GetInputJoyPad();

	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::Getinstance()->GetFade();

	//�V�[���̏����擾
	CScene *pScene = CManager::Getinstance()->GetScene();

	//�v���C���[(�N�\�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�v���C���[(�`�r�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	//�T�E���h���擾
	CSound *pSound = CManager::Getinstance()->GetSound();

	if (pChibi != nullptr && pFoot != nullptr)
	{
		if ((InputKeyboard->GetTrigger(DIK_F) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_Y, 0) == true)
			&& pFoot->GetState() != CFoot::STATE_APPR && pChibi->GetState() != CChibi::STATE_APPR
			&& pFoot->GetState() != CFoot::STATE_JUMP && pChibi->GetState() != CChibi::STATE_JUMP
			&& pFoot->GetState() != CFoot::STATE_ATTACK && pChibi->GetState() != CChibi::STATE_ATTACK
			&& pFoot->GetState() != CFoot::STATE_DEATH && pChibi->GetState() != CChibi::STATE_DEATH
			&& pChibi->GetState() != CChibi::STATE_RELOAD
			&& pChibi->GetState() != CChibi::STATE_DAMAGE && pFoot->GetState() != CFoot::STATE_DAMAGE)
		{//SPACE�L�[�������ꂽ

			//�T�E���h�X�g�b�v
			pSound->Play(CSound::SOUND_LABEL_CHANGE);

			if (pChibi->GetbAppr() == false)
			{
				pChibi->SetbDisp(true);
				pChibi->SetbAppr(true);

				pFoot->SetbDisp(false);
				pFoot->SetbAppr(false);

				pChibi->SetPos(&pFoot->Getpos());
				pChibi->SetRot(&pFoot->GetRot());

				CParticl::Create({ pChibi->Getpos().x, pChibi->Getpos().y, pChibi->Getpos().z }, { 0.0f,0.0f,0.0f }, { 1.0f,1.0f,1.0f,1.0f }, 10.0f, CParticl::TYPEPAR_CIRCLE);
			}

			else if (pFoot->GetbAppr() == false)
			{
				pFoot->SetbDisp(true);
				pFoot->SetbAppr(true);

				pChibi->SetbDisp(false);
				pChibi->SetbAppr(false);

				pFoot->SetPos(&pChibi->Getpos());
				pFoot->SetRot(&pChibi->GetRot());

				CParticl::Create({ pFoot->Getpos().x, pFoot->Getpos().y, pFoot->Getpos().z }, { 0.0f,0.0f,0.0f }, { 1.0f,1.0f,1.0f,1.0f }, 10.0f, CParticl::TYPEPAR_CIRCLE);
			}

			pChibi->SetState(CChibi::STATE_APPR);
			pFoot->SetState(CFoot::STATE_APPR);
		}
	}

	if (pChibi->GetState() == CChibi::STATE_DEATH && pFoot->GetState() == CFoot::STATE_DEATH)
	{
		if (pFade->Get() != pFade->FADE_OUT)
		{
			//�V�[�����^�C�g���ɑJ��
			pFade->Set(CScene::MODE_RESULT);
		}
	}
}

//================================================================
//�v���C���[�̕`�揈��
//================================================================
void CPlayer::Draw(void)
{
	CTexture *pTexture = CManager::Getinstance()->GetTexture();
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
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
//�U������������̏���
//================================================================
void CChibi::Hit(void)
{
	if (m_bDamage != true)
	{
		int life = GetLife();

		life--;

		SetLife(life);

		m_State = STATE_DAMAGE;

		m_bDamage = true;

		m_nCntDamage = 80;
	}
}

//================================================================
//�v���C���[�̐��䏈��(�`�r�f�u)
//================================================================
void CChibi::Control(void)
{
	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();

	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::Getinstance()->GetKeyBoard();

	//�}�E�X���擾
	CInputMouse *pInputMouse = CManager::Getinstance()->GetInputMouse();

	//�Q�[���p�b�h���擾
	CInputJoyPad *pInputJoyPad = CManager::Getinstance()->GetInputJoyPad();

	//�}�E�X�̈ʒu���擾
	D3DXVECTOR2 MousePos = pInputMouse->GetMouseMove();

	//�T�E���h���擾
	CSound *pSound = CManager::Getinstance()->GetSound();

	//�J�����擾
	CCamera *pCamera = CManager::Getinstance()->GetCamera();

	//�J�����̌����擾
	D3DXVECTOR3 CameraRot = pCamera->GetRot();

	//�v���C���[(�`�r�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	//�v���C���[(�N�\�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�ʒu�ƌ������擾
	D3DXVECTOR3 m_pos = pChibi->Getpos();
	D3DXVECTOR3 PlayerRot = pChibi->GetRot();

	if (m_State != STATE_DEATH)
	{
		m_posOld = m_pos;  //�ʒu����

						   //float fHeight;

		if ((m_State != STATE_ATTACK || (m_State == STATE_ATTACK && m_bJump == true) || m_bRand == false) && m_State != STATE_APPR)
		{
			//�d��
			m_move.y -= CHIBIGRAVITY;
		}
		 
		//�����Ă��Ȃ����
		m_bDash = false;

		if (m_State != STATE_APPR && m_State != STATE_ATTACK)
		{
			if (InputKeyboard->GetPress(DIK_W) == true)
			{//W�L�[�������ꂽ

				m_nLife--;
			}

			if (InputKeyboard->GetPress(DIK_S) == true)
			{//W�L�[�������ꂽ

				m_nLife++;
			}

			////��Ɉړ�----------------------------------------------
			//if (InputKeyboard->GetPress(DIK_W) == true || pInputJoyPad->GetXStick(CInputJoyPad::STICK_LY, 0) > 0)
			//{//W�L�[�������ꂽ

			//}
			////���Ɉړ�----------------------------------------------
			//else if (InputKeyboard->GetPress(DIK_S) == true || pInputJoyPad->GetXStick(CInputJoyPad::STICK_LY, 0) < 0)
			//{//S�L�[�������ꂽ

			//}

			//�E�Ɉړ�----------------------------------------------
			if (InputKeyboard->GetPress(DIK_D) == true || pInputJoyPad->GetXStick(CInputJoyPad::STICK_LX, 0) > 0 && m_bAction != true)
			{//D�L�[����������

			 //�ړ���
				m_move.x += sinf(CameraRot.y + (D3DX_PI * 0.5f)) * CHIBISPEED;

				//����
				m_fDest = D3DX_PI * -0.5f;

				//�����Ă����Ԃɂ���
				m_bDash = true;
			}
			//���Ɉړ�----------------------------------------------
			if (InputKeyboard->GetPress(DIK_A) == true || pInputJoyPad->GetXStick(CInputJoyPad::STICK_LX, 0) < 0 && m_bAction != true)
			{//A�L�[����������

			 //�ړ���
				m_move.x -= sinf(CameraRot.y + (D3DX_PI * 0.5f)) * CHIBISPEED;

				//����
				m_fDest = D3DX_PI * 0.5f;

				//�����Ă����Ԃɂ���
				m_bDash = true;
			}

			//�������
			PlayerRot.y = m_fDest;
		}

		if (m_State != STATE_APPR)
		{
			//�W�����v---------------
			if ((InputKeyboard->GetTrigger(DIK_SPACE) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true) && m_bJump == false)
			{//SPACE�L�[�������ꂽ

				m_bJump = true;

				m_move.y += CHIBIJUMP;

				//�T�E���h�X�g�b�v
				pSound->Play(CSound::SOUND_LABEL_SEJUMP00);
			}

			//�U��-------------------
			if ((InputKeyboard->GetPress(DIK_K) == true || pInputJoyPad->GetPress(CInputJoyPad::BUTTON_RB, 0) == true) && m_RestBullet > 0)
			{//K�L�[�������ꂽ

				m_bAction = true;

				if (m_nCntBullet == 0)
				{
					D3DXMATRIX Matrix = m_apModel[5]->GetMtxWorld();

					//�e����
					CBullet::Create(D3DXVECTOR3(Matrix._41, Matrix._42, Matrix._43), D3DXVECTOR3(0.0f, m_fDest, 0.0f), CBullet::TYPE_PLAYER);

					//�T�E���h�X�g�b�v
					pSound->Play(CSound::SOUND_LABEL_SEMAGIC);

					m_RestBullet--;
				}

				if (m_bDash == true)
				{
					m_bDash = false;
				}

				m_nCntBullet++;
			}

			if (m_bDash == true && m_State != STATE_MOVE && m_State != STATE_ATTACK)
			{
				//���[�V�������Z�b�g(�ړ�)
				m_motion->Set(MOTIONTYPE_MOVE);

				m_State = STATE_MOVE;

				m_bAction = false;
			}

			if (m_bDash == false && m_State != STATE_NEUTRAL && m_State != STATE_ATTACK && m_State != STATE_APPR && m_State != STATE_RELOAD)
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

			if ((InputKeyboard->GetPress(DIK_R) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_LB, 0) == true) && m_bJump != true && m_bAction != true && m_State != STATE_RELOAD)
			{
				m_State = STATE_RELOAD;

				m_motion->Set(MOTIONTYPE_RELOAD);

				pSound->Play(CSound::SOUND_LABEL_SEMAGICPOWER);
			}

			if (m_bAction == true && m_bDash != true && m_State != STATE_ATTACK)
			{
				//���[�V�������Z�b�g(�U��)
				m_motion->Set(MOTIONTYPE_ATTACK);

				m_State = STATE_ATTACK;
			}

			if (m_nCntBullet >= BULLETWAIT)
			{
				m_nCntBullet = 0;
			}
		}

		//�ʒu�Ɉړ��ʉ��Z----------------------------------------------------
		m_pos.x += m_move.x;
		m_pos.y += m_move.y;

		//m_pos.y = fHeight + 18.0f;

		//�ړ��ʂ��X�V(����������)--------------------------------------------
		m_move.x += (0.0f - m_move.x) * 0.1f;

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
				pFoot->SetState(CFoot::STATE_NONE);
			}
			else if (m_State == STATE_RELOAD)
			{
				m_RestBullet = REST_BULLET;

				m_State = STATE_NONE;
			}
			else
			{
				m_State = STATE_NONE;

				m_nCntBullet = 0;
			}
		}

		if (m_pos.y <= 0.0f)
		{
			m_pos.y = 0.0f;

			m_move.y = 0.0f;

			m_bJump = false;
		}

		if (m_RestBullet <= 0)
		{
			pDebugProc->Print("\n���؂ꂾ��`�`\n");
		}

		if (m_bDash == true && m_nCntSound == 0)
		{
			m_nCntSound = 35;

			pSound->Play(CSound::SOUND_LABEL_SEASIOTO);
		}

		if (m_nCntSound > 0)
		{
			m_nCntSound--;
		}

		if (m_bDamage == true)
		{
			m_nCntDamage--;

			if (m_nCntDamage <= 0)
			{
				m_bDamage = false;
			}
		}
	}
	
	SetPos(&m_pos);
	SetRot(&PlayerRot);

	pFoot->SetPos(&m_pos);

	pDebugProc->Print("\n�v���C���[�̈ʒu�F%f,%f,%f\n", m_pos.x, m_pos.y, m_pos.z);
	pDebugProc->Print("�v���C���[�̌����F%f,%f,%f\n", PlayerRot.x, PlayerRot.y, PlayerRot.z);
	pDebugProc->Print("�v���C���[�̈ړ��ʁF%f,%f,%f\n", m_move.x, m_move.y, m_move.z);
	pDebugProc->Print("�c��̒e���F%d", m_RestBullet);
}

//================================================================
//�U������������̏���
//================================================================
void CFoot::Hit(void)
{
	if (m_bDamage != true)
	{
		m_nLife--;

		m_State = STATE_DAMAGE;

		m_bDamage = true;

		m_nCntDamage = 80;
	}
}

//================================================================
//�v���C���[�̐��䏈��(�N�\�f�u)
//================================================================
void CFoot::Control(void)
{
	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();

	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::Getinstance()->GetKeyBoard();

	//�}�E�X���擾
	CInputMouse *pInputMouse = CManager::Getinstance()->GetInputMouse();

	//�Q�[���p�b�h���擾
	CInputJoyPad *pInputJoyPad = CManager::Getinstance()->GetInputJoyPad();

	//�}�E�X�̈ʒu���擾
	D3DXVECTOR2 MousePos = pInputMouse->GetMouseMove();

	//�T�E���h���擾
	CSound *pSound = CManager::Getinstance()->GetSound();

	//�J�����擾
	CCamera *pCamera = CManager::Getinstance()->GetCamera();

	//�J�����̌����擾
	D3DXVECTOR3 CameraRot = pCamera->GetRot();

	//�����蔻��̏��擾
	CCollision *pCollision = CGame::GetCollsion();

	//�G�̏��擾
	CEnemy **pEnemy = CEnemy::GetEnemy();

	//�v���C���[(�`�r�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�v���C���[(�`�r�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	//�ʒu�ƌ������擾
	D3DXVECTOR3 m_pos = pFoot->Getpos();
	D3DXVECTOR3 PlayerRot = pFoot->GetRot();

	if (m_State != STATE_DEATH)
	{
		m_posOld = m_pos;  //�ʒu����

						   //float fHeight;

		m_bRand = false;

		if ((m_bRand != true || m_bJump == true) && m_State != STATE_APPR)
		{
			//�d��
			m_move.y -= FOOTGRAVITY;
		}
		
		//�����Ă��Ȃ����
		m_bDash = false;

		if (m_State != STATE_APPR)
		{
			////��Ɉړ�----------------------------------------------
			//if (InputKeyboard->GetPress(DIK_W) == true)
			//{//W�L�[�������ꂽ

			//}
			////���Ɉړ�----------------------------------------------
			//else if (InputKeyboard->GetPress(DIK_S) == true)
			//{//S�L�[�������ꂽ

			//}
			//�E�Ɉړ�----------------------------------------------
			if (InputKeyboard->GetPress(DIK_D) == true || pInputJoyPad->GetXStick(CInputJoyPad::STICK_LX, 0) > 0 && m_bAttack != true)
			{//D�L�[����������

			 //�ړ���
				m_move.x += sinf((D3DX_PI * 0.5f)) * FOOTSPEED;
				m_move.z += cosf((D3DX_PI * 0.5f)) * FOOTSPEED;

				//����
				m_fDest = ((D3DX_PI * -0.5f));

				//�����Ă����Ԃɂ���
				m_bDash = true;
			}
			//���Ɉړ�----------------------------------------------
			if (InputKeyboard->GetPress(DIK_A) == true || pInputJoyPad->GetXStick(CInputJoyPad::STICK_LX, 0) < 0 && m_bAttack != true)
			{//A�L�[����������

			 //�ړ���
				m_move.x -= sinf((D3DX_PI * 0.5f)) * FOOTSPEED;
				m_move.z -= cosf((D3DX_PI * 0.5f)) * FOOTSPEED;

				//����
				m_fDest = ((D3DX_PI * 0.5f));

				//�����Ă����Ԃɂ���
				m_bDash = true;
			}

			PlayerRot.y = m_fDest;


			//�W�����v------------
			if ((InputKeyboard->GetTrigger(DIK_SPACE) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true) && m_bJump == false && m_bAttack != true)
			{//SPACE�L�[�������ꂽ

				m_bJump = true;

				m_move.y += FOOTJUMP;

				//�T�E���h�X�g�b�v
				pSound->Play(CSound::SOUND_LABEL_SEJUMP01);
			}

			//�U��----------------
			if (InputKeyboard->GetTrigger(DIK_K) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_RB, 0) == true && m_bAttack == false)
			{//K�L�[�������ꂽ

				m_bAttack = true;

				//�T�E���h�X�g�b�v
				pSound->Play(CSound::SOUND_LABEL_SESWORD);

				//m_State = STATE_ATTACK;
			}

			if (m_bAttack == true)
			{
				m_nCntColi++;

				if (m_nCntColi >= 10 && 30 >= m_nCntColi)
				{
					if (pCollision != NULL)
					{
						if (pCollision->Sword(m_apModel[28]->GetMtxWorld(), m_apModel[28]->GetMtxWorld(), 100.0f, pEnemy) == true)
						{
							int n = 0;
						}
					}
				}
			}

			if (m_bDash == true && m_bAttack == false
				&& m_State != STATE_MOVE && m_State != STATE_ATTACK)
			{
				//���[�V�������Z�b�g(�ړ�)
				m_motion->Set(MOTIONTYPE_MOVE);

				m_State = STATE_MOVE;
			}

			if (m_bDash == false && m_bAttack == false
				&& m_State != STATE_NEUTRAL && m_State != STATE_ATTACK && m_State != STATE_APPR)
			{
				//���[�V�������Z�b�g(�ړ�)
				m_motion->Set(MOTIONTYPE_NEUTRAL);

				m_State = STATE_NEUTRAL;
			}

			if (m_bJump == true && m_bAttack == false && m_State != STATE_JUMP)
			{
				//���[�V�������Z�b�g(�ړ�)
				m_motion->Set(MOTIONTYPE_JUMP);

				m_State = STATE_JUMP;
			}

			if (m_bAttack == true && m_bDash != true && m_State != STATE_ATTACK)
			{
				//���[�V�������Z�b�g(�U��)
				m_motion->Set(MOTIONTYPE_ATTACK);

				m_State = STATE_ATTACK;
			}
		}

		//�ʒu�Ɉړ��ʉ��Z----------------------------------------------------
		m_pos.x += m_move.x;
		m_pos.y += m_move.y;

		//m_pos.y = fHeight + 18.0f;

		//�ړ��ʂ��X�V(����������)--------------------------------------------
		m_move.x += (0.0f - m_move.x) * 0.1f;

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
			m_bAttack = false;

			if (m_State == STATE_APPR)
			{
				m_WaitApper = false;

				pChibi->SetState(CChibi::STATE_NONE);
				pFoot->SetState(STATE_NONE);
			}
			else
			{
				m_State = STATE_NONE;
			}
		}

		if (m_pos.y <= 0.0f)
		{
			m_pos.y = 0.0f;

			m_move.y = 0.0f;

			m_bJump = false;
		}

		if (m_bDash == true && m_nCntSound == 0)
		{
			m_nCntSound = 35;

			pSound->Play(CSound::SOUND_LABEL_SEASIOTO);
		}

		if (m_nCntSound > 0)
		{
			m_nCntSound--;
		}

		if (m_bDamage == true)
		{
			m_nCntDamage--;

			if (m_nCntDamage <= 0)
			{
				m_bDamage = false;
			}
		}
	}

	SetPos(&m_pos);
	SetRot(&PlayerRot);

	pChibi->SetPos(&m_pos);

	pDebugProc->Print("\n�v���C���[�̈ʒu�F%f,%f,%f\n", m_pos.x, m_pos.y, m_pos.z);
	pDebugProc->Print("�v���C���[�̌����F%f,%f,%f\n", PlayerRot.x, PlayerRot.y, PlayerRot.z);
	pDebugProc->Print("�v���C���[�̈ړ��ʁF%f,%f,%f", m_move.x, m_move.y, m_move.z);
	pDebugProc->Print("\n���� : %d", m_nCntColi);
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

	if (pChibi->GetState() == CChibi::STATE_APPR && pChibi->GetbAppr() == true)
	{
		pChibi->SetMove({ -0.1f, 0.0f , 0.0f });
	}
	else if (pChibi->GetState() == CChibi::STATE_APPR && pChibi->GetbAppr() == false)
	{
		pChibi->SetMove({ 0.1f, 0.0f , 0.0f });
	}

	if (pFoot->GetState() == CFoot::STATE_APPR && pFoot->GetbAppr() == false)
	{
		pFoot->SetMove({ 0.1f, 0.0f , 0.0f });
	}
	else if (pFoot->GetState() == CFoot::STATE_APPR && pFoot->GetbAppr() == true)
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
	//�v���C���[(�N�\�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�v���C���[(�`�r�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	if (pFoot->GetbAppr() == true)
	{
		pFoot->Hit();
	}

	if (pChibi->GetbAppr() == true)
	{
		pChibi->Hit();
	}
}

//================================================================
//�O���t�@�C���ǂݍ���
//================================================================
void CFoot::ReadText(const char *fliename)
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

//================================================================
//�O���t�@�C���ǂݍ���
//================================================================
void CChibi::ReadText(const char *fliename)
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

//******************************************************************************************************************************************************
//�`�r�f�u
//******************************************************************************************************************************************************
//=======================================================
//�R���X�g���N�^
//=======================================================
CChibi::CChibi()
{
	SetLife(MAX_LIFECHIBI);
	m_State = STATE_NONE;
	m_TitleState = TITLE_STATE_NONE;
	m_move = { 0.0f,0.0f,0.0f };
	m_nCntBullet = 0;
	m_nLife = 0;
	m_nCntDamage = 0;
	m_bRand = false;
	m_bDamage = false;
	m_motion = NULL;
}

//=======================================================
//�R���X�g���N�^
//=======================================================
CChibi::CChibi(D3DXVECTOR3 pos)
{
	CObject::SetPos(&pos);  //�ʒu
	SetLife(MAX_LIFECHIBI);
	m_pos = pos;
	SetRot(&D3DXVECTOR3(0.0f, -1.57f, 0.0f));
	m_move = { 0.0f,0.0f,0.0f };
	m_State = STATE_NONE;
	m_TitleState = TITLE_STATE_NONE;
	m_nCntBullet = 0;
	m_nLife = 0;
	m_nCntDamage = 0;
	m_bRand = false;
	m_bDamage = false;
	m_motion = NULL;
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

	//�e�̍ő吔�ݒ�
	m_RestBullet = REST_BULLET;

	//�e�L�X�g�t�@�C���ǂݍ���
	ReadText(PLAYER02_TEXT);

	//�̗͐ݒ�
	m_nLife = MAX_LIFECHIBI;

	

	if (CScene::GetMode() == CScene::MODE_GAME)
	{
		//�̗̓Q�[�W��UI
		CUIManager::Create({ 125.0f, 50.0f, 0.0f }, CUIManager::TYPE_LIFECHIBI);

		//�A�C�R��
		CUIManager::Create({ 25.0f, 50.0f, 0.0f }, CUIManager::TYPE_ICONCHIBI);

		//�c�e�\��UI
		CUIManager::Create({ 100.0f, 150.0f, 0.0f }, CUIManager::TYPE_GUNGAGE);

		//���@UI
		CUIManager::Create({ 50.0f, 150.0f, 0.0f }, CUIManager::TYPE_MAGIC);

		m_fDest = -1.57f;
	}

	if (CScene::GetMode() == CScene::MODE_GAME)
	{
		//�`�悵�Ȃ�
		SetbDisp(false);

		//�o�����Ȃ�
		SetbAppr(false);
	}
	else
	{
		//�`�悵�Ȃ�
		SetbDisp(true);

		//�o�����Ȃ�
		SetbAppr(true);

		SetRot(&D3DXVECTOR3( 0.0f , (D3DX_PI * -0.5f) , 0.0f ));
	}


	return S_OK;
}

//=======================================================
//�I������
//=======================================================
void CChibi::Uninit(void)
{
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

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{//�g�p���Ă�����

			m_apModel[nCount]->Uninit();  //�I������
										  //delete m_apModel[nCount];  //���������J��
			m_apModel[nCount] = NULL;  //�g�p���Ă��Ȃ���Ԃɂ���
		}
	}

	CPlayer::Uninit();
}

//=======================================================
//�X�V����
//=======================================================
void CChibi::Update(void)
{
	//�}�b�v���f���̏����擾
	CMap *pmap = CGame::GetMap();

	//�����蔻��̏��擾
	CCollision *pCollision = CGame::GetCollsion();

	//�G�̏��擾
	CEnemy **pEnemy = CEnemy::GetEnemy();

	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::Getinstance()->GetFade();

	if (CScene::GetMode() == CScene::MODE_GAME)
	{
		CPlayer::Update();
	}

	if (m_nLife > 0)
	{
		if (m_bAppr == true)
		{
			m_bRand = false;

			if (CScene::GetMode() == CScene::MODE_GAME)
			{
				Control();
			}
			else
			{
				D3DXVECTOR3 pos = Getpos();

				if (m_TitleState != TITLE_STATE_NEUTRAL && m_TitleState != TITLE_STATE_MOVE)
				{
					m_motion->Set(MOTIONTYPE_TITLE);

					m_TitleState = TITLE_STATE_NEUTRAL;
				}

				if (m_TitleState == TITLE_STATE_MOVE && m_bDash != true)
				{
					m_motion->Set(MOTIONTYPE_MOVE);

					m_bDash = true;
				}

				if (m_TitleState == TITLE_STATE_MOVE && m_bDash == true)
				{
					//�ړ���
					m_move.x += sinf((D3DX_PI * 0.5f)) * CHIBISPEED;
				}

				pos.x += m_move.x;

				//�ړ��ʂ��X�V(����������)--------------------------------------------
				m_move.x += (0.0f - m_move.x) * 0.1f;

				SetPos(&pos);
			}

			if (pmap != nullptr)
			{
				if (pCollision != nullptr && pmap->GetX() != nullptr)
				{
					(pCollision->Map(&Getpos(), &m_posOld, pmap->GetX()));
				}

				if (pCollision != nullptr)
				{
					if (pCollision->Enemy(&Getpos(), &m_posOld, 30.0f, 30.0f, pEnemy) == true)
					{
						Hit();
					}
				}
			}
		}

		for (int nCount = 0; nCount < m_nNumModel; nCount++)
		{
			m_apModel[nCount]->Update();
		}

		if (m_motion != nullptr)
		{
			//����������
			m_motion->Update();
		}
	}
	else
	{
		//�I������
		//Uninit();

		m_State = STATE_DEATH;

		//�v���C���[(�N�\�f�u)�̏����擾
		CFoot *pFoot = CGame::GetPlayerFoot();

		if (pFoot != nullptr)
		{
			if (pFoot->GetbAppr() == false && pFoot->GetState() != CChibi::STATE_DEATH)
			{
				pFoot->SetState(CFoot::STATE_APPR);

				pFoot->SetbDisp(true);
				pFoot->SetbAppr(true);

				SetbDisp(false);
				SetbAppr(false);
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

		for (int nCount = 0; nCount < m_nNumModel; nCount++)
		{
			//�`�揈��
			m_apModel[nCount]->Draw();
		}
	}
}
CChibi * CChibi::Create(D3DXVECTOR3 pos)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CChibi *pPlayer = NULL;

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pPlayer == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pPlayer = new CChibi(pos);

			//����������
			pPlayer->Init();
		}
	}

	return pPlayer;
}
//******************************************************************************************************************************************************
//�N�\�f�u
//******************************************************************************************************************************************************
//=======================================================
//�R���X�g���N�^
//=======================================================
CFoot::CFoot()
{
	SetLife(MAX_LIFEFOOT);
	m_move = { 0.0f,0.0f,0.0f };
	m_State = STATE_NONE;
	m_TitleState = TITLE_STATE_NONE;
	m_nLife = 0;
	m_nCntDamage = 0;
	m_bRand = false;
	m_motion = NULL;
}

//=======================================================
//�R���X�g���N�^
//=======================================================
CFoot::CFoot(D3DXVECTOR3 pos)
{
	CObject::SetPos(&pos);  //�ʒu]
	SetLife(MAX_LIFEFOOT);
	m_pos = pos;
	SetRot(&D3DXVECTOR3(0.0f, -1.57f, 0.0f));
	m_move = { 0.0f,0.0f,0.0f };
	m_nLife = 0;
	m_nCntDamage = 0;
	m_State = STATE_NONE;
	m_TitleState = TITLE_STATE_NONE;
	m_bRand = false;
	m_motion = NULL;
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

	//�e�L�X�g�t�@�C���ǂݍ���
	ReadText(PLAYER01_TEXT);

	//�̗͐ݒ�
	m_nLife = MAX_LIFEFOOT;

	SetLife(MAX_LIFEFOOT);

	if (CScene::GetMode() == CScene::MODE_GAME)
	{
		//�̗̓Q�[�W��UI
		CUIManager::Create({ 350.0f, 50.0f, 0.0f }, CUIManager::TYPE_LIFEFOOT);

		//�A�C�R��
		CUIManager::Create({ 250.0f, 50.0f, 0.0f }, CUIManager::TYPE_ICONFOOT);

		m_fDest = -1.57f;
	}
	else
	{
		SetRot(&D3DXVECTOR3(0.0f, (D3DX_PI * -0.5f), 0.0f));
	}

	//�`�悷��
	SetbDisp(true);

	//�o����Ԃɂ���
	SetbAppr(true);
	
	return S_OK;
}

//=======================================================
//�I������
//=======================================================
void CFoot::Uninit(void)
{
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

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{//�g�p���Ă�����

			m_apModel[nCount]->Uninit();  //�I������
										  //delete m_apModel[nCount];  //���������J��
			m_apModel[nCount] = NULL;  //�g�p���Ă��Ȃ���Ԃɂ���
		}
	}

	CPlayer::Uninit();
}

//=======================================================
//�X�V����
//=======================================================
void CFoot::Update(void)
{
	CMap *pmap = CGame::GetMap();

	//�����蔻��̏��擾
	CCollision *pCollision = CGame::GetCollsion();

	//�G�̏��擾
	CEnemy **pEnemy = CEnemy::GetEnemy();

	if (CScene::GetMode() == CScene::MODE_GAME)
	{
		CPlayer::Update();
	}
	
	if (m_nLife > 0)
	{
		if (m_bAppr == true)
		{
			m_bRand = false;

			if (CScene::GetMode() == CScene::MODE_GAME)
			{
				Control();

				
			}
			else
			{
				D3DXVECTOR3 pos = Getpos();

				if (m_TitleState != TITLE_STATE_NEUTRAL && m_TitleState != TITLE_STATE_MOVE)
				{
					m_motion->Set(MOTIONTYPE_TITLE);

					m_TitleState = TITLE_STATE_NEUTRAL;
				}

				if (m_TitleState == TITLE_STATE_MOVE && m_bDash != true)
				{
					m_motion->Set(MOTIONTYPE_MOVE);

					m_bDash = true;
				}

				if (m_TitleState == TITLE_STATE_MOVE && m_bDash == true)
				{
					//�ړ���
					m_move.x += sinf((D3DX_PI * 0.5f)) * CHIBISPEED;
				}

				pos.x += m_move.x;

				//�ړ��ʂ��X�V(����������)--------------------------------------------
				m_move.x += (0.0f - m_move.x) * 0.1f;

				SetPos(&pos);
			}

			if (pmap != NULL)
			{
				//�}�b�v���f���̏����擾
				//CObjectX **pMap = CMap::GetX();

				if (pCollision != NULL && pmap->GetX() != NULL)
				{
					(pCollision->Map(&Getpos(), &m_posOld, pmap->GetX()));
				}

				if (pCollision != nullptr)
				{
					if (pCollision->Enemy(&Getpos(), &m_posOld, 30.0f, 30.0f, pEnemy) == true)
					{
						Hit();
					}
				}
			}
		}

		for (int nCount = 0; nCount < m_nNumModel; nCount++)
		{
			m_apModel[nCount]->Update();
		}

		if (m_motion != NULL)
		{
			//����������
			m_motion->Update();
		}
	}
	else
	{
		//�I������
		//Uninit();

		m_State = STATE_DEATH;

		//�v���C���[(�N�\�f�u)�̏����擾
		CChibi *pChibi = CGame::GetPlayerChibi();

		if (pChibi != nullptr)
		{
			if (pChibi->GetbAppr() == false && pChibi->GetState() != CChibi::STATE_DEATH)
			{
				pChibi->SetState(CChibi::STATE_APPR);

				pChibi->SetbDisp(true);
				pChibi->SetbAppr(true);

				SetbDisp(false);
				SetbAppr(false);
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

		for (int nCount = 0; nCount < m_nNumModel; nCount++)
		{
			//�`�揈��
			m_apModel[nCount]->Draw();
		}
	}
}

CFoot * CFoot::Create(D3DXVECTOR3 pos)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CFoot *pPlayer = NULL;

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pPlayer == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pPlayer = new CFoot(pos);

			//����������
			pPlayer->Init();
		}
	}

	return pPlayer;
}
