//=============================================================================
//
//  �|���S�����o�����[object3D.cpp]
// Author : �匴�@�叫
//
//=============================================================================

#include "main.h"
#include "object3D.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "player.h"
#include "debugproc.h"

//================================================================
//�R���X�g���N�^
//================================================================
CObject3D::CObject3D()
{
	//�l���N���A
	m_pTexture = NULL;  //�e�N�X�`���ւ̃|�C���^
	m_pVtxBuff = NULL;  //���_�����i�[
}

//================================================================
//�R���X�g���N�^(�I�[�o�[���[�h)
//================================================================
CObject3D::CObject3D(D3DXVECTOR3 pos)
{
	//�l���N���A
	m_pTexture = NULL;  //�e�N�X�`���ւ̃|�C���^
	m_pVtxBuff = NULL;  //���_�����i�[
	SetPos(&pos);
}

//================================================================
//�f�X�g���N�^
//================================================================
CObject3D::~CObject3D()
{

}

//================================================================
//��������
//================================================================
CObject3D *CObject3D::Create(void)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CObject3D *pObject3D = NULL;

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pObject3D == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pObject3D = new CObject3D();

			//����������
			pObject3D->Init();
		}
	}

	return pObject3D;
}

//================================================================
//3D�I�u�W�F�N�g�̏���������
//================================================================
HRESULT CObject3D::Init(void)
{
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���_�o�b�t�@�𐶐�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D * pVtx;     //���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//�@���x�N�g���̐ݒ�
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//================================================================
//3D�I�u�W�F�N�g�̏I������
//================================================================
void CObject3D::Uninit(void)
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

	Release();
}

//================================================================
//3D�I�u�W�F�N�g�̍X�V����
//================================================================
void CObject3D::Update(void)
{
	
}

//================================================================
//3D�I�u�W�F�N�g�̕`�揈��
//================================================================
void CObject3D::Draw(void)
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

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	//pDevice->SetTexture(0, m_pTexture);

	//�|���S���̕`��  D3DPT_LINESTRIP
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,    //�v���~�e�B�u�̎��
		0,                                         //�`�悷��ŏ��̒��_�C���f�b�N�X
		2                                          //�`�悷��v���~�e�B�u��
	);					

	//z�e�X�g��L���ɂ���
	//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	//pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//���e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 160);
}

//================================================================
//�e�N�X�`���擾
//================================================================
void CObject3D::BindTexture(LPDIRECT3DTEXTURE9 m_Texture)
{
	m_pTexture = m_Texture;
}

//================================================================
//�r���{�[�h�̐ݒ�
//================================================================
void CObject3D::SetVtxBillBoard(void)
{
	VERTEX_3D * pVtx;     //���_���ւ̃|�C���^
   	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-5.0f, 5.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(5.0f,  5.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(-5.0f, -5.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(5.0f,  -5.0f, 0.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�t�B�[���h�̐ݒ�
//================================================================
void CObject3D::SetVtxField(void)
{
	VERTEX_3D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-5000.0f, 0.0f, 5000.0f);
	pVtx[1].pos = D3DXVECTOR3(5000.0f, 0.0f, 5000.0f);
	pVtx[2].pos = D3DXVECTOR3(-5000.0f, 0.0f, -5000.0f);
	pVtx[3].pos = D3DXVECTOR3(5000.0f, 0.0f, -5000.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�e�̐ݒ�
//================================================================
void CObject3D::SetVtxBullet(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_3D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth,  pos.y + fWidth,  0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fHeight, pos.y + fWidth,  0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth,  pos.y - fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fHeight, pos.y - fHeight, 0.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�G�t�F�N�g�̐ݒ�
//================================================================
void CObject3D::SetVtxEffect(D3DXVECTOR3 pos, float m_fRadius, D3DXCOLOR col)
{
	VERTEX_3D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-m_fRadius, +m_fRadius, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(+m_fRadius, +m_fRadius, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(-m_fRadius, -m_fRadius, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(+m_fRadius, -m_fRadius, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[1].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[2].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[3].col = D3DXCOLOR(col.r, col.g, col.b, col.a);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�G�t�F�N�g�̐ݒ�
//================================================================
void CObject3D::SetVtxEffectSword(float fWidth, float fHeight, D3DXCOLOR col)
{
	VERTEX_3D * pVtx;                                //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-fWidth,  0.0f,  fWidth);
	pVtx[1].pos = D3DXVECTOR3(fHeight,  0.0f,  fWidth);
	pVtx[2].pos = D3DXVECTOR3(-fWidth,  0.0f, -fHeight);
	pVtx[3].pos = D3DXVECTOR3(fHeight,  0.0f, -fHeight);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�����蔻��̉~�̐ݒ�
//================================================================
void CObject3D::SetVtxCircle(float fWidth, float fHeight, D3DXCOLOR col)
{
	VERTEX_3D * pVtx;                                //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-fWidth, 0.0f, fWidth);
	pVtx[1].pos = D3DXVECTOR3(fHeight, 0.0f, fWidth);
	pVtx[2].pos = D3DXVECTOR3(-fWidth, 0.0f, -fHeight);
	pVtx[3].pos = D3DXVECTOR3(fHeight, 0.0f, -fHeight);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�e�̐ݒ�
//================================================================
void CObject3D::SetShadowPosition(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_3D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth,  0.0f, pos.z + fWidth);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fHeight, 0.0f, pos.z + fWidth);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth,  0.0f, pos.z - fHeight);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fHeight, 0.0f, pos.z - fHeight);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//���C�t�̐ݒ�
//================================================================
void CObject3D::SetVtxLife(D3DXVECTOR3 pos, float fWidth, float fHeight, float fTex)
{
	VERTEX_3D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

													 //���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x,        pos.y,           0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fTex, pos.y,           0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x,        pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fTex, pos.y + fHeight, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(0.0f, 0.9f, 0.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(0.0f, 0.9f, 0.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(0.0f, 0.9f, 0.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(0.0f, 0.9f, 0.0f, 1.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�e�N�X�`���擾
//================================================================
//float CObject3D::GetHeight(D3DXVECTOR3 pos)
//{
//	//float fHeight = 0.0f;
//
//	//VERTEX_3D * pVtx;     //���_���ւ̃|�C���^
//
//	////���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾
//	//m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
//
//	//if (pos.x >= -500.0f && pos.x <= 500.0f && pos.z >= -500.0f && pos.z <= 500.0f)
//	//{
//	//	m_vec0 = pVtx[0].pos - pVtx[2].pos;
//	//	m_vec1 = pVtx[3].pos - pVtx[2].pos;
//
//	//	m_vec2 = pVtx[0].pos - pVtx[1].pos;
//	//	m_vec3 = pVtx[3].pos - pVtx[1].pos;
//
//	//	m_nor0 = pVtx[2].nor;
//
//	//	D3DXVec3Cross(&m_nor0, &m_vec0, &m_vec1);
//
//	//	//�x�N�g���𐳋K������
//	//	D3DXVec3Normalize(&m_nor0, &m_nor0);
//
//	//	m_nor1 = pVtx[1].nor;
//
//	//	D3DXVec3Cross(&m_nor1, &m_vec2, &m_vec3);
//
//	//	//�x�N�g���𐳋K������
//	//	D3DXVec3Normalize(&m_nor1, &m_nor1);
//
//	//	D3DXVECTOR3 vecA, vecB, vecC;
//
//	//	vecA.x = pVtx[0].pos.y * pVtx[2].pos.z - pVtx[0].pos.z * pVtx[2].pos.y;
//	//	vecA.y = pVtx[0].pos.z * pVtx[2].pos.x - pVtx[0].pos.x * pVtx[2].pos.z;
//	//	vecA.z = pVtx[0].pos.x * pVtx[2].pos.y - pVtx[0].pos.y * pVtx[2].pos.x;
//
//	//	vecB.x = pVtx[0].pos.y * pVtx[2].pos.z - pVtx[0].pos.z * pVtx[2].pos.y;
//	//	vecB.y = pVtx[0].pos.z * pVtx[2].pos.x - pVtx[0].pos.x * pVtx[2].pos.z;
//	//	vecB.z = pVtx[0].pos.x * pVtx[2].pos.y - pVtx[0].pos.y * pVtx[2].pos.x;
//
//
//
//
//	//	if (m_nor0.y != 0.0f)
//	//	{
//	//		fHeight = ((pos.x + pVtx[2].pos.x) * m_nor0.x - pVtx[2].pos.y - (pos.z + pVtx[2].pos.z) * m_nor0.z) / m_nor0.y;
//	//	}
//	//	
//
//	//	
//
//	//	/*if (m_nor1.y != 0.0f)
//	//	{
//	//		fHeight = ((pos.x + pVtx[2].pos.x) * m_nor1.x - pVtx[2].pos.y - (pos.z + pVtx[2].pos.z) * m_nor1.z) / m_nor1.y;
//	//	}*/
//
//	//	//�@���x�N�g���̐ݒ�
//	//	pVtx[1].nor = D3DXVECTOR3(m_nor1.x, m_nor1.y, m_nor1.z);
//	//	pVtx[2].nor = D3DXVECTOR3(m_nor0.x, m_nor0.y, m_nor0.z);
//	//	
//	//	//���_�o�b�t�@���A�����b�N����
//	//	m_pVtxBuff->Unlock();
//	//}
//
//	//return fHeight;
//}