//=============================================================================
//
// �e�N�X�`������ [texture.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _SKY_H_
#define _SKY_H_

#include "main.h"
#include "objectX.h"

class CSky : public CObjectX
{
public:
	CSky();                //�R���X�g���N�^
	CSky(D3DXVECTOR3 pos); //�R���X�g���N�^
	~CSky();               //�f�X�g���N�^

	HRESULT Init(void);    //��̏���������    
	void Uninit(void);     //��̏I������
	void Update(void);     //��̍X�V����
	void Draw(void);       //��̕`�揈��

	static CSky *Create(D3DXVECTOR3 pos);  //����

private:
	int m_nIdxTexture;     //�e�N�X�`���̃C���f�b�N�X�ԍ�
	CObjectX *m_pObjectX;  //�I�u�W�F�N�gX�ւ̃|�C���^
};

#endif // !_TEXTURE_H_