//===========================================================
//
//�|���S�����o�����[motion.h]
//Author �匴�叫
//
//===========================================================
#include "motion.h"
#include "player.h"
#include<stdio.h>
#include<time.h>
#include<string.h>

//�ÓI�����o�ϐ�
int CMotion::m_nObj = 0;

//===========================================================
//�R���X�g���N�^
//===========================================================
CMotion::CMotion()
{
	m_nNumAll = 0;
	m_nType = 0;
	m_nTypeold = 0;
	m_nNumKey = 0;
	m_nKey = 0;
	m_nCounter = 0;
	m_nCntkeySet = 0;
	m_nNumFrame = 0;
	m_bLoop = false;
	m_bFinish = false;
}

//===========================================================
//�f�X�g���N�^
//===========================================================
CMotion::~CMotion()
{
	
}

//===========================================================
//����������
//===========================================================
void CMotion::Init(void)
{
	
}

//===========================================================
//�I������
//===========================================================
void CMotion::Uninit(void)
{

}

//===========================================================
//�X�V����
//===========================================================
void CMotion::Update(void)
{
	D3DXVECTOR3 fDiffpos, fDiffrot;  //�ʒu�A�����̍���
	D3DXVECTOR3 fDestpos, fDestrot;  //�ʒu�A�����̖ڕW

	//m_nType = GetType();

	if (m_nCounter >= m_aInfo[m_nType].m_KeySet[m_nKey].m_nFrame)
	{
		m_nKey = (m_nKey + 1) % m_aInfo[m_nType].m_nNumKey;

		m_nCounter = 0;
	}

	for (int nCount = 0; nCount < m_aInfo[m_nType].m_nNumKey; nCount++)
	{
		m_nNumFrame += m_aInfo[m_nType].m_KeySet[nCount].m_nFrame;
	}

	int Next = (m_nKey + 1) % m_aInfo[m_nType].m_nNumKey;

	if (m_nType != m_nTypeold && m_nKey + 1 < m_aInfo[m_nType].m_nNumKey)
	{
		int n = 0;
	}

	if (m_aInfo[m_nType].m_bFinish == false)
	{
		for (int nCount = 0; nCount < m_nNumModel; nCount++)
		{
			D3DXVECTOR3 pos = m_ppModel[nCount]->GetPosition();
			D3DXVECTOR3 rot = m_ppModel[nCount]->GetRot();
			D3DXVECTOR3 posOrigin = m_ppModel[nCount]->GetPositionOri();
			D3DXVECTOR3 rotOrigin = m_ppModel[nCount]->GetRotOrigin();

			fDiffpos = m_aInfo[m_nType].m_KeySet[Next].m_aKey[nCount].m_pos - m_aOldInfo.m_KeySet[m_nKey].m_aKey[nCount].m_pos;
			fDiffrot = m_aInfo[m_nType].m_KeySet[Next].m_aKey[nCount].m_rot - m_aOldInfo.m_KeySet[m_nKey].m_aKey[nCount].m_rot;

			if (fDiffrot.x > D3DX_PI)
			{
				fDiffrot.x -= D3DX_PI * 2.0f;
			}
			else if (fDiffrot.x < -D3DX_PI)
			{
				fDiffrot.x += D3DX_PI * 2.0f;
			}

			if (fDiffrot.y > D3DX_PI)
			{
				fDiffrot.y -= D3DX_PI * 2.0f;
			}
			else if (fDiffrot.y < -D3DX_PI)
			{
				fDiffrot.y += D3DX_PI * 2.0f;
			}

			if (fDiffrot.z > D3DX_PI)
			{
				fDiffrot.z -= D3DX_PI * 2.0f;
			}
			else if (fDiffrot.z < -D3DX_PI)
			{
				fDiffrot.z += D3DX_PI * 2.0f;
			}

			fDestpos = fDiffpos * ((float)m_nCounter / (float)m_aInfo[m_nType].m_KeySet[m_nKey].m_nFrame);
			fDestrot = fDiffrot * ((float)m_nCounter / (float)m_aInfo[m_nType].m_KeySet[m_nKey].m_nFrame);

			pos = posOrigin + m_aInfo[m_nType].m_KeySet[m_nKey].m_aKey[nCount].m_pos + fDestpos;
			rot = rotOrigin + m_aInfo[m_nType].m_KeySet[m_nKey].m_aKey[nCount].m_rot + fDestrot;

			m_ppModel[nCount]->SetPosition(pos);
			m_ppModel[nCount]->SetRot(rot);
		}

		m_nCounter++;

		if (m_aInfo[m_nType].m_nLoop == 0 && m_nKey + 1 >= m_aInfo[m_nType].m_nNumKey)
		{
			m_aInfo[m_nType].m_bFinish = true;
		}

		SetInfo(m_aInfo[m_nType]);
	}

	//SetInfo(m_aInfo[m_nType]);
}

//===========================================================
//�ݒ菈��
//===========================================================
void CMotion::Set(int nType)
{	
	SetInfo(m_aInfo[m_nType]);

	m_nTypeold = m_nType;

	m_nType = nType;

	m_aInfo[nType].m_bFinish = false;

	m_nCounter = 0;
	m_nKey = 0;
}

//===========================================================
//��ގ擾����
//===========================================================
int CMotion::GetType(void)
{
	return m_nType;
}

//===========================================================
//�I���������ǂ���
//===========================================================
bool CMotion::IsFinish(void)
{
	return m_aInfo[m_nType].m_bFinish;
}

//===========================================================
//���ݒ菈��
//===========================================================
void CMotion::SetInfo(INFO info)
{
	m_aOldInfo = info;
}

//===========================================================
//���ݒ菈��
//===========================================================
void CMotion::SetModel(CCharacter **ppModel, int nNumModel)
{
	m_ppModel = ppModel;
	m_nNumModel = nNumModel;
}

//===========================================================
//�O���t�@�C���ǂݍ���
//===========================================================
void CMotion::ReadText(const char *TextFilename)
{
	char aString[128] = {};
	char aComment[128] = {};
	int nCntParts = 0, nCntParts2 = 0, nCntParts3 = 0;
	int nCntMotion = 0;
	int nCntKeySet = 0;
	int nCntKey = 0;
	int nCntModel = 0;
	int nCntMotionIdx = 0;

	FILE *pFile;   //�t�@�C���|�C���^��錾

	pFile = fopen(TextFilename, "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		fscanf(pFile, "%s", &aString[0]);

		if (strcmp("SCRIPT", aString) == 0)
		{
			while (strcmp("END_SCRIPT", aString) != 0)
			{
				fscanf(pFile, "%s", &aString[0]);

				if (strcmp("MOTIONSET", aString) == 0)
				{
					while (strcmp("END_MOTIONSET", aString) != 0)
					{
						fscanf(pFile, "%s", &aString);

						if (strcmp("LOOP", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);
							fscanf(pFile, "%d", &m_aInfo[nCntMotion].m_nLoop);
						}

						if (strcmp("NUM_KEY", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);
							fscanf(pFile, "%d", &m_aInfo[nCntMotion].m_nNumKey);
						}

						if (strcmp("KEYSET", aString) == 0)
						{
							while (strcmp("END_KEYSET", aString) != 0)
							{
								fscanf(pFile, "%s", &aString);

								if (strcmp("FRAME", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);
									fscanf(pFile, "%d", &m_aInfo[nCntMotion].m_KeySet[nCntKeySet].m_nFrame);
								}

								if (m_aInfo[nCntMotion].m_nNumKey != nCntKeySet)
								{
									if (strcmp("PARTS", aString) == 0)
									{
										while (strcmp("END_PARTS", aString) != 0)
										{
											fscanf(pFile, "%s", &aString);

											if (strcmp("POS", aString) == 0)
											{
												fscanf(pFile, "%s", &aString);
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].m_KeySet[nCntKeySet].m_aKey[nCntKey].m_pos.x);
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].m_KeySet[nCntKeySet].m_aKey[nCntKey].m_pos.y);
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].m_KeySet[nCntKeySet].m_aKey[nCntKey].m_pos.z);
											}

											if (strcmp("ROT", aString) == 0)
											{
												fscanf(pFile, "%s", &aString);
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].m_KeySet[nCntKeySet].m_aKey[nCntKey].m_rot.x);
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].m_KeySet[nCntKeySet].m_aKey[nCntKey].m_rot.y);
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].m_KeySet[nCntKeySet].m_aKey[nCntKey].m_rot.z);
											}
										}


										nCntKey++;
									}
								}
							}

							nCntKeySet++;
							nCntKey = 0;
						}
					}

					nCntMotion++;
					nCntKeySet = 0;
				}
			}
		}

		//�t�@�C�������
		fclose(pFile);
	}
}