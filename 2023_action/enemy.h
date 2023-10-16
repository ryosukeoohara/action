//=============================================================================
//
// 敵の処理 [enemy.h]
// Author : 大原　怜将
//
//=============================================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//*=============================================================================
//インクルードファイル
//*=============================================================================
#include "character.h"
#include "object.h"

//*=============================================================================
//クラス定義
//*=============================================================================
class CMotion;

//*=============================================================================
//クラス定義
//*=============================================================================
class CEnemy : public CObject
{
public:
	CEnemy();                            //コンストラクタ
	CEnemy(D3DXVECTOR3 pos);             //コンストラクタ
	~CEnemy();                           //デストラクタ

	HRESULT Init(void);                  //初期化
	void Uninit(void);                   //終了
	void Update(void);                   //更新
	void Draw(void);                     //描画

	CEnemy *Create(void);                //生成
	void ReadText(char *fliename);       //テキストファイル読み込み

private:
	CMotion *m_motion;                   //モーションへのポインタ
	CCharacter *m_apModel[MAX_PRATS];    //モデル(パーツ)へのポインタ

	D3DXVECTOR3 m_posOld;                //前回の位置
	D3DXVECTOR3 m_move;                  //移動
	D3DXMATRIX m_mtxWorld;               //ワールドマトリックス

	//*=============================================================================
	//外部ファイル読み込み用
	//*=============================================================================
	D3DXVECTOR3 m_Readpos;               //位置読み込み用
	D3DXVECTOR3 m_Readrot;               //向き読み込み用
	int m_nIdx;                          //インデックス番号
	int m_nParent;                       //親のインデックス番号
	int m_nNumModel;                     //モデル(パーツ)の総数
	char m_filename[128] = {};           //文字読み込み用

};

#endif // !_ENEMY_H_