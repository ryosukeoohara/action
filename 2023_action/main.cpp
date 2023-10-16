//===========================================================
//
//�|���S�����o�����[main.cpp]
//Author �匴�叫
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "object.h"
#include "object2D.h"
#include "manager.h"
#include <stdlib.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

//===========================================================
//�}�N����`
//===========================================================
#define WINDOW_NAME       "C++:�A�N�V�����V���[�e�B���O"          //�E�C���h�E�̖��O�i�L���v�V�����ɕ\���j
#define ID_BUTTON_FINISH  (101)                    //�I���{�^��

//===========================================================
//�v���g�^�C�v�錾
//===========================================================
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);   //�E�C���h�E�v���[�W��

//===========================================================
//���C���֐�
//===========================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hInstancePrev, LPSTR lpCmdline, int nCmdshow)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CManager *pManager = NULL;

	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),                    //WNDCLASSEX�̃������T�C�Y
		CS_CLASSDC,                            //�E�C���h�E�̃X�^�C��
		WindowProc,                            //�E�C���h�E�v���[�W��
		0,                                     //0�ɂ���i�ʏ�͎g��Ȃ��j
		0,                                     //0�ɂ���i�ʏ�͎g��Ȃ��j
		hInstance,                             //�C���X�^���X�n���h��
		LoadIcon(NULL, IDI_APPLICATION),       //�^�X�N�o�[�̃A�C�R��
		LoadCursor(NULL, IDC_ARROW),           //�}�E�X�J�[�\��
		(HBRUSH)(COLOR_WINDOW + 1),            //�N���C�A���g�̈�̔w�i�F
		NULL,                                  //���j���[�o�[
		CLASS_NAME,                            //�E�C���h�E�N���X�̖��O
		LoadIcon(NULL, IDI_APPLICATION),       //�t�@�C���̃A�C�R��
	};

	HWND hWnd;      //�E�C���h�E�n���h���i���ʎq�j

	MSG msg;        //���b�Z�[�W���i�[����ϐ�

	RegisterClassEx(&wcex);       //�E�C���h�E�N���X�̓o�^

	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

	//�N���C�A���g�̈���w��̃T�C�Y�ɒ���
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	//�E�C���h�E�𐶐�
	hWnd = CreateWindowEx
	(
		0,                            //�g���E�C���h�E�X�^�C��
		CLASS_NAME,                   //�E�C���h�E�N���X�̖��O
		WINDOW_NAME,                  //�E�C���h�E�̖��O
		WS_OVERLAPPEDWINDOW,          //�E�C���h�E�X�^�C��
		CW_USEDEFAULT,                //�E�C���h�E�̍���X���W
		CW_USEDEFAULT,                //�E�C���h�E�̍���Y���W
		(rect.right - rect.left),     //�E�C���h�E�̕�
		(rect.bottom - rect.top),     //�E�C���h�E�̍���
		NULL,                         //�e�E�C���h�E�̃n���h��
		NULL,                         //���j���[�n���h���܂��͎q�E�C���h�EID
		hInstance,                    //�C���X�^���X�n���h��
		NULL                          //�E�C���h�E�쐬�f�[�^
	);

	if (pManager == NULL)
	{
		pManager = new CManager;
		pManager->Getinstance();
	}

	//�}�l�[�W���̏���������
	if (pManager != NULL)
	{
		if (FAILED(pManager->Getinstance()->Init(hInstance, hWnd, FALSE)))
		{
			return -1;
		}
	}

	DWORD dwCurrentTime;   //���ݎ���
	DWORD dwExecLastTime;  //�Ō�ɏ�����������
	DWORD dwwFrameCount;   //�t���[���J�E���g
	DWORD dwFPSLastTime;   //�Ō��FPS���v����������

	//����\��ݒ�
	timeBeginPeriod(1);

	dwCurrentTime = 0;
	dwExecLastTime = timeGetTime();
	dwwFrameCount = 0;
	dwFPSLastTime = timeGetTime();

	//�E�C���h�E�̕\��
	ShowWindow(hWnd, nCmdshow);       //�E�C���h�E�̕\����Ԃ�ݒ�
	UpdateWindow(hWnd);               //�N���C�A���g�̈���X�V

	//���b�Z�[�W���[�v
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{//Windows�̏���

			if (msg.message == WM_QUIT)
			{//WM_QUIT���b�Z�[�W���󂯎�����烁�b�Z�[�W���[�v�𔲂���

				break;
			}
			else
			{
				TranslateMessage(&msg);       //���z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�
				DispatchMessage(&msg);        //�E�C���h�E�v���[�W���փ��b�Z�[�W�𑗏o
			}
		}
		else
		{//DirectX�̏���

			dwCurrentTime = timeGetTime();    //���ݎ������擾

			if ((dwCurrentTime - dwFPSLastTime) >= 500)
			{//0.5�b�o��
			 //FPS���v��
				//g_nCountFPS = (dwwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime);
				dwFPSLastTime = dwCurrentTime;       //FPS�𑪒肵��������ۑ�
				dwwFrameCount = 0;                   //�t���[���J�E���g���N���A
			}

			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
			{//60����1�b�o��
				dwExecLastTime = dwCurrentTime;

				if (pManager->Getinstance() != NULL)
				{
					//�}�l�[�W���̍X�V����
					pManager->Getinstance()->Update();

					//�}�l�[�W���̕`�揈��
					pManager->Getinstance()->Draw();
				}

				dwwFrameCount++;     //�t���[���J�E���g�����Z
			}
		}
	}

	if (pManager->Getinstance() != NULL)
	{
		pManager->Getinstance()->Release();

		pManager = NULL;

		//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
		//_CrtDumpMemoryLeaks();
	}
	
	//�E�C���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return (int)msg.wParam;
}

//================================================================
//�E�C���h�E�v���[�W��
//================================================================
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nID;
	
	switch (uMsg)
	{
	case WM_DESTROY:         //�E�C���h�E�j���̃��b�Z�[�W

		//WM_QUIT���b�Z�[�W�𑗂�
		PostQuitMessage(0);

		break;

	case WM_KEYDOWN:         //�L�[�����̃��b�Z�[�W

		switch (wParam)
		{
		case VK_ESCAPE:      //[ESC]�L�[�������ꂽ   

			nID = MessageBox(hWnd, "�I�����܂����H", "�I�����b�Z�[�W", MB_YESNO);

			if (nID == IDYES)
			{
				//�E�C���h�E��j������(WM_DESTROY���b�Z�[�W�𑗂�)
				DestroyWindow(hWnd);
			}
			break;
		}
		break;

	case WM_CLOSE:
		nID = MessageBox(hWnd, "�I�����܂����H", "�I�����b�Z�[�W", MB_YESNO);
		if (nID == IDYES)
		{//�e�E�C���h�E�́~�������ꂽ
		 //�E�C���h�E��j������(WM_DESTROY���b�Z�[�W�𑗂�)
			DestroyWindow(hWnd);
		}
		else
		{
			return 0;     //0��Ԃ��Ȃ��ƏI�����Ă��܂�
		}
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}