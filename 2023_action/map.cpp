//===========================================================
//
//�|���S�����o�����[map.cpp]
//Author �匴�叫
//
//===========================================================
#include "map.h"
#include "texture.h"
#include "manager.h"
#include "renderer.h"

//�}�N����`
#define MAPMODEL  ("data\\TEXT\\map.txt")  //�e�L�X�g�t�@�C����

//�ÓI�����o�ϐ�
CObjectX *CMap::m_apModel[MAX_MODEL] = {};

//===========================================================
//�R���X�g���N�^
//===========================================================
CMap::CMap()
{
	m_nIdxModel = -1;
}

//================================================================
//�f�X�g���N�^
//================================================================
CMap::~CMap()
{

}

//================================================================
//�v���C���[�̏���������
//================================================================
HRESULT CMap::Init(void)
{
	for (int nCount = 0; nCount < MAX_MODEL; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{
			//�I������
			m_apModel[nCount] = NULL;
		}
	}

	//�O���t�@�C���ǂݍ���
	ReadText();

	return S_OK;
}

//================================================================
//�v���C���[�̏I������
//================================================================
void CMap::Uninit(void)
{
	for (int nCount = 0; nCount < MAX_MODEL; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{//�g�p���Ă�����

			//�I������
			m_apModel[nCount]->Uninit();

			//�g�p���Ă��Ȃ���Ԃɂ���
			m_apModel[nCount] = NULL;
		}
	}

	Release();
}

//================================================================
//�v���C���[�̍X�V����
//================================================================
void CMap::Update(void)
{
	for (int nCount = 0; nCount < MAX_MODEL; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{//�g�p���Ă�����

			//�X�V����
			m_apModel[nCount]->Update();
		}
	}
}

//================================================================
//�v���C���[�̕`�揈��
//================================================================
void CMap::Draw(void)
{
	for (int nCount = 0; nCount < MAX_MODEL; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{//�g�p���Ă�����

			//�`�揈��
			m_apModel[nCount]->Draw();
		}
	}
}

//================================================================
//�O���t�@�C���ǂݍ���
//================================================================
void CMap::ReadText(void)
{
	char aString[128] = {};
	char aComment[128] = {};
	int nCntModel = 0;
	int nIdx = 0;

	//���f���̃|�C���^�擾
	CModel *pModel = CManager::GetModel();

	D3DXVECTOR3 pos = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 rot = { 0.0f,0.0f,0.0f };

	FILE *pFile;   //�t�@�C���|�C���^��錾

	pFile = fopen(MAPMODEL, "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		fscanf(pFile, "%s", &aString[0]);

		if (strcmp("SCRIPT", aString) == 0)
		{
			while (strcmp("END_SCRIPT", aString) != 0)
			{
				fscanf(pFile, "%s", &aString[0]);

				if (strcmp("NUM_MODEL", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);                   //=
					fscanf(pFile, "%d", &m_nNumAll);                 //���f���̑���

				}  //NUM_MODEL�̂�����

				if (strcmp("MODEL_FILENAME", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);                   //=
					fscanf(pFile, "%s", &m_filename[nCntModel][0]);  //���f���̖��O

					nCntModel++;

				}  //MODEL_LILENAME�̂�����

				if (strcmp("MODELSET", aString) == 0)
				{
					while (strcmp("END_MODELSET", aString) != 0)
					{
						fscanf(pFile, "%s", &aString[0]);

						if (strcmp("TYPE", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);         //=
							fscanf(pFile, "%d", &m_nIdx);          //���
						}

						if (strcmp("POS", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);          //=
							fscanf(pFile, "%f", &pos.x);            //�ʒu
							fscanf(pFile, "%f", &pos.y);            //�ʒu
							fscanf(pFile, "%f", &pos.z);            //�ʒu
						}

						if (strcmp("ROT", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);          //=
							fscanf(pFile, "%f", &rot.x);            //�ʒu
							fscanf(pFile, "%f", &rot.y);            //�ʒu
							fscanf(pFile, "%f", &rot.z);            //�ʒu
						}
					}

					if (m_apModel[nIdx] == NULL)
					{//�g�p���Ă��Ȃ�������

						m_apModel[nIdx] = CObjectX::Create(pos, rot, m_filename[m_nIdx]);
					}
					
					nIdx++;  //�J�E���g�A�b�v

				}  //NUM_MODEL�̂�����
			}
		}

		//�t�@�C�������
		fclose(pFile);
	}
}