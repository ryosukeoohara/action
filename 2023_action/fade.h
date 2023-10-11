//=============================================================================
//
// �t�F�[�h���� [fade.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _FADE_H_             //���̃}�N����`������ĂȂ�������
#define _FADE_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "object2D.h"
#include "manager.h"

class CFade
{
public:

	typedef enum
	{
		FADE_NONE = 0,
		FADE_IN,
		FADE_OUT,
		FADE_MAX

	}FADE;

	CFade();                                   //�R���X�g���N�^
	CFade(CScene::MODE modenext);              //�R���X�g���N�^
	~CFade();                                  //�f�X�g���N�^

	HRESULT Init(void);                        //����������
	void Uninit(void);                         //�I������
	void Update(void);                         //�X�V����
	void Draw(void);                           //�`�揈��
	void Set(CScene::MODE modenext);           //�ݒ菈��
	FADE Get(void) { return m_fade; }          //�擾����

	static CFade *Create(CScene::MODE modenext);                //����

private:
	LPDIRECT3DTEXTURE9 m_pTexture;              //�e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;         //���_�����i�[
	FADE m_fade;                                //�t�F�[�h�̏��
	CScene::MODE m_modeNext;                    //���̉��
	D3DXCOLOR m_Color;                          //�|���S���̐F
							                    
	int m_nIdxTexture;                          //�e�N�X�`���̃C���f�b�N�X�ԍ�
};

#endif