//===========================================================
//
//���U���g���[result.h]
//Author �匴�叫
//
//===========================================================
#ifndef _RESULT_H_
#define _RESULT_H_
#include "manager.h"
#include "object2D.h"

//���U���g�N���X
class CResult : public CScene
{
public:
	CResult();
	~CResult();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CResult *Create(void);

private:
};

#endif // !_TITLE_H_