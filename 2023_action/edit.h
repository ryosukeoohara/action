//===========================================================
//
//�G�f�B�b�g���[�h[edit.h]
//Author �匴�叫
//
//===========================================================
#ifndef _EDIT_H_
#define _EDIT_H_
#include "main.h"
#include "objectX.h"

//�}�N����`
#define MAX_MODELSET    (1024)

class CEdit : public CObject
{
public:
	CEdit();
	~CEdit();

	typedef enum
	{
		MODE_CREATE = 0,
		MODE_DELETE,
		MODE_MAX
	} MODE;

	typedef struct
	{
		char m_filename[256] = {};
		int m_nType;
		D3DXVECTOR3 m_pos;		  //�ʒu
		D3DXVECTOR3 m_rot;		  //����
		D3DXVECTOR3 m_move;		  //�ړ���
		D3DXVECTOR3 m_vtxMini;    //���f���̍ŏ��l
		D3DXVECTOR3 m_vtxMax;     //���f���̍ő�l
		LPD3DXMESH   m_pMesh;       //�e�N�X�`���ւ̃|�C���^
		LPD3DXBUFFER m_pBuffMat;  //���_�o�b�t�@�ւ̃|�C���^
		DWORD m_dwNumMat;         //�}�e���A���̐�
		D3DXMATRIX m_mtxWorld;    //���[���h�}�g���b�N�X
		LPDIRECT3DTEXTURE9  *m_pTexture;    //�e�N�X�`���ւ̃|�C���^

	} MODEL;

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Save(void);
	void XLoad(void);
	void TEXTLoad(void);
	void ReadText(void);

	void Control(void);
	void SetModelDelete(void);

private:

	CObjectX *m_apModel[MAX_MODELSET];  //���f��(�p�[�c)�ւ̃|�C���^
	MODEL m_Model[MAX_MODELSET];
	MODE m_mode;
	D3DXVECTOR3 m_pos;   //�ʒu
	D3DXVECTOR3 m_rot;   //����
	int m_nIdx;          //���f���̃C���f�b�N�X�ԍ�
	int m_nNumAll;       //�ǂݍ��񂾃��f���̑���
	int m_SetModel;      //�ݒu�������f���̑���
	int m_nSelectModel;  //���ݑI�����Ă��郂�f��
};

#endif // !_EDIT_H_