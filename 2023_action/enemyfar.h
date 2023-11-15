//=============================================================================
//
// �G�̏��� [enemyfar.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _ENEMYFAR_H_
#define _ENEMYFAR_H_

//*=============================================================================
//�C���N���[�h�t�@�C��
//*=============================================================================
//#include "character.h"
//#include "object.h"
#include "enemy.h"

//*=============================================================================
//�N���X��`
//*=============================================================================
class CMotion;

//*=============================================================================
//�N���X��`
//*=============================================================================
class CEnemyFar : public CEnemy
{
public:

	enum STATE
	{
		STATE_NONE = 0,
		STATE_NEUTRAL,
		STATE_ACTION,
		STATE_MAX
	};

	//���[�V����
	enum MOTIONTYPE
	{
		MOTIONTYPE_NEUTRAL = 0,              //�j���[�g����
		MOTIONTYPE_ACTION,                   //�U��
		MOTIONTYPE_MAX
	};

	CEnemyFar();                                  //�R���X�g���N�^
	CEnemyFar(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nlife);                   //�R���X�g���N�^
	~CEnemyFar();                                 //�f�X�g���N�^

	HRESULT Init(void);                        //������
	void Uninit(void);                         //�I��
	void Update(void);                         //�X�V
	void Draw(void);                           //�`��

	static CEnemyFar *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nlife);    //����
	void ReadText(char *fliename);             //�e�L�X�g�t�@�C���ǂݍ���

	//static CEnemyFar **GetEnemy(void) { return &m_pEnemy[0]; }
	void SetMoveX(float move) { m_move.x = move; }
	void SetMoveY(float move) { m_move.y = move; }

	static int GetNumAll(void) { return m_nNumAll; }

private:
	void Controll(void);                       //���䏈��
	CMotion *m_motion;                         //���[�V�����ւ̃|�C���^
	CCharacter *m_apModel[MAX_PRATS];          //���f��(�p�[�c)�ւ̃|�C���^
	STATE m_state;                             //���
	//static CEnemyFar *m_pEnemy[64];            //�G�̃|�C���^
	D3DXVECTOR3 m_posOld;                      //�O��̈ʒu
	D3DXVECTOR3 m_move;                        //�ړ�
	D3DXMATRIX m_mtxWorld;                     //���[���h�}�g���b�N�X
	//int m_nidxID;                              //�C���f�b�N�X�ԍ�
	int m_nActionCounter;                      //���ɍU������܂ł̃J�E���g
	int m_nLife;
	//static int m_nNumAll;                      //�G�̑���

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

#endif // !_ENEMYFAR_H_