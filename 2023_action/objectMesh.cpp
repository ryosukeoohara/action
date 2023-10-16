//=============================================================================
//
// ���b�V���|���S������ [objectMesh.cpp]
// Author : �匴�@�叫
//
//=============================================================================
#include "objectMesh.h"
#include "renderer.h"
#include "manager.h"

#define HIGHT   (100)    //������
#define WI      (100)    //������
#define HILEN   (100.0f) //�c�̒���
#define WILEN   (100.0f) //���̒���

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CObjectMesh::CObjectMesh()
{
	//�l���N���A
	m_pTexture = NULL;  //�e�N�X�`���ւ̃|�C���^
	m_pVtxBuff = NULL;  //���_�����i�[
	m_pIdxBuff = NULL;
}

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CObjectMesh::CObjectMesh(D3DXVECTOR3 pos)
{
	//�l���N���A
	m_pTexture = NULL;  //�e�N�X�`���ւ̃|�C���^
	m_pVtxBuff = NULL;  //���_�����i�[
	m_pIdxBuff = NULL;
	SetPos(&pos);
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CObjectMesh::~CObjectMesh()
{

}

//=============================================================================
//��������
//=============================================================================
CObjectMesh * CObjectMesh::Create(void)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CObjectMesh *pObjectMesh = NULL;

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pObjectMesh == NULL)
		{
			//�I�u�W�F�N�g���b�V���̐���
			pObjectMesh = new CObjectMesh();

			//����������
			pObjectMesh->Init();
		}
	}

	return pObjectMesh;
}


//=============================================================================
//����������
//=============================================================================
HRESULT CObjectMesh::Init(void)
{
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���_�o�b�t�@�𐶐�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * ((HIGHT + 1) * (WI + 1)),
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D * pVtx;     //���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int n = 0; n < HIGHT + 1; n++)
	{
		for (int a = 0; a < WI + 1; a++)
		{
			pVtx[0].pos = D3DXVECTOR3((WILEN * a) - ((WILEN * WI) * 0.5f), 0.0f, -((HILEN * n) - ((HILEN * HIGHT) * 0.5f)));

			pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			//�e�N�X�`�����W�̐ݒ�
			pVtx[0].tex = D3DXVECTOR2(((float)a / (1.0f / (float)(WI + 1))) * (1.0f / (float)(WI + 1)), ((float)n / (1.0f / (float)(HIGHT + 1))) * (1.0f / (float)(HIGHT + 1)));

			pVtx += 1;
		}
	}

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	//���_�o�b�t�@�𐶐�
	pDevice->CreateIndexBuffer(sizeof(WORD) * (HIGHT * ((WI + 1) * 2)) + (2 * (HIGHT - 1)),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&m_pIdxBuff,
		NULL);

	//�C���f�b�N�X���ւ̃|�C���^
	WORD * pIdx;

	//�C���f�b�N�X�o�b�t�@�����b�N���A���_���փ|�C���^���擾
	m_pIdxBuff->Lock(0, 0, (void**)&pIdx, 0);
	
	int nCntIdx = 0;

	for (int n = 0; n < HIGHT; n++)
	{
		for (int a = 0; a < WI + 1; a++)
		{
			if ((nCntIdx % 2) == 0)
			{
				pIdx[nCntIdx] = (a + (WI + 1) * (n + 1) + 1);
			}
			else
			{
				pIdx[nCntIdx ] = (a + ((WI + 1) * n));
			}
			
			
			nCntIdx += 1;
		}
	}

	//���_�o�b�t�@���A�����b�N����
	m_pIdxBuff->Unlock();

	return S_OK;
}

//=============================================================================
//�I������
//=============================================================================
void CObjectMesh::Uninit(void)
{
	//�e�N�X�`���̏���
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//�C���f�b�N�X�o�b�t�@��j��
	if (m_pIdxBuff != NULL)
	{
		m_pIdxBuff->Release();
		m_pIdxBuff = NULL;
	}

	Release();
}

//=============================================================================
//�X�V����
//=============================================================================
void CObjectMesh::Update(void)
{
	
}

//=============================================================================
//�`�揈��
//=============================================================================
void CObjectMesh::Draw(void)
{
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	D3DXVECTOR3 pos = Getpos();
	D3DXVECTOR3 rot = GetRot();

	//z�e�X�g�𖳌��ɂ���
	//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	//pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	//���e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 160);

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

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//�C���f�b�N�X�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetIndices(m_pIdxBuff);

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	//pDevice->SetTexture(0, m_pTexture);

	////�|���S���̕`��  D3DPT_LINESTRIP
	//pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,    //�v���~�e�B�u�̎��
	//	0,                      //�`�悷��ŏ��̒��_�C���f�b�N�X
	//	HIGHT * WI                      //�`�悷��v���~�e�B�u��
	//);

	//�|���S���̕`��
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP,
		0,
		0,
		((HIGHT + 1) * (WI + 1)),
		0,
		(HIGHT * ((WI + 1) * 2)) + (2 * (HIGHT - 1))
	);

	//z�e�X�g��L���ɂ���
	//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	//pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//���e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 160);
}