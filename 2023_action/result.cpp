//===========================================================
//
//���U���g���[result.cpp]
//Author �匴�叫
//
//===========================================================

//*==========================================================
//�C���N���[�h�t�@�C��
//*==========================================================
#include "result.h"
#include "texture.h"
#include "game.h"
#include "debugproc.h"
#include "renderer.h"
#include "sound.h"
#include "UImanager.h"

//===========================================================
//�R���X�g���N�^
//===========================================================
CResult::CResult()
{
	
}

//===========================================================
//�f�X�g���N�^
//===========================================================
CResult::~CResult()
{

}

//===========================================================
//����
//===========================================================
CResult *CResult::Create(void)
{
	CResult *pTitle = NULL;

	if (pTitle == NULL)
	{
		pTitle = new CResult;

		pTitle->Init();
	}

	return pTitle;
}

//===========================================================
//����������
//===========================================================
HRESULT CResult::Init(void)
{
	//�^�C�g���̃��S����
	CUIManager::Create({ SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f }, CUIManager::TYPE_RESULT);

	//�T�E���h���擾
	CSound *pSound = CManager::Getinstance()->GetSound();

	//�T�E���h�Đ�
	pSound->Play(CSound::SOUND_LABEL_BGM001);

	return S_OK;
}

//===========================================================
//�I������
//===========================================================
void CResult::Uninit(void)
{
	//�T�E���h���擾
	CSound *pSound = CManager::Getinstance()->GetSound();

	pSound->Stop();

	CObject::ReleaseAll();
}

//===========================================================
//�X�V����
//===========================================================
void CResult::Update(void)
{
	//���ׂẴI�u�W�F�N�g�̍X�V����
	CObject::UpdateAll();

	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();

	pDebugProc->Print("\n�V�[���F���U���g");
}

//===========================================================
//�`�揈��
//===========================================================
void CResult::Draw(void)
{
	
}