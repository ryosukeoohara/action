//===========================================================
//
//UI�}�l�[�W��[UImanager.h]
//Author �匴�叫
//
//===========================================================

//*==========================================================
//�C���N���[�h�t�@�C��
//*==========================================================
#include "UImanager.h"
#include "texture.h"
#include "manager.h"
#include "renderer.h"

//===========================================================
//�R���X�g���N�^
//===========================================================
CUIManager::CUIManager()
{
	//������
	m_type = TYPE_NONE;
	m_nIdxTexture = -1;
}

//===========================================================
//�R���X�g���N�^
//===========================================================
CUIManager::CUIManager(D3DXVECTOR3 pos, TYPE type)
{
	//������
	SetPos(&pos);
	m_type = type;
	m_nIdxTexture = -1;
}

//===========================================================
//�f�X�g���N�^
//===========================================================
CUIManager::~CUIManager()
{

}

//===========================================================
//��������
//===========================================================
CUIManager * CUIManager::Create(D3DXVECTOR3 pos, TYPE type)
{
	//UI�}�l�[�W���ւ̃|�C���^
	CUIManager *pUI = NULL;

	if (pUI == NULL)
	{//�g�p����Ă��Ȃ�������

		//����
		pUI = new CUIManager(pos, type);

		//����������
		pUI->Init();
	}

	return pUI;
}


//===========================================================
//����������
//===========================================================
HRESULT CUIManager::Init(void)
{
	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::GetTexture();

	//����������
	CObject2D::Init();

	switch (m_type)
	{
	case CUIManager::TYPE_NONE:     //�Ȃ���Ȃ�
		break;

	case CUIManager::TYPE_TITLE:    //�^�C�g��

		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\taitoru.jpg");
		break;

	case CUIManager::TYPE_RESULT:   //���U���g

		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\res.jpg");
		break;

	case CUIManager::TYPE_MAX:
		break;

	default:
		break;
	}

	return S_OK;
}

//===========================================================
//�I������
//===========================================================
void CUIManager::Uninit(void)
{
	//�I������
	CObject2D::Uninit();

	//���g�̔j��
	Release();
}

//===========================================================
//�X�V����
//===========================================================
void CUIManager::Update(void)
{
	//�X�V����
	CObject2D::Update();

	//�傫���Ƃ��ݒ�
	switch (m_type)
	{
	case CUIManager::TYPE_NONE:     //�Ȃ���Ȃ�
		break;

	case CUIManager::TYPE_TITLE:    //�^�C�g��

		CObject2D::SetVtxUI(Getpos(), 400.0f, 200.0f, { 1.0f,1.0f,1.0f,1.0f });
		break;

	case CUIManager::TYPE_RESULT:   //���U���g

		CObject2D::SetVtxUI(Getpos(), 400.0f, 200.0f, { 1.0f,1.0f,1.0f,1.0f });
		break;

	case CUIManager::TYPE_MAX:
		break;

	default:
		break;
	}
}

//===========================================================
//�`�揈��
//===========================================================
void CUIManager::Draw(void)
{
	//�e�N�X�`���̏����擾
	CTexture *pTexture = CManager::GetTexture();

	//�����_���[�̏����擾
	CRenderer *pRenderer = CManager::GetRenderer();

	//�f�o�C�X�̏����擾
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�e�N�X�`���ݒ�
	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//�`�揈��
	CObject2D::Draw();
}