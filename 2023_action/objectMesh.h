//=============================================================================
//
// ���b�V���|���S������ [objectMesh.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _OBJECTMESH_H_             //���̃}�N����`������ĂȂ�������
#define _OBJECTMESH_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "object.h"

//�I�u�W�F�N�g3D�N���X
class CObjectMesh : public CObject
{
public:
	CObjectMesh();
	CObjectMesh(D3DXVECTOR3 pos);  //�R���X�g���N�^(overdose)
	~CObjectMesh();

	HRESULT Init(void);   //3D�I�u�W�F�N�g�̏���������    
	void Uninit(void);    //3D�I�u�W�F�N�g�̏I������
	void Update(void);    //3D�I�u�W�F�N�g�̍X�V����
	void Draw(void);      //3D�I�u�W�F�N�g�̕`�揈��

	static CObjectMesh *Create(void);  //����

private:
	LPDIRECT3DTEXTURE9 m_pTexture;       //�e�N�X�`���ւ̃|�C���^
	D3DXMATRIX m_mtxWorld;    //���[���h�}�g���b�N�X
	D3DXMATRIX m_mtxRot, m_mtxTrans;    //�v�Z�p�}�g���b�N�X
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;        //���_�o�b�t�@�ւ̃|�C���^
	LPDIRECT3DINDEXBUFFER9  m_pIdxBuff;     //�C���f�b�N�X�o�b�t�@�ւ̃|�C���g
};



#endif