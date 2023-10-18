//===========================================================
//
//�|���S�����o�����[motion.h]
//Author �匴�叫
//
//===========================================================
#ifndef _MOTION_H_
#define _MOTION_H_

#include "main.h"
#include "objectX.h"
#include "character.h"

//�}�N����`
#define MAX_INFO   (64)

//���[�V�����N���X
class CMotion
{
public:
	CMotion();
	~CMotion();

	//���f��---------------------------------------------------------------
	typedef struct
	{
		D3DXVECTOR3 m_pos;
		D3DXVECTOR3 m_rot;

	} KEY;

	//���f��---------------------------------------------------------------
	typedef struct
	{
		KEY m_aKey[MAX_INFO];  //���݂̃L�[
		int m_nFrame;   //���[�V�����̃t���[����

	} KEYINFO;

	//���[�V����---------------------------------------------------------------
	typedef struct
	{
		int m_nNumKey;  //�L�[�̑���
		int m_nLoop;    //���[�v���邩�ǂ���
		bool m_bLoop;   //���[�v���邩�ǂ���
		bool m_bFinish; //�I���������ǂ���

		KEYINFO m_KeySet[MAX_INFO];
		
	} INFO;

	//���f��---------------------------------------------------------------
	typedef struct
	{
		D3DXVECTOR3 m_pos;
		D3DXVECTOR3 m_rot;

	} OLDKEY;

	//���f��---------------------------------------------------------------
	typedef struct
	{
		OLDKEY m_aKey[MAX_INFO];  //���݂̃L�[
		int m_nFrame;   //���[�V�����̃t���[����

	} OLDKEYINFO;

	//���[�V����---------------------------------------------------------------
	typedef struct
	{
		int m_nNumKey;  //�L�[�̑���
		int m_nLoop;    //���[�v���邩�ǂ���
		bool m_bLoop;   //���[�v���邩�ǂ���
		bool m_bFinish; //�I���������ǂ���

		OLDKEYINFO m_KeySet[MAX_INFO];

	} OLDINFO;

	//���[�V����---------------------------------------------------------------
	/*typedef struct
	{
		INFO m_aInfo[9];

	} Obj;*/

	void Init(void);
	void Uninit(void);
	void Update(void);

	void Set(int nType);
	int GetType(void);
	bool IsFinish(void);
	void SetInfo(INFO info);
	void SetModel(CCharacter **ppModel, int nNumModel);
	CCharacter **GetModel(void) { return m_ppModel; }
	void ReadText(const char *TextFilename);        //�O���t�@�C���ǂݍ���
	int GetNumFrame(void) { return m_nNumFrame; }   //���[�V�����̑��t���[��

private:
	//Obj m_aObj[9];
	INFO m_aInfo[MAX_INFO];
	INFO m_aOldInfo;
	int  m_nNumAll;              //���[�V�����̑���
	int  m_nType;                //���[�V�����̎��
	int m_nTypeold;
	bool m_bLoop;                //���[�v���邩�ǂ���
	int  m_nNumKey;              //�L�[�̑���
	int  m_nKey;                 //���݂̃L�[
	int  m_nCounter;             //�t���[�����ɒB������
	int  m_nCntkeySet;
	int m_nNumFrame;             //���[�V�����̃t���[����
	bool m_bFinish;              //�I���������ǂ���
	
	CCharacter **m_ppModel;  //���f���ւ̃_�u���|�C���^
	int m_nNumModel;         //���f���̑���
	static int m_nObj;       //�N�̃��[�V������
};

#endif // !_MOTION_H_

