//===========================================================
//
//�|���S�����o�����[number.h]
//Author �匴�叫
//
//===========================================================
#ifndef _NUMBER_H_
#define _NUMBER_H_

#include "main.h"
#include "object2D.h"

//�i���o�[�N���X
class CNumber : public CObject2D 
{
public:		//�N�ł��A�N�Z�X�ł���
	CNumber();  //�R���X�g���N�^
	CNumber(D3DXVECTOR3 pos);  //�R���X�g���N�^(overdose)
	~CNumber(); //�f�X�g���N�^

	typedef enum
	{
		TYPENUMBER_NONE = 0,
		TYPENUMBER_TIME,              //����
		TYPENUMBER_SCORE,             //�X�R�A
		TYPENUMBER_DESTROYCOUNTER,    //�G��|������
		TYPENUMBER_MAX
	} TYPENUMBER;

	HRESULT Init(void);   //����������
	void Uninit(void);    //�I������
	void Update(void);    //�X�V����
	void Draw(void);      //�`�揈��

	void SetPosition(D3DXVECTOR3 pos); //�ʒu�ݒ�
	D3DXVECTOR3 GetPosition(void);     //�ʒu�擾   

	void BindTexture(LPDIRECT3DTEXTURE9 m_Texture);  //�e�N�X�`�����o�C���h
	void UpdateTime(int m_nTime);  //���Ԃ̍X�V
	void UpdateScore(void);  //�X�R�A���Z

	void SetVtxCounter(D3DXVECTOR3 pos, float fWidth, float fHeight);

	void SetNumberType(TYPENUMBER type) { m_ntype = type;};

	TYPENUMBER GetNumberType(void) { return m_ntype; };

	void SetNumber(int nNumber);
	int GetNumber(void) { return m_Number; };

	static CNumber *Create(D3DXVECTOR3 pos);  //����
	int m_Number;

private:	//�����������A�N�Z�X�ł���
	LPDIRECT3DTEXTURE9 m_pTexture;        //�e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;   //���_�����i�[
	D3DXVECTOR3 m_pos;  //�ʒu
	TYPENUMBER m_ntype; //���
	static CObject2D *m_apObject2D;
	int m_nTimerCount;                          //���Ԃ̃J�E���^�[
	int m_nIdxTexture;                          //�e�N�X�`���̃C���f�b�N�X�ԍ�

};

#endif // !1