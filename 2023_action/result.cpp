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
#include "ranking.h"
#include "score.h"
#include "camera.h"
#include "sky.h"
#include "map.h"

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
	//�J�����擾
	CCamera *pCamera = CManager::Getinstance()->GetCamera();

	pCamera->SetType(CCamera::TYPE_TITLE);

	//�󐶐�
	CSky::Create({ 0.0f,0.0f,0.0f });

	//�}�b�v����
	CMap::Create();

	//�����L���O��̌��o��
	CUIManager::Create({ 400.0f, 100.0f, 0.0f }, CUIManager::TYPE_SCORE);

	//�����N�\��
	CUIManager::Create({ 300.0f, 380.0f, 0.0f }, CUIManager::TYPE_RANK);

	

	//�����L���O�̐���
	CRanking::Create();

	//�����L���O�ݒ�
	CRanking::SetRanking(CScore::Getscore());

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

	//�T�E���h��~
	pSound->Stop();

	//���ׂẴI�u�W�F�N�g�j��
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