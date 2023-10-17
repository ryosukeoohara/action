//===========================================================
//
//�|���S�����o�����[manager.h]
//Author �匴�叫
//
//===========================================================
#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "main.h"
//#include "object.h"

//===========================================================
//�O���錾
//===========================================================
class CRenderer;
class CInputKeyboard;
class CInputMouse;
class CInputJoyPad;
class CSound;
class CPlayer;
class CDebugProc;
class CCamera;
class CLight;
class CTexture;
class CModel;
class CObject3D;
class CEnemy;
class CCollision;
class CEdit;
class CMap;
class CGame;
class CTutorial;
class CTitle;
class CResult;
class CFade;
class CPause;

//�V�[���N���X
class CScene /*: public CObject*/
{
public:

	enum MODE
	{
		MODE_TITLE = 0,   //�^�C�g��
		MODE_TUTORIAL,    //�`���[�g���A��
		MODE_GAME,        //�Q�[��
		MODE_RESULT,      //���U���g
		MODE_RANKING,     //�����L���O
		MODE_MAX
	};

	CScene();  //�R���X�g���N�^
	CScene(MODE mode);  //�R���X�g���N�^
	~CScene(); //�f�X�g���N�^

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CScene *Create(MODE mode);
	static CScene::MODE GetMode(void);

private:
	static MODE m_mode;
	static CGame *m_Game;
	static CTutorial *m_Tutorial;
	static CTitle *m_Title;
	static CResult *m_Result;

};

//�}�l�[�W���N���X
class CManager
{
public:		//�N�ł��A�N�Z�X�ł���

	static CManager *Getinstance();
	static HRESULT Release(void);
	CManager();  //�R���X�g���N�^
	~CManager(); //�f�X�g���N�^

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);       //����������
	void Uninit(void);  //�I������
	void Update(void);  //�X�V����
	void Draw(void);    //�`�揈��

	CRenderer *GetRenderer(void);
	CInputKeyboard *GetKeyBoard(void);
	CInputMouse *GetInputMouse(void);
	CInputJoyPad *GetInputJoyPad(void);
	CSound *GetSound(void);
	CPlayer *GetPlayer(void);
	CDebugProc *GetDebugProc(void);
	CCamera *GetCamera(void);
	CLight *GetLight(void);
	CTexture *GetTexture(void);
	CModel *GetModel(void);
	CObject3D *GetObject3D(void);
	CEnemy *GetEnemy(void);
	//static void *SetEnemy(CEnemy *enemy) { return m_Enemy = enemy; }
	CCollision *GetCollsion(void);
	CEdit *GetEdit(void);
	CMap *GetMap(void);
	CScene *GetScene(void);
	CFade *GetFade(void);
	CPause *GetPause(void);
	

	void SetMode(CScene::MODE mode);

	void SetbPause(bool bpause) { m_bPause = bpause; }
	bool GetbPause(void) { return m_bPause; }

private:	//�����������A�N�Z�X�ł���

	static CManager *m_pManager;
	CRenderer *m_Renderer;
	CInputKeyboard *m_InputKeyboard;
	CInputMouse *m_InputMouse;
	CInputJoyPad *m_InputJoyPad;
	CSound *m_Sound;
	CPlayer *m_Player;
	CDebugProc *m_DebugProc;
	CCamera *m_Camera;
	CLight *m_Light;
	CTexture *m_Texture;
	CModel *m_Model;
	CObject3D *m_Object3D;
	CEnemy *m_Enemy;
	CCollision *m_Collision;
	CEdit *m_Edit;
	CMap *m_Map;
	CScene *m_pScene;
	CFade *m_Fade;
	CPause *m_Pause;
	

	int m_ResetCounter;  //���Z�b�g������
	bool m_bPause;       //�|�[�Y�����ǂ���
	bool m_EditUse;   //�G�f�B�b�g���[�h�ɂ��邩�ǂ���
};

#endif // !1