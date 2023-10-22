//=============================================================================
//
// ���f������ [model.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _MODEL_H_
#define _MODEL_H_

#include "main.h"

#define MAX_MODEL  (1024)  //�ő吔
#define MAX_CHAR   (128)   //������̍ő吔

class CModel
{
public:

	CModel();
	~CModel();

	struct MODEL
	{
		int *m_pIdxTexture;            //�e�N�X�`���̃C���f�b�N�X�ԍ�
		char aName[MAX_CHAR] = "a";    //���f���̃t�@�C���l�[��
		LPD3DXMESH m_pMesh;            //�e�N�X�`���ւ̃|�C���^
		LPD3DXBUFFER m_pBuffMat;       //���_�o�b�t�@�ւ̃|�C���^
		DWORD m_dwNumMat;              //�}�e���A���̐�
	};

	HRESULT Load(void);
	void UnLoad(void);

	int Regist(const char *pFilename);

	int GetNumAll(void) { return m_nNumAll; };

private:
	int m_nNumAll;                 //���f���̑���
	int m_nIdxModel;               //���f���̃C���f�b�N�X�ԍ�       
	MODEL *m_aModel[MAX_MODEL];    //���f���̍\����

};
#endif // !_MODEL_H_
