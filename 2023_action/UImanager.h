//===========================================================
//
//UIマネージャ[UImanager.h]
//Author 大原怜将
//
//===========================================================
#ifndef _UIMANAGER_H_
#define _UIMANAGER_H_

//*==========================================================
//インクルードファイル
//*==========================================================
#include "object2D.h"

//*==========================================================
//クラス定義
//*==========================================================
class CUIManager : CObject2D
{
public:

	//種類
	enum TYPE
	{
		TYPE_NONE = 0,                              //なんもない
		TYPE_TITLE,                                 //タイトル
		TYPE_RESULT,                                //リザルト
		TYPE_GUNGAGE,                               //銃の残弾表示
		TYPE_LIFEFOOT,                              //体力
		TYPE_LIFECHIBI,                             //体力
		TYPE_ICONFOOT,                              //デブの顔アイコン
		TYPE_ICONCHIBI,                             //チビの顔アイコン
		TYPE_MAGIC,                                 //魔法
		TYPE_TITLESELECT,                           //ゲームスタート
		TYPE_MAX
	};

	CUIManager();                                   //コンストラクタ
	CUIManager(D3DXVECTOR3 pos, TYPE type);         //コンストラクタ
	~CUIManager();                                  //デストラクタ

	HRESULT Init(void);                             //初期化処理
	void Uninit(void);                              //終了処理
	void Update(void);                              //更新処理
	void Draw(void);                                //描画処理

	static CUIManager *Create(D3DXVECTOR3 pos, TYPE type); //生成処理

private:
	TYPE m_type;                                    //種類
	int m_nIdxTexture;                              //テクスチャのインデックス番号
};

#endif // !_UIMANAGER_H_