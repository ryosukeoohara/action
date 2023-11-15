//===========================================================
//
//�|���S�����o�����[player.h]
//Author �匴�叫
//
//===========================================================
#ifndef _PLAYER_H_             //���̃}�N����`������ĂȂ�������
#define _PLAYER_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

//*==========================================================
//�C���N���[�h�t�@�C��
//*==========================================================
#include "character.h"
#include "object.h"

//*==========================================================
//�O���錾
//*==========================================================
class CMotion;
class CEnemy;
class CChibi;
class CFoot;

//*==========================================================
//�v���C���[�N���X
//*==========================================================
class CPlayer : public CObject
{
public:
	CPlayer();  //�R���X�g���N�^
	CPlayer(D3DXVECTOR3 pos);  //�R���X�g���N�^(�I�[�o�[���[�h)
	~CPlayer();  //�f�X�g���N�^

	HRESULT Init(void);        //�v���C���[�̏���������    
	void Uninit(void);		   //�v���C���[�̏I������
	void Update(void);         //�v���C���[�̍X�V����
	void Draw(void);           //�v���C���[�̕`�揈��

	static CPlayer *Create(D3DXVECTOR3 pos);  //����
	//static CPlayer *GetPlayer(void) { return m_Player; };
	
	void ReadText(const char *fliename);       //�O���t�@�C���ǂݍ���
	void Hit(void);			//�U��������������̏���

	D3DXVECTOR3 GetMove(void) { return m_move; }       //�ړ��ʎ擾
	void SetMove(D3DXVECTOR3 move) { m_move = move; }  //�ړ��ʐݒ�

	void SetBullet(int RestBullet) { m_RestBullet = RestBullet; }

	bool GetbAttack(void) { return m_bAttack; }

	int GetRestBullet(void) { return m_RestBullet; }

protected:
	//CMotion *m_motion;                   //���[�V�����ւ̃|�C���^
	//CCharacter *m_apModel[MAX_PRATS];   //���f��(�p�[�c)�ւ̃|�C���^
	int m_ApprCharcter;
	
private:

	void ControlPlayer(void);    //�v���C���[�̐���
	void Appear(void);           //�o������
	D3DXVECTOR3 m_posOld;  //�O��̈ʒu
	D3DXVECTOR3 m_move;   //�ړ�
	D3DXMATRIX m_mtxWorld;              //���[���h�}�g���b�N�X
	
	int m_nNumModel;                    //���f��(�p�[�c)�̑���
	int m_nIdxTexture;
	int m_nIdxShaadow;
	char m_filename[128] = {};

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
	float m_fDiff;			             
	float m_fDest;			             
	bool m_bDash;                        //�����Ă��邩�ǂ���
	bool m_bJump;                        //�W�����v���Ă��邩�ǂ���
	bool m_bAction;		                 //�U���������ǂ���
	bool m_bAppr;                        //�o�����Ă��邩�ǂ���
	bool m_bEncounter;                   //�퓬���Ă��邩�ǂ���
	bool m_bIconDisp;                    //�A�C�R�����������
	bool m_bAcFir;                       //�A����
	bool m_bAcSec;                       //�A����
	bool m_bAcThr;                       //�A����
	
	D3DXVECTOR3 m_posOrigin;             
	//CMotion *m_motion;                   //���[�V�����ւ̃|�C���^

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

//*==========================================================
//�`�r�f�u
//*==========================================================
class CChibi : public CPlayer
{
public:

	//���
	typedef enum
	{
		STATE_NONE = 0,
		STATE_NEUTRAL,                //�ҋ@
		STATE_MOVE,                   //�ړ�
		STATE_JUMP,                   //�W�����v
		STATE_ATTACK,                 //�U��
		STATE_APPR,                   //�o��
		STATE_DAMAGE,                 //�_���[�W
		STATE_DEATH,                  //���S
		STATE_TITLE,                  //�^�C�g��
		STATE_RELOAD,                 //�����[�h
		STATE_MAX
	} STATE;

	//�^�C�g���̏��
	enum TITLE_STATE
	{
		TITLE_STATE_NONE = 0,          //�Ȃ���Ȃ�
		TITLE_STATE_NEUTRAL,           //�ҋ@
		TITLE_STATE_MOVE,              //�ړ�
		TITLE_STATE_MAX
	};

	//���[�V����
	typedef enum
	{
		MOTIONTYPE_NEUTRAL = 0,              //�j���[�g����
		MOTIONTYPE_MOVE,                     //�ړ�
		MOTIONTYPE_JUMP,                     //�W�����v
		MOTIONTYPE_ATTACK,                   //�U��
		MOTIONTYPE_APPR,                     //�o��
		MOTIONTYPE_TITLE,                    //�^�C�g��
		MOTIONTYPE_RELOAD,                   //�����[�h
		MOTIONTYPE_MAX
	} MOTIONTYPE;

	CChibi();  //�R���X�g���N�^
	CChibi(D3DXVECTOR3 pos);  //�R���X�g���N�^(�I�[�o�[���[�h)
	~CChibi();  //�f�X�g���N�^

	HRESULT Init(void);        //�v���C���[�̏���������    
	void Uninit(void);		   //�v���C���[�̏I������
	void Update(void);         //�v���C���[�̍X�V����
	void Draw(void);           //�v���C���[�̕`�揈��

	static CChibi *Create(D3DXVECTOR3 pos);  //����

	void SetState(STATE state) { m_State = state; };
	STATE GetState(void) { return m_State; };

	void SetTState(TITLE_STATE state) { m_TitleState = state; };

	bool GetbDisp(void) { return m_bDisp; }
	void SetbDisp(bool disp) { m_bDisp = disp; }

	bool GetbAppr(void) { return m_bAppr; }
	void SetbAppr(bool appr) { m_bAppr = appr; }

	void SetMoveY(float move) { m_move.y = move; }
	float GetMoveY(void) { return m_move.y; }

	void SetbJump(bool bjump) { m_bJump = bjump; }

	void SetbRand(bool brand) { m_bRand = brand; }
	bool GetbRand(void) { return m_bRand; }

	void SetLife(int nLife) { m_nLife = nLife; }  //�̗͂̐ݒ�
	int GetLife(void) { return m_nLife; }		  //�̗͂��擾

	void Hit(void);

	int GetRestBullet(void) { return m_RestBullet; }

	void Control(void);    //�v���C���[�̐���

protected:
	
private:
	void ReadText(const char *fliename);       //�O���t�@�C���ǂݍ���
	STATE m_State;                             //���
	TITLE_STATE m_TitleState;                  //�^�C�g���̏��
	D3DXVECTOR3 m_pos;  //�ʒu
	D3DXVECTOR3 m_posOld;  //�O��̈ʒu
						   //D3DXVECTOR3 m_rot;  //����
	D3DXVECTOR3 m_move;   //�ړ�
	D3DXMATRIX m_mtxWorld;              //���[���h�}�g���b�N�X
	CCharacter *m_apModel[MAX_PRATS];   //���f��(�p�[�c)�ւ̃|�C���^
	CMotion *m_motion;                  //���[�V�����ւ̃|�C���^
	int m_nLife;                        //�̗�
	int m_nNumModel;                    //���f��(�p�[�c)�̑���
	int m_nIdxTexture;
	int m_nIdxShaadow;
	char m_filename[128] = {};

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
	int m_nCntBullet;                    //�e�̏o��Ԋu
	int m_nCntDamage;                    //�_���[�W��ԂɂȂ��Ă���J�E���g
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
	bool m_WaitApper;                    //�o���҂����
	bool m_bRand;                        //�n�ʂɒ��n���Ă��邩�ǂ���
	bool m_bDamage;                      //�_���[�W���󂯂�
	D3DXVECTOR3 m_posOrigin;

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

//*==========================================================
//�N�\�f�u
//*==========================================================
class CFoot : public CPlayer
{
public:

	//���
	typedef enum
	{
		STATE_NONE = 0,
		STATE_NEUTRAL,                //�ҋ@
		STATE_MOVE,                   //�ړ�
		STATE_JUMP,                   //�W�����v
		STATE_ATTACK,                 //�U��
		STATE_APPR,                   //�o��
		STATE_DAMAGE,                 //�_���[�W
		STATE_DEATH,                  //���S
		STATE_TITLE,                  //�^�C�g��
		STATE_MAX
	} STATE;

	//�^�C�g���̏��
	enum TITLE_STATE
	{
		TITLE_STATE_NONE = 0,          //�Ȃ���Ȃ�
		TITLE_STATE_NEUTRAL,           //�ҋ@
		TITLE_STATE_MOVE,              //�ړ�
		TITLE_STATE_MAX
	};

	//���[�V����
	typedef enum
	{
		MOTIONTYPE_NEUTRAL = 0,              //�j���[�g����
		MOTIONTYPE_MOVE,                     //�ړ�
		MOTIONTYPE_JUMP,                     //�W�����v
		MOTIONTYPE_ATTACK,                   //�U��
		MOTIONTYPE_APPR,                     //�o��
		MOTIONTYPE_TITLE,                    //�^�C�g��
		MOTIONTYPE_MAX
	} MOTIONTYPE;

	CFoot();  //�R���X�g���N�^
	CFoot(D3DXVECTOR3 pos);  //�R���X�g���N�^(�I�[�o�[���[�h)
	~CFoot();  //�f�X�g���N�^

	HRESULT Init(void);        //�v���C���[�̏���������    
	void Uninit(void);		   //�v���C���[�̏I������
	void Update(void);         //�v���C���[�̍X�V����
	void Draw(void);           //�v���C���[�̕`�揈��

	static CFoot *Create(D3DXVECTOR3 pos);  //����

	void SetState(STATE state) { m_State = state; };
	STATE GetState(void) { return m_State; };

	void SetTState(TITLE_STATE state) { m_TitleState = state; };
	//TITLE_STATE GetState(void) { return m_TitleState; };

	bool GetbDisp(void) { return m_bDisp; }
	void SetbDisp(bool disp) { m_bDisp = disp; }

	bool GetbAppr(void) { return m_bAppr; }
	void SetbAppr(bool appr) { m_bAppr = appr; }

	void SetMoveY(float move) { m_move.y = move; }
	float GetMoveY(void) { return m_move.y; }

	void SetbJump(bool bjump) { m_bJump = bjump; }

	void SetbRand(bool brand) { m_bRand = brand; }
	bool GetbRand(void) { return m_bRand; }

	void SetLife(int nLife) { m_nLife = nLife; }  //�̗͂̐ݒ�
	int GetLife(void) { return m_nLife; }		  //�̗͂��擾

	void Hit(void);

	void Control(void);    //�v���C���[�̐���

protected:
	
private:
	void ReadText(const char *fliename);       //�O���t�@�C���ǂݍ���
	STATE m_State;
	TITLE_STATE m_TitleState;                  //�^�C�g���̏��
	D3DXVECTOR3 m_pos;  //�ʒu
	D3DXVECTOR3 m_posOld;  //�O��̈ʒu
						   //D3DXVECTOR3 m_rot;  //����
	D3DXVECTOR3 m_move;   //�ړ�
	D3DXMATRIX m_mtxWorld;              //���[���h�}�g���b�N�X
	CCharacter *m_apModel[MAX_PRATS];   //���f��(�p�[�c)�ւ̃|�C���^
	CMotion *m_motion;                  //���[�V�����ւ̃|�C���^
	int m_nLife;                        //�̗�
	int m_nNumModel;                    //���f��(�p�[�c)�̑���
	int m_nIdxTexture;
	int m_nIdxShaadow;
	char m_filename[128] = {};

	D3DXVECTOR3 m_Readpos;
	D3DXVECTOR3 m_Readrot;
	int m_nCntInvincible;                //���G����
	int m_nIdx;
	int m_nParent;
	int m_nLoop;
	int m_nFrame;                        //���[�V�����̃t���[����
	int m_nCntColi;                      //�U�����肪�o�Ă��鎞��
	int m_nCntEff;                        //�G�t�F�N�g�������J�E���g
	int m_nCntDuration;                  //�A���ł��鎞��
	int m_nCntDie;                       //�|���܂ł̎���
	int m_nCntSound;                     //�T�E���h�����čēx��܂ł̎���
	int m_nNumMotion;
	int m_nCntMotion;
	int m_nCnterMotion;
	int m_nNumkey;
	int m_nCntDamage;                    //�_���[�W��ԂɂȂ��Ă���J�E���g
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
	bool m_WaitApper;                    //�o���҂����
	bool m_bRand;                        //�n�ʂɒ��n���Ă��邩�ǂ���
	bool m_bDamage;                      //�_���[�W���󂯂�
	D3DXVECTOR3 m_posOrigin;
	//CMotion *m_motion;                   //���[�V�����ւ̃|�C���^

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