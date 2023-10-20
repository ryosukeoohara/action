//===========================================================
//
//�|���S�����o�����[ranking.cpp]
//Author �匴�叫
//
//===========================================================
#include "ranking.h"
#include "texture.h"
#include "manager.h"
#include "time.h"
#include "renderer.h"

//===========================================================
//�ÓI�����o�ϐ�
//===========================================================
int CRanking::m_nScore[MAX_RANK] = {};

//===========================================================
//�R���X�g���N�^
//===========================================================
CRanking::CRanking()
{
	m_nIdxTexture = 0;
}

//===========================================================
//�f�X�g���N�^
//===========================================================
CRanking::~CRanking()
{

}

//===========================================================
//��������
//===========================================================
CRanking *CRanking::Create(void)
{
	//�����L���O�̃|�C���^
	CRanking *pRanking = NULL;

	//�e�N�X�`���̃|�C���^
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	if (pRanking == NULL)
	{//�g�p����Ă��Ȃ��ꍇ

		//����
		pRanking = new CRanking;

		//����������
		pRanking->Init();
	}

	return pRanking;
}

//===========================================================
//����������
//===========================================================
HRESULT CRanking::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		for (int nCntScore = 0; nCntScore < MAX_SCORE; nCntScore++)
		{
			if (m_apObject2D[nCntRank] != NULL)
			{//�g�p����Ă��Ȃ��ꍇ

				//����
				m_apObject2D[nCntRank][nCntScore] = CObject2D::Create({ 500.0f + nCntScore * 50.0f, 180.0f + nCntRank * 100.0f, 0.0f });

				//�e�N�X�`���ǂݍ���
				m_apObject2D[nCntRank][nCntScore]->SetIdxTex(pTexture->Regist("data\\TEXTURE\\number002.png"));
			}
		}
	}

	return S_OK;
}

//===========================================================
//�I������
//===========================================================
void CRanking::Uninit(void)
{
	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		for (int nCntScore = 0; nCntScore < MAX_SCORE; nCntScore++)
		{
			if (m_apObject2D[nCntRank][nCntScore] != NULL)
			{//�g�p���ꂢ���Ԃ̂Ƃ�

			 //�I������
				m_apObject2D[nCntRank][nCntScore]->Uninit();

				//�g�p���Ă��Ȃ���Ԃɂ���
				m_apObject2D[nCntRank][nCntScore] = NULL;
			}
		}
	}

	Release();
}

//===========================================================
//�X�V����
//===========================================================
void CRanking::Update(void)
{
	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		for (int nCntScore = 0; nCntScore < MAX_SCORE; nCntScore++)
		{
			if (m_apObject2D[nCntRank][nCntScore] != NULL)
			{//�g�p����Ă����Ԃ̂Ƃ�

			 //�X�V����
				m_apObject2D[nCntRank][nCntScore]->Update();
			}
		}
	}

	int aTexU[MAX_RANK][MAX_SCORE];    //�e���̐������i�[

	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		aTexU[nCntRank][0] = m_nScore[nCntRank] % 100000000 / 10000000;
		aTexU[nCntRank][1] = m_nScore[nCntRank] % 10000000 / 1000000;
		aTexU[nCntRank][2] = m_nScore[nCntRank] % 1000000 / 100000;
		aTexU[nCntRank][3] = m_nScore[nCntRank] % 100000 / 10000;
		aTexU[nCntRank][4] = m_nScore[nCntRank] % 10000 / 1000;
		aTexU[nCntRank][5] = m_nScore[nCntRank] % 1000 / 100;
		aTexU[nCntRank][6] = m_nScore[nCntRank] % 100 / 10;
		aTexU[nCntRank][7] = m_nScore[nCntRank] % 10;
	}

	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		for (int nCntScore = 0; nCntScore < MAX_SCORE; nCntScore++)
		{
			m_apObject2D[nCntRank][nCntScore]->SetVtxRanking(aTexU[nCntRank][nCntScore]);
		}
	}
}

//===========================================================
//�`�揈��
//===========================================================
void CRanking::Draw(void)
{
	CTexture *pTexture = CManager::Getinstance()->GetTexture();
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		for (int nCntScore = 0; nCntScore < MAX_SCORE; nCntScore++)
		{
			if (m_apObject2D[nCntRank][nCntScore] != NULL)
			{//�g�p����Ă����Ԃ̂Ƃ�

				//�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, pTexture->GetAddress(m_apObject2D[nCntRank][nCntScore]->GetIdxTex()));

				//�`�揈��
				m_apObject2D[nCntRank][nCntScore]->Draw();
			}
		}
	}
}

//===========================================================
//�����L���O���Z�b�g����
//===========================================================
void CRanking::ResetRanking(void)
{

}

//===========================================================
//�����L���O�ݒ菈��
//===========================================================
void CRanking::SetRanking(int nScore)
{
	FILE *pFile;

	pFile = fopen("ranking.txt", "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		for (int nCount = 0; nCount < MAX_RANK; nCount++)
		{
			fscanf(pFile, "%d", &m_nScore[nCount]);
		}

		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***");
	}

	if (m_nScore[MAX_RANK - 1] < nScore)
	{
		m_nScore[MAX_RANK - 1] = nScore;
	}

	//�\�[�g�J�n
	for (int nCount = 0; nCount < MAX_RANK - 1; nCount++)
	{
		for (int nCntRank = 1 + nCount; nCntRank < MAX_RANK; nCntRank++)
		{
			//�傫�����������ւ�
			if (m_nScore[nCount] < m_nScore[nCntRank])
			{//����ւ�

				int nTmp = m_nScore[nCntRank];
				m_nScore[nCntRank] = m_nScore[nCount];
				m_nScore[nCount] = nTmp;
			}
		}
	}

	pFile = fopen("ranking.txt", "w");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ
		for (int nCount = 0; nCount < MAX_RANK; nCount++)
		{
			fprintf(pFile, "%d\n", m_nScore[nCount]);
		}

		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***");
	}
}