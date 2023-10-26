//===========================================================
//
//�|���S�����o�����[title.cpp]
//Author �匴�叫
//
//===========================================================

//*==========================================================
//�C���N���[�h�t�@�C��
//*==========================================================
#include "title.h"
#include "texture.h"
#include "game.h"
#include "debugproc.h"
#include "renderer.h"
#include "sound.h"
#include "UImanager.h"
#include "camera.h"
#include "sky.h"
#include "player.h"
#include "field.h"
#include "map.h"
#include "input.h"
#include "fade.h"

//*==========================================================
//�ÓI�����o�ϐ�
//*==========================================================
CChibi *CTitle::m_PlayerChibi = nullptr;
CFoot *CTitle::m_PlayerFoot = nullptr;

//===========================================================
//�R���X�g���N�^
//===========================================================
CTitle::CTitle()
{
	
}

//===========================================================
//�f�X�g���N�^
//===========================================================
CTitle::~CTitle()
{

}

//===========================================================
//����
//===========================================================
CTitle *CTitle::Create(void)
{
	CTitle *pTitle = NULL;

	if (pTitle == NULL)
	{
		pTitle = new CTitle;

		pTitle->Init();
	}

	return pTitle;
}

//===========================================================
//����������
//===========================================================
HRESULT CTitle::Init(void)
{
	//�J�����擾
	CCamera *pCamera = CManager::Getinstance()->GetCamera();

	pCamera->SetType(CCamera::TYPE_TITLE);

	CSky::Create({ 0.0f,0.0f,0.0f });

	CMap::Create();

	if (m_PlayerChibi == nullptr)
	{
		m_PlayerChibi = new CChibi({ -650.0f, 30.0f, 0.0f });

		m_PlayerChibi->Init();
	}

	if (m_PlayerFoot == nullptr)
	{
		m_PlayerFoot = new CFoot({ -675.0f, 30.0f, -50.0f });

		m_PlayerFoot->Init();
	}

	//�^�C�g���̃��S����
	CUIManager::Create({ 100.0f, 180.0f, 0.0f }, CUIManager::TYPE_TITLE);

	//�T�E���h���擾
	CSound *pSound = CManager::Getinstance()->GetSound();
	pSound->Play(CSound::SOUND_LABEL_BGM002);

	return S_OK;
}

//===========================================================
//�I������
//===========================================================
void CTitle::Uninit(void)
{
	//�T�E���h���擾
	CSound *pSound = CManager::Getinstance()->GetSound();

	//�T�E���h��~
	pSound->Stop();

	if (m_PlayerChibi != nullptr)
	{
		m_PlayerChibi->Uninit();

		m_PlayerChibi = nullptr;
	}

	if (m_PlayerFoot != nullptr)
	{
		m_PlayerFoot->Uninit();

		m_PlayerFoot = nullptr;
	}

	//���ׂẴI�u�W�F�N�g�j��
	CObject::ReleaseAll();
}

//===========================================================
//�X�V����
//===========================================================
void CTitle::Update(void)
{
	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::Getinstance()->GetKeyBoard();

	//�}�E�X���擾
	CInputMouse *pInputMouse = CManager::Getinstance()->GetInputMouse();

	//�Q�[���p�b�h���擾
	CInputJoyPad *pInputJoyPad = CManager::Getinstance()->GetInputJoyPad();

	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::Getinstance()->GetFade();

	if (InputKeyboard->GetTrigger(DIK_RETURN) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true)
	{//ENTER�L�[�����������V�[�����^�C�g���̂Ƃ�

		m_PlayerFoot->SetTState(CFoot::TITLE_STATE_MOVE);

		m_PlayerChibi->SetTState(CChibi::TITLE_STATE_MOVE);

		if (pFade->Get() != pFade->FADE_OUT)
		{
			//�V�[�����Q�[���ɑJ��
			pFade->Set(CScene::MODE_GAME);
		}
	}

	//���ׂẴI�u�W�F�N�g�̍X�V����
	CObject::UpdateAll();

	CDebugProc *pDebugProc = CManager::Getinstance()->Getinstance()->GetDebugProc();
	pDebugProc->Print("\n�V�[���F�^�C�g��");
}

//===========================================================
//�`�揈��
//===========================================================
void CTitle::Draw(void)
{
	
}