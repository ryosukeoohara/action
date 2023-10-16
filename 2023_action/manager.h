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

	CManager();  //�R���X�g���N�^
	~CManager(); //�f�X�g���N�^

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);       //����������
	void Uninit(void);  //�I������
	void Update(void);  //�X�V����
	void Draw(void);    //�`�揈��

	static CRenderer *GetRenderer(void);
	static CInputKeyboard *GetKeyBoard(void);
	static CInputMouse *GetInputMouse(void);
	static CInputJoyPad *GetInputJoyPad(void);
	static CSound *GetSound(void);
	static CPlayer *GetPlayer(void);
	static CDebugProc *GetDebugProc(void);
	static CCamera *GetCamera(void);
	static CLight *GetLight(void);
	static CTexture *GetTexture(void);
	static CModel *GetModel(void);
	static CObject3D *GetObject3D(void);
	static CEnemy *GetEnemy(void);
	//static void *SetEnemy(CEnemy *enemy) { return m_Enemy = enemy; }
	static CCollision *GetCollsion(void);
	static CEdit *GetEdit(void);
	static CMap *GetMap(void);
	static CScene *GetScene(void);
	static CFade *GetFade(void);
	static CPause *GetPause(void);

	static void SetMode(CScene::MODE mode);

	static void SetbPause(bool bpause) { m_bPause = bpause; }
	static bool GetbPause(void) { return m_bPause; }

private:	//�����������A�N�Z�X�ł���

	static CRenderer *m_Renderer;
	static CInputKeyboard *m_InputKeyboard;
	static CInputMouse *m_InputMouse;
	static CInputJoyPad *m_InputJoyPad;
	static CSound *m_Sound;
	static CPlayer *m_Player;
	static CDebugProc *m_DebugProc;
	static CCamera *m_Camera;
	static CLight *m_Light;
	static CTexture *m_Texture;
	static CModel *m_Model;
	static CObject3D *m_Object3D;
	static CEnemy *m_Enemy;
	static CCollision *m_Collision;
	static CEdit *m_Edit;
	static CMap *m_Map;
	static CScene *m_pScene;
	static CFade *m_Fade;
	static CPause *m_Pause;

	int m_ResetCounter;  //���Z�b�g������
	static bool m_bPause;       //�|�[�Y�����ǂ���
	bool m_EditUse;   //�G�f�B�b�g���[�h�ɂ��邩�ǂ���
};

#endif // !1