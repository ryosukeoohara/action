//=============================================================================
//
// �J�������� [camera.h]
// Author : �匴�@�叫
//
//=============================================================================

#ifndef _CAMERA_H_             //���̃}�N����`������ĂȂ�������
#define _CAMERA_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "main.h"

//�J�����N���X
class CCamera
{
public:
	CCamera();
	~CCamera();

	enum TYPE
	{
		TYPE_NONE = 0,
		TYPE_TITLE,      //�^�C�g���̃J����
		TYPE_GAME,       //�Q�[���̃J����
		TYPE_RESULT,     //���U���g�̃J����
		TYPE_EDIT,       //�G�f�B�b�g�̃J����
		TYPE_MAX 
	};

	void Init(void);          //�J�����̏���������    
	void Uninit(void);        //�J�����̏I������
	void Update(void);        //�J�����̍X�V����
	void CameraV(void);
	void Edit(void);          //�G�f�B�b�g�̃J����
	void CameraR(void);
	void Title(void);
	void Scope(void);
	void SetCamera(void);

	void Boss(void);

	void SetRot(D3DXVECTOR3 Rot) { m_rot = Rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }

	void SetType(TYPE type) { m_type = type; }
	TYPE GetType(void) { return m_type; }

private:
	D3DXMATRIX m_mtxView;        //�r���[�}�g���b�N�X
	D3DXMATRIX m_mtxProjection;  //�v���W�F�N�V�����}�g���b�N�X

	D3DXVECTOR3 m_posV;    //���_
	D3DXVECTOR3 m_posR;    //�����_
	D3DXVECTOR3 m_posU;    //������x�N�g��

	D3DXVECTOR3 m_posVDest;  //�ړI�̎��_
	D3DXVECTOR3 m_posRDest;  //�ړI�̒����_

	D3DXVECTOR3 m_rot;  //����
	D3DXVECTOR3 m_move; //�ړ�

	TYPE m_type;

	int m_nCounter;     //�J�������؂�ւ���Ă��鎞��
};



#endif
