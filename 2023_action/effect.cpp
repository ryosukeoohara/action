//===========================================================
//
//�|���S�����o�����[effect.cpp]
//Author �匴�叫
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "object.h"
#include "manager.h"
#include "effect.h"
#include "debugproc.h"
#include "texture.h"

//================================================================
//�ÓI�����o�ϐ��錾
//================================================================
LPDIRECT3DTEXTURE9 CEffect::m_pTexture = NULL;
//struct CEffect::Effect CEffect::m_effect;
//float CEffect::m_fRadius = 0.0f;
//D3DXCOLOR CEffect::m_col = { 0.0f,0.0f,0.0f,0.0f };

//================================================================
//�R���X�g���N�^
//================================================================
CEffect::CEffect()
{
	m_fRadius = 0;
	m_nLife = 0;
	m_nIdxTexture = -1;
	m_type = TYPEEFF_NONE;
}

//================================================================
//�R���X�g���N�^
//================================================================
CEffect::CEffect(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXCOLOR col, float fRadius, int nLife, TYPEEFF type)
{
	SetPos(&pos);
	m_col = col;
	m_fRadius = fRadius;
	m_nLife = nLife;
	m_move = move;
	m_type = type;
	m_nIdxTexture = -1;
}

//================================================================
//�f�X�g���N�^
//================================================================
CEffect::~CEffect()
{

}

//================================================================
//��������
//================================================================
CEffect *CEffect::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXCOLOR col, float fRadius, int nLife, TYPEEFF type)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CEffect *pEffect = NULL;

	if (GetNumAll() < MAX_OBJECT)
	{
		if (pEffect == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pEffect = new CEffect(pos, move, col, fRadius, nLife, type);

			//�e�N�X�`�����o�C���h
			//pEffect->BindTexture(m_pTexture);

			//����������
			pEffect->Init();
		}
	}
	
	return pEffect;
}

//================================================================
//�|���S���̏���������
//================================================================
HRESULT CEffect::Init(void)
{
	//��ނ̐ݒ�
	SetType(TYPE_EFFECT);

	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	switch (m_type)
	{
	case TYPEEFF_NONE:

		break;

	case TYPEEFF_GROUND:

		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\effect000.jpg");
		break;

	case TYPEEFF_BLOOD:

		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\effect000.jpg");
		break;

	case TYPEEFF_SMOOK:

		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\effect000.jpg");
		break;

	case TYPEEFF_CIRCLE:

		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\effect000.jpg");
		break;

	case TYPEEFF_MAX:
		break;

	default:
		break;
	}
	
	//����������
	CBillBoard::Init();
	//m_fRadius = 15.0f;
	//m_nLife = 15;
	return S_OK;
}

//================================================================
//�|���S���̏I������
//================================================================
void CEffect::Uninit(void)
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}

	//�I������
	CBillBoard::Uninit();
}

//================================================================
//�|���S���̍X�V����
//================================================================
void CEffect::Update(void)
{
	D3DXVECTOR3 pos = Getpos();  //�ʒu�擾

	m_nLife--;
	
	//m_fRadius -= 0.1f;
	
	//�X�V����
	CBillBoard::Update();

	pos.x += m_move.x;
	pos.y += m_move.y;
	pos.z += m_move.z;

	switch (m_type)
	{
	case CEffect::TYPEEFF_NONE:
		
		break;

	case CEffect::TYPEEFF_GROUND:

		Ground();
		break;

	case CEffect::TYPEEFF_BLOOD:

		Blood();
		break;

	case CEffect::TYPEEFF_SMOOK:

		Smook();
		break;

	case CEffect::TYPEEFF_CIRCLE:

		Circle();

		m_col.a -= 0.009f;
		break;

	case CEffect::TYPEEFF_MAX:
		break;

	default:
		break;
	}

	SetVtxEffect(pos, m_fRadius, m_col);

	if (m_nLife <= 0)
	{//�������s������

		//�I������
		CEffect::Uninit();
	}
	else
	{
		//�ʒu��ݒ�
		SetPos(&pos);
	}
}

//================================================================
//�|���S���̕`�揈��
//================================================================
void CEffect::Draw(void)
{
	CTexture *pTexture = CManager::Getinstance()->GetTexture();
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���u�����f�B���O�����Z���v�ɐݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	
	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//�`�揈��
	CBillBoard::Draw();

	//���u�����f�B���O�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//================================================================
// �y���̃G�t�F�N�g
//================================================================
void CEffect::Ground(void)
{
	D3DXVECTOR3 pos = Getpos();  //�ʒu�擾

	if (pos.y >= 30.0f)
	{
		m_move.y *= -1;
	}
}

//================================================================
// ���t�̃G�t�F�N�g
//================================================================
void CEffect::Blood(void)
{
	D3DXVECTOR3 pos = Getpos();  //�ʒu�擾

	if (pos.y >= 60.0f)
	{
		m_move.y *= -1;
	}
}

//================================================================
// ���̃G�t�F�N�g
//================================================================
void CEffect::Smook(void)
{
	m_fRadius += 1.0f;
}

//================================================================
// �~�`�̃G�t�F�N�g
//================================================================
void CEffect::Circle(void)
{
	/*if (m_col.a >= 0)
	{
		m_col.a -= 0.01f;
	}*/
}

//================================================================
//�e�N�X�`���̐���(�ǂݍ���)
//================================================================
HRESULT CEffect::Load(void)
{
	CRenderer *pRenderer;
	pRenderer = CManager::Getinstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\effect000.jpg",
		&m_pTexture);

	return S_OK;
}

//================================================================
//�e�N�X�`���̔j��
//================================================================
void CEffect::UnLoad(void)
{
	//�e�N�X�`���̏���
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}