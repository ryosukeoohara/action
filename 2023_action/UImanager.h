//===========================================================
//
//UI�}�l�[�W��[UImanager.h]
//Author �匴�叫
//
//===========================================================
#ifndef _UIMANAGER_H_
#define _UIMANAGER_H_

//*==========================================================
//�C���N���[�h�t�@�C��
//*==========================================================
#include "object2D.h"

//*==========================================================
//�N���X��`
//*==========================================================
class CUIManager : CObject2D
{
public:

	//���
	enum TYPE
	{
		TYPE_NONE = 0,                              //�Ȃ���Ȃ�
		TYPE_TITLE,                                 //�^�C�g��
		TYPE_RESULT,                                //���U���g
		TYPE_GUNGAGE,                               //�e�̎c�e�\��
		TYPE_LIFEFOOT,                              //�̗�
		TYPE_LIFECHIBI,                             //�̗�
		TYPE_ICONFOOT,                              //�f�u�̊�A�C�R��
		TYPE_ICONCHIBI,                             //�`�r�̊�A�C�R��
		TYPE_MAGIC,                                 //���@
		TYPE_TITLESELECT,                           //�Q�[���X�^�[�g
		TYPE_RANK,                                  //����
		TYPE_SCORE,                                 //�����L���O�̏�̌��o��
		TYPE_PAUSEFRAME,                            //�|�[�Y�̃t���[��
		TYPE_COUTINUE,                              //�Q�[���ɖ߂�
		TYPE_RETRY,                                 //�Q�[������蒼��
		TYPE_QUIT,                                  //�^�C�g����ʂɖ߂�
		TYPE_MAX							        
	};

	CUIManager();                                   //�R���X�g���N�^
	CUIManager(D3DXVECTOR3 pos, TYPE type);         //�R���X�g���N�^
	~CUIManager();                                  //�f�X�g���N�^

	HRESULT Init(void);                             //����������
	void Uninit(void);                              //�I������
	void Update(void);                              //�X�V����
	void Draw(void);                                //�`�揈��

	static CUIManager *Create(D3DXVECTOR3 pos, TYPE type); //��������

private:
	TYPE m_type;                                    //���
	int m_nIdxTexture;                              //�e�N�X�`���̃C���f�b�N�X�ԍ�
};

#endif // !_UIMANAGER_H_