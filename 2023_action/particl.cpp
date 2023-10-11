//===========================================================
//
//�|���S�����o�����[particl.cpp]
//Author �匴�叫
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "object.h"
#include "manager.h"
#include "effect.h"
#include "particl.h"

#include <time.h>

//�}�N����`
#define TYPE_BLOOD    (20)   //���̃p�[�e�B�N��
#define TYPE_GROUND   (10)   //�y���̃p�[�e�B�N��
#define TYPE_CIRCLE   (314)   //�~�`�̃p�[�e�B�N��
#define SPEED    (2.0f)  //�ړ���

//================================================================
//�ÓI�����o�ϐ��錾
//================================================================
LPDIRECT3DTEXTURE9 CParticl::m_pTexture = NULL;

//================================================================
//�R���X�g���N�^
//================================================================
CParticl::CParticl()
{
	m_fRadius = 0;
	m_nLife = 0;
	m_type = TYPEPAR_NONE;
}

//================================================================
//�R���X�g���N�^
//================================================================
CParticl::CParticl(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXCOLOR col, float fRadius, TYPEPAR type)
{
	SetPos(&pos);
	SetRot(&rot);
	m_col = col;
	m_fRadius = fRadius;
	m_nLife = 0;
	m_type = type;
}

//================================================================
//�f�X�g���N�^
//================================================================
CParticl::~CParticl()
{

}

//================================================================
//��������
//================================================================
CParticl *CParticl::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXCOLOR col, float fRadius, TYPEPAR type)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CParticl *pParticl = NULL;

	if (GetNumAll() < MAX_OBJECT)
	{
		if (pParticl == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pParticl = new CParticl(pos, rot, col, fRadius, type);

			//�e�N�X�`�����o�C���h
			pParticl->BindTexture(m_pTexture);

			//����������
			pParticl->Init();
		}
	}

	return pParticl;
}

//================================================================
//�|���S���̏���������
//================================================================
HRESULT CParticl::Init(void)
{
	//��ނ̐ݒ�
	SetType(TYPE_PARTICL);

	//����������
	CBillBoard::Init();
	//m_fRadius = 15.0f;
	//m_nLife = 20;
	return S_OK;
}

//================================================================
//�|���S���̏I������
//================================================================
void CParticl::Uninit(void)
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
void CParticl::Update(void)
{
	//�X�V����
	CBillBoard::Update();

	switch (m_type)
	{
	case TYPEPAR_NONE:
		break;

	case TYPEPAR_BULLET:
		ParticlMove();
		break;

	case TYPEPAR_BLOOD:
		Blood();
		break;

	case TYPEPAR_GROUND:
		Ground();
		break;

	case TYPEPAR_SMOOK:
		Smook();
		break;

	case TYPEPAR_CIRCLE:
		Circle();
		break;
	}

	m_nLife--;

	if (m_nLife <= 0)
	{
		//�I������
		CParticl::Uninit();
	}
}

//================================================================
//�|���S���̕`�揈��
//================================================================
void CParticl::Draw(void)
{
	CRenderer *pRenderer;
	pRenderer = CManager::GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���u�����f�B���O�����Z���v�ɐݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//�`�揈��
	CBillBoard::Draw();

	//���u�����f�B���O�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//================================================================
//�|���S���̕`�揈��
//================================================================
void CParticl::ParticlMove(void)
{
	D3DXVECTOR3 pos;

	pos = Getpos();

	//�����̎��ݒ�
	srand((unsigned int)time(0));

	for (int nCnt = 0; nCnt < 10; nCnt++)
	{
		float fMove, fRot;

		fMove = (float)(rand() % 50) / 100.0f * 8.0f;
		fRot = (float)(rand() % 629 - 314) / 100.0f;
		
		m_move.x = sinf(fRot) * fMove;
		m_move.y = cosf(fRot) * fMove;
		m_move.z = cosf(fRot) * fMove;

		CEffect::Create(pos, { m_move.x, m_move.y, m_move.z }, { 0.8f, 1.0f, 1.0f, 1.0f }, m_fRadius, 30, CEffect::TYPEEFF_NONE);
	}

	SetPos(&pos);
}

//================================================================
//���t�̃p�[�e�B�N��
//================================================================
void CParticl::Blood(void)
{
	D3DXVECTOR3 pos;

	pos = Getpos();

	//�����̎��ݒ�
	srand((unsigned int)time(0));

	for (int nCnt = 0; nCnt < TYPE_BLOOD; nCnt++)
	{
		float fMove, fRot, fRange;

		fMove = (float)(rand() % 50) / 100.0f * 8.0f;
		fRot = GetRot().y;
		fRange = (float)(rand() % 10) - D3DX_PI * 2;

		m_move.x = sinf(fRot * fRange) * fMove;
		m_move.y = cosf(fRot * fRange) * fMove;
		m_move.z = cosf(fRot * fRange) * fMove;

		if (m_move.z > 0.0f)
		{
			m_move.z *= -1;
		}
		
		CEffect::Create(pos, { m_move.x, m_move.y, m_move.z }, { 1.0f, 0.0f, 0.0f, 1.0f }, m_fRadius, 30, CEffect::TYPEEFF_BLOOD);
	}

	SetPos(&pos);
}

//================================================================
//�y���݂����ȃp�[�e�B�N��
//================================================================
void CParticl::Ground(void)
{
	D3DXVECTOR3 pos;

	pos = Getpos();

	//�����̎��ݒ�
	srand((unsigned int)time(0));

	for (int nCnt = 0; nCnt < TYPE_BLOOD; nCnt++)
	{
		float fPosX, fPosZ, fMove, fRot, fRange;

		fPosX = (float)(rand() % 100);
		fPosZ = (float)(rand() % 100);
		fMove = (float)(rand() % 50) / 100.0f * 8.0f;
		fRot = (float)(rand() % 629 - 314) / 100.0f;
		fRange = (float)(rand() % 10) - D3DX_PI * 2;

		m_move.x = sinf(fRot * fRange) * fMove;
		m_move.y = cosf(fRot * fRange) * fMove;
		m_move.z = cosf(fRot * fRange) * fMove;

		if (m_move.y < 0.0f)
		{
			m_move.y *= -1;
		}

		CEffect::Create({pos.x, 0.0f, pos.z}, { m_move.x, m_move.y, m_move.z }, { 1.0f, 0.0f, 0.0f, 1.0f }, m_fRadius, 30, CEffect::TYPEEFF_GROUND);
	}

	SetPos(&pos);
}

//================================================================
//���݂����ȃp�[�e�B�N��
//================================================================
void CParticl::Smook(void)
{
	D3DXVECTOR3 pos;

	pos = Getpos();

	//�����̎��ݒ�
	srand((unsigned int)time(0));

	for (int nCnt = 0; nCnt < TYPE_BLOOD; nCnt++)
	{
		float fPosX, fPosZ, fMove, fRot, fRange;

		fPosX = (float)(rand() % 100);
		fPosZ = (float)(rand() % 100);
		fMove = (float)(rand() % 50) / 100.0f * 8.0f;
		fRot = (float)(rand() % 629 - 314) / 100.0f;
		fRange = (float)(rand() % 10) - D3DX_PI * 2;

		//m_move.x = sinf(fRot * fRange) * fMove;
		m_move.y = cosf(fRot * fRange) * fMove * 2.0f;
		//m_move.z = cosf(fRot * fRange) * fMove;

		if (m_move.y < 0.0f)
		{
			m_move.y *= -1;
		}

		CEffect::Create({ pos.x, 0.0f, pos.z }, { m_move.x, m_move.y, m_move.z }, { 1.0f, 0.0f, 0.0f, 1.0f }, 10.0f, 30, CEffect::TYPEEFF_SMOOK);
	}

	SetPos(&pos);
}

//================================================================
//�~�`�̃p�[�e�B�N��
//================================================================
void CParticl::Circle(void)
{
	//���[�J���ϐ��錾
	D3DXVECTOR3 pos;
	float fRot;

	//�ʒu�擾
	pos = Getpos();

	for (int nCnt = 0; nCnt < TYPE_CIRCLE; nCnt++)
	{
		//�����ݒ�
		fRot = ((float)nCnt / (D3DX_PI * 1.0f));

		//�ړ��ʐݒ�
		m_move.x = sinf(fRot) * SPEED;
		m_move.y = cosf(fRot) * SPEED;

		//�G�t�F�N�g�̐���
		CEffect::Create({ pos.x, 50.0f, pos.z }, { m_move.x, m_move.y, m_move.z }, { 1.0f, 0.0f, 0.0f, 1.0f }, 3.0f, 30, CEffect::TYPEEFF_CIRCLE);
	}

	//�ʒu�ݒ�
	SetPos(&pos);
}