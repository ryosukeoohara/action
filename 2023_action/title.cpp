//===========================================================
//
//ポリゴンを出すやつ[title.cpp]
//Author 大原怜将
//
//===========================================================
#include "title.h"
#include "texture.h"
#include "game.h"
#include "debugproc.h"
#include "renderer.h"
#include "sound.h"

//===========================================================
//コンストラクタ
//===========================================================
CTitle::CTitle()
{
	for (int nCount = 0; nCount < MAX_TITLEOBJ; nCount++)
	{
		m_apObject2D[nCount] = NULL;
		m_apObject3D[nCount] = NULL;
	}
}

//===========================================================
//デストラクタ
//===========================================================
CTitle::~CTitle()
{

}

//===========================================================
//生成
//===========================================================
CTitle *CTitle::Create(void)
{
	CTitle *pTitle = NULL;

	if (pTitle == NULL)
	{
		pTitle = new CTitle;

		pTitle->Init();
	}

	return pTitle;
}

//===========================================================
//初期化処理
//===========================================================
HRESULT CTitle::Init(void)
{
	//サウンドを取得
	CSound *pSound = CManager::GetSound();
	pSound->Play(CSound::SOUND_LABEL_BGM002);

	return S_OK;
}

//===========================================================
//終了処理
//===========================================================
void CTitle::Uninit(void)
{
	//サウンドを取得
	CSound *pSound = CManager::GetSound();

	pSound->Stop();

	CObject::ReleaseAll();
}

//===========================================================
//更新処理
//===========================================================
void CTitle::Update(void)
{
	//すべてのオブジェクトの更新処理
	CObject::UpdateAll();

	CDebugProc *pDebugProc = CManager::GetDebugProc();
	pDebugProc->Print("\nシーン：タイトル");
}

//===========================================================
//描画処理
//===========================================================
void CTitle::Draw(void)
{
	
}