//===============================================================
//
//�`���[�g���A������[tutorial.h]
// Author �匴�叫
//
//===============================================================
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include "main.h"
#include "manager.h"

class CTutorial : public CScene
{
public:

	CTutorial();
	~CTutorial();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CTutorial *Create(void);

private:


};

#endif 