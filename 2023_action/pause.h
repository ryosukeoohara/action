//=============================================================================
//
// �|�[�Y���� [pause.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _PAUSE_H_             //���̃}�N����`������ĂȂ�������
#define _PAUSE_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "object2D.h"

//�}�N����`
#define MAX_PAUSEOBJ   (5)

class CPause : public CObject
{
public:
	CPause();                                  //�R���X�g���N�^
	~CPause();                                 //�f�X�g���N�^
								               
	//�|�[�Y���j���[				            
	typedef enum				               
	{
		MENU_BACK = 0, 
		MENU_FRAME,
		MENU_COUTINUE,                         //�Q�[���ɖ߂�
		MENU_RETRY,                            //�Q�[������蒼��
		MENU_QUIT,                             //�^�C�g����ʂɖ߂�
		MENU_MAX			               
	} PAUSE_MENU;	

	struct COL
	{
		D3DXCOLOR col;
	};

	//�\����
	struct PAUSE
	{
		CObject2D *pBackGround;   //��Ԍ��ɏo�������w�i
		CObject2D *pFrame;        //�|�[�Y�̃t���[��
		CObject2D *pContinue;     //������
		CObject2D *pReStart;      //��蒼��
		CObject2D *pTitleBack;    //�^�C�g���ɖ߂�
		
	};

	HRESULT Init(void);                        //�|�[�Y����������    
	void Uninit(void);                         //�|�[�Y�I������
	void Update(void);                         //�|�[�Y�X�V����
	void Draw(void);                           //�|�[�Y�`�揈��
							                   
private:					                   
	int m_nIdxTexture[MAX_PAUSEOBJ];           //�e�N�X�`���̃C���f�b�N�X�ԍ�

	CObject2D *m_Object2D[MAX_PAUSEOBJ];       //�I�u�W�F�N�g2D�ւ̃|�C���^
	PAUSE m_Pause;                             //�|�[�Y�̍\����
	PAUSE_MENU m_pauseMenu;                    //�|�[�Y���j���[
	COL m_Color[5];
	bool m_bPause;                             //�|�[�Y�����ǂ���

};

#endif