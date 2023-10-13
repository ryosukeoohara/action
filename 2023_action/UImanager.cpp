//===========================================================
//
//UIマネージャ[UImanager.h]
//Author 大原怜将
//
//===========================================================

//*==========================================================
//インクルードファイル
//*==========================================================
#include "UImanager.h"
#include "texture.h"
#include "manager.h"
#include "renderer.h"

//===========================================================
//コンストラクタ
//===========================================================
CUIManager::CUIManager()
{
	//初期化
	m_type = TYPE_NONE;
	m_nIdxTexture = -1;
}

//===========================================================
//コンストラクタ
//===========================================================
CUIManager::CUIManager(D3DXVECTOR3 pos, TYPE type)
{
	//初期化
	SetPos(&pos);
	m_type = type;
	m_nIdxTexture = -1;
}

//===========================================================
//デストラクタ
//===========================================================
CUIManager::~CUIManager()
{

}

//===========================================================
//生成処理
//===========================================================
CUIManager * CUIManager::Create(D3DXVECTOR3 pos, TYPE type)
{
	//UIマネージャへのポインタ
	CUIManager *pUI = NULL;

	if (pUI == NULL)
	{//使用されていなかったら

		//生成
		pUI = new CUIManager(pos, type);

		//初期化処理
		pUI->Init();
	}

	return pUI;
}


//===========================================================
//初期化処理
//===========================================================
HRESULT CUIManager::Init(void)
{
	//テクスチャの情報取得
	CTexture *pTexture = CManager::GetTexture();

	//初期化処理
	CObject2D::Init();

	switch (m_type)
	{
	case CUIManager::TYPE_NONE:     //なんもない
		break;

	case CUIManager::TYPE_TITLE:    //タイトル

		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\taitoru.jpg");
		break;

	case CUIManager::TYPE_RESULT:   //リザルト

		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\res.jpg");
		break;

	case CUIManager::TYPE_MAX:
		break;

	default:
		break;
	}

	return S_OK;
}

//===========================================================
//終了処理
//===========================================================
void CUIManager::Uninit(void)
{
	//終了処理
	CObject2D::Uninit();

	//自身の破棄
	Release();
}

//===========================================================
//更新処理
//===========================================================
void CUIManager::Update(void)
{
	//更新処理
	CObject2D::Update();

	//大きさとか設定
	switch (m_type)
	{
	case CUIManager::TYPE_NONE:     //なんもない
		break;

	case CUIManager::TYPE_TITLE:    //タイトル

		CObject2D::SetVtxUI(Getpos(), 400.0f, 200.0f, { 1.0f,1.0f,1.0f,1.0f });
		break;

	case CUIManager::TYPE_RESULT:   //リザルト

		CObject2D::SetVtxUI(Getpos(), 400.0f, 200.0f, { 1.0f,1.0f,1.0f,1.0f });
		break;

	case CUIManager::TYPE_MAX:
		break;

	default:
		break;
	}
}

//===========================================================
//描画処理
//===========================================================
void CUIManager::Draw(void)
{
	//テクスチャの情報を取得
	CTexture *pTexture = CManager::GetTexture();

	//レンダラーの情報を取得
	CRenderer *pRenderer = CManager::GetRenderer();

	//デバイスの情報を取得
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//テクスチャ設定
	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//描画処理
	CObject2D::Draw();
}