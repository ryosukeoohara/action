//===========================================================
//
//�|���S�����o�����[time.h]
//Author �匴�叫
//
//===========================================================
#ifndef _TIME_H_             //���̃}�N����`������ĂȂ�������
#define _TIME_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "number.h"

//�}�N����`
#define SETTIME   (2)  //���Ԃ̌�
#define TIME      (99) //�Q�[���̐�������
#define INITTIME  (9)  //���ꂼ��̌��̏����l

//�^�C���N���X
class CTime : public CNumber
{
public:
	CTime();  //�R���X�g���N�^
	CTime(D3DXVECTOR3 pos);  //�R���X�g���N�^(�I�[�o�[���[�h)
	~CTime();  //�f�X�g���N�^

	HRESULT Init(void);      //�|���S���̏���������    
	void Uninit(void);    //�|���S���̏I������
	void Update(void);    //�|���S���̍X�V����
	void Draw(void);      //�|���S���̕`�揈��

	static CTime *Create(void);  //����
	static HRESULT Load(void);  //
	static void UnLoad(void);
	static CTime *GetTime(void) { return m_Time; };
	static void SetTime(int nTime) { m_nTime = nTime; };
	static int Gettime(void) { return m_nTime; };
	static void TimeCounter(void);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;        //�e�N�X�`���ւ̃|�C���^
	D3DXVECTOR3 m_pos;  //�ʒu
	D3DXVECTOR3 m_move; //�ړ�
	static CTime *m_Time;
	static CNumber *m_apNumber[SETTIME];
	static int m_nTimerCount;
	static int m_nTime;  //����
	int m_nIdxTexture;
};

#endif