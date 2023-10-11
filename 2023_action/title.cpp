//===========================================================
//
//�|���S�����o�����[title.cpp]
//Author �匴�叫
//
//===========================================================
#include "title.h"
#include "texture.h"
#include "game.h"
#include "debugproc.h"
#include "renderer.h"
#include "sound.h"

//===========================================================
//�R���X�g���N�^
//===========================================================
CTitle::CTitle()
{
	for (int nCount = 0; nCount < MAX_TITLEOBJ; nCount++)
	{
		m_apObject2D[nCount] = NULL;
		m_apObject3D[nCount] = NULL;
	}
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
	//�T�E���h���擾
	CSound *pSound = CManager::GetSound();
	pSound->Play(CSound::SOUND_LABEL_BGM002);

	return S_OK;
}

//===========================================================
//�I������
//===========================================================
void CTitle::Uninit(void)
{
	//�T�E���h���擾
	CSound *pSound = CManager::GetSound();

	pSound->Stop();

	CObject::ReleaseAll();
}

//===========================================================
//�X�V����
//===========================================================
void CTitle::Update(void)
{
	//���ׂẴI�u�W�F�N�g�̍X�V����
	CObject::UpdateAll();

	CDebugProc *pDebugProc = CManager::GetDebugProc();
	pDebugProc->Print("\n�V�[���F�^�C�g��");
}

//===========================================================
//�`�揈��
//===========================================================
void CTitle::Draw(void)
{
	
}