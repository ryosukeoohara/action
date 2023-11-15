//=============================================================================
//
// �󏈗� [sky.cpp]
// Author : �匴�@�叫
//
//=============================================================================
#include "sky.h"
#include "game.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//================================================================
//�R���X�g���N�^
//================================================================
CSky::CSky()
{
	m_nIdxTexture = -1;
}

//================================================================
//�R���X�g���N�^
//================================================================
CSky::CSky(D3DXVECTOR3 pos)
{
	SetPos(&pos);
	m_nIdxTexture = -1;
}

//================================================================
//�f�X�g���N�^
//================================================================
CSky::~CSky()
{

}

//================================================================
//�f�X�g���N�^
//================================================================
CSky *CSky::Create(D3DXVECTOR3 pos)
{
	CSky *pSky = NULL;

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pSky == NULL)
		{
			//��̐���
			pSky = new CSky(pos);

			//����������
			pSky->Init();
		}
	}

	return pSky;
}

//================================================================
//��̏���������
//================================================================
HRESULT CSky::Init(void)
{
	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	D3DXVECTOR3 pos = Getpos();

	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\sky101.jpg");

	//����
	CObjectX::Create(pos, { 0.0f,0.0f,0.0f }, "data\\MODEL\\sky.x");

	//����������
	//CObjectX::Init();

	return S_OK;
}

//================================================================
//��̏I������
//================================================================
void CSky::Uninit(void)
{
	//�I������
	CObjectX::Uninit();

	//�I�u�W�F�N�g�̔j��
	Release();
}

//================================================================
//��̍X�V����
//================================================================
void CSky::Update(void)
{
	//�X�V����
	CObjectX::Update();
}

//================================================================
//��̕`�揈��
//================================================================
void CSky::Draw(void)
{
	CRenderer *pRenderer;
	pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//�`�揈��
	//CObjectX::Draw();
}