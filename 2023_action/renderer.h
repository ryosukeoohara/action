//===========================================================
//
//�|���S�����o�����[renderer.h]
//Author �匴�叫
//
//===========================================================
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "main.h"

class CEdit;
//�����_���[�N���X
class CRenderer
{
public:		//�N�ł��A�N�Z�X�ł���

	CRenderer();  //�R���X�g���N�^
	~CRenderer(); //�f�X�g���N�^

	HRESULT Init(HWND hWnd, BOOL bWindow);       //����������
	void Uninit(void);  //�I������
	void Update(void);  //�X�V����
	void Draw(void);    //�`�揈��
	
	LPDIRECT3DDEVICE9 GetDevice(void) { return m_pD3DDevice; }  //�f�o�C�X�̎擾

private:	//�����������A�N�Z�X�ł���

	LPDIRECT3D9 m_pD3D = NULL;                    //Direct3D�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECT3DDEVICE9 m_pD3DDevice = NULL;        //Direct3D�I�u�W�F�N�g�ւ̃|�C���^

};

#endif // !1