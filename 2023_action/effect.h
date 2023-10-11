//===========================================================
//
//�|���S�����o�����[effect.h]
//Author �匴�叫
//
//===========================================================
#ifndef _EFFECT_H__             //���̃}�N����`������ĂȂ�������
#define _EFFECT_H__             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "billboard.h"

//�}�N����`
#define EFFECTMOVE   (5.0f)    //�G�t�F�N�g�̍ő吔

//�G�t�F�N�g�N���X
class CEffect : public CBillBoard
{
public:

	enum TYPEEFF
	{
		TYPEEFF_NONE = 0,   //�Ȃ���Ȃ�
		TYPEEFF_GROUND,     //�y��
		TYPEEFF_BLOOD,      //���t
		TYPEEFF_SMOOK,      //��
		TYPEEFF_CIRCLE,     //�~�`
		TYPEEFF_MAX
	};

	CEffect();  //�R���X�g���N�^
	CEffect(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXCOLOR col, float fRadius, int nLife, TYPEEFF type);  //�R���X�g���N�^
	~CEffect();  //�f�X�g���N�^

	//�G�t�F�N�g�̍\����
	typedef struct
	{
		D3DXVECTOR3 m_pos;        //�ʒu
		D3DXVECTOR3 m_move;       //�ړ���
		D3DXCOLOR m_col;          //�F
		float m_fRadius;          //���a(�傫��)
		int m_nLife;              //����(�\������)
	} Effect;

	HRESULT Init(void); //Bg�̏���������    
	void Uninit(void);  //Bg�̏I������
	void Update(void);  //Bg�̍X�V����
	void Draw(void);    //Bg�̕`�揈��

	static HRESULT Load(void);  //�e�N�X�`���̐���(�ǂݍ���)
	static void UnLoad(void);   //�e�N�X�`���̔j��

	void Ground(void);
	void Blood(void);
	void Smook(void);
	void Circle(void);

	static CEffect *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXCOLOR col, float fRadius, int nLife, TYPEEFF type);  //����
	D3DXCOLOR m_col;          //�F
	float m_fRadius;          //���a(�傫��)
	int m_nLife;              //����(�\������)
	D3DXVECTOR3 m_move;
	static Effect m_effect;

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;  //�e�N�X�`���ւ̃|�C���^
	TYPEEFF m_type;                        //���
	int m_nIdxTexture;                     //�e�N�X�`���̃C���f�b�N�X�ԍ�

};

#endif