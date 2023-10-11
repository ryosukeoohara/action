//===========================================================
//
//�|���S�����o�����[input.h]
//Author �匴�叫
//
//===========================================================
#ifndef _INPUT_H_
#define _INPUT_H_

#include "main.h"

//�}�N����`
#define NUM_KEY_MAX     (256)     //�L�[�̍ő吔

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

#endif