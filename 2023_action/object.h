//===========================================================
//
//�|���S�����o�����[object.h]
//Author �匴�叫
//
//===========================================================
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "main.h"

//�}�N����`
#define MAX_OBJECT    (2048)  //�I�u�W�F�N�g�̍ő吔

//�I�u�W�F�N�g�N���X
class CObject
{
public:		//�N�ł��A�N�Z�X�ł���

	CObject();             //�R���X�g���N�^
	virtual ~CObject();    //�f�X�g���N�^

	typedef enum
	{
		TYPE_NONE = 0,
		TYPE_PLAYER,  //�v���C���[
		TYPE_ENEMY,   //�G
		TYPE_BULLET,  //�e
		TYPE_EXPLOSION, //����
		TYPE_EFFECT,    //�G�t�F�N�g
		TYPE_PARTICL,   //�p�[�e�B�N��
		TYPE_ITEM,      //�A�C�e��
		TYPE_TIME,      //����
		TYPE_SCORE,     //�X�R�A
		TYPE_MAX
	} TYPE;

	virtual HRESULT Init(void) = 0;   //����������
	virtual void Uninit(void) = 0;    //�I������
	virtual void Update(void) = 0;    //�X�V����
	virtual void Draw(void) = 0;      //�`�揈��

	static void ReleaseAll(void);  //���ׂĂ��I��
	static void UpdateAll(void);   //���ׂĂ��X�V
	static void DrawAll(void);     //���ׂĂ�`��
	void Release(void);

	void BindTexture(LPDIRECT3DTEXTURE9 m_Texture);  //�e�N�X�`�����o�C���h
	static CObject *Getobject(int nIdx);
	int GetID(void) { return m_nID; }

	void SetType(TYPE type) { m_ntype = type;  }   //��ސݒ�
	TYPE GetType(void) { return m_ntype; }         //��ގ擾

	void SetPos(D3DXVECTOR3 *pos) { m_pos = *pos; }
	D3DXVECTOR3 Getpos(void) { return m_pos; }

	void SetRot(D3DXVECTOR3 *rot) { m_rot = *rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }

	void SetLife(int nLife) { m_nLife = nLife; }  //�̗͂̐ݒ�
	int GetLife(void) { return m_nLife; }		  //�̗͂��擾
	
	static int GetNumAll(void) { return m_nNumAll; }
	
private:	//�����������A�N�Z�X�ł���
	//LPDIRECT3DTEXTURE9 m_pTexture;        //�e�N�X�`���ւ̃|�C���^
	static CObject *m_apObjct[MAX_OBJECT];
	static int m_nNumAll;   //�I�u�W�F�N�g�̑���
	int m_nID;  //�������g��ID
	static CObject *m_pTop;  //�擪�̃I�u�W�F�N�g�ւ̃|�C���^
	static CObject *m_pCur; //�Ō���̃I�u�W�F�N�g�ւ̃|�C���^
	static CObject *m_pSNext;
	CObject *m_pPrev;       //�O�̃I�u�W�F�N�g�ւ̃|�C���^
	CObject *m_pNext;       //���̃I�u�W�F�N�g�ւ̃|�C���^
	bool m_bDeath;          //���S�t���O

	D3DXVECTOR3 m_pos;  //�ʒu
	D3DXVECTOR3 m_move; //�ړ���
	D3DXVECTOR3 m_rot;  //����
	TYPE m_ntype;        //���
	int m_nLife; //�̗�

};

#endif // !1