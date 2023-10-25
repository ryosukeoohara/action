//===========================================================
//
//�|�[�Y����[pause.cpp]
//Author �匴�叫
//
//===========================================================
#include "pause.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "input.h"
#include "fade.h"
#include "game.h"

//===========================================================
//�R���X�g���N�^
//===========================================================
CPause::CPause()
{
	//m_nIdxTexture[MAX_PAUSEOBJ] = -1;
	m_pauseMenu = MENU_COUTINUE;
	m_bPause = false;
}

//===========================================================
//�f�X�g���N�^
//===========================================================
CPause::~CPause()
{

}

//===========================================================
//����������
//===========================================================
HRESULT CPause::Init(void)
{
	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	for (int nCount = 0; nCount < MAX_PAUSEOBJ; nCount++)
	{
		m_Object2D[nCount] = NULL;
	}

	for (int nCount = 0; nCount < MAX_PAUSEOBJ; nCount++)
	{
		if (m_Object2D[nCount] == NULL)
		{
			switch (nCount)
			{
			case MENU_BACK:

				m_Object2D[nCount] = new CObject2D({ 640.0f, 360.0f, 0.0f });
				
				m_Object2D[nCount]->SetIdxTex(pTexture->Regist("data\\TEXTURE\\kuro.jpg"));
				break;

			case MENU_FRAME:

				m_Object2D[nCount] = new CObject2D({ 640.0f, 360.0f, 0.0f });

				m_Object2D[nCount]->SetIdxTex(pTexture->Regist("data\\TEXTURE\\pause100.png"));
				break;

			case MENU_COUTINUE:

				m_Object2D[nCount] = new CObject2D({ 640.0f, 210.0f, 0.0f });
				
				m_Object2D[nCount]->SetIdxTex(pTexture->Regist("data\\TEXTURE\\pause000.png"));
				break;

			case MENU_RETRY:

				m_Object2D[nCount] = new CObject2D({ 640.0f, 360.0f, 0.0f });
				
				m_Object2D[nCount]->SetIdxTex(pTexture->Regist("data\\TEXTURE\\pause001.png"));
				break;

			case MENU_QUIT:

				m_Object2D[nCount] = new CObject2D({ 640.0f, 510.0f, 0.0f });
				
				m_Object2D[nCount]->SetIdxTex(pTexture->Regist("data\\TEXTURE\\pause002.png"));
				break;
			}

			m_Object2D[nCount]->Init();
		}
	}

	//if (m_Pause.pBackGround == NULL)
	//{
	//	m_Pause.pBackGround = new CObject2D({SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f});
	//	m_Pause.pBackGround->Init();
	//	m_Pause.pBackGround->SetIdxTex(pTexture->Regist("data\\TEXTURE\\kuro.jpg"));

	//	//m_Pause.pBackGround->SetVtxUI(m_Pause.pBackGround->Getpos(), 640.0f, 360.0f, { 1.0f, 1.0f, 1.0f, 0.5f });
	//}

	//if (m_Pause.pFrame == NULL)
	//{
	//	m_Pause.pFrame = new CObject2D({ SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f });
	//	m_Pause.pFrame->Init();
	//	m_Pause.pFrame->SetIdxTex(pTexture->Regist("data\\TEXTURE\\pause100.png"));

	//	//m_Pause.pFrame->SetVtxUI(m_Pause.pFrame->Getpos(), 300.0f, 200.0f, { 1.0f, 1.0f, 1.0f, 0.5f });
	//}

	//if (m_Pause.pContinue == NULL)
	//{
	//	m_Pause.pContinue = new CObject2D({ SCREEN_WIDTH * 0.5f, 210.0f, 0.0f });
	//	m_Pause.pContinue->Init();
	//	m_Pause.pContinue->SetIdxTex(pTexture->Regist("data\\TEXTURE\\pause000.png"));

	//	//m_Pause.pContinue->SetVtxUI(m_Pause.pContinue->Getpos(), 200.0f, 50.0f, { 1.0f, 1.0f, 1.0f, 0.5f });
	//}

	//if (m_Pause.pReStart == NULL)
	//{
	//	m_Pause.pReStart = new CObject2D({ SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f });
	//	m_Pause.pReStart->Init();
	//	m_Pause.pReStart->SetIdxTex(pTexture->Regist("data\\TEXTURE\\pause001.png"));

	//	//m_Pause.pReStart->SetVtxUI(m_Pause.pReStart->Getpos(), 200.0f, 50.0f, { 1.0f, 1.0f, 1.0f, 0.5f });
	//}

	//if (m_Pause.pTitleBack == NULL)
	//{
	//	m_Pause.pTitleBack = new CObject2D({ SCREEN_WIDTH * 0.5f, 510.0f, 0.0f });
	//	m_Pause.pTitleBack->Init();
	//	m_Pause.pTitleBack->SetIdxTex(pTexture->Regist("data\\TEXTURE\\pause002.png"));

	//	//m_Pause.pTitleBack->SetVtxUI(m_Pause.pTitleBack->Getpos(), 200.0f, 50.0f, { 1.0f, 1.0f, 1.0f, 0.5f });
	//}

	return S_OK;
}

//===========================================================
//�I������
//===========================================================
void CPause::Uninit(void)
{
	for (int nCount = 0; nCount < MAX_PAUSEOBJ; nCount++)
	{
		if (m_Object2D[nCount] != NULL)
		{
			m_Object2D[nCount]->Uninit();

			m_Object2D[nCount] = NULL;
		}
	}

	//Release();

	//if (m_Pause.pBackGround != NULL)
	//{
	//	m_Pause.pBackGround->Uninit();
	//	//delete m_Pause.pBackGround;
	//	m_Pause.pBackGround = NULL;
	//}

	//if (m_Pause.pFrame != NULL)
	//{
	//	m_Pause.pFrame->Uninit();
	//	//delete m_Pause.pFrame;
	//	m_Pause.pFrame = NULL;
	//}

	//if (m_Pause.pContinue != NULL)
	//{
	//	m_Pause.pContinue->Uninit();
	//	//delete m_Pause.pContinue;
	//	m_Pause.pContinue = NULL;
	//}

	//if (m_Pause.pReStart != NULL)
	//{
	//	m_Pause.pReStart->Uninit();
	//	//delete m_Pause.pReStart;
	//	m_Pause.pReStart = NULL;
	//}

	//if (m_Pause.pTitleBack != NULL)
	//{
	//	m_Pause.pTitleBack->Uninit();
	//	//delete m_Pause.pTitleBack;
	//	m_Pause.pTitleBack = NULL;
	//}
}

//===========================================================
//�X�V����
//===========================================================
void CPause::Update(void)
{
	CInputKeyboard *InputKeyboard = CManager::Getinstance()->GetKeyBoard();

	CSound *pSound;

	pSound = CManager::Getinstance()->GetSound();

	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::Getinstance()->GetFade();

	if (CManager::Getinstance()->GetbPause() == true)
	{
		if (InputKeyboard->GetTrigger(DIK_W) == true)
		{//����L�[��(ENTER�L�[)�������ꂽ

			if (m_pauseMenu == MENU_COUTINUE)
			{
				m_pauseMenu = MENU_QUIT;
			}
			else if (m_pauseMenu == MENU_QUIT)
			{
				m_pauseMenu = MENU_RETRY;
			}
			else if (m_pauseMenu == MENU_RETRY)
			{
				m_pauseMenu = MENU_COUTINUE;
			}
		}
		else if (InputKeyboard->GetTrigger(DIK_S) == true)
		{//����L�[��(ENTER�L�[)�������ꂽ

			if (m_pauseMenu == MENU_COUTINUE)
			{
				m_pauseMenu = MENU_RETRY;
			}
			else if (m_pauseMenu == MENU_QUIT)
			{
				m_pauseMenu = MENU_COUTINUE;
			}
			else if (m_pauseMenu == MENU_RETRY)
			{
				m_pauseMenu = MENU_QUIT;
			}
		}

		if (InputKeyboard->GetTrigger(DIK_RETURN) == true)
		{
			if (m_pauseMenu == MENU_COUTINUE)
			{
				if (InputKeyboard->GetTrigger(DIK_RETURN) == true)
				{
					CManager::Getinstance()->SetbPause(false);
				}
			}
			else if (m_pauseMenu == MENU_QUIT)
			{
				if (pFade->Get() != pFade->FADE_OUT)
				{
					pFade->Set(CScene::MODE_TITLE);

					CManager::Getinstance()->SetbPause(false);
				}
			}
			else if (m_pauseMenu == MENU_RETRY)
			{
				if (pFade->Get() != pFade->FADE_OUT)
				{
					pFade->Set(CScene::MODE_GAME);

					CManager::Getinstance()->SetbPause(false);
				}
			}
		}

		for (int nCount = 0; nCount < MAX_PAUSEOBJ; nCount++)
		{
			m_Color[nCount].col.a = 0.0f;
		}

		if (m_Object2D[m_pauseMenu] != NULL)
		{
			m_Color[m_pauseMenu].col.a = 0.7f;
		}

		/*if (m_Pause.pBackGround != NULL)
		{
			m_Pause.pBackGround->SetVtxUI(m_Pause.pBackGround->Getpos(), 640.0f, 360.0f, { 1.0f, 1.0f, 1.0f, 0.5f });
		}

		if (m_Pause.pFrame != NULL)
		{
			m_Pause.pFrame->SetVtxUI(m_Pause.pFrame->Getpos(), 300.0f, 200.0f, { 1.0f, 1.0f, 1.0f, 0.5f });
		}

		if (m_Pause.pContinue != NULL)
		{
			m_Pause.pContinue->SetVtxUI(m_Pause.pContinue->Getpos(), 200.0f, 50.0f, { 1.0f, 1.0f, 1.0f, 0.5f });
		}

		if (m_Pause.pReStart != NULL)
		{
			m_Pause.pReStart->SetVtxUI(m_Pause.pReStart->Getpos(), 200.0f, 50.0f, { 1.0f, 1.0f, 1.0f, 0.5f });
		}

		if (m_Pause.pTitleBack != NULL)
		{
			m_Pause.pTitleBack->SetVtxUI(m_Pause.pTitleBack->Getpos(), 200.0f, 50.0f, { 1.0f, 1.0f, 1.0f, 0.5f });
		}*/

		/*for (int nCount = 0; nCount < MAX_PAUSEOBJ; nCount++)
		{
			if (m_Object2D[nCount] != NULL)
			{
				m_Object2D[nCount]->Update();

				D3DXVECTOR3 pos = m_Object2D[nCount]->Getpos();

				switch (nCount)
				{
				case MENU_BACK:

					m_Object2D[nCount]->SetVtxUI(pos, 640.0f, 360.0f, { 1.0f, 1.0f, 1.0f, 0.5f + m_Color[nCount].col.a });
					break;

				case MENU_FRAME:

					m_Object2D[nCount]->SetVtxUI(pos, 300.0f, 200.0f, { 1.0f, 1.0f, 1.0f, 0.3f + m_Color[nCount].col.a });
					break;

				case MENU_COUTINUE:

					m_Object2D[nCount]->SetVtxUI(pos, 200.0f, 50.0f, { 1.0f, 1.0f, 1.0f, 0.3f + m_Color[nCount].col.a });
					break;

				case MENU_RETRY:

					m_Object2D[nCount]->SetVtxUI(pos, 200.0f, 50.0f, { 1.0f, 1.0f, 1.0f, 0.3f + m_Color[nCount].col.a });
					break;

				case MENU_QUIT:

					m_Object2D[nCount]->SetVtxUI(pos, 200.0f, 50.0f, { 1.0f, 1.0f, 1.0f, 0.5f + m_Color[nCount].col.a });
					break;
				}
			}
		}*/
	}
}

//===========================================================
//�`�揈��
//===========================================================
void CPause::Draw(void)
{
	CTexture *pTexture = CManager::Getinstance()->GetTexture();
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	if (CManager::Getinstance()->GetbPause() == true)
	{
		for (int nCount = 0; nCount < MAX_PAUSEOBJ; nCount++)
		{
			if (m_Object2D[nCount] != NULL)
			{
				pDevice->SetTexture(0, pTexture->GetAddress(m_Object2D[nCount]->GetIdxTex()));

				m_Object2D[nCount]->Draw();
			}
		}
	}
}