//===========================================================
//
//�|���S�����o�����[input.cpp]
//Author �匴�叫
//
//===========================================================
#include "input.h"
#include "manager.h"
#include "debugproc.h"

//================================================================
//�ÓI�����o�ϐ�
//================================================================
LPDIRECTINPUT8 CInput::m_pInput = NULL;

//================================================================
//�R���X�g���N�^
//================================================================
CInput::CInput()
{
	m_pDevice = NULL;
}

//================================================================
//�f�X�g���N�^
//================================================================
CInput::~CInput()
{

}

//================================================================
//����������
//================================================================
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (m_pInput == NULL)
	{
		//direct�I�u�W�F�N�g�̐���
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
		{
			return E_FAIL;
		}
	}

	return S_OK;
}

//================================================================
//�L�[�{�[�h�̏I������
//================================================================
void CInput::Uninit(void)
{
	//���̓f�o�C�X�i�L�[�{�[�h�j�̔j��
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	//DirectInput�I�u�W�F�N�g�̔j��
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//================================================================================
//�L�[�{�[�h
//================================================================================

//================================================================
//�R���X�g���N�^
//================================================================
CInputKeyboard::CInputKeyboard()
{
	m_pDevice = NULL;
	/*m_aKeyState[0] = {};
	m_aKeyStateTrigger[0] = {};
	m_aKeyStateRelease[0] = {};
	m_aKeyStateRepeat[0] = {};*/
}

//================================================================
//�f�X�g���N�^
//================================================================
CInputKeyboard::~CInputKeyboard()
{

}

//================================================================
//����������
//================================================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	if (m_pInput != NULL)
	{
		//���̓f�o�C�X�i�L�[�{�[�h�j�̐���
		if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
		{
			return E_FAIL;
		}

		//�f�[�^�t�H�[�}�b�g
		if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
		{
			return E_FAIL;
		}

		//�������[�h��ݒ�
		if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))
		{
			return E_FAIL;
		}
	}

	//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	m_pDevice->Acquire();

	return S_OK;
}

//================================================================
//�L�[�{�[�h�̏I������
//================================================================
void CInputKeyboard::Uninit(void)
{
	//���̓f�o�C�X�i�L�[�{�[�h�j�̔j��
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	//DirectInput�I�u�W�F�N�g�̔j��
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//================================================================
//�L�[�{�[�h�̍X�V����
//================================================================
void CInputKeyboard::Update(void)
{
	BYTE aKeyState[NUM_KEY_MAX];       //�L�[�{�[�h�̓��͏��
	int nCntKey;

	//���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];
			m_aKeyStateRelease[nCntKey] = (m_aKeyState[nCntKey] | aKeyState[nCntKey]) ^ aKeyState[nCntKey];

			m_aKeyState[nCntKey] = aKeyState[nCntKey];     //�L�[�{�[�h�̃v���X����ۑ�
		}
	}
	else
	{
		m_pDevice->Acquire();     //�L�[�{�[�h�̃A�N�Z�X�����l��
	}
}

//================================================================
//�L�[�{�[�h�̃v���X��������
//================================================================
bool CInputKeyboard::GetPress(int nKey)
{
	return (m_aKeyState[nKey] & 0x80) ? true : false;
}

//================================================================
//�L�[�{�[�h�̃g���K�[��������
//================================================================
bool CInputKeyboard::GetTrigger(int nKey)
{
	return (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//================================================================
//�L�[�{�[�h�̃����[�X��������
//================================================================
bool CInputKeyboard::GetRelease(int nKey)
{
	return (m_aKeyStateRelease[nKey] & 0x80) ? true : false;
}

//********************************************************************************
//�}�E�X
//********************************************************************************

//================================================================
//�R���X�g���N�^
//================================================================
CInputMouse::CInputMouse()
{
	m_pDevice = NULL;
	/*m_aKeyState[0] = {};
	m_aKeyStateTrigger[0] = {};
	m_aKeyStateRelease[0] = {};
	m_aKeyStateRepeat[0] = {};*/
}

//================================================================
//�f�X�g���N�^
//================================================================
CInputMouse::~CInputMouse()
{

}

//================================================================
//�}�E�X�̏���������
//================================================================
HRESULT CInputMouse::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	if (m_pInput != NULL)
	{
		//���̓f�o�C�X�i�}�E�X�j�̐���
		if (FAILED(m_pInput->CreateDevice(GUID_SysMouse, &m_pDevice, NULL)))
		{
			return E_FAIL;
		}

		//�f�[�^�t�H�[�}�b�g
		if (FAILED(m_pDevice->SetDataFormat(&c_dfDIMouse)))
		{
			return E_FAIL;
		}

		//�������[�h��ݒ�
		if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))
		{
			return E_FAIL;
		}
	}

	//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	m_pDevice->Acquire();

	return S_OK;
}

//================================================================
//�}�E�X�̏I������
//================================================================
void CInputMouse::Uninit(void)
{
	//���̓f�o�C�X�i�}�E�X�j�̔j��
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	//DirectInput�I�u�W�F�N�g�̔j��
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//================================================================
//�}�E�X�̍X�V����
//================================================================
void CInputMouse::Update(void)
{
	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();

	//BYTE aKeyState[NUM_KEY_MAX];       //�}�E�X���͏��
	//int nCntKey;

	//�}�E�X���W���擾����
	POINT pos;
	GetCursorPos(&pos);

	ShowCursor(FALSE);

	//�X�N���[�����W���N���C�A���g���W�ɕϊ�����
	ScreenToClient(FindWindowA(CLASS_NAME, nullptr), &pos);

	int posX = 0, posY = 0;

	//���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(DIMOUSESTATE), &m_CurrentMouseState)))
	{

	}
	else
	{
		m_pDevice->Acquire();     //�}�E�X�A�N�Z�X�����l��
	}

	pDebugProc->Print("\n---�}�E�X�̏��---");
	pDebugProc->Print("\n<<�ʒu : X:%d Y:%d>>", pos, pos);
	pDebugProc->Print("\n<<[X] : %f, [Y] : %f>>", (float)m_CurrentMouseState.lX, (float)m_CurrentMouseState.lY);
	pDebugProc->Print("\n<<�z�C�[���̉�]�� : %f>>", (float)m_CurrentMouseState.lZ);
}

//================================================================
//�}�E�X�̉E�N���b�N
//================================================================
bool CInputMouse::GetLButton(void)
{
	return (m_CurrentMouseState.rgbButtons[0] & 0x80) ? true : false;
}

//================================================================
//�}�E�X�̍��N���b�N
//================================================================
bool CInputMouse::GetRButton(void)
{
	return (m_CurrentMouseState.rgbButtons[1] & 0x80) ? true : false;
}

//================================================================
//�}�E�X�̃z�C�[��
//================================================================
bool CInputMouse::GetWheel(void)
{
	return (m_CurrentMouseState.rgbButtons[2] & 0x80) ? true : false;
}

//================================================================
//�ړ��ʂ̎擾
//================================================================
D3DXVECTOR2 CInputMouse::GetMouseMove(void)
{
	return D3DXVECTOR2((float)m_CurrentMouseState.lX, (float)m_CurrentMouseState.lY);
}

//================================================================
//�z�C�[���̉�]�ʎ擾
//================================================================
float CInputMouse::GetMouseWheel(void)
{
	return (float)m_CurrentMouseState.lZ;
}

//********************************************************************************
//�Q�[���p�b�h
//********************************************************************************

//================================================================
//�R���X�g���N�^
//================================================================
CInputJoyPad::CInputJoyPad()
{
	ZeroMemory(&m_State, sizeof(m_State));
	ZeroMemory(&m_StateRelease, sizeof(m_StateRelease));
	ZeroMemory(&m_StateTrigger, sizeof(m_StateTrigger));
	ZeroMemory(&m_StateRepeat, sizeof(m_StateRepeat));
}

//================================================================
//�f�X�g���N�^
//================================================================
CInputJoyPad::~CInputJoyPad()
{

}

//================================================================
//����������
//================================================================
HRESULT CInputJoyPad::Init(void)
{
	XInputEnable(true);

	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		memset(&m_State[nCount], 0, sizeof(XINPUT_STATE));
		memset(&m_StateTrigger[nCount], 0, sizeof(XINPUT_STATE));
		memset(&m_StateRelease[nCount], 0, sizeof(XINPUT_STATE));
		memset(&m_StateRepeat[nCount], 0, sizeof(XINPUT_STATE));
	}

	return S_OK;
}

//================================================================
//�I������
//================================================================
void CInputJoyPad::Uninit(void)
{
	XInputEnable(false);
}

//================================================================
//�X�V����
//================================================================
void CInputJoyPad::Update(void)
{
	XINPUT_STATE aState[MAX_PLAYER];

	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		if (XInputGetState(nCount, &aState[nCount]) == ERROR_SUCCESS)
		{
			//�Ƃ肪�[
			m_StateTrigger[nCount].Gamepad.wButtons =
				(m_State[nCount].Gamepad.wButtons ^ aState[nCount].Gamepad.wButtons)
				& aState[nCount].Gamepad.wButtons;

			//���[��
			m_StateRelease[nCount].Gamepad.wButtons =
				(m_State[nCount].Gamepad.wButtons | aState[nCount].Gamepad.wButtons)
				^ aState[nCount].Gamepad.wButtons;

			//�Ղꂷ
			m_State[nCount] = aState[nCount];
		}
		else
		{
			return;
			//m_pDevice->Acquire();     //�}�E�X�A�N�Z�X�����l��
		}
	}
}

bool CInputJoyPad::GetPress(PADBUTTON nKey, int nCntPlayer)
{
	return (m_State[nCntPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false;
}

bool CInputJoyPad::GetTrigger(PADBUTTON nKey, int nCntPlayer)
{
	return (m_StateTrigger[nCntPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false;
}

bool CInputJoyPad::GetRelease(PADBUTTON nKey, int nCntPlayer)
{
	return (m_StateRelease[nCntPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false;
}