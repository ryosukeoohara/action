//=============================================================================
//
// 敵の処理 [enemyfar.h]
// Author : 大原　怜将
//
//=============================================================================
#ifndef _ENEMYFAR_H_
#define _ENEMYFAR_H_

#include "enemy.h"

////敵クラス(近距離)
//class CEnemyFar : public CEnemy
//{
//public:
//	CEnemyFar();                 //コンストラクタ
//	CEnemyFar(D3DXVECTOR3 pos, D3DXVECTOR3 rot);  //コンストラクタ(オーバーロード)
//	~CEnemyFar();                //デストラクタ
//
//	//状態------------------------------------------------------------------
//	enum STATE
//	{
//		TATE_NONE = 0,             //ニュートラル
//		TATE_MOVE,                 //移動
//		TATE_ACTION,               //攻撃
//		TATE_ACTIONNEUTRAL,        //攻撃ニュートラル
//		TATE_DAMEGE,               //ダメージ受け
//		TATE_STAGGER,              //よろけ
//		TATE_DEATH,                //死亡
//		TATE_MAX
//	};
//
//								 //モーション-------------------------------------------------------------
//	typedef enum
//	{
//		MOTIONTYPE_NONE = 0,         //ニュートラル
//		MOTIONTYPE_MOVE,             //移動
//		MOTIONTYPE_ACTION,           //攻撃
//		MOTIONTYPE_ACTIONNEUTRAL,    //攻撃待機
//		MOTIONTYPE_REROAD,           //爆弾をポッケから取り出す
//		MOTIONTYPE_DAMEGE,           //ダメージ
//		MOTIONTYPE_DEATH,            //死亡
//		MOTIONTYPE_MAX
//	} MOTIONTYPE;
//
//	HRESULT Init(void);   //初期化処理    
//	void Uninit(void);    //終了処理
//	void Update(void);    //更新処理
//	void Draw(void);      //描画処理
//
//	static CEnemyFar *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);  //生成
//
//	void ReadText(char *Filename);  //外部ファイル読み込み
//	static CEnemyWeak **GetEnemy(void) { return &m_EnemyWeak[0]; };
//	static CEnemyWeak *SetEnemy(CEnemyWeak *pEnemy) {  };
//	static void UninitWeak(void);
//
//	void Control(void);  //敵の動き
//	void Death(int nCntEnemy);    //死んだとき
//
//	void SetState(STATE state) { m_state = state; }  //状態設定
//	STATE GetState(void) { return m_state; }  //状態取得
//
//private:
//
//	TYPE m_type;
//	int m_nIdx;
//	int m_nParent;
//	int m_nNumPatrol;      //巡回する地点の数
//	int m_nCurrentpos;     //現在どこの巡回地点にいるか
//	int m_nCntAction;      //攻撃してから再び攻撃するまでの時間
//	int m_nCntDeath;       //死亡してから消滅するまでの時間
//	int m_DeathEnemyIdx;   //死亡した敵の番号
//	int m_nCntReload;      //リロードするまでのカウント
//	float m_fDiff;
//	float m_fDest;
//	bool m_Tracking;       //プレイヤーを追尾するかどうか
//	bool m_bAction;        //攻撃したかどうか
//	bool m_bBom;           //爆弾をポッケから取り出す
//};

#endif // !_ENEMYFAR_H_