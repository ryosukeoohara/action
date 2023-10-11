//=============================================================================
//
// ���C�g���� [light.h]
// Author : �匴�@�叫
//
//=============================================================================

#ifndef _LIGHT_H_             //���̃}�N����`������ĂȂ�������
#define _LIGHT_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "main.h"

//�}�N����`
#define MAX_LIGHT     (3)

//���C�g�N���X
class CLight
{
public:
	CLight();
	~CLight();

	//�v���g�^�C�v�錾
	void Init(void);          //���C�g�̏���������    
	void Uninit(void);        //���C�g�̏I������
	void Update(void);        //���C�g�̍X�V����

private:
	//D3DLIGHT9 m_light;    //�J�����̏��
						  
	D3DLIGHT9 m_light[MAX_LIGHT];     //�J�����̏��
	D3DXVECTOR3 m_vecDir[MAX_LIGHT];  //�ݒ�p�����x�N�g��

};


#endif