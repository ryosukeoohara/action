//===========================================================
//
//出現演出処理[appear.h]
//Author 大原怜将
//
//===========================================================

//*==========================================================
//インクルードファイル
//*==========================================================
#include "appear.h"

//===========================================================
//コンストラクタ
//===========================================================
CAppear::CAppear()
{
}

//===========================================================
//コンストラクタ
//===========================================================
CAppear::CAppear(D3DXVECTOR3 pos)
{
}

//===========================================================
//デストラクタ
//===========================================================
CAppear::~CAppear()
{
}

//===========================================================
//生成
//===========================================================
CAppear * CAppear::Create(D3DXVECTOR3 pos)
{
	CAppear *pAppear = NULL;

	if (pAppear == NULL)
	{
		pAppear = new CAppear;

		pAppear->Init();
	}

	return pAppear;
}

//===========================================================
//初期化処理
//===========================================================
HRESULT CAppear::Init(void)
{


	return S_OK;
}

//===========================================================
//終了処理
//===========================================================
void CAppear::Uninit(void)
{

}

//===========================================================
//更新処理
//===========================================================
void CAppear::Update(void)
{

}

//===========================================================
//描画処理
//===========================================================
void CAppear::Draw(void)
{

}