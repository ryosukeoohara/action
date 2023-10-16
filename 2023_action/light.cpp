//=============================================================================
//
// �J�������� [light.cpp]
// Author : �匴�@�叫
//
//=============================================================================

#include "main.h"
#include "light.h"
#include "renderer.h"
#include "manager.h"

//================================================================
//�R���X�g���N�^
//================================================================
CLight::CLight()
{
	
}

//================================================================
//�f�X�g���N�^
//================================================================
CLight::~CLight()
{

}

//================================================================
//�J�����̏���������
//================================================================
void CLight::Init(void)
{
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���C�g�̏����N���A����
	ZeroMemory(&m_light, sizeof(D3DLIGHT9));

	for (int nCntLight = 0; nCntLight < MAX_LIGHT; nCntLight++)
	{
		//���C�g�̎�ނ�ݒ�
		m_light[nCntLight].Type = D3DLIGHT_DIRECTIONAL;

		switch (nCntLight)
		{
		case 0:
			//���C�g�̊g�U�Z��ݒ�
			m_light[nCntLight].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			//���C�g�̕�����ݒ�
			m_vecDir[nCntLight] = D3DXVECTOR3(-0.04f, -0.24f, 0.97f);
			break;

		case 1:
			//���C�g�̊g�U�Z��ݒ�
			m_light[nCntLight].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			//���C�g�̕�����ݒ�
			m_vecDir[nCntLight] = D3DXVECTOR3(-0.34f, -0.85f, 0.41f);
			break;

		case 2:
			//���C�g�̊g�U�Z��ݒ�
			m_light[nCntLight].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			//���C�g�̕�����ݒ�
			m_vecDir[nCntLight] = D3DXVECTOR3(0.44f, -0.60f, -0.66f);
			break;
		}

		//�x�N�g���𐳋K������
		D3DXVec3Normalize(&m_vecDir[nCntLight], &m_vecDir[nCntLight]);

		m_light[nCntLight].Direction = m_vecDir[nCntLight];

		//���C�g��ݒ肷��
		pDevice->SetLight(nCntLight, &m_light[nCntLight]);

		//���C�g��L���ɂ���
		pDevice->LightEnable(nCntLight, TRUE);
	}
}

//================================================================
//�J�����̏I������
//================================================================
void CLight::Uninit(void)
{

}

//================================================================
//�J�����X�V����
//================================================================
void CLight::Update(void)
{

}