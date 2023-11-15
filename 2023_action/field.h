//===========================================================
//
//�|���S�����o�����[field.h]
//Author �匴�叫
//
//===========================================================
#ifndef _FIELD_H_
#define _FIELD_H_
#include "object3D.h"

class CField : public CObject3D
{
public:
	CField();
	~CField();

	HRESULT Init(void);   //�t�B�[���h�̏���������    
	void Uninit(void);    //�t�B�[���h�̏I������
	void Update(void);    //�t�B�[���h�̍X�V����
	void Draw(void);      //�t�B�[���h�̕`�揈��

	static CField *Create(void);  //����

private:
	int m_nIdxTexture;  //�e�N�X�`���̃C���f�b�N�X�ԍ�

};
#endif // !_FIELD_H_