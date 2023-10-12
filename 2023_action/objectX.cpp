//=============================================================================
//
// �|���S�����o����� [object3D.cpp]
// Author : �匴�@�叫
//
//=============================================================================
#include "main.h"
#include "objectX.h"
#include "renderer.h"
#include "manager.h"
#include "debugproc.h"
#include "texture.h"

//�}�N����`
//#define MAX_TEXTURE     (8)
#define MOVELIMIT       (580.0f)
#define PLAYERMOVE      (0.5f)     //�v���C���[�̃X�s�[�h
#define PLAYERDESH      (10.0f)    //�_�b�V���̃X�s�[�h
#define PlAYERLOWMOVE   (0.1f)     //����

//================================================================
//�ÓI�����o�ϐ��錾
//================================================================
//LPDIRECT3DTEXTURE9 *CObjectX::m_pTexture = NULL;

//================================================================
//�R���X�g���N�^
//================================================================
CObjectX::CObjectX()
{
	//�l���N���A
	m_aObjectX.m_vtxMax = D3DXVECTOR3(-900000.0f, -900000.0f, -900000.0f);
	m_aObjectX.m_vtxMini = D3DXVECTOR3(900000.0f, 900000.0f, 900000.0f);
	m_aObjectX.m_vtxMax = D3DXVECTOR3(-900000.0f, -900000.0f, -900000.0f);
	m_aObjectX.m_vtxMini = D3DXVECTOR3(900000.0f, 900000.0f, 900000.0f);

	//m_nIdxTexture[5] = -1;
}

//================================================================
//�R���X�g���N�^(�I�[�o�[���[�h)
//================================================================
CObjectX::CObjectX(D3DXVECTOR3 pos, D3DXVECTOR3 rot, const char *aModelFliename)
{
	//�l���N���A
	m_aObjectX.m_vtxMax = D3DXVECTOR3(-900000.0f, -900000.0f, -900000.0f);
	m_aObjectX.m_vtxMini = D3DXVECTOR3(900000.0f, 900000.0f, 900000.0f);
	m_aObjectX.m_vtxMax = D3DXVECTOR3(-900000.0f, -900000.0f, -900000.0f);
	m_aObjectX.m_vtxMini = D3DXVECTOR3(900000.0f, 900000.0f, 900000.0f);

	//�l���N���A
	//m_pTexture = NULL;  //�e�N�X�`���ւ̃|�C���^

	SetPos(&pos);
	SetRot(&rot);
	//m_aObjectX.m_pos = pos;
	//m_aObjectX.m_rot = rot;
	//SetPos(&pos);
	m_Fliename = aModelFliename;
	//m_nIdxTexture[5] = -1;
}

//================================================================
//�f�X�g���N�^
//================================================================
CObjectX::~CObjectX()
{

}

//================================================================
//��������
//================================================================
CObjectX *CObjectX::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, const char *aModelFliename)
{
	//�I�u�W�F�N�gX�̃|�C���^
	CObjectX *pObjectX = NULL;

	//���f�������擾
	CModel *pModel = CManager::GetModel();

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pObjectX == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pObjectX = new CObjectX(pos, rot, aModelFliename);

			//����������
			pObjectX->Init();
		}
	}

	return pObjectX;
}

//================================================================
//�|���S���̏���������
//================================================================
HRESULT CObjectX::Init(void)
{
	int nNumVtx;      //���_��
	DWORD dwSizeFVF;  //���_�t�H�[�}�b�g�̃T�C�Y
	BYTE *pVtxBuff;   //���_�o�b�t�@�ւ̃|�C���^

	for (int n = 0; n < 5; n++)
	{
		m_nIdxTexture[n] = -1;
	}

	//�f�o�C�X�̎擾
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//X�t�@�C���ǂݍ���
	D3DXLoadMeshFromX(m_Fliename,
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_aObjectX.m_pBuffMat,
		NULL,
		&m_aObjectX.m_dwNumMat,
		&m_aObjectX.m_pMesh);

	//���_�����擾
 	nNumVtx = m_aObjectX.m_pMesh->GetNumVertices();

	//���_�t�H�[�}�b�g�̃T�C�Y���擾
	dwSizeFVF = D3DXGetFVFVertexSize(m_aObjectX.m_pMesh->GetFVF());

	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::GetTexture();

	if (m_aObjectX.m_pTexture == NULL)
	{
		m_aObjectX.m_pTexture = new LPDIRECT3DTEXTURE9[(int)m_aObjectX.m_dwNumMat];
	}
	
	//�}�e���A���ւ̃|�C���^
	D3DXMATERIAL *pMat;

	//�}�e���A�����ɑ΂���|�C���^���擾
	pMat = (D3DXMATERIAL*)m_aObjectX.m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_aObjectX.m_dwNumMat; nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != NULL)
		{//�e�N�X�`�������݂���

			D3DXCreateTextureFromFile(pDevice,
				pMat[nCntMat].pTextureFilename,
				&m_aObjectX.m_pTexture[nCntMat]);
		}
		else
		{
			m_aObjectX.m_pTexture[nCntMat] = NULL;
		}
	}

	//���_�o�b�t�@�����b�N
	m_aObjectX.m_pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

	for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
	{
		D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;     //���_���W�̑��

		//�ŏ��l-------------------------------------------------
		if (m_aObjectX.m_vtxMini.x > vtx.x)
		{
			m_aObjectX.m_vtxMini.x = vtx.x;
		}

		if (m_aObjectX.m_vtxMini.y > vtx.y)
		{
			m_aObjectX.m_vtxMini.y = vtx.y;
		}

		if (m_aObjectX.m_vtxMini.z > vtx.z)
		{
			m_aObjectX.m_vtxMini.z = vtx.z;
		}

		//�ő�l-------------------------------------------------
		if (m_aObjectX.m_vtxMax.x < vtx.x)
		{
			m_aObjectX.m_vtxMax.x = vtx.x;
		}

		if (m_aObjectX.m_vtxMax.y < vtx.y)
		{
			m_aObjectX.m_vtxMax.y = vtx.y;
		}

		if (m_aObjectX.m_vtxMax.z < vtx.z)
		{
			m_aObjectX.m_vtxMax.z = vtx.z;
		}

		pVtxBuff += dwSizeFVF;    //���_�t�H�[�}�b�g�̃T�C�Y���|�C���^��i�߂�
	}

	//���_�o�b�t�@���A�����b�N
	m_aObjectX.m_pMesh->UnlockVertexBuffer();

	return S_OK;
}

//================================================================
//�|���S���̏I������
//================================================================
void CObjectX::Uninit(void)
{
	if (m_aObjectX.m_pTexture != NULL)
	{
		delete m_aObjectX.m_pTexture;
		m_aObjectX.m_pTexture = NULL;
	}
	
	//�e�N�X�`���̏���
	if (m_aObjectX.m_pMesh != NULL)
	{
		m_aObjectX.m_pMesh->Release();
		m_aObjectX.m_pMesh = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (m_aObjectX.m_pBuffMat != NULL)
	{
		m_aObjectX.m_pBuffMat->Release();
		m_aObjectX.m_pBuffMat = NULL;
	}

	//�I�u�W�F�N�g�̔j��
	Release();
}

//================================================================
//�|���S���̍X�V����
//================================================================
void CObjectX::Update(void)
{
	
}

//================================================================
//�|���S���̕`�揈��
//================================================================
void CObjectX::Draw(void)
{
	//�f�o�C�X�̎擾
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	CTexture *pTexture = CManager::GetTexture();
	
	D3DXVECTOR3 pos = Getpos();
	D3DXVECTOR3 rot = GetRot();

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX m_mtxRot, m_mtxTrans;

	//���݂̃}�e���A���ۑ��p
	D3DMATERIAL9 matDef;

	//�}�e���A���f�[�^�ւ̃|�C���^
	D3DXMATERIAL *pMat;

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_aObjectX.m_mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&m_mtxRot, rot.y, rot.x, rot.z);

	D3DXMatrixMultiply(&m_aObjectX.m_mtxWorld, &m_aObjectX.m_mtxWorld, &m_mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&m_mtxTrans, pos.x, pos.y, pos.z);

	D3DXMatrixMultiply(&m_aObjectX.m_mtxWorld, &m_aObjectX.m_mtxWorld, &m_mtxTrans);

	//���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_aObjectX.m_mtxWorld);

	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)m_aObjectX.m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_aObjectX.m_dwNumMat; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, *&m_aObjectX.m_pTexture[nCntMat]);

		//���f��(�p�[�c)�̕`��
		m_aObjectX.m_pMesh->DrawSubset(nCntMat);
	}
	
	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
}

//================================================================
//���f���̃o�C���h����
//================================================================
void CObjectX::BindModel(OBJX pObjX)
{
	m_aObjectX = pObjX;
}

//================================================================
//�|���S���̕`�揈��
//================================================================
void CObjectX::UpdateItemPos(void)
{
	
}