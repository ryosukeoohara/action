//===========================================================
//
//�|���S�����o�����[object2D.cpp]
//Author �匴�叫
//
//===========================================================
#include "object.h"
#include "object2D.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//================================================================
//�R���X�g���N�^
//================================================================
CObject2D::CObject2D()
{
	//�l���N���A
	//m_pTexture = NULL;  //�e�N�X�`���ւ̃|�C���^
	m_nIdxTexture = -1;
	m_pVtxBuff = NULL;  //���_�����i�[
	//m_nLife = 30;
	m_nCounterAnimPlayer = 0;
	m_nPatternAnimPlayer = 0;
}

//================================================================
//�R���X�g���N�^(�I�[�o�[���[�h)
//================================================================
CObject2D::CObject2D(D3DXVECTOR3 pos)
{
	//�l���N���A
	SetPos(&pos);
	//m_pTexture = NULL;  //�e�N�X�`���ւ̃|�C���^
	m_nIdxTexture = -1;
	m_pVtxBuff = NULL;  //���_�����i�[
	//m_nLife = 30;
	m_nCounterAnimPlayer = 0;
	m_nPatternAnimPlayer = 0;
}

//================================================================
//�f�X�g���N�^
//================================================================
CObject2D::~CObject2D()
{

}

//================================================================
//��������
//================================================================
CObject2D *CObject2D::Create(D3DXVECTOR3 pos)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CObject2D *pObject2D = NULL;

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pObject2D == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pObject2D = new CObject2D(pos);

			//����������
			pObject2D->Init();
		}
	}
	
	return pObject2D;
}

//================================================================
//����������
//================================================================
HRESULT CObject2D::Init(void)
{
	CRenderer *pRenderer;
	pRenderer = CManager::GetRenderer();
	
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���_�o�b�t�@�𐶐�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	//���_���ւ̃|�C���^
	VERTEX_2D * pVtx;

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

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
//�I������
//================================================================
void CObject2D::Uninit(void)
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//�I�u�W�F�N�g�̔j��
	Release();
}

//================================================================
//�X�V����
//================================================================
void CObject2D::Update(void)
{
	
}

//================================================================
//�`�揈��
//================================================================
void CObject2D::Draw(void)
{
	CRenderer *pRenderer;
	pRenderer = CManager::GetRenderer();
	CTexture *pTexture = CManager::GetTexture();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,    //�v���~�e�B�u�̎��
		0,                                         //�`�悷��ŏ��̒��_�C���f�b�N�X
		2                                          //�`�悷��v���~�e�B�u��
	);
}

//================================================================
//���a�̍X�V
//================================================================
void CObject2D::SetVtxEffect(D3DXVECTOR3 pos, float m_fRadius, D3DXCOLOR col)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - m_fRadius, pos.y - m_fRadius , 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + m_fRadius, pos.y - m_fRadius , 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - m_fRadius, pos.y + m_fRadius , 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + m_fRadius, pos.y + m_fRadius , 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[1].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[2].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[3].col = D3DXCOLOR(col.r, col.g, col.b, col.a);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�u���b�N�̐ݒ�
//================================================================
void CObject2D::SetVtxBlock(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x,          pos.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x,          pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);
	
	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�e�̐ݒ�
//================================================================
void CObject2D::SetVtxBullet(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth,  pos.y - fWidth, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fHeight, pos.y - fWidth, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth,  pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fHeight, pos.y + fHeight, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�v���C���[�̐ݒ�
//================================================================
void CObject2D::SetVtxPlayer(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth,  pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth,  pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth,  pos.y , 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth,  pos.y , 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�A�C�e���̐ݒ�
//================================================================
void CObject2D::SetVtxItem(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fWidth, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fHeight, pos.y - fWidth, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fHeight, pos.y + fHeight, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�A�C�e���̐ݒ�
//================================================================
void CObject2D::SetVtxNumber(D3DXVECTOR3 pos, float fWidth, float fHeight, int m_nNumber)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fWidth, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fHeight, pos.y - fWidth, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fHeight, pos.y + fHeight, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f + 0.1f * m_nNumber, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.1f + 0.1f * m_nNumber, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f + 0.1f * m_nNumber, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.1f + 0.1f * m_nNumber, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�w�i�̐ݒ�
//================================================================
void CObject2D::SetVtxBg(void)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	D3DXVECTOR3 pos = Getpos();

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x + 0.0f,   pos.y + 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + 580.0f, pos.y + 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x + 0.0f,   pos.y + 320.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + 580.0f, pos.y + 320.0f, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�w�i�̐ݒ�
//================================================================
void CObject2D::SetVtxMessage(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�t���[���̐ݒ�
//================================================================
void CObject2D::SetVtxFrame(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�A�C�e���X���b�g�̐ݒ�
//================================================================
void CObject2D::SetVtxItemSlot(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�^�C�g�����S�̐ݒ�
//================================================================
void CObject2D::SetVtxTitleLogo(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�W�����̐ݒ�
//================================================================
void CObject2D::SetVtxEffectLine(void)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//���C�t�Q�[�W�̐ݒ�
//================================================================
void CObject2D::SetVtxLifeGage(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

													 //���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//���C�t�Q�[�W�̐ݒ�
//================================================================
void CObject2D::SetVtxIcon(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//���C�t�̐ݒ�
//================================================================
void CObject2D::SetVtxLife(D3DXVECTOR3 pos, float fWidth, float fHeight, float fTex)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x,        pos.y          , 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fTex, pos.y          , 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x ,       pos.y + fHeight, 0.0f);
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
//�t�F�[�h�̐ݒ�
//================================================================
void CObject2D::SetVtxFade(D3DXCOLOR col)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�t�F�[�h�̐ݒ�
//================================================================
void CObject2D::SetVtxTarget(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�|�[�Y�̐ݒ�
//================================================================
void CObject2D::SetVtxPause(D3DXVECTOR3 pos, float fWidth, float fHeight, D3DXCOLOR col)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//UI�̐ݒ�
//================================================================
void CObject2D::SetVtxUI(D3DXVECTOR3 pos, float fWidth, float fHeight, D3DXCOLOR col)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, col.a);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�����L���O�̐ݒ�
//================================================================
void CObject2D::SetVtxRanking(int Tex)
{
	D3DXVECTOR3 pos = Getpos();

	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x + -25.0f, pos.y + -50.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + 25.0f, pos.y + -50.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x + -25.0f, pos.y + 50.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + 25.0f, pos.y + 50.0f, 0.0f);

	pVtx[0].tex = D3DXVECTOR2(0.1f * Tex + 0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.1f * Tex + 0.1f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.1f * Tex + 0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.1f * Tex + 0.1f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

////================================================================
////�ʒu�ݒ�
////================================================================
//void CObject2D::SetPosition(D3DXVECTOR3 pos)
//{
//	m_pos = pos;  //�ʒu����
//}
//
////================================================================
////�ʒu�擾
////================================================================
//D3DXVECTOR3 CObject2D::GetPosition(void)
//{
//	return m_pos;
//}

//================================================================
//�e�N�X�`���擾
//================================================================
void CObject2D::BindTexture(LPDIRECT3DTEXTURE9 m_Texture)
{
	//m_pTexture = m_Texture;
}