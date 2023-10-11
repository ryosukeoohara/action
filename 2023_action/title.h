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

//�}�N����`
#define MAX_TITLEOBJ   (64)   //�^�C�g�����ł�2D�I�u�W�F�N�g�̍ő吔

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
	int m_nIdxTexture;                          //�e�N�X�`���̃C���f�b�N�X�ԍ�
	CObject2D *m_apObject2D[MAX_TITLEOBJ];      //2D�I�u�W�F�N�g�ւ̃|�C���^
	CObject3D *m_apObject3D[MAX_TITLEOBJ];      //3D�I�u�W�F�N�g�ւ̃|�C���^

};
#endif // !_TITLE_H_