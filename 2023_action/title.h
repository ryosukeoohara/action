//===========================================================
//
//�|���S�����o�����[title.h]
//Author �匴�叫
//
//===========================================================
#ifndef _TITLE_H_
#define _TITLE_H_
#include "manager.h"
#include "object2D.h"

//�O���錾
class CChibi;
class CFoot;

//�^�C�g���N���X
class CTitle : public CScene
{
public:
	CTitle();
	~CTitle();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CTitle *Create(void);

	static CChibi *GetPlayerChibi(void) { return m_PlayerChibi; }
	static CFoot *GetPlayerFoot(void) { return m_PlayerFoot; }

private:
	static CChibi *m_PlayerChibi;
	static CFoot *m_PlayerFoot;

};
#endif // !_TITLE_H_