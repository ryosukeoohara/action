//=============================================================================
//
// �E�H�[������ [billboard.h]
// Author : �匴�@�叫
//
//=============================================================================

#ifndef _BILLBOARD_H_             //���̃}�N����`������ĂȂ�������
#define _BILLBOARD_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "main.h"
#include "object3D.h"

//�r���{�[�h�N���X
class CBillBoard : public CObject3D
{
public:
	CBillBoard();
	~CBillBoard();

	HRESULT Init(void);  //�r���{�[�h�̏���������    
	void Uninit(void);   //�r���{�[�h�̏I������
	void Update(void);   //�r���{�[�h�̍X�V����
	void Draw(void);     //�r���{�[�h�̕`�揈��

	static CBillBoard *Create(void);  //����

private:
	LPDIRECT3DTEXTURE9 m_pTexture = NULL;       //�e�N�X�`���ւ̃|�C���^
	D3DXMATRIX m_mtxView;
};


#endif