//=============================================================================
//
// ���f������ [model->cpp]
// Author : �匴�@�叫
//
//=============================================================================

//*============================================================================
//�C���N���[�h�t�@�C��
//*============================================================================
#include "model.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"

//================================================================
//�R���X�g���N�^
//================================================================
CModel::CModel()
{
	for (int nCount = 0; nCount < MAX_MODEL; nCount++)
	{
		m_aModel[nCount]->aName[MAX_CHAR] = {};
		m_aModel[nCount]->m_dwNumMat = NULL;
		m_aModel[nCount]->m_pBuffMat = NULL;
		m_aModel[nCount]->m_pMesh = NULL;
	}
}

//================================================================
//�f�X�g���N�^
//================================================================
CModel::~CModel()
{

}

//================================================================
//����������
//================================================================
HRESULT CModel::Load(void)
{
	return S_OK;
}

//================================================================
//�I������
//================================================================
void CModel::UnLoad(void)
{
	for (int nCount = 0; nCount < MAX_MODEL; nCount++)
	{
		m_aModel[nCount]->aName[MAX_CHAR] = {};
		m_aModel[nCount]->m_dwNumMat = NULL;
		m_aModel[nCount]->m_pBuffMat = NULL;
		m_aModel[nCount]->m_pMesh = NULL;
	}

	m_nNumAll = 0;
}

//================================================================
//�w��̃e�N�X�`���ǂݍ���
//================================================================
int CModel::Regist(const char *pFilename)
{
	//�f�o�C�X�̎擾
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	for (int nCount = 0; nCount < m_nNumAll; nCount++)
	{
		if (strcmp(pFilename, m_aModel[nCount]->aName) == 0)
		{
			return nCount;
		}
	}

	for (int nCount = 0; nCount < MAX_MODEL; nCount++)
	{
		//X�t�@�C���ǂݍ���
		D3DXLoadMeshFromX(pFilename,
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&m_aModel[nCount]->m_pBuffMat,
			NULL,
			&m_aModel[nCount]->m_dwNumMat,
			&m_aModel[nCount]->m_pMesh);

		m_aModel[nCount]->m_pIdxTexture = new int [m_aModel[nCount]->m_dwNumMat];

		//�}�e���A���ւ̃|�C���^
		D3DXMATERIAL *pMat;

		//�}�e���A�����ɑ΂���|�C���^���擾
		pMat = (D3DXMATERIAL*)m_aModel[nCount]->m_pBuffMat->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)m_aModel[nCount]->m_dwNumMat; nCntMat++)
		{
			if (pMat[nCntMat].pTextureFilename != NULL)
			{//�e�N�X�`�������݂���

				m_aModel[nCount]->m_pIdxTexture[nCntMat] = pTexture->Regist(pMat[nCntMat].pTextureFilename);
			}
			else
			{
				m_aModel[nCount]->m_pIdxTexture[nCntMat] = -1;
			}
		}

		m_nIdxModel = nCount;

		break;
	}

	return m_nIdxModel;
}

////================================================================
////�e�N�X�`���̃A�h���X�擾
////================================================================
//LPDIRECT3DTEXTURE9 CModel::GetAddress(int nIdx)
//{
//	if (nIdx >= 0)
//	{
//		return m_aTexture[nIdx]->m_pTexture;
//	}
//	else
//	{
//		return NULL;
//	}
//}
