//===========================================================
//
//�|���S�����o�����[number.cpp]
//Author �匴�叫
//
//===========================================================
#include "number.h"
#include "object.h"
#include "object2D.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "effect.h"
#include "time.h"
#include "score.h"
#include "input.h"
#include "camera.h"
#include "game.h"
#include "player.h"

//CObject2D *CMultiplexBg::m_apObject2D[TYPETEX_MAX] = {};

//================================================================
//�R���X�g���N�^
//================================================================
CNumber::CNumber()
{
	//�l���N���A
	m_pTexture = NULL;  //�e�N�X�`���ւ̃|�C���^
	m_pVtxBuff = NULL;  //���_�����i�[
	m_nTimerCount = 0;
	m_Number = 0;
	m_nIdxTexture = -1;
}

//================================================================
//�R���X�g���N�^(�I�[�o�[���[�h)
//================================================================
CNumber::CNumber(D3DXVECTOR3 pos)
{
	//�l���N���A
	m_pTexture = NULL;  //�e�N�X�`���ւ̃|�C���^
	m_pVtxBuff = NULL;  //���_�����i�[
	m_nTimerCount = 0;
	m_Number = 0;
	m_nIdxTexture = -1;
	m_pos = pos;
}

//================================================================
//�f�X�g���N�^
//================================================================
CNumber::~CNumber()
{

}

//================================================================
//��������
//================================================================
CNumber *CNumber::Create(D3DXVECTOR3 pos)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CNumber *pNumber = NULL;

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pNumber == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pNumber = new CNumber(pos);

			//����������
			pNumber->Init();
		}
	}

	return pNumber;
}

//================================================================
//����������
//================================================================
HRESULT CNumber::Init(void)
{
	CRenderer *pRenderer;
	pRenderer = CManager::Getinstance()->GetRenderer();

	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	D3DXVECTOR3 pos = GetPosition();

	//���_�o�b�t�@�𐶐�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	//�e�N�X�`���ǂݍ���
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\number002.png");

	//���_���ւ̃|�C���^
	VERTEX_2D * pVtx;

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - 30.0f, pos.y - 30.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + 30.0f, pos.y - 30.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - 30.0f, pos.y + 30.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + 30.0f, pos.y + 30.0f, 0.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.9f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.9f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

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

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//================================================================
//�I������
//================================================================
void CNumber::Uninit(void)
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	Release();
}

//================================================================
//�X�V����
//================================================================
void CNumber::Update(void)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	pVtx[0].tex = D3DXVECTOR2(0.0f + 0.1f * m_Number, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.1f + 0.1f * m_Number, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f + 0.1f * m_Number, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.1f + 0.1f * m_Number, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�`�揈��
//================================================================
void CNumber::Draw(void)
{
	//�����_���[�̏����擾
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();

	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	//�f�o�C�X�̏����擾
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,    //�v���~�e�B�u�̎��
		0,                   //�`�悷��ŏ��̒��_�C���f�b�N�X
		2                    //�`�悷��v���~�e�B�u��
	);
	
}

//================================================================
//Number�̐ݒ�
//================================================================
void CNumber::SetNumber(int nNumber)
{
	m_Number = nNumber;

	if (m_Number >= 10)
	{
		m_Number = 0;
	}

	if (m_Number < 0)
	{
		m_Number = 9;
	}

	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	pVtx[0].tex = D3DXVECTOR2(0.0f + 0.1f * m_Number, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.1f + 0.1f * m_Number, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f + 0.1f * m_Number, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.1f + 0.1f * m_Number, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�ʒu�ݒ�
//================================================================
void CNumber::SetVtxCounter(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;     //���_���ւ̃|�C���^
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);        //���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - fWidth, pos.y - fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + fWidth, pos.y - fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - fWidth, pos.y + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + fWidth, pos.y + fHeight, 0.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�ʒu�ݒ�
//================================================================
void CNumber::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;  //�ʒu����
}

//================================================================
//�ʒu�擾
//================================================================
D3DXVECTOR3 CNumber::GetPosition(void)
{
	return m_pos;
}

//================================================================
//�e�N�X�`���擾
//================================================================
void CNumber::BindTexture(LPDIRECT3DTEXTURE9 m_Texture)
{
	m_pTexture = m_Texture;
}