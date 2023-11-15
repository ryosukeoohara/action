//=============================================================================
//
// �G�̏��� [enemy.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//*=============================================================================
//�C���N���[�h�t�@�C��
//*=============================================================================
#include "character.h"
#include "object.h"

//*=============================================================================
//�N���X��`
//*=============================================================================
class CMotion;

//*=============================================================================
//�N���X��`
//*=============================================================================
class CEnemy : public CObject
{
public:

	enum STATE
	{
		STATE_NONE = 0,
		STATE_NEUTRAL,
		STATE_MOVE,
		STATE_MAX
	};

	//���[�V����
	enum MOTIONTYPE
	{
		MOTIONTYPE_NEUTRAL = 0,              //�j���[�g����
		MOTIONTYPE_MOVE,                     //�ړ�
		MOTIONTYPE_JUMP,                     //�W�����v
		MOTIONTYPE_MAX
	} ;

	CEnemy();                                  //�R���X�g���N�^
	CEnemy(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nlife);                   //�R���X�g���N�^
	~CEnemy();                                 //�f�X�g���N�^
										       
	HRESULT Init(void);                        //������
	void Uninit(void);                         //�I��
	void Update(void);                         //�X�V
	void Draw(void);                           //�`��

	static CEnemy *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nlife);    //����
	void ReadText(char *fliename);             //�e�L�X�g�t�@�C���ǂݍ���

	static CEnemy **GetEnemy(void) { return &m_pEnemy[0]; }
	
	void SetMoveX(float move) { m_move.x = move; }
	void SetMoveY(float move) { m_move.y = move; }

	D3DXVECTOR3 GetMove(void) { return m_move; }

	void SetIdx(int idx) { m_nidxID = idx; }

	

	static int GetNumAll(void) { return m_nNumAll; }

protected:

	static CEnemy *m_pEnemy[64];               //�G�̃|�C���^
	int m_nidxID;                              //�C���f�b�N�X�ԍ�
	static int m_nNumAll;                      //�G�̑���
										       
private:								       
	void Controll(void);                       //���䏈��
	CMotion *m_motion;                         //���[�V�����ւ̃|�C���^
	CCharacter *m_apModel[MAX_PRATS];          //���f��(�p�[�c)�ւ̃|�C���^
	STATE m_state;                             //���
	
	D3DXVECTOR3 m_posOld;                      //�O��̈ʒu
	D3DXVECTOR3 m_move;                        //�ړ�
	D3DXMATRIX m_mtxWorld;                     //���[���h�}�g���b�N�X
	int m_nLife;
	

	//*=============================================================================
	//�O���t�@�C���ǂݍ��ݗp
	//*=============================================================================
	D3DXVECTOR3 m_Readpos;                     //�ʒu�ǂݍ��ݗp
	D3DXVECTOR3 m_Readrot;                     //�����ǂݍ��ݗp
	int m_nIdx;                                //�C���f�b�N�X�ԍ�
	int m_nParent;                             //�e�̃C���f�b�N�X�ԍ�
	int m_nNumModel;                           //���f��(�p�[�c)�̑���
	char m_filename[128] = {};                 //�����ǂݍ��ݗp

};

#endif // !_ENEMY_H_