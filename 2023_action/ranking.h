//===========================================================
//
//�|���S�����o�����[ranking.h]
//Author �匴�叫
//
//===========================================================
#ifndef _RANKING_H_
#define _RANKING_H_

#include "object2D.h"

//�}�N����`
#define MAX_RANK        (5)     //�����N�̐�
#define MAX_SCORE       (8)     //�X�R�A�̌���

class CRanking : public CObject2D
{
public:
	CRanking();
	~CRanking();

	HRESULT Init(void);             //����������
	void Uninit(void);              //�I������
	void Update(void);              //�X�V����
	void Draw(void);                //�`�揈��
	static CRanking *Create(void);  //����

	void ResetRanking(void);        //���Z�b�g����
	static void SetRanking(int nScore);    //�����L���O�ݒ�

	void SaveData(void);            //�����L���O�ۑ�
	void LoadData(void);            //�����L���O�ǂݍ���

private:
	CObject2D *m_apObject2D[MAX_RANK][MAX_SCORE];  //�I�u�W�F�N�g2D�̃|�C���^
												   //CObject2D *m_apScoreObj[MAX_SCORE];
	int m_nIdxTexture;                             //�e�N�X�`���̃C���f�b�N�X�ԍ�
	static int m_nScore[MAX_RANK];
};

#endif // !_RANKING_H_