//===========================================================
//
//�|���S�����o�����[time.cpp]
//Author �匴�叫
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "time.h"
#include "texture.h"
#include "game.h"
#include "fade.h"

//================================================================
//�ÓI�����o�ϐ��錾
//================================================================
LPDIRECT3DTEXTURE9 CTime::m_pTexture = NULL;
CNumber *CTime::m_apNumber[SETTIME] = {};
int CTime::m_nTime = 0;
int CTime::m_nTimerCount = 0;

//================================================================
//�R���X�g���N�^
//================================================================
CTime::CTime()
{
	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
	m_nTime = 0;  //����
}

//================================================================
//�R���X�g���N�^(�I�[�o�[���[�h)
//================================================================
CTime::CTime(D3DXVECTOR3 pos)
{
	m_pos = pos;  //�ʒu
	SetPosition(pos);
	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
	m_nTime = 0;  //����
}

//================================================================
//�f�X�g���N�^
//================================================================
CTime::~CTime()
{

}

//================================================================
//��������
//================================================================
CTime *CTime::Create(void)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CTime *pTime = NULL;

	CTexture *pTexture = CManager::GetTexture();

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pTime == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pTime = new CTime();

			//����������
			pTime->Init();
		}
	}

	return pTime;
}

//================================================================
//�v���C���[�̏���������
//================================================================
HRESULT CTime::Init(void)
{
	CTexture *pTexture = CManager::GetTexture();

	for (int nCount = 0; nCount < SETTIME; nCount++)
	{
		if (m_apNumber[nCount] == NULL)
		{
			m_apNumber[nCount] = CNumber::Create({ 600.0f + 50.0f * nCount, 50.0f, 0.0f });

			//�e�N�X�`�����o�C���h
			//m_apNumber[nCount]->BindTexture(pTexture->GetAddress(m_nIdxTexture));

			m_apNumber[nCount]->SetNumberType(TYPENUMBER_TIME);

			//����������
			//m_apNumber[nCount]->Init();

			m_apNumber[nCount]->m_Number = INITTIME;
		}
	}

	m_nTime = TIME;  //����

	return S_OK;
}

//================================================================
//�v���C���[�̏I������
//================================================================
void CTime::Uninit(void)
{
	for (int nCount = 0; nCount < SETTIME; nCount++)
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
void CTime::Update(void)
{
	for (int nCount = 0; nCount < SETTIME; nCount++)
	{
		if (m_apNumber[nCount] != NULL)
		{
			//�X�V����
			m_apNumber[nCount]->Update();
		}
	}

	TimeCounter();
}

//================================================================
//�v���C���[�̕`�揈��
//================================================================
void CTime::Draw(void)
{
	CTexture *pTexture = CManager::GetTexture();
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	for (int nCount = 0; nCount < SETTIME; nCount++)
	{
		if (m_apNumber[nCount] != NULL)
		{
			//�`�揈��
			m_apNumber[nCount]->Draw();
		}
	}
}

//================================================================
//�^�C��
//================================================================
void CTime::TimeCounter(void)
{
	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::GetFade();

	m_nTimerCount++;

	if (m_nTimerCount % 60 == 0)
	{
		m_nTime--;

		m_apNumber[0]->m_Number = m_nTime % 100 / 10;
		m_apNumber[1]->m_Number = m_nTime % 10 / 1;
	}

	for (int nCount = 0; nCount < SETTIME; nCount++)
	{
		m_apNumber[nCount]->SetNumber(m_apNumber[nCount]->m_Number);
	}

	if (m_nTime <= 0)
	{
		if (pFade->Get() != pFade->FADE_OUT)
		{
			pFade->Set(CScene::MODE_RESULT);
		}
	}
}

////================================================================
////�e�N�X�`���̐���(�ǂݍ���)
////================================================================
//HRESULT CTime::Load(void)
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
//void CTime::UnLoad(void)
//{
//	//�e�N�X�`���̏���
//	if (m_pTexture != NULL)
//	{//�g�p����Ă�����
//
//		m_pTexture->Release();
//		m_pTexture = NULL;
//	}
//}