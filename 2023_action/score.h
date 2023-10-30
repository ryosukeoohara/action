//===========================================================
//
//�|���S�����o�����[score.h]
//Author �匴�叫
//
//===========================================================
#ifndef _SCORE_H_             //���̃}�N����`������ĂȂ�������
#define _SCORE_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "number.h"

//�}�N����`
#define SETSCORE   (8)   //�X�R�A�̌�

//�X�R�A�N���X
class CScore : public CNumber
{
public:
	CScore();  //�R���X�g���N�^
	CScore(D3DXVECTOR3 pos);  //�R���X�g���N�^(�I�[�o�[���[�h)
	~CScore();  //�f�X�g���N�^

	HRESULT Init(void);      //�|���S���̏���������    
	void Uninit(void);    //�|���S���̏I������
	void Update(void);    //�|���S���̍X�V����
	void Draw(void);      //�|���S���̕`�揈��

	static CScore *Create(void);  //����
	static HRESULT Load(void);  //
	static void UnLoad(void);
	CScore *GetScore(void) { return m_Score; };
	static void AddScore(int nScore);  //�X�R�A���Z

	static void SetScore(int nScore) 
	{ 
		m_nScore += nScore;
	};

	static int Getscore(void) 
	{ 
		return m_nScore; 
	};

	static void GameEndScore(void);     //�Q�[���I�����ɉ��Z����X�R�A

protected:
	static int m_nScore;

private:
	void ControlPlayer(void);  //�v���C���[�̐���
	static LPDIRECT3DTEXTURE9 m_pTexture;        //�e�N�X�`���ւ̃|�C���^
												 //LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;   //���_�����i�[
	D3DXVECTOR3 m_pos;  //�ʒu
	D3DXVECTOR3 m_move; //�ړ�
	static CScore *m_Score;
	static CNumber *m_apNumber[8];
	int m_nIdxTexture;
	//int m_nScore;  //�X�R�A
};

#endif