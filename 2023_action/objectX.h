//===========================================================
//
//�|���S�����o�����[oBjectX.h]
//Author �匴�叫
//
//===========================================================
#ifndef _OBJECTX_H__             //���̃}�N����`������ĂȂ�������
#define _OBJECTX_H__             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "object.h"

#define MAX_FILENAME   (128)

class CModel;

//�I�u�W�F�N�gX(X�t�@�C��)�N���X
class CObjectX : public CObject
{
public:
	CObjectX();
	CObjectX(D3DXVECTOR3 pos, D3DXVECTOR3 rot, const char *aModelFliename);
	~CObjectX();

	HRESULT Init(void);           //���f���̏���������    
	void Uninit(void);            //���f���̏I������
	void Update(void);            //���f���̍X�V����
	void Draw(void);              //���f���̕`�揈��
						          
	void ReadText(void);          //�e�L�X�g�t�@�C���ǂݍ���

	typedef struct
	{
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
		LPDIRECT3DTEXTURE9 *m_pTexture;     //�e�N�X�`���ւ̃|�C���^
	} OBJX;

	static CObjectX *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, const char *aModelFliename);  //����

	void BindModel(OBJX pObjX);

	void SetPositionOri(D3DXVECTOR3 posOrigin) { m_aObjectX.m_posOrigin = posOrigin;}  //���_�̈ʒu�ݒ�
	D3DXVECTOR3 GetPositionOri(void) { return m_aObjectX.m_posOrigin; }     //���_�̈ʒu�擾  

	void SetRotOrigin(D3DXVECTOR3 rotOrigin) { m_aObjectX.m_rotOrigin = rotOrigin; }       //�����ݒ�
	D3DXVECTOR3 GetRotOrigin(void) { return m_aObjectX.m_rotOrigin; }          //�����擾

	//void SetIdx(int nIdx) {}

	D3DXMATRIX GetMtxWorld(void) { return m_aObjectX.m_mtxWorld; }     //�}�g���b�N�X�擾

	D3DXVECTOR3 GetVtxMin(void) { return m_aObjectX.m_vtxMini; }  //���f���̍ŏ��l�擾
	D3DXVECTOR3 GetVtxMax(void) { return m_aObjectX.m_vtxMax; }   //���f���̍ő�l�擾

	int GetIdxModel(void) { return m_nIdxModel; }
	void SetIdxModel(int nIdx) { m_nIdxModel = nIdx; }


	void UpdateItemPos(void);

	

private:
	

	
	OBJX m_aObjectX;
	int m_nNumModel;          //���f��(�p�[�c)�̑���
	int m_nIdxModel;	      //���f���̃C���f�b�N�X�ԍ�
	int m_nIdxTexture[5];
	const char *m_Fliename;       //���f����X�t�@�C���̖��O
};

#endif