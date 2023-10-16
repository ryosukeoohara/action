//===========================================================
//
//�|���S�����o�����[score.cpp]
//Author �匴�叫
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "score.h"
#include "input.h"
#include "input.h"
#include "texture.h"
#include "game.h"

//================================================================
//�ÓI�����o�ϐ��錾
//================================================================
LPDIRECT3DTEXTURE9 CScore::m_pTexture = NULL;
CNumber *CScore::m_apNumber[SETSCORE] = {};
int CScore::m_nScore = 0;

//================================================================
//�R���X�g���N�^
//================================================================
CScore::CScore()
{
	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
	m_nScore = 0;  //�X�R�A
}

//================================================================
//�R���X�g���N�^(�I�[�o�[���[�h)
//================================================================
CScore::CScore(D3DXVECTOR3 pos)
{
	m_pos = pos;  //�ʒu
	SetPosition(pos);
	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
	m_nScore = 0;  //�X�R�A
}

//================================================================
//�f�X�g���N�^
//================================================================
CScore::~CScore()
{

}

//================================================================
//��������
//================================================================
CScore *CScore::Create(void)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CScore *pScore = NULL;

	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pScore == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pScore = new CScore();

			//����������
			pScore->Init();
		}
	}

	return pScore;
}

//================================================================
//�v���C���[�̏���������
//================================================================
HRESULT CScore::Init(void)
{
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	for (int nCount = 0; nCount < SETSCORE; nCount++)
	{
		if (m_apNumber[nCount] == NULL)
		{
			m_apNumber[nCount] = CNumber::Create({ 800.0f + 50.0f * nCount, 50.0f, 0.0f });

			//�e�N�X�`�����o�C���h
			//m_apNumber[nCount]->BindTexture(pTexture->GetAddress(m_nIdxTexture));

			m_apNumber[nCount]->SetNumberType(TYPENUMBER_SCORE);

			//����������
			m_apNumber[nCount]->Init();
		}
	}

	return S_OK;
}

//================================================================
//�v���C���[�̏I������
//================================================================
void CScore::Uninit(void)
{
	for (int nCount = 0; nCount < SETSCORE; nCount++)
	{
		if (m_apNumber[nCount] != NULL)
		{
			//�I������
			m_apNumber[nCount]->Uninit();

			m_apNumber[nCount] = NULL;
		}
	}

	Release();
}

//================================================================
//�v���C���[�̍X�V����
//================================================================
void CScore::Update(void)
{
	for (int nCount = 0; nCount < SETSCORE; nCount++)
	{
		if (m_apNumber[nCount] != NULL)
		{
			//�X�V����
			m_apNumber[nCount]->Update();
		}
	}
}

//================================================================
//�v���C���[�̕`�揈��
//================================================================
void CScore::Draw(void)
{
	CTexture *pTexture = CManager::Getinstance()->GetTexture();
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	for (int nCount = 0; nCount < SETSCORE; nCount++)
	{
		if (m_apNumber[nCount] != NULL)
		{
			//�`�揈��
			m_apNumber[nCount]->Draw();
		}
	}
}

//================================================================
//�X�R�A���Z����
//================================================================
void CScore::AddScore(int nScore)
{
	m_nScore += nScore;

	m_apNumber[0]->m_Number = m_nScore % 100000000 / 10000000;
	m_apNumber[1]->m_Number = m_nScore % 10000000 / 1000000;
	m_apNumber[2]->m_Number = m_nScore % 1000000 / 100000;
	m_apNumber[3]->m_Number = m_nScore % 100000 / 10000;
	m_apNumber[4]->m_Number = m_nScore % 10000 / 1000;
	m_apNumber[5]->m_Number = m_nScore % 1000 / 100;
	m_apNumber[6]->m_Number = m_nScore % 100 / 10;
	m_apNumber[7]->m_Number = m_nScore % 10 / 1;
	
	for (int nCount = 0; nCount < SETSCORE; nCount++)
	{
		m_apNumber[nCount]->SetNumber(m_apNumber[nCount]->m_Number);
	}
}

////================================================================
////�e�N�X�`���̐���(�ǂݍ���)
////================================================================
//HRESULT CScore::Load(void)
//{
//	CRenderer *pRenderer;
//	pRenderer = CManager::GetRenderer();
//
//	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();
//
//	//�e�N�X�`���̓ǂݍ���
//	D3DXCreateTextureFromFile(pDevice,
//		"data\\TEXTURE\\number000.png",
//		&m_pTexture
//	);
//
//	return S_OK;
//}
//
////================================================================
////�e�N�X�`���̔j��
////================================================================
//void CScore::UnLoad(void)
//{
//	//�e�N�X�`���̏���
//	if (m_pTexture != NULL)
//	{//�g�p����Ă�����
//
//		m_pTexture->Release();
//		m_pTexture = NULL;
//	}
//}