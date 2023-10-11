//===========================================================
//
//�|���S�����o�����[map.h]
//Author �匴�叫
//
//===========================================================
#ifndef _MAP_H_             //���̃}�N����`������ĂȂ�������
#define _MAP_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "objectX.h"

//�}�N����`
#define MAX_MODEL    (1024)

//�v���C���[�N���X
class CMap : public CObject
{
public:
	CMap();  //�R���X�g���N�^
	~CMap();  //�f�X�g���N�^

	HRESULT Init(void);   //�|���S���̏���������    
	void Uninit(void);    //�|���S���̏I������
	void Update(void);    //�|���S���̍X�V����
	void Draw(void);      //�|���S���̕`�揈��

	void ReadText(void);  //�O���t�@�C���ǂݍ���

	typedef struct
	{
		char m_filename[256] = {};
		int m_nIdx;                         //���f���̃C���f�b�N�X�ԍ�
		D3DXVECTOR3 m_pos;		            //�ʒu
		D3DXVECTOR3 m_rot;		            //����
		D3DXVECTOR3 m_move;		            //�ړ���
		D3DXVECTOR3 m_vtxMini;              //���f���̍ŏ��l
		D3DXVECTOR3 m_vtxMax;               //���f���̍ő�l
		LPD3DXMESH   m_pMesh;               //�e�N�X�`���ւ̃|�C���^
		LPD3DXBUFFER m_pBuffMat;            //���_�o�b�t�@�ւ̃|�C���^
		DWORD m_dwNumMat;                   //�}�e���A���̐�
		D3DXMATRIX m_mtxWorld;              //���[���h�}�g���b�N�X
		LPDIRECT3DTEXTURE9  *m_pTexture;    //�e�N�X�`���ւ̃|�C���^

		D3DXVECTOR3 GetVtxMin(void) { return m_vtxMini; }  //���f���̍ŏ��l�擾
		D3DXVECTOR3 GetVtxMax(void) { return m_vtxMax; }   //���f���̍ő�l�擾

		void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
		D3DXVECTOR3 Getpos(void) { return m_pos; }

		void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }
		D3DXVECTOR3 GetRot(void) { return m_rot; }

	} MODEL;

	static CObjectX **GetX(void) { return &m_apModel[0]; }   //�}�b�v���f�����擾
	int GetnNumAll(void) { return m_nNumAll; }        //�������擾

private:
	static CObjectX *m_apModel[MAX_MODEL];  //���f��(�p�[�c)�ւ̃|�C���^
	MODEL m_aModel[MAX_MODEL];
	D3DXVECTOR3 m_pos;                  //�ʒu
	D3DXVECTOR3 m_rot;                  //����
	int m_nIdx;                         //���f���̃C���f�b�N�X�ԍ�
	int m_nIdxModel;
	int m_nNumAll;                      //�ǂݍ��񂾃��f���̑���
	int m_SetModel;                     //�ݒu�������f���̑���
	int m_nSelectModel;                 //���ݑI�����Ă��郂�f��
	char m_filename[MAX_MODEL][256] = {};
	//char m_filename[256] = {};
};

#endif