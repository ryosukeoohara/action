//===========================================================
//
//�|���S�����o�����[object2D.h]
//Author �匴�叫
//
//===========================================================
#ifndef _OBJECT2D_H_
#define _OBJECT2D_H_

#include "main.h"
#include "object.h"


//�I�u�W�F�N�g2D�N���X
class CObject2D : public CObject
{
public:		//�N�ł��A�N�Z�X�ł���
	CObject2D();  //�R���X�g���N�^
	CObject2D(D3DXVECTOR3 pos);  //�R���X�g���N�^(overdose)
	~CObject2D(); //�f�X�g���N�^

	//typedef enum
	//{
	//	TYPE_PLAYER = 0,  //�v���C���[
	//	TYPE_BULLET,      //�e
	//} TYPE;

	HRESULT Init(void);   //����������
	void Uninit(void);    //�I������
	void Update(void);    //�X�V����
	void Draw(void);      //�`�揈��

	static CObject2D *Create(D3DXVECTOR3 pos);  //����

	void BindTexture(LPDIRECT3DTEXTURE9 m_Texture);  //�e�N�X�`�����o�C���h
	void SetVtxEffect(D3DXVECTOR3 pos, float m_fRadius ,D3DXCOLOR col);
	void SetVtxBlock(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxBullet(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxPlayer(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxItem(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxNumber(D3DXVECTOR3 pos, float fWidth, float fHeight, int m_nNumber);
	void SetVtxBg(void);
	void SetVtxMessage(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxFrame(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxItemSlot(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxTitleLogo(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxEffectLine(void);
	void SetVtxLifeGage(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxIcon(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxLife(D3DXVECTOR3 pos, float fWidth, float fHeight, float fTex);
	void SetVtxFade(D3DXCOLOR col);
	void SetVtxTarget(D3DXVECTOR3 pos, float fWidth, float fHeight);
	void SetVtxPause(D3DXVECTOR3 pos, float fWidth, float fHeight, D3DXCOLOR col);
	void SetVtxUI(D3DXVECTOR3 pos, float fWidth, float fHeight, D3DXCOLOR col);
	void SetVtxRanking(int Tex);
	int GetIdxTex(void) { return m_nIdxTexture;	}
	void SetIdxTex(int Idx) { m_nIdxTexture = Idx; }

	//CItemSlot:: GetAttackType()

protected:

	//int m_nIdxTexture;

private:	//�����������A�N�Z�X�ł���
	//LPDIRECT3DTEXTURE9 m_pTexture;        //�e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;   //���_�����i�[
	int m_nIdxTexture;
	int m_nCounterAnimPlayer = 0;     //�J�E���^�[������������
	int m_nPatternAnimPlayer = 0;     //�p�^�[��No.������������

};

#endif // !1