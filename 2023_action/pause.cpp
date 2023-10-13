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
	m_nIdxTexture[MAX_PAUSEOBJ] = -1;
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
	CTexture *pTexture = CManager::GetTexture();

	/*for (int nCount = 0; nCount < MAX_PAUSEOBJ; nCount++)
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
	}*/



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

	Release();
}

//===========================================================
//�X�V����
//===========================================================
void CPause::Update(void)
{
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	CSound *pSound;

	pSound = CManager::GetSound();

	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::GetFade();

	if (CManager::GetbPause() == true)
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
					CManager::SetbPause(false);
				}
			}
			else if (m_pauseMenu == MENU_QUIT)
			{
				if (pFade->Get() != pFade->FADE_OUT)
				{
					pFade->Set(CScene::MODE_TITLE);

					CManager::SetbPause(false);
				}
			}
			else if (m_pauseMenu == MENU_RETRY)
			{
				if (pFade->Get() != pFade->FADE_OUT)
				{
					pFade->Set(CScene::MODE_GAME);

					CManager::SetbPause(false);
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

		for (int nCount = 0; nCount < MAX_PAUSEOBJ; nCount++)
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
		}
	}
}

//===========================================================
//�`�揈��
//===========================================================
void CPause::Draw(void)
{
	CTexture *pTexture = CManager::GetTexture();
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	if (CManager::GetbPause() == true)
	{
		for (int nCount = 0; nCount < MAX_PAUSEOBJ; nCount++)
		{
			if (m_Object2D[nCount] != NULL)
			{
				pDevice->SetTexture(0, pTexture->GetAddress(m_Object2D[nCount]->GetIdxTex()));

				//m_Object2D[nCount]->Draw();
			}
		}
	}
}