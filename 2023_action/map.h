//===========================================================
//
//�|���S�����o�����[map.h]
//Author �匴�叫
//
//===========================================================
#ifndef _MAP_H_             //���̃}�N����`������ĂȂ�������
#define _MAP_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "objectX.h"

//�}�N����`
#define MAX_MODEL    (1024)
#define MAX_CHAR     (256)

//�v���C���[�N���X
class CMap
{
public:
	CMap();  //�R���X�g���N�^
	~CMap();  //�f�X�g���N�^

	HRESULT Init(void);   //�|���S���̏���������    
	void Uninit(void);    //�|���S���̏I������
	void Update(void);    //�|���S���̍X�V����
	void Draw(void);      //�|���S���̕`�揈��

	void ReadText(void);  //�O���t�@�C���ǂݍ���

	CObjectX **GetX(void) { return &m_apModel[0]; }   //�}�b�v���f�����擾
	int GetnNumAll(void) { return m_nNumAll; }        //�������擾

private:
	CObjectX *m_apModel[MAX_MODEL];          //���f��(�p�[�c)�ւ̃|�C���^
	int m_nIdx;                              //���f���̃C���f�b�N�X�ԍ�
	int m_nNumAll;                           //�ǂݍ��񂾃��f���̑���
	char m_filename[MAX_MODEL][MAX_CHAR] = {};    //������ǂݍ���
};

#endif