//=============================================================================
//
// �|���S������ [billboard.cpp]
// Author : �匴�@�叫
//
//=============================================================================
#include "main.h"
#include "billboard.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "object2D.h"

//================================================================
//�R���X�g���N�^
//================================================================
CBillBoard::CBillBoard()
{
	//�l���N���A
	m_pTexture = NULL;  //�e�N�X�`���ւ̃|�C���^
}

//================================================================
//�f�X�g���N�^
//================================================================
CBillBoard::~CBillBoard()
{

}

//================================================================
//��������
//================================================================
CBillBoard *CBillBoard::Create(void)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CBillBoard *pBillBoard = NULL;

	if (pBillBoard == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pBillBoard = new CBillBoard();

		//����������
		pBillBoard->Init();
	}

	return pBillBoard;
}

//================================================================
//�ǂ̏���������
//===============================================================
HRESULT CBillBoard::Init(void)
{
	//����������
	CObject3D::Init();

	return S_OK;
}

//================================================================
//�ǂ̏I������
//================================================================
void CBillBoard::Uninit(void)
{
	//�I������
	CObject3D::Uninit();
}

//================================================================
//�ǂ̕ǂ̍X�V����
//================================================================
void CBillBoard::Update(void)
{
	//�X�V����
	CObject3D::Update();

	CObject3D::SetVtxBillBoard();
}

//================================================================
//�ǂ̕`�揈��
//================================================================
void CBillBoard::Draw(void)
{
	//�f�o�C�X�̎擾
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	D3DXVECTOR3 pos = Getpos();
	D3DXVECTOR3 rot = GetRot();

	//z�e�X�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	//���e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 160);

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�r���[�}�g���b�N�X���擾
	pDevice->GetTransform(D3DTS_VIEW, &m_mtxView);

	//�|���S�����J�����ɑ΂��Đ��ʂɌ�����
	D3DXMatrixInverse(&m_mtxWorld, NULL, &m_mtxView);
	m_mtxWorld._41 = 0.0f;
	m_mtxWorld._42 = 0.0f;
	m_mtxWorld._43 = 0.0f;

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&m_mtxTrans, pos.x, pos.y, pos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &m_mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//z�e�X�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	//pDevice->SetTexture(0, m_pTexture);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,    //�v���~�e�B�u�̎��
		0,                      //�`�悷��ŏ��̒��_�C���f�b�N�X
		2                       //�`�悷��v���~�e�B�u��
	);

	//z�e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//���e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 160);
}