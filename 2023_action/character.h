//===========================================================
//
//�|���S�����o�����[oBjectX.h]
//Author �匴�叫
//
//===========================================================
#ifndef _CHARACTER_H__             //���̃}�N����`������ĂȂ�������
#define _CHARACTER_H__             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "main.h"

//�}�N����`
#define MAX_FILENAME   (128)
#define MAX_PRATS      (128)
#define MAX_TEX        (8)

//�I�u�W�F�N�gX(X�t�@�C��)�N���X
class CCharacter
{
public:
	CCharacter();
	CCharacter(const char *aModelFliename);
	~CCharacter();

	HRESULT Init(void);     //���f���̏���������    
	void Uninit(void);   //���f���̏I������
	void Update(void);   //���f���̍X�V����
	void Draw(void);     //���f���̕`�揈��

	void BindTexture(LPDIRECT3DTEXTURE9 *m_Texture);  //�e�N�X�`�����o�C���h
	static CCharacter *Create(const char *aModelFliename);  //����
	void SetParent(CCharacter *pModel) { m_pParent = pModel; }  //�e�̐ݒ�

	void SetPosition(D3DXVECTOR3 pos) { m_pos = pos; }  //�ʒu�ݒ�
	D3DXVECTOR3 GetPosition(void) { return m_pos; }     //�ʒu�擾   
	void SetPositionOri(D3DXVECTOR3 posOrigin) { m_posOrigin = posOrigin; }  //���_�̈ʒu�ݒ�
	D3DXVECTOR3 GetPositionOri(void) { return m_posOrigin; }     //���_�̈ʒu�擾  

	void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }       //�����ݒ�
	D3DXVECTOR3 GetRot(void) { return m_rot; }          //�����擾   
	void SetRotOrigin(D3DXVECTOR3 rotOrigin) { m_rotOrigin = rotOrigin; }       //�����ݒ�
	D3DXVECTOR3 GetRotOrigin(void) { return m_rotOrigin; }          //�����擾   

	D3DXMATRIX GetMtxWorld(void) { return m_mtxWorld; }     //�}�g���b�N�X�擾
	CCharacter *GetParent(void) { return m_pParent; }       //�e���f���̃|�C���^�擾

	D3DXVECTOR3 GetVtxMin(void) { return m_vtxMini; }  //���f���̍ŏ��l�擾
	D3DXVECTOR3 GetVtxMax(void) { return m_vtxMax; }   //���f���̍ő�l�擾

private:
	LPDIRECT3DTEXTURE9 *m_pTexture;     //�e�N�X�`���ւ̃|�C���^
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_posOrigin;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_rotOrigin;
	D3DXVECTOR3 m_vtxMini;    //���f���̍ŏ��l
	D3DXVECTOR3 m_vtxMax;     //���f���̍ő�l
	LPD3DXMESH m_pMesh;       //�e�N�X�`���ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat;  //���_�o�b�t�@�ւ̃|�C���^
	DWORD m_dwNumMat;         //�}�e���A���̐�
	D3DXMATRIX m_mtxWorld;    //���[���h�}�g���b�N�X
	int m_nNumModel;          //���f��(�p�[�c)�̑���
	const char *m_Fliename;   //���f����X�t�@�C���̖��O

	CCharacter *m_pParent;    //�e���f���ւ̃|�C���^

	int m_nIdxTexture[MAX_TEX];
};

#endif