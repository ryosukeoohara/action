//=============================================================================
//
// �G�̊Ǘ� [enemymanager.cpp]
// Author : �匴�@�叫
//
//=============================================================================

//*============================================================================
//�C���N���[�h�t�@�C��
//*============================================================================
#include "enemymanager.h"

//*============================================================================
//�}�N����`
//*============================================================================
#define ENEMY_TEXT   ("data\\TEXT\\enemyinformation.txt")    //�G�̍ő吔

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CEnemyManager::CEnemyManager()
{
	//������
	ZeroMemory(m_pEnemy, sizeof(CEnemy));
	m_nEnemyAll = 0;
	m_Readpos = { 0.0f,0.0f,0.0f };
	m_Readrot = { 0.0f,0.0f,0.0f };
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CEnemyManager::~CEnemyManager()
{

}

//=============================================================================
//����������
//=============================================================================
HRESULT CEnemyManager::Init(void)
{
	//�e�L�X�g�t�@�C���ǂݍ���
	//ReadText();

	/*CEnemy::Create({ 0.0f,10.0f,0.0f }, { 0.0f,0.0f,0.0f }, 90);
	CEnemy::Create({ 3600.0f,115.0f,0.0f }, { 0.0f,0.0f,0.0f }, 80);
	CEnemy::Create({ 3000.0f,455.0f,0.0f }, { 0.0f,0.0f,0.0f }, 50);
	CEnemy::Create({ 4800.0f,310.0f,0.0f }, { 0.0f,0.0f,0.0f }, 100);
	CEnemy::Create({ 4300.0f,650.0f,0.0f }, { 0.0f,0.0f,0.0f }, 90);

	CEnemy::Create({ 5600.0f,620.0f,0.0f }, { 0.0f,0.0f,0.0f }, 250);*/

	return S_OK;
}

//=============================================================================
//�I������
//=============================================================================
void CEnemyManager::Uninit(void)
{
	for (int nCount = 0; nCount < MAX_ENEMY; nCount++)
	{
		if (m_pEnemy[nCount] != NULL)
		{//�g�p����Ă�����

			////�I������
			m_pEnemy[nCount]->Uninit();

			//�g�p���Ă��Ȃ���Ԃɂ���
			m_pEnemy[nCount] = NULL;
		}
	}
}

//=============================================================================
//�X�V����
//=============================================================================
void CEnemyManager::Update(void)
{
	//for (int nCount = 0; nCount < MAX_ENEMY; nCount++)
	//{
	//	if (m_pEnemy[nCount] != NULL)
	//	{//�g�p����Ă�����

	//		//�X�V����
	//		m_pEnemy[nCount]->Update();
	//	}
	//}
}

void CEnemyManager::Draw(void)
{
	//for (int nCount = 0; nCount < MAX_ENEMY; nCount++)
	//{
	//	if (m_pEnemy[nCount] != NULL)
	//	{//�g�p����Ă�����

	//		//�X�V����
	//		m_pEnemy[nCount]->Draw();
	//	}
	//}
}

//=============================================================================
//�e�L�X�g�t�@�C���ǂݍ���
//=============================================================================
void CEnemyManager::ReadText(void)
{
	int nLife = 0;
	char aString[128] = {};

	FILE *pFile;   //�t�@�C���|�C���^��錾

	pFile = fopen(ENEMY_TEXT, "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		fscanf(pFile, "%s", &aString[0]);

		if (strcmp("SCRIPT", aString) == 0)
		{
			fscanf(pFile, "%s", &aString[0]);

			if (strcmp("ALL_ENEMY", aString) == 0)
			{
				fscanf(pFile, "%s", &aString);          //=
				fscanf(pFile, "%d", &m_nEnemyAll);  //���f���̑���

			}  //NUM_MODEL�̂�����

			while (strcmp("END_SCRIPT", aString) != 0)
			{
				fscanf(pFile, "%s", &aString[0]);

				if (strcmp("ENEMYSET", aString) == 0)
				{
					while (strcmp("ENEMYSET_END", aString) != 0)
					{
						fscanf(pFile, "%s", &aString);

						if (strcmp("POS", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);      //=
							fscanf(pFile, "%f", &m_Readpos.x);  //�G�̈ʒu
							fscanf(pFile, "%f", &m_Readpos.y);  //�G�̈ʒu
							fscanf(pFile, "%f", &m_Readpos.z);  //�G�̈ʒu
						}

						if (strcmp("ROT", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);      //=
							fscanf(pFile, "%f", &m_Readrot.x);  //�G�̌���
							fscanf(pFile, "%f", &m_Readrot.y);  //�G�̌���
							fscanf(pFile, "%f", &m_Readrot.z);  //�G�̌���
						}

						if (strcmp("LIFE", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);       //=
							fscanf(pFile, "%d", &nLife);       //�G�̗̑�
						}

					}//ENEMYSET_END�̂����� 

					for (int nCount = 0; nCount < MAX_ENEMY; nCount++)
					{
						if (m_pEnemy[nCount] == NULL)
						{//�g�p����Ă��Ȃ�������

							//CEnemy *pEnemy = new CEnemy(m_Readpos, m_Readrot, nLife);

							//m_pEnemy[nCount] = CEnemy::Create(m_Readpos, m_Readrot, nLife);

							//m_pEnemy[nCount]->Init();

							break;
						}
					}

				}//ENEMYSET�̂����� 

			}

		}

		//�t�@�C�������
		fclose(pFile);
	}
	else
	{
		return;
	}
}
