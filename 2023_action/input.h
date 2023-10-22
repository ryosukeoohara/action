//===========================================================
//
//�|���S�����o�����[input.h]
//Author �匴�叫
//
//===========================================================
#ifndef _INPUT_H_
#define _INPUT_H_

#include "main.h"
#pragma comment(lib, "xinput.lib")

//�}�N����`
#define NUM_KEY_MAX     (256)     //�L�[�̍ő吔
#define MAX_PLAYER      (1)

//���̓N���X------------------------------------------------------
class CInput
{
public:
	CInput();  //�R���X�g���N�^
	virtual ~CInput();  //�f�X�g���N�^

	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);  //����������
	virtual void Uninit(void);      //�I������
	virtual void Update(void) = 0;  //�X�V����
	
protected:
	static LPDIRECTINPUT8 m_pInput;     //directInput�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECTINPUTDEVICE8 m_pDevice;     //���̓f�o�C�X�i�L�[�{�[�h�j�ւ̃|�C���^
};

//�L�[�{�[�h�̓��̓N���X-------------------------------------------
class CInputKeyboard : public CInput
{
public:
	CInputKeyboard();   //�R���X�g���N�^
	~CInputKeyboard();  //�f�X�g���N�^

	HRESULT Init(HINSTANCE hInstance, HWND hWnd);  //����������
	void Uninit(void);  //�I������
	void Update(void);  //�X�V����

	bool GetPress(int nKey);
	bool GetTrigger(int nKey);
	bool GetRelease(int nKey);
	bool GetRepeat(int nKey);

private:
	BYTE m_aKeyState[NUM_KEY_MAX];
	BYTE m_aKeyStateTrigger[NUM_KEY_MAX];
	BYTE m_aKeyStateRelease[NUM_KEY_MAX];
	BYTE m_aKeyStateRepeat[NUM_KEY_MAX];
};

//�}�E�X�̓��̓N���X------------------------------------------------
class CInputMouse : public CInput
{
public:
	CInputMouse();   //�R���X�g���N�^
	~CInputMouse();  //�f�X�g���N�^

	HRESULT Init(HINSTANCE hInstance, HWND hWnd);  //����������
	void Uninit(void);  //�I������
	void Update(void);  //�X�V����

	bool GetLButton(void);  //���N���b�N
	bool GetRButton(void);  //�E�N���b�N
	bool GetWheel(void);    //�z�C�[��

	D3DXVECTOR2 GetMouseMove(void);  //�ړ��ʎ擾
	float GetMouseWheel(void);       //�}�E�X�z�C�[���̉�]�ʎ擾

private:
	DIMOUSESTATE  m_CurrentMouseState;
	//BYTE rgbButtons[4];
};

//�Q�[���p�b�g�̃N���X----------------------------------------------
class CInputJoyPad : public CInput
{
public:
	/*XINPUT_GAMEPAD_DPAD_UP
	XINPUT_GAMEPAD_DPAD_DOWN
	XINPUT_GAMEPAD_DPAD_LEFT
	XINPUT_GAMEPAD_DPAD_RIGHT
	XINPUT_GAMEPAD_START
	XINPUT_GAMEPAD_BACK
	XINPUT_GAMEPAD_LEFT_THUMB
	XINPUT_GAMEPAD_RIGHT_THUMB
	XINPUT_GAMEPAD_LEFT_SHOULDER
	XINPUT_GAMEPAD_RIGHT_SHOULDER
	XINPUT_GAMEPAD_A
	XINPUT_GAMEPAD_B
	XINPUT_GAMEPAD_X
	XINPUT_GAMEPAD_Y*/

	//PAD_UP,		//	�\���L�[�̏�
	//	PAD_DOWN,	//	�\���L�[�̉�
	//	PAD_LEFT,	//	�\���L�[�̍�
	//	PAD_RIGHT,	//	�\���L�[�̉E
	//	PAD_START,	//	Start
	//	PAD_BACK,	//	Back
	//	PAD_LEFT_THUMB,		//	���X�e�B�b�N
	//	PAD_RIGHT_THUMB,	//	�E�X�e�B�b�N
	//	PAD_LB,  //	LB
	//	PAD_RB,	//	RB
	//	PAD_A,	//	A�{�^��
	//	PAD_B,	//	B�{�^��
	//	PAD_X,	//	X�{�^��
	//	PAD_Y,	//	Y�{�^��
	//			// �A�i���O
	//	PAD_LEFT_U_STICK,	//	���X�e�B�b�N�̏�
	//	PAD_LEFT_D_STICK,	//	���X�e�B�b�N�̉�
	//	PAD_LEFT_L_STICK,	//	���X�e�B�b�N�̍�
	//	PAD_LEFT_R_STICK,	//	���X�e�B�b�N�̉E
	//	PAD_RIGHT_U_STICK,	//	�E�X�e�B�b�N�̏�
	//	PAD_RIGHT_D_STICK,	//	�E�X�e�B�b�N�̉�
	//	PAD_RIGHT_L_STICK,	//	�E�X�e�B�b�N�̍�
	//	PAD_RIGHT_R_STICK,	//	�E�X�e�B�b�N�̉E
	//	PAD_LT,	//	���g���K�[
	//	PAD_RT,	//	�E�g���K�[

	enum PADBUTTON
	{
		BUTTON_UP = 0,
		BUTTON_DOWN,
		BOTTON_LEFt,
		BUTTON_RIGHT,
		BUTTON_START,
		BUTTON_BACK,
		BUTTON_LTHUMB,
		BUTTON_RTHUMB,
		BUTTON_LB,
		BUTTON_RB,
		BUTTON_LT,
		BUTTON_RT,
		BUTTON_A,
		BUTTON_B,
		BUTTON_X,
		BUTTON_Y,
		STICK_LX,
		STICK_LY,
		BUTTON_MAX
	};

	CInputJoyPad();   //�R���X�g���N�^
	~CInputJoyPad();  //�f�X�g���N�^

	HRESULT Init(void);  //����������
	void Uninit(void);  //�I������
	void Update(void);  //�X�V����

	bool GetPress(PADBUTTON nKey, int nCntPlayer);
	bool GetTrigger(PADBUTTON nKey, int nCntPlayer);
	bool GetRelease(PADBUTTON nKey, int nCntPlayer);

	bool GetLeftTirgger(PADBUTTON nKey, int nCntPlayer);
	bool GetRightTirgger(PADBUTTON nKey, int nCntPlayer);

	float GetXStick(PADBUTTON nKey, int nCntPlayer);
	float GetYStick(PADBUTTON nKey, int nCntPlayer);

	

private:
	XINPUT_STATE m_State[MAX_PLAYER];
	XINPUT_STATE m_StateTrigger[MAX_PLAYER];
	XINPUT_STATE m_StateRelease[MAX_PLAYER];
	XINPUT_STATE m_StateRepeat[MAX_PLAYER];
};

#endif