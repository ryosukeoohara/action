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
	CDebugProc *pDebugProc = CManager::GetDebugProc();

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