//=============================================================================
//
// �e�N�X�`������ [texture.cpp]
// Author : �匴�@�叫
//
//=============================================================================
#include "texture.h"
#include "manager.h"
#include "renderer.h"
#include<string.h>

//================================================================
//�ÓI�����o�ϐ�
//================================================================
int CTexture::m_nNumAll = 0;

//================================================================
//�R���X�g���N�^
//================================================================
CTexture::CTexture()
{
	
}

//================================================================
//�f�X�g���N�^
//================================================================
CTexture::~CTexture()
{
	
}

//================================================================
//����������
//================================================================
HRESULT CTexture::Load(void)
{
	for (int nCount = 0; nCount < MAX_TEXTURE; nCount++)
	{
		m_aTexture[nCount].m_pTexture = NULL;
	}

	return S_OK;
}

//================================================================
//�I������
//================================================================
void CTexture::UnLoad(void)
{
	for (int nCount = 0; nCount < MAX_TEXTURE; nCount++)
	{
		if (m_aTexture[nCount].m_pTexture != NULL)
		{
			m_aTexture[nCount].m_pTexture = NULL;
		}
	}

	m_nNumAll = 0;
}

//================================================================
//�w��̃e�N�X�`���ǂݍ���
//================================================================
int CTexture::Regist(const char *pFilename)
{
	//�f�o�C�X���擾
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	int nIdx = m_nNumAll;

	for (int nCount = 0; nCount < m_nNumAll; nCount++)
	{
		if (strcmp(pFilename, m_aTexture[nCount].aName) == 0)
		{
			return nCount;
		}
	}

	if (m_aTexture[nIdx].m_pTexture == NULL)
	{//�g�p����Ă��Ȃ�������

		strcpy(m_aTexture[nIdx].aName, pFilename);

		//�e�N�X�`���̓ǂݍ���
		D3DXCreateTextureFromFile(pDevice, m_aTexture[nIdx].aName, &m_aTexture[nIdx].m_pTexture);

		m_nNumAll++;  //�e�N�X�`���̑������J�E���g�A�b�v
	}
	
	return nIdx;
}

//================================================================
//�e�N�X�`���̃A�h���X�擾
//================================================================
LPDIRECT3DTEXTURE9 CTexture::GetAddress(int nIdx)
{
	if (nIdx >= 0)
	{
		return m_aTexture[nIdx].m_pTexture;
	}
	else
	{
		return NULL;
	}
}
