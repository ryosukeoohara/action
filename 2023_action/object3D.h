//=============================================================================
//
// �|���S������ [object3D.h]
// Author : �匴�@�叫
//
//=============================================================================

#ifndef _OBJECT3D_H_             //���̃}�N����`������ĂȂ�������
#define _OBJECT3D_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "main.h"
#include "object.h"

//�I�u�W�F�N�g3D�N���X
class CObject3D : public CObject
{
public:
	CObject3D();
	CObject3D(D3DXVECTOR3 pos);  //�R���X�g���N�^(overdose)
	~CObject3D();

	HRESULT Init(void);   //3D�I�u�W�F�N�g�̏���������    
	void Uninit(void);    //3D�I�u�W�F�N�g�̏I������
	void Update(void);    //3D�I�u�W�F�N�g�̍X�V����
	void Draw(void);      //3D�I�u�W�F�N�g�̕`�揈��

	void BindTexture(LPDIRECT3DTEXTURE9 m_Texture);  //�e�N�X�`�����o�C���h
	void SetVtxBillBoard(void);
	void SetVtxField(void);
	void SetVtxEffect(D3DXVECTOR3 pos, float m_fRadius, D3DXCOLOR col);
	void SetVtxBullet(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxEffectSword(float fWidth, float fHeight, D3DXCOLOR col);
	void SetVtxCircle(float fWidth, float fHeight, D3DXCOLOR col);
	void SetShadowPosition(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxLife(D3DXVECTOR3 pos, float fWidth, float fHeight, float fTex);
	void SetPosition(D3DXVECTOR3 pos) { m_pos = pos; } //�ʒu�ݒ�
	

	D3DXVECTOR3 GetPosition(void) { return m_pos; }     //�ʒu�擾   

	static CObject3D *Create(void);  //����
	D3DXMATRIX m_mtxWorld;    //���[���h�}�g���b�N�X
	D3DXMATRIX m_mtxRot, m_mtxTrans;    //�v�Z�p�}�g���b�N�X
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = NULL;        //���_�o�b�t�@�ւ̃|�C���^
//	float GetHeight(D3DXVECTOR3 pos);

private:
	LPDIRECT3DTEXTURE9 m_pTexture = NULL;       //�e�N�X�`���ւ̃|�C���^
	D3DXVECTOR3 m_vec0;
	D3DXVECTOR3 m_vec1;
	D3DXVECTOR3 m_vec2;
	D3DXVECTOR3 m_vec3;
	D3DXVECTOR3 m_vecLine0;
	D3DXVECTOR3 m_vecLine1;
	D3DXVECTOR3 m_vecLine2;
	D3DXVECTOR3 m_vecLine3;
	D3DXVECTOR3 m_nor0;
	D3DXVECTOR3 m_nor1;

	D3DXVECTOR3 m_pos;
};



#endif