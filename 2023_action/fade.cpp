//=============================================================================
//
// �t�F�[�h���� [fade.cpp]
// Author : �匴�@�叫
//
//=============================================================================
#include "fade.h"
#include "texture.h"
#include "renderer.h"

//================================================================
//�R���X�g���N�^
//================================================================
CFade::CFade()
{
	m_fade = FADE_IN;
	m_modeNext = m_modeNext;
	m_Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_nIdxTexture = -1;
}

//================================================================
//�R���X�g���N�^(�I�[�o�[���[�h)
//================================================================
CFade::CFade(CScene::MODE modenext)
{
	m_fade = FADE_OUT;
	m_modeNext = modenext;
	m_Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
	m_nIdxTexture = -1;
}

//================================================================
//�f�X�g���N�^
//================================================================
CFade::~CFade()
{

}

//===========================================================
//�N���G�C�g
//===========================================================
CFade *CFade::Create(CScene::MODE modenext)
{
	//�n�ʂ̃|�C���^
	CFade *pFade = NULL;

	if (CObject::GetNumAll() < MAX_OBJECT)
	{
		if (pFade == NULL)
		{//�g�p����Ă��Ȃ�������

			//�I�u�W�F�N�g�𐶐�
			pFade = new CFade(modenext);

			pFade->Init();
		}
	}

	return pFade;
}

//================================================================
//�t�F�[�h�̏���������
//================================================================
HRESULT CFade::Init(void)
{
	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	m_nIdxTexture = -1;

	CRenderer *pRenderer;
	pRenderer = CManager::Getinstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���_�o�b�t�@�𐶐�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	//���_���ւ̃|�C���^
	VERTEX_2D * pVtx;

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//================================================================
//�t�F�[�h�̏I������
//================================================================
void CFade::Uninit(void)
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//�e�N�X�`���̏���
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//================================================================
//�t�F�[�h�̍X�V����
//================================================================
void CFade::Update(void)
{
	if (m_fade != FADE_NONE)
	{
		if (m_fade == FADE_IN)
		{
			m_Color.a -= 0.015f;

			if (m_Color.a <= 0.0f)
			{
				m_Color.a = 0.0f;
				m_fade = FADE_NONE;

				//Uninit();

				//return;
			}
		}

		else if (m_fade == FADE_OUT)
		{
			m_Color.a += 0.015f;

			if (m_Color.a >= 1.0f)
			{
				m_Color.a = 1.0f;

				m_fade = FADE_IN;

				CManager::Getinstance()->SetMode(m_modeNext);
			}
		}
	}

	//���_���ւ̃|�C���^
	VERTEX_2D * pVtx;

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, m_Color.a);
	pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, m_Color.a);
	pVtx[2].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, m_Color.a);
	pVtx[3].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, m_Color.a);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//================================================================
//�t�F�[�h�̕`�揈��
//================================================================
void CFade::Draw(void)
{
	CTexture *pTexture = CManager::Getinstance()->GetTexture();
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,    //�v���~�e�B�u�̎��
		0,                                         //�`�悷��ŏ��̒��_�C���f�b�N�X
		2                                          //�`�悷��v���~�e�B�u��
	);
}

//================================================================
//�t�F�[�h�̐ݒ菈��
//================================================================
void CFade::Set(CScene::MODE modeNext)
{
	m_fade = FADE_OUT;
	m_modeNext = modeNext;
	m_Color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
}