//===========================================================
//
//�o�����o����[appear.h]
//Author �匴�叫
//
//===========================================================
#ifndef _APPEAR_H_             //���̃}�N����`������ĂȂ�������
#define _APPEAR_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "character.h"
#include "object.h"

//�O���錾
class CMotion;
class CEnemy;
class CChibi;
class CFoot;

//�}�N����`
#define PLAYERMOVE   (1.0f)

//�v���C���[�N���X
class CPlayer : public CObject
{
public:
	CPlayer();  //�R���X�g���N�^
	CPlayer(D3DXVECTOR3 pos);  //�R���X�g���N�^(�I�[�o�[���[�h)
	~CPlayer();  //�f�X�g���N�^

				 //���
	typedef enum
	{
		STATE_NONE = 0,
		STATE_NEUTRAL,                //�ҋ@
		STATE_MOVE,                   //�ړ�
		STATE_JUMP,                   //�W�����v
		STATE_ATTACK,                 //�U��
		STATE_APPR,                   //�o��
		STATE_MAX
	} STATE;

	//���[�V����
	typedef enum
	{
		MOTIONTYPE_NEUTRAL = 0,               //�j���[�g����
		MOTIONTYPE_MOVE,                     //�ړ�
		MOTIONTYPE_JUMP,                     //�W�����v
		MOTIONTYPE_ATTACK,                   //�U��
		MOTIONTYPE_APPR,                     //�o��
		MOTIONTYPE_MAX
	} MOTIONTYPE;

	struct CHIBI
	{

	};

	struct FOOT
	{

	};

	struct PLAYER
	{

	};

	HRESULT Init(void);        //�v���C���[�̏���������    
	void Uninit(void);		   //�v���C���[�̏I������
	void Update(void);         //�v���C���[�̍X�V����
	void Draw(void);           //�v���C���[�̕`�揈��

	static CPlayer *Create(D3DXVECTOR3 pos);  //����
											  //static CPlayer *GetPlayer(void) { return m_Player; };
	void SetState(STATE state) { m_State = state; };
	STATE GetState(void) { return m_State; };
	void ReadText(const char *fliename);       //�O���t�@�C���ǂݍ���
	void Hit(void);			//�U��������������̏���

	D3DXVECTOR3 GetMove(void) { return m_move; }      //�ړ��ʎ擾
	void SetMove(D3DXVECTOR3 move) { m_move = move; }  //�ړ��ʐݒ�

	void SetBullet(int RestBullet) { m_RestBullet = RestBullet; }

	bool GetbAttack(void) { return m_bAttack; }

	int GetRestBullet(void) { return m_RestBullet; }

	bool GetbDisp(void) { return m_bDisp; }
	void SetbDisp(bool disp) { m_bDisp = disp; }

private:

	void Control(void);    //�v���C���[�̐���
								 //D3DXVECTOR3 m_pos;  //�ʒu
	D3DXVECTOR3 m_posOld;  //�O��̈ʒu
						   //D3DXVECTOR3 m_rot;  //����
	D3DXVECTOR3 m_move;   //�ړ�
	STATE m_State;
	D3DXMATRIX m_mtxWorld;              //���[���h�}�g���b�N�X
	CCharacter *m_apModel[MAX_PRATS];   //���f��(�p�[�c)�ւ̃|�C���^
	int m_nNumModel;                    //���f��(�p�[�c)�̑���
	int m_nIdxTexture;
	int m_nIdxShaadow;
	char m_filename[128] = {};

	CChibi *m_Chibi;
	CFoot *m_Foot;

	PLAYER m_Player[2];

	D3DXVECTOR3 m_Readpos;
	D3DXVECTOR3 m_Readrot;
	int m_nCntInvincible;                //���G����
	int m_nIdx;
	int m_nParent;
	int m_nLoop;
	int m_nFrame;                        //���[�V�����̃t���[����
	int m_nCntColi;                       //�U�����肪�o�Ă��鎞��
	int m_nCntEff;                        //�G�t�F�N�g�������J�E���g
	int m_nCntDuration;               //�A���ł��鎞��
	int m_nCntDie;                       //�|���܂ł̎���
	int m_nCntSound;                     //�T�E���h�����čēx��܂ł̎���
	int m_nNumMotion;
	int m_nCntMotion;
	int m_nCnterMotion;
	int m_nNumkey;
	int m_nLifeGage;
	int m_RestBullet;                    //�c�e��
	int m_ApprCharcter;
	float m_fDiff;
	float m_fDest;
	bool m_bDash;                        //�����Ă��邩�ǂ���
	bool m_bJump;                        //�W�����v���Ă��邩�ǂ���
	bool m_bAction;		                 //�U���������ǂ���
	bool m_bDisp;                        //�`�悷�邩�ǂ���
	bool m_bAppr;                        //�o�����Ă��邩�ǂ���
	bool m_bEncounter;                   //�퓬���Ă��邩�ǂ���
	bool m_bIconDisp;                    //�A�C�R�����������
	bool m_bAcFir;                       //�A����
	bool m_bAcSec;                       //�A����
	bool m_bAcThr;                       //�A����
	D3DXVECTOR3 m_posOrigin;
	CMotion *m_motion;                   //���[�V�����ւ̃|�C���^

										 //�`���[�g���A���Ŏg���֐�,�ϐ�
	void ControlTutorial(void);          //�`���[�g���A���̃v���C���[�̐���
	bool m_bPushW;                       //W�L�[��������
	bool m_bPushA;                       //A�L�[��������
	bool m_bPushS;                       //S�L�[��������
	bool m_bPushD;                       //D�L�[��������
	bool m_bAttack;                      //�U��������
	bool m_bAvoi;                        //�������
	bool m_bWhee;                        //�z�C�[������]����
};

#endif