//===========================================================
//
//リザルト画面[result.cpp]
//Author 大原怜将
//
//===========================================================

//*==========================================================
//インクルードファイル
//*==========================================================
#include "result.h"
#include "texture.h"
#include "game.h"
#include "debugproc.h"
#include "renderer.h"
#include "sound.h"
#include "UImanager.h"
#include "ranking.h"
#include "score.h"

//===========================================================
//コンストラクタ
//===========================================================
CResult::CResult()
{
	
}

//===========================================================
//デストラクタ
//===========================================================
CResult::~CResult()
{

}

//===========================================================
//生成
//===========================================================
CResult *CResult::Create(void)
{
	CResult *pTitle = NULL;

	if (pTitle == NULL)
	{
		pTitle = new CResult;

		pTitle->Init();
	}

	return pTitle;
}

//===========================================================
//初期化処理
//===========================================================
HRESULT CResult::Init(void)
{
	//タイトルのロゴ生成
	//CUIManager::Create({ SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f }, CUIManager::TYPE_RESULT);

	CRanking::Create();

	CRanking::SetRanking(CScore::Getscore());

	//サウンドを取得
	CSound *pSound = CManager::Getinstance()->GetSound();

	//サウンド再生
	pSound->Play(CSound::SOUND_LABEL_BGM001);

	return S_OK;
}

//===========================================================
//終了処理
//===========================================================
void CResult::Uninit(void)
{
	//サウンドを取得
	CSound *pSound = CManager::Getinstance()->GetSound();

	pSound->Stop();

	CObject::ReleaseAll();
}

//===========================================================
//更新処理
//===========================================================
void CResult::Update(void)
{
	//すべてのオブジェクトの更新処理
	CObject::UpdateAll();

	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();

	pDebugProc->Print("\nシーン：リザルト");
}

//===========================================================
//描画処理
//===========================================================
void CResult::Draw(void)
{
	
}