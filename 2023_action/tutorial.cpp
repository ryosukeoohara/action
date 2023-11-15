//===============================================================
//
//�`���[�g���A������[tutorial.cpp]
// Author �匴�叫
//
//===============================================================
#include "tutorial.h"
#include "input.h"
#include "sound.h"
#include "UImanager.h"
#include "fade.h"

//===============================================================
//�R���X�g���N�^
//===============================================================
CTutorial::CTutorial()
{
	
}

//===============================================================
//�f�X�g���N�^
//===============================================================
CTutorial::~CTutorial()
{

}

//===============================================================
//�N���G�C�g
//===============================================================
CTutorial * CTutorial::Create(void)
{
	CTutorial *pTutorial = NULL;

	if (pTutorial == NULL)
	{
		pTutorial = new CTutorial;

		pTutorial->Init();
	}

	return pTutorial;
}

//===============================================================
//����������
//===============================================================
HRESULT CTutorial::Init(void)
{
	//�T�E���h���擾
	CSound *pSound = CManager::Getinstance()->GetSound();

	//�^�C�g���̃��S����
	CUIManager::Create({ 0.0f, SCREEN_HEIGHT * 0.5f, 0.0f }, CUIManager::TYPE_TUTORIAL);

	pSound->Play(CSound::SOUND_LABEL_BGM003);

	return S_OK;
}

//===============================================================
//�I������
//===============================================================
void CTutorial::Uninit(void)
{
	//�T�E���h���擾
	CSound *pSound = CManager::Getinstance()->GetSound();

	pSound->Stop();

	//���ׂẴI�u�W�F�N�g�j��
	CObject::ReleaseAll();
}

//===============================================================
//�X�V����
//===============================================================
void CTutorial::Update(void)
{
	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();

	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::Getinstance()->GetKeyBoard();

	//�Q�[���p�b�h���擾
	CInputJoyPad *pInputJoyPad = CManager::Getinstance()->GetInputJoyPad();

	//�V�[���̏����擾
	CScene *pScene = CManager::Getinstance()->GetScene();

	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::Getinstance()->GetFade();

	if (InputKeyboard->GetTrigger(DIK_RETURN) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true)
	{//ENTER�L�[�����������V�[�����^�C�g���̂Ƃ�

		if (pFade->Get() != pFade->FADE_OUT)
		{
			//�V�[�����Q�[���ɑJ��
			pFade->Set(CScene::MODE_GAME);
		}
	}

	//���ׂẴI�u�W�F�N�g�̍X�V����
	CObject::UpdateAll();
}

//===============================================================
//�`�揈��
//===============================================================
void CTutorial::Draw(void)
{
	
}