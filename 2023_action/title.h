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

private:
};
#endif // !_TITLE_H_