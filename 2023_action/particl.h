//===========================================================
//
//�|���S�����o�����[particl.h]
//Author �匴�叫
//
//===========================================================
#ifndef _PARTICL_H__             //���̃}�N����`������ĂȂ�������
#define _PARTICL_H__             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "billboard.h"

//�}�N����`
#define EFFECTMOVE   (5.0f)    //�G�t�F�N�g�̍ő吔



//�p�[�e�B�N���N���X
class CParticl : public CBillBoard
{
public:

	enum TYPEPAR
	{
		TYPEPAR_NONE = 0,  //�Ȃ���Ȃ�
		TYPEPAR_BULLET,    //�e
		TYPEPAR_BLOOD,     //���t
		TYPEPAR_GROUND,    //�y��
		TYPEPAR_SMOOK,     //��
		TYPEPAR_CIRCLE,    //�~�`
		TYPEPAR_MAX
	};

	CParticl();  //�R���X�g���N�^
	CParticl(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXCOLOR col, float fRadius, TYPEPAR type);  //�R���X�g���N�^
	~CParticl();  //�f�X�g���N�^

	

	HRESULT Init(void); //Bg�̏���������    
	void Uninit(void);  //Bg�̏I������
	void Update(void);  //Bg�̍X�V����
	void Draw(void);    //Bg�̕`�揈��

	static HRESULT Load(void);  //�e�N�X�`���̐���(�ǂݍ���)
	static void UnLoad(void);   //�e�N�X�`���̔j��

	void ParticlMove(void);
	void Blood(void);
	void Ground(void);
	void Smook(void);
	void Circle(void);

	static CParticl *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXCOLOR col, float fRadius, TYPEPAR type);  //����
	D3DXCOLOR m_col;          //�F
	float m_fRadius;          //���a(�傫��)
	int m_nLife;              //����(�\������)
	D3DXVECTOR3 m_move;

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;  //�e�N�X�`���ւ̃|�C���^
	TYPEPAR m_type;

};

#endif