//=============================================================================
//
// �G�̏��� [enemyfar.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _ENEMYFAR_H_
#define _ENEMYFAR_H_

#include "enemy.h"

////�G�N���X(�ߋ���)
//class CEnemyFar : public CEnemy
//{
//public:
//	CEnemyFar();                 //�R���X�g���N�^
//	CEnemyFar(D3DXVECTOR3 pos, D3DXVECTOR3 rot);  //�R���X�g���N�^(�I�[�o�[���[�h)
//	~CEnemyFar();                //�f�X�g���N�^
//
//	//���------------------------------------------------------------------
//	enum STATE
//	{
//		TATE_NONE = 0,             //�j���[�g����
//		TATE_MOVE,                 //�ړ�
//		TATE_ACTION,               //�U��
//		TATE_ACTIONNEUTRAL,        //�U���j���[�g����
//		TATE_DAMEGE,               //�_���[�W��
//		TATE_STAGGER,              //��낯
//		TATE_DEATH,                //���S
//		TATE_MAX
//	};
//
//								 //���[�V����-------------------------------------------------------------
//	typedef enum
//	{
//		MOTIONTYPE_NONE = 0,         //�j���[�g����
//		MOTIONTYPE_MOVE,             //�ړ�
//		MOTIONTYPE_ACTION,           //�U��
//		MOTIONTYPE_ACTIONNEUTRAL,    //�U���ҋ@
//		MOTIONTYPE_REROAD,           //���e���|�b�P������o��
//		MOTIONTYPE_DAMEGE,           //�_���[�W
//		MOTIONTYPE_DEATH,            //���S
//		MOTIONTYPE_MAX
//	} MOTIONTYPE;
//
//	HRESULT Init(void);   //����������    
//	void Uninit(void);    //�I������
//	void Update(void);    //�X�V����
//	void Draw(void);      //�`�揈��
//
//	static CEnemyFar *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);  //����
//
//	void ReadText(char *Filename);  //�O���t�@�C���ǂݍ���
//	static CEnemyWeak **GetEnemy(void) { return &m_EnemyWeak[0]; };
//	static CEnemyWeak *SetEnemy(CEnemyWeak *pEnemy) {  };
//	static void UninitWeak(void);
//
//	void Control(void);  //�G�̓���
//	void Death(int nCntEnemy);    //���񂾂Ƃ�
//
//	void SetState(STATE state) { m_state = state; }  //��Ԑݒ�
//	STATE GetState(void) { return m_state; }  //��Ԏ擾
//
//private:
//
//	TYPE m_type;
//	int m_nIdx;
//	int m_nParent;
//	int m_nNumPatrol;      //���񂷂�n�_�̐�
//	int m_nCurrentpos;     //���݂ǂ��̏���n�_�ɂ��邩
//	int m_nCntAction;      //�U�����Ă���ĂэU������܂ł̎���
//	int m_nCntDeath;       //���S���Ă�����ł���܂ł̎���
//	int m_DeathEnemyIdx;   //���S�����G�̔ԍ�
//	int m_nCntReload;      //�����[�h����܂ł̃J�E���g
//	float m_fDiff;
//	float m_fDest;
//	bool m_Tracking;       //�v���C���[��ǔ����邩�ǂ���
//	bool m_bAction;        //�U���������ǂ���
//	bool m_bBom;           //���e���|�b�P������o��
//};

#endif // !_ENEMYFAR_H_