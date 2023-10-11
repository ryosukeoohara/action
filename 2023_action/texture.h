//=============================================================================
//
// �e�N�X�`������ [texture.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "main.h"

//�}�N����`
#define MAX_TEXTURE   (1024)   //�e�N�X�`���̍ő吔

class CTexture
{
public:
	CTexture();
	~CTexture();

	//�e�N�X�`���̎��
	typedef enum
	{
		TYPE_PLAYER = 0,  //�v���C���[
		TYPE_ENEMY,       //�G
		TYPE_BULLET,      //�e
		TYPE_MAX
	} TYPE;

	struct TEX
	{
		char aName[64] = "a";
		LPDIRECT3DTEXTURE9 m_pTexture;

	} ;

	HRESULT Load(void);
	void UnLoad(void);

	int Regist(const char *pFilename);
	LPDIRECT3DTEXTURE9 GetAddress(int nIdx);

	int GetNumTexture(void) { return m_nNumAll; };

private:
	
	TEX m_aTexture[MAX_TEXTURE];
	static int m_nNumAll;

	
};


#endif // !_TEXTURE_H_

