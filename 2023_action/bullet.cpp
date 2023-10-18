//===========================================================
//
//�|���S�����o�����[bullet.cpp]
//Author �匴�叫
//
//===========================================================
#include "main.h"
#include "player.h"
#include "renderer.h"
#include "manager.h"
#include "input.h"
#include "sound.h"
#include "bullet.h"
#include "effect.h"
#include "debugproc.h"
#include "texture.h"
#include "game.h"
#include "sound.h"
#include "collision.h"
#include "enemy.h"
#include "map.h"

//================================================================
//�}�N����`
//================================================================
#define BULLETMOVE       (-10.0f)    //�e�̈ړ���
#define BULLETPOS        (50.0f)     //�e�̈ʒu
#define BULLETLIFE       (120)       //�e�̎���
#define BULLET_WIDTH     (10.0f)     //�e�̕�
#define BULLET_HEIGHT    (20.0f)     //�e�̍���

//================================================================
//�ÓI�����o�ϐ��錾
//================================================================
//LPDIRECT3DTEXTURE9 CBullet::m_pTexture = NULL;
CBullet *CBullet::m_Bullet = NULL;

//================================================================
//�R���X�g���N�^
//================================================================
CBullet::CBullet()
{
	m_nLife = 0;
	m_nIdxTexture = -1;
	m_type = TYPE_NONE;
	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
}

//================================================================
//�R���X�g���N�^(�I�[�o�[���[�h)
//================================================================
CBullet::CBullet(D3DXVECTOR3 pos, D3DXVECTOR3 rot, TYPE type)
{
	SetPos(&pos);
	SetRot(&rot);
	m_type = type;
	m_nLife = 0;
	m_nIdxTexture = -1;
	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
}

//================================================================
//�f�X�g���N�^
//================================================================
CBullet::~CBullet()
{

}

//================================================================
//��������
//================================================================
CBullet *CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, TYPE type)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CBullet *pBullet = NULL;

	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	if (GetNumAll() < MAX_OBJECT)
	{
		if (pBullet == NULL)
		{
			//�I�u�W�F�N�g2D�̐���
			pBullet = new CBullet(pos, rot, type);

			//����������
			pBullet->Init();
		}
	}

	return pBullet;
}

//================================================================
//�o���b�g�̏���������
//================================================================
HRESULT CBullet::Init(void)
{
	//��ސݒ�
	SetType(TYPE_BULLET);

	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::Getinstance()->GetTexture();

	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\bom.png");

	//����������
	CBillBoard::Init();

	//�e�̎���
	m_nLife = BULLETLIFE;

	return S_OK;
}

//================================================================
//�o���b�g�̏I������
//================================================================
void CBullet::Uninit(void)
{
	//�I������
	CBillBoard::Uninit();
}

//================================================================
//�o���b�g�̍X�V����
//================================================================
void CBullet::Update(void)
{
	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();

	//�}�b�v���f���̏����擾
	CObjectX **pMap = CMap::GetX();

	//�����蔻��̏��擾
	CCollision *pCollision = CManager::Getinstance()->GetCollsion();

	//�v���C���[�̏��擾
	CPlayer *pPlayer = CGame::GetPlayerFoot();

	//�G�̏��擾
	CEnemy **pEnemy = CEnemy::GetEnemy();

	//�T�E���h�̏����擾
	CSound *pSound = CManager::Getinstance()->GetSound();

	//�ʒu����
	D3DXVECTOR3 pos = Getpos();

	//��������
	D3DXVECTOR3 rot = GetRot();

	//�O��̈ʒu���L�^
	m_posOld = pos;

	SetVtxBullet(pos, BULLET_WIDTH, BULLET_HEIGHT);

	//�ʒu���X�V
	pos.x += sinf(rot.y) * BULLETMOVE;

	//�X�V����
	CBillBoard::Update();

	//���������炷
	m_nLife--;

	switch (m_type)
	{
	case CBullet::TYPE_NONE:
		break;

	case CBullet::TYPE_PLAYER:

		if (pCollision->BulletEnemy(&pos, 20.0f, 100.0f, pEnemy) == true)
		{
			m_nLife = 0;
		}
		else if(pCollision->BulletMap(&pos, pMap) == true)
		{
			m_nLife = 0;
		}

		break;

	case CBullet::TYPE_ENEMY:
		break;

	case CBullet::TYPE_BOM:
		break;

	case CBullet::TYPE_MAX:
		break;

	default:
		break;
	}

	if (m_nLife <= 0)
	{//�������Ȃ��Ȃ�����

		//�����𐶐�
		//CExplosion::Create(pos);

		//�p�[�e�B�N���𐶐�
		//CParticl::Create(pos, {0.0f, 0.0f, 0.0f}, { 0.6f, 1.0f, 5.0f, 1.0f }, 5.0f, TYPEPAR_BULLET);

		//�I������
		CBullet::Uninit();
	}
	else
	{
		CEffect::Create({ pos.x, pos.y, pos.z }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 1.0f, 0.8f, 0.7f }, 5.0f, 15, CEffect::TYPEEFF_NONE);

		//�ʒu��ݒ�
		CBillBoard::SetPos(&pos);
	}
}

//================================================================
//�o���b�g�̕`�揈��
//================================================================
void CBullet::Draw(void)
{
	CTexture *pTexture = CManager::Getinstance()->GetTexture();
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//�`�揈��
	CBillBoard::Draw();
}

//================================================================
//�G�Ƃ̓����蔻��
//================================================================
bool CBullet::CollisionEnemy(D3DXVECTOR3 pos)
{
	//for (int nCount = 0; nCount < MAX_OBJECT; nCount++)
	//{
	//	CObject *pObj;

	//	//�I�u�W�F�N�g���擾
	//	pObj = Getobject(nCount);

	//	if (pObj != NULL)  //�킷��Ă�
	//	{
	//		//��ނ��擾
	//		TYPE type = pObj->GetType();
	//		
	//		if (type == TYPE_ENEMY)
	//		{//��ނ��G�̏ꍇ

	//			//�L���X�g���đ��
	//			CEnemy *pEnemy = (CEnemy*)pObj;

	//			D3DXVECTOR3 Enemypos = pEnemy->Getpos();

	//			if (pos.x >= Enemypos.x - 50.0f
	//			 && pos.x <= Enemypos.x + 50.0f
	//			 && pos.y >= Enemypos.y - 50.0f
	//			 && pos.y <= Enemypos.y + 50.0f)
	//			{
	//				//�����𐶐�
	//				//CExplosion::Create(pEnemy->GetPosition());

	//				CParticl::Create(pos, {0.6f, 1.0f, 5.0f, 1.0f}, 15.0f);

	//				CScore::AddScore(100);

	//				pObj->Uninit();

	//				//�I������
	//				Uninit();

	//				return true;
	//			}
	//			
	//		}
	//	}
	//}

	return false;
}