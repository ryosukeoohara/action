//==============================================================================
//
// 敵の処理 [enemy.cpp]
// Author : 大原　怜将
//
//==============================================================================

//*=============================================================================
//インクルードファイル
//*=============================================================================
#include "enemy.h"
#include "texture.h"
#include "manager.h"
#include "renderer.h"
#include "motion.h"

//*=============================================================================
//マクロ定義
//*=============================================================================
#define ENEMY_TEXT   ("data\\TEXT\\ENEMY00.txt")   //敵のテキストファイル

//==============================================================================
//コンストラクタ
//==============================================================================
CEnemy::CEnemy()
{

}

//==============================================================================
//コンストラクタ
//==============================================================================
CEnemy::CEnemy(D3DXVECTOR3 pos)
{

}

//==============================================================================
//デストラクタ
//==============================================================================
CEnemy::~CEnemy()
{

}

//==============================================================================
//生成処理
//==============================================================================
CEnemy * CEnemy::Create(void)
{
	return nullptr;
}

//==============================================================================
//初期化処理
//==============================================================================
HRESULT CEnemy::Init(void)
{
	if (m_motion == NULL)
	{//使用されていなかったら

		//生成
		m_motion = new CMotion;

		//初期化処理
		m_motion->Init();
	}

	ReadText(ENEMY_TEXT);

	return S_OK;
}

//==============================================================================
//終了処理
//==============================================================================
void CEnemy::Uninit(void)
{

}

//==============================================================================
//更新処理
//==============================================================================
void CEnemy::Update(void)
{

}

//==============================================================================
//描画処理
//==============================================================================
void CEnemy::Draw(void)
{

}

//==============================================================================
//テキストファイル読み込み
//==============================================================================
void CEnemy::ReadText(char *fliename)
{
	char aString[128] = {};
	char aComment[128] = {};
	int nCntParts = 0, nCntParts2 = 0, nCntParts3 = 0;
	int nCntMotion = 0;
	int nCntKeySet = 0;
	int nCntKey = 0;
	int nCntModel = 0;
	int nCntMotionIdx = 0;

	//テクスチャの情報取得
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	FILE *pFile;   //ファイルポインタを宣言

	pFile = fopen(fliename, "r");

	if (pFile != NULL)
	{//ファイルを開けた場合

		fscanf(pFile, "%s", &aString[0]);

		if (strcmp("SCRIPT", aString) == 0)
		{
			while (strcmp("END_SCRIPT", aString) != 0)
			{
				fscanf(pFile, "%s", &aString[0]);

				if (strcmp("NUM_MODEL", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%d", &m_nNumModel);  //モデルの総数

				}  //NUM_MODELのかっこ

				if (strcmp("MODEL_FILENAME", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%s", &m_filename[0]);  //モデルの名前

					m_apModel[nCntModel] = CCharacter::Create(m_filename);
					nCntModel++;

					nCntParts++;

				}  //MODEL_LILENAMEのかっこ


				if (strcmp("CHARACTERSET", aString) == 0)
				{
					while (strcmp("END_CHARACTERSET", aString) != 0)
					{
						fscanf(pFile, "%s", &aString);

						if (strcmp("PARTSSET", aString) == 0)
						{
							while (strcmp("END_PARTSSET", aString) != 0)
							{
								fscanf(pFile, "%s", &aString);

								if (strcmp("INDEX", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);          //=
									fscanf(pFile, "%d", &m_nIdx);  //モデルの番号
								}

								if (strcmp("PARENT", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);          //=
									fscanf(pFile, "%d", &m_nParent);  //親モデルの番号

									if (m_nParent > -1 && m_nNumModel > m_nParent)
									{
										m_apModel[nCntParts2]->SetParent(m_apModel[m_nParent]);
									}
									else
									{
										m_apModel[nCntParts2]->SetParent(NULL);
									}
								}

								if (strcmp("POS", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);      //=
									fscanf(pFile, "%f", &m_Readpos.x);  //モデルの総数
									fscanf(pFile, "%f", &m_Readpos.y);  //モデルの総数
									fscanf(pFile, "%f", &m_Readpos.z);  //モデルの総数

									m_apModel[nCntParts2]->SetPositionOri(m_Readpos);

									m_apModel[nCntParts2]->SetPosition(m_Readpos);
								}

								if (strcmp("ROT", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);      //=
									fscanf(pFile, "%f", &m_Readrot.x);  //モデルの総数
									fscanf(pFile, "%f", &m_Readrot.y);  //モデルの総数
									fscanf(pFile, "%f", &m_Readrot.z);  //モデルの総数

									m_apModel[nCntParts2]->SetRotOrigin(m_Readrot);

									m_apModel[nCntParts2]->SetRot(m_Readrot);
								}

							}//END_PARTSSETのかっこ

							nCntParts2++;

						}//PARTSSETのかっこ

					}//END_CHARACTERSETのかっこ 

				}//CHARACTERSETのかっこ 
			}
		}

		//ファイルを閉じる
		fclose(pFile);
	}
	else
	{
		return;
	}

	if (m_motion != NULL)
	{
		//モデルの設定
		m_motion->SetModel(&m_apModel[0], m_nNumModel);

		//初期化処理
		m_motion->ReadText(fliename);
	}
}
