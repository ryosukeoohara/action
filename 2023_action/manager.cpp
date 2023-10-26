//===========================================================
//
//�|���S�����o�����[manager.cpp]
//Author �匴�叫
//
//===========================================================
#include "renderer.h"
#include "object.h"
#include "object2D.h"
#include "manager.h"
#include "input.h"
#include "sound.h"
#include "input.h"
#include "time.h"
#include "debugproc.h"
#include "camera.h"
#include "texture.h"
#include "game.h"
#include "fade.h"
#include "pause.h"
#include "title.h"
#include "light.h"
#include "result.h"

//================================================================
//�ÓI�����o�ϐ�
//================================================================
//CRenderer *CManager::m_Renderer = NULL;
//CInputKeyboard *CManager::m_InputKeyboard = NULL;
//CInputMouse *CManager::m_InputMouse = NULL;
//CInputJoyPad *CManager::m_InputJoyPad = NULL;
//CSound *CManager::m_Sound = NULL;
//CPlayer *CManager::m_Player = NULL;
//CDebugProc *CManager::m_DebugProc = NULL;
//CCamera *CManager::m_Camera = NULL;
//CLight *CManager::m_Light = NULL;
//CTexture *CManager::m_Texture = NULL;
//CModel *CManager::m_Model = NULL;
//CObject3D *CManager::m_Object3D = NULL;
//CEnemy *CManager::m_Enemy = NULL;
//CCollision *CManager::m_Collision = NULL;
//CEdit *CManager::m_Edit = NULL;
//CMap *CManager::m_Map = NULL;
//CScene *CManager::m_pScene = NULL;
//CFade *CManager::m_Fade = NULL;
//CPause *CManager::m_Pause = NULL;

CManager *CManager::m_pManager = NULL;

CGame  *CScene::m_Game = NULL;
CTutorial *CScene::m_Tutorial = NULL;
CTitle *CScene::m_Title = NULL;
CResult *CScene::m_Result = NULL;
CScene::MODE CScene::m_mode = CScene::MODE_TITLE;
//bool CManager::m_bPause = NULL;

//================================================================
//�}�l�[�W���̐���
//================================================================
CManager * CManager::Getinstance()
{
	if (m_pManager == NULL)
	{
		return m_pManager = new CManager;
	}
	else
	{
		return m_pManager;
	}
}

//================================================================
//�}�l�[�W���̔j��
//================================================================
HRESULT CManager::Release(void)
{
	if (m_pManager != NULL)
	{
		m_pManager->Uninit();

		delete m_pManager;

		m_pManager = NULL;
	}

	return S_OK;
}

//================================================================
//�R���X�g���N�^
//================================================================
CManager::CManager()
{
	m_ResetCounter = 0;
	m_bPause = false;
}

//================================================================
//�f�X�g���N�^
//================================================================
CManager::~CManager()
{

}

//================================================================
//����������
//================================================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	if (m_Renderer == NULL)
	{//�g�p����Ă��Ȃ�������

		//�����_���[�̐���
		m_Renderer = new CRenderer;

		//����������
		m_Renderer->Init(hWnd, TRUE);
	}

	if (m_InputKeyboard == NULL)
	{//�g�p����Ă��Ȃ�������

		//�L�[�{�[�h�̐���
		m_InputKeyboard = new CInputKeyboard;

		//����������
		m_InputKeyboard->Init(hInstance, hWnd);
	}

	if (m_InputMouse == NULL)
	{//�g�p����Ă��Ȃ�������

		//�}�E�X����
		m_InputMouse = new CInputMouse;

		//����������
		m_InputMouse->Init(hInstance, hWnd);
	}

	if (m_InputJoyPad == NULL)
	{//�g�p����Ă��Ȃ�������

		//�Q�[���p�b�h�̐���
		m_InputJoyPad = new CInputJoyPad;

		//����������
		m_InputJoyPad->Init();
	}

	if (m_Sound == NULL)
	{//�g�p����Ă��Ȃ�������

		//�T�E���h�̐���
		m_Sound = new CSound;

		//����������
		m_Sound->Init(hWnd);
	}

	if (m_DebugProc == NULL)
	{//�g�p����Ă��Ȃ�������

		//�f�o�b�O�v���b�N�̐���
		m_DebugProc = new CDebugProc;

		//����������
		m_DebugProc->Init();
	}

	if (m_Camera == NULL)
	{//�g�p����Ă��Ȃ�������

		//�J�����𐶐�
		m_Camera = new CCamera;

		//����������
		m_Camera->Init();
	}

	if (m_Light == NULL)
	{//�g�p����Ă��Ȃ�������

	 //���C�g�𐶐�
		m_Light = new CLight;

		//����������
		m_Light->Init();
	}

	if (m_Texture == NULL)
	{//�g�p����Ă��Ȃ�������

		//�e�N�X�`���𐶐�
		m_Texture = new CTexture;

		//����������
		m_Texture->Load();
	}

	if (m_pScene == NULL)
	{//�g�p����Ă��Ȃ�������

		//�V�[���̐���
		m_pScene = CScene::Create(CScene::MODE_TITLE);

		//����������
		m_pScene->Init();
	}

	if (m_Fade == NULL)
	{//�g�p����Ă��Ȃ�������

		//�t�F�[�h�𐶐�
		m_Fade = new CFade;

		//����������
		m_Fade->Init();
	}

	return S_OK;
}

//================================================================
//�I������
//================================================================
void CManager::Uninit(void)
{
	//�T�E���h���~�߂�
	m_Sound->Stop();

	//�V�[���̔j��
	if (m_pScene != NULL)
	{
		//�V�[���̏I������
		m_pScene->Uninit();

		//���������J��
		delete m_pScene;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_pScene = NULL;
	}

	//�����_���[�̔j��
	if (m_Renderer != NULL)
	{
		//�����_���[�̏I������
		m_Renderer->Uninit();

		//���������J��
		delete m_Renderer;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Renderer = NULL;
	}

	//�L�[�{�[�h�̔j��
	if (m_InputKeyboard != NULL)
	{
		//�L�[�{�[�h�̏I������
		m_InputKeyboard->Uninit();

		//���������J��
		delete m_InputKeyboard;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_InputKeyboard = NULL;
	}

	//�}�E�X�̔j��
	if (m_InputMouse != NULL)
	{
		//�}�E�X�̏I������
		m_InputMouse->Uninit();

		//���������J��
		delete m_InputMouse;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_InputMouse = NULL;
	}

	//�Q�[���p�b�h�̔j��
	if (m_InputJoyPad != NULL)
	{
		//�Q�[���p�b�h�̏I������
		m_InputJoyPad->Uninit();

		//���������J��
		delete m_InputJoyPad;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_InputJoyPad = NULL;
	}

	//�T�E���h�̔j��
	if (m_Sound != NULL)
	{
		//�T�E���h�̏I������
		m_Sound->Uninit();
	
		//���������J��
		delete m_Sound;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Sound = NULL;
	}

	//�f�o�b�O�v���b�N�̔j��
	if (m_DebugProc != NULL)
	{
		//�f�o�b�O�v���b�N�̏I������
		m_DebugProc->Uninit();

		//���������J��
		delete m_DebugProc;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_DebugProc = NULL;
	}

	//�J�����̔j��
	if (m_Camera != NULL)
	{
		//�f�o�b�O�v���b�N�̏I������
		m_Camera->Uninit();

		//���������J��
		delete m_Camera;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Camera = NULL;
	}

	//���C�g�̔j��
	if (m_Light != NULL)
	{
		//�f�o�b�O�v���b�N�̏I������
		m_Light->Uninit();

		//���������J��
		delete m_Light;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Light = NULL;
	}

	//�e�N�X�`���̔j��
	if (m_Texture != NULL)
	{
		//�e�N�X�`���̏I������
		m_Texture->UnLoad();

		//���������J��
		delete m_Texture;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Texture = NULL;
	}

	//�t�F�[�h�̔j��
	if (m_Fade != NULL)
	{
		//�t�F�[�h�̏I������
		m_Fade->Uninit();

		//���������J��
		delete m_Fade;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Fade = NULL;
	}
}

//================================================================
//�X�V����
//================================================================
void CManager::Update(void)
{
	//�����_���[�̍X�V����
	m_Renderer->Update();

	//�L�[�{�[�h�̍X�V����
	m_InputKeyboard->Update();

	//�}�E�X�̍X�V����
	m_InputMouse->Update();

	//�Q�[���p�b�h�̍X�V����
	m_InputJoyPad->Update();

	//�|�[�Y�̏����擾
	CPause *pPause = CGame::GetPause();

	m_Enemy = GetEnemy();

	if (m_InputKeyboard->GetTrigger(DIK_P) == true && m_pScene->GetMode() == CScene::MODE_GAME)
	{//ENTER�L�[�𐄂���
		
		if (m_Fade->Get() != m_Fade->FADE_OUT)
		{
			m_bPause = m_bPause ? false : true;
		}
	}

	if (m_bPause == true)
	{
		if (m_Pause == NULL)
		{//�g�p����Ă��Ȃ�������

			//�|�[�Y�𐶐�
			m_Pause = new CPause;

			//����������
			m_Pause->Init();
		}

		if (m_Pause != NULL)
		{
			m_Pause->Update();
		}
	}
	else
	{
		if (m_Pause != NULL)
		{
			//�|�[�Y�̏I������
			m_Pause->Uninit();

			//delete m_Pause;

			//�g�p���Ă��Ȃ���Ԃɂ���
			m_Pause = NULL;
		}

		if (m_Camera != NULL)
		{
			//�J�����̍X�V����
			m_Camera->Update();
		}

		if (m_pScene != NULL)
		{
			//�V�[���̍X�V
			m_pScene->Update();
		}
	}

	if ((m_InputKeyboard->GetTrigger(DIK_RETURN) == true || m_InputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true) && m_pScene->GetMode() == CScene::MODE_TITLE)
	{//ENTER�L�[�����������V�[�����^�C�g���̂Ƃ�

		if (m_Fade->Get() != m_Fade->FADE_OUT)
		{
			//�V�[�����Q�[���ɑJ��
			m_Fade->Set(CScene::MODE_GAME);
		}
	}
	else if (m_InputKeyboard->GetTrigger(DIK_RETURN) == true && m_pScene->GetMode() == CScene::MODE_GAME)
	{//ENTER�L�[�����������V�[�����Q�[���̂Ƃ�

		if (m_Fade->Get() != m_Fade->FADE_OUT)
		{
			//�V�[�����^�C�g���ɑJ��
			m_Fade->Set(CScene::MODE_RESULT);
		}
	}
	else if ((m_InputKeyboard->GetTrigger(DIK_RETURN) == true || m_InputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true) && m_pScene->GetMode() == CScene::MODE_RESULT)
	{//ENTER�L�[�����������V�[�����Q�[���̂Ƃ�

		if (m_Fade->Get() != m_Fade->FADE_OUT)
		{
			//�V�[�����^�C�g���ɑJ��
			m_Fade->Set(CScene::MODE_TITLE);
		}
	}

	//if (m_Fade->Get() != m_Fade->FADE_OUT)
	//{
	//	//�V�[�����Q�[���ɑJ��
	//	m_Fade->Set(CScene::MODE_GAME);
	//}

	//if (m_Fade->Get() != m_Fade->FADE_OUT)
	//{
	//	//�V�[�����^�C�g���ɑJ��
	//	m_Fade->Set(CScene::MODE_RESULT);
	//}

	//if (m_Fade->Get() != m_Fade->FADE_OUT)
	//{
	//	//�V�[�����^�C�g���ɑJ��
	//	m_Fade->Set(CScene::MODE_TITLE);
	//}

	//�g�p���Ă���e�N�X�`���̍��v����
	int nTexAll = m_Texture->GetNumTexture();

	m_DebugProc->Print("\n<<�e�N�X�`���̑��� : %d>>", nTexAll);
	m_DebugProc->Print("\n<<ENTER�Ŏ��̃V�[���ɑJ��>>");
}

//================================================================
//�`�揈��
//================================================================
void CManager::Draw(void)
{
	//�|�[�Y�̏����擾
	CPause *pPause = CGame::GetPause();

	//�����_���[�̕`�揈��
	m_Renderer->Draw();

	if (m_pScene != NULL)
	{
		m_pScene->Draw();
	}

	if (m_bPause == true)
	{
		if (pPause != NULL)
		{
			pPause->Draw();
		}
	}
}

//================================================================
//�R���X�g���N�^
//================================================================
CScene::CScene()
{
	//m_mode = MODE_TITLE;
}

//================================================================
//�R���X�g���N�^
//================================================================
CScene::CScene(MODE mode)
{
	m_mode = mode;
}

//================================================================
//�f�X�g���N�^
//================================================================
CScene::~CScene()
{

}

//================================================================
//����
//================================================================
CScene *CScene::Create(MODE mode)
{
	CScene *pScene = NULL;

	if (pScene == NULL)
	{
		pScene = new CScene(mode);

		pScene->Init();
	}

	return pScene;
}

//================================================================
//����������
//================================================================
HRESULT CScene::Init(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title == NULL)
		{
			m_Title = new CTitle;

			m_Title->Init();
		}

		break;

	/*case MODE_TUTORIAL:

		if (m_Tutorial == NULL)
		{
			m_Tutorial = new CTutorial;

			m_Tutorial->Init();
		}

		break;*/

	case MODE_GAME:

		if (m_Game == NULL)
		{
			m_Game = new CGame;

			m_Game->Init();
		}

		break;

	case MODE_RESULT:

		if (m_Result == NULL)
		{
			m_Result = new CResult;

			m_Result->Init();
		}

		break;
	}

	return S_OK;
}

//================================================================
//�I������
//================================================================
void CScene::Uninit(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title != NULL)
		{
			m_Title->Uninit();

			delete m_Title;

			m_Title = NULL;
		}

		break;

	/*case MODE_TUTORIAL:

		if (m_Tutorial != NULL)
		{
			m_Tutorial->Uninit();

			delete m_Tutorial;

			m_Tutorial = NULL;
		}

		break;*/

	case MODE_GAME:

		if (m_Game != NULL)
		{
			m_Game->Uninit();

			delete m_Game;

			m_Game = NULL;
		}

		break;

	case MODE_RESULT:

		if (m_Result != NULL)
		{
			m_Result->Uninit();

			delete m_Result;

			m_Result = NULL;
		}

		break;
	}
}

//================================================================
//�X�V����
//================================================================
void CScene::Update(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title != NULL)
		{
			m_Title->Update();
		}

		break;

	/*case MODE_TUTORIAL:

		if (m_Tutorial != NULL)
		{
			m_Tutorial->Update();
		}

		break;*/

	case MODE_GAME:

		if (m_Game != NULL)
		{
			m_Game->Update();
		}

		break;

	case MODE_RESULT:

		if (m_Result != NULL)
		{
			m_Result->Update();
		}

		break;
	}
}

//================================================================
//�`��
//================================================================
void CScene::Draw(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title != NULL)
		{
			m_Title->Draw();
		}

		break;

	/*case MODE_TUTORIAL:

		if (m_Tutorial != NULL)
		{
			m_Tutorial->Draw();
		}

		break;*/

	case MODE_GAME:

		if (m_Game != NULL)
		{
			m_Game->Draw();
		}

		break;

	case MODE_RESULT:

		if (m_Result != NULL)
		{
			m_Result->Draw();
		}

		break;
	}
}

//================================================================
//�����_���[�̎擾
//================================================================
CRenderer *CManager::GetRenderer(void)
{
	return m_Renderer;
}

//================================================================
//�L�[�{�[�h�̎擾
//================================================================
CInputKeyboard *CManager::GetKeyBoard(void)
{
	return m_InputKeyboard;
}

//================================================================
//�}�E�X�擾
//================================================================
CInputMouse *CManager::GetInputMouse(void)
{
	return m_InputMouse;
}

//================================================================
//�Q�[���p�b�h�擾
//================================================================
CInputJoyPad *CManager::GetInputJoyPad(void)
{
	return m_InputJoyPad;
}

//================================================================
//�T�E���h�̎擾
//================================================================
CSound *CManager::GetSound(void)
{
	return m_Sound;
}

//================================================================
//�v���C���[�̎擾
//================================================================
CPlayer *CManager::GetPlayer(void)
{
	return m_Player;
}

//================================================================
//�f�o�b�O�v���b�N�̎擾
//================================================================
CDebugProc *CManager::GetDebugProc(void)
{
	return m_DebugProc;
}

//================================================================
//�J�����̎擾
//================================================================
CCamera *CManager::GetCamera(void)
{
	return m_Camera;
}

//================================================================
//���C�g�̎擾
//================================================================
CLight *CManager::GetLight(void)
{
	return m_Light;
}

//================================================================
//�e�N�X�`���̎擾
//================================================================
CTexture *CManager::GetTexture(void)
{
	return m_Texture;
}

//================================================================
//���f���̎擾
//================================================================
CModel *CManager::GetModel(void)
{
	return m_Model;
}

//================================================================
//�I�u�W�F�N�g3D�̎擾
//================================================================
CObject3D *CManager::GetObject3D(void)
{
	return m_Object3D;
}

//================================================================
//�G�̎擾
//================================================================
CEnemy *CManager::GetEnemy(void)
{
	return m_Enemy;
}
//================================================================
//�����蔻��̎擾
//================================================================
CCollision *CManager::GetCollsion(void)
{
	return m_Collision;
}

//================================================================
//�G�f�B�b�g�̎擾
//================================================================
CEdit *CManager::GetEdit(void)
{
	return m_Edit;
}

//================================================================
//�}�b�v�̎擾
//================================================================
CMap *CManager::GetMap(void)
{
	return m_Map;
}

//================================================================
//�}�b�v�̎擾
//================================================================
CScene *CManager::GetScene(void)
{
	return m_pScene;
}

//================================================================
//�}�b�v�̎擾
//================================================================
CFade *CManager::GetFade(void)
{
	return m_Fade;
}

//================================================================
//�|�[�Y�̎擾
//================================================================
CPause *CManager::GetPause(void)
{
	return m_Pause;
}

//================================================================
//���[�h�ݒ�
//================================================================
void CManager::SetMode(CScene::MODE mode)
{
	//m_Sound->Stop();

	//CObject::ReleaseAll();

	if (m_pScene != NULL)
	{
		m_pScene->Uninit();

		delete m_pScene;

		m_pScene = NULL;
	}

	if (m_pScene == NULL)
	{
		m_pScene = new CScene(mode);

		m_pScene->Init();
	}
}

//================================================================
//���[�h�̎擾
//================================================================
CScene::MODE CScene::GetMode(void)
{
	return m_mode;
}