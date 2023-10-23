//=============================================================================
//
// �����蔻�菈�� [collision.cpp]
// Author : �匴�@�叫
//
//=============================================================================

//*============================================================================
//�C���N���[�h�t�@�C��
//*============================================================================
#include "main.h"
#include "collision.h"
#include "renderer.h"
#include "manager.h"
#include "bullet.h"
#include "player.h"
#include "debugproc.h"
#include "collision.h"
#include "object.h"
#include "objectX.h"
#include "particl.h"
#include "game.h"
#include "map.h"
#include "enemy.h"
#include "particl.h"

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CCollision::CCollision()
{

}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CCollision::~CCollision()
{

}

//=============================================================================
//����������
//=============================================================================
HRESULT CCollision::Init(void)
{
	return S_OK;
}

//=============================================================================
//�I������
//=============================================================================
void CCollision::Uninit(void)
{
	
}

//=============================================================================
//�G�ƃI�u�W�F�N�g�̓����蔻�菈��
//=============================================================================
bool CCollision::Enemy(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, float fWidthX, float fWidthZ, CEnemy *pEnemy)
{
	////�f�o�b�O�v���b�N
	//CDebugProc *pDebugProc = CManager::GetDebugProc();

	//for (int nCount = 0; nCount < MAX_OBJECT; nCount++)
	//{
	//	CObject *pObj;

	//	//�I�u�W�F�N�g���擾
	//	pObj = CObject::Getobject(nCount);

	//	if (pObj != NULL)  //�킷��Ă�
	//	{
	//		//��ނ��擾
	//		CObject::TYPE type = pObj->GetType();

	//		if (type == TYPE_ENEMY)
	//		{//��ނ��G�̏ꍇ

	//		 //�L���X�g���đ��
	//			CEnemy *pEnemy = (CEnemy*)pObj;

	//			//�G�̈ʒu�擾
	//			D3DXVECTOR3 Enepos = pEnemy->Getpos();

	//			if (pos->x + fWidthX >= Enepos.x - 10.0f
	//				&& pos->x - fWidthX <= Enepos.x + 10.0f
	//				&& pos->z + fWidthZ >= Enepos.z - 10.0f
	//				&& pos->z - fWidthZ <= Enepos.z + 10.0f)
	//			{
	//				//����======================================
	//				if (pos->z + fWidthZ >= Enepos.z - 10.0f
	//				 && posOld->z + fWidthZ <= Enepos.z - 10.0f)
	//				{
	//					pos->z = Enepos.z - fWidthZ - 10.0f;

	//					pDebugProc->Print("���ʂ�������`\n");

	//					return true;
	//				}

	//				//�w��======================================
	//				else if (pos->z - fWidthZ <= Enepos.z + 10.0f
	//					&& posOld->z - fWidthZ >= Enepos.z + 10.0f)
	//				{
	//					pos->z = Enepos.z + fWidthZ + 10.0f;

	//					pDebugProc->Print("�w�ʂ�������`\n");

	//					return true;
	//				}

	//				//������߂荞��
	//				else if (pos->x + fWidthX >= Enepos.x - 10.0f
	//					&& pos->x - fWidthX <= Enepos.x + 10.0f)
	//				{
	//					//��==================================
	//					if (pos->x + fWidthX >= Enepos.x - 10.0f
	//						&& posOld->x + fWidthX <= Enepos.x - 10.0f)
	//					{
	//						pos->x = Enepos.x - fWidthX - 10.0f;

	//						pDebugProc->Print("����������`\n");

	//						return true;
	//					}

	//					//�E==================================
	//					else if (pos->x - fWidthX <= Enepos.x + 10.0f
	//						&& posOld->x - fWidthX >= Enepos.x + 10.0f)
	//					{
	//						pos->x = Enepos.x + fWidthX + 10.0f;

	//						pDebugProc->Print("�E��������`\n");

	//						return true;
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	return false;
}

//=============================================================================
//�e�ƃI�u�W�F�N�g�̓����蔻�菈��
//=============================================================================
bool CCollision::BulletEnemy(D3DXVECTOR3 *pos, float fWidthX, float fWidthY, CEnemy **pEnemy)
{
	//int nNumEnemy = CEnemyManager::GetNumAll();
	float c = 0.0f;

	for (int nCount = 0; nCount < 6; nCount++)
	{
		float EnemyfRadius = 50.0f;

		if (pEnemy[nCount] != NULL)
		{
			D3DXVECTOR3 Enepos = pEnemy[nCount]->Getpos();

			if (pos->x <= Enepos.x + fWidthX
			 && pos->x >= Enepos.x - fWidthX
			 && pos->y <= Enepos.y + fWidthY
			 && pos->y >= Enepos.y)
			{
				int nLife = pEnemy[nCount]->GetLife();

				nLife -= 10;

				pEnemy[nCount]->SetLife(nLife);

				D3DXVECTOR3 rot = pEnemy[nCount]->GetRot();

				//�p�[�e�B�N���𐶐�
				CParticl::Create({ Enepos.x, Enepos.y + 50.0f, Enepos.z }, { rot.x, rot.y, rot.z }, { 1.0f, 0.5f, 5.0f, 1.0f }, 5.0f, CParticl::TYPEPAR_BULLET);

				return true; 
			} 
		}
	}

	return false;
}

//=============================================================================
//�e�ƃI�u�W�F�N�g�̓����蔻�菈��
//=============================================================================
bool CCollision::BulletPlayer(D3DXVECTOR3 *pPos, float fWidthX, float fWidthZ, CPlayer *pPlayer)
{
	//if (pPlayer != NULL)
	//{//�g�p����Ă���Ƃ�

	//    //�G�̈ʒu�擾
	//	D3DXVECTOR3 pos = pPlayer->Getpos();

	//	if (pPos->x <= pos.x + fWidthX
	//	 && pPos->x >= pos.x - fWidthX
	//	 && pPos->z <= pos.z + fWidthZ
	//	 && pPos->z >= pos.z - fWidthZ)
	//	{
	//		D3DXVECTOR3 rot = pPlayer->GetRot();

	//		pPlayer->Hit();

	//		//�p�[�e�B�N���𐶐�
	//		CParticl::Create({ pos.x, pos.y + 50.0f, pos.z }, { rot.x, rot.y, rot.z }, { 1.0f, 0.5f, 5.0f, 1.0f }, 5.0f, TYPEPAR_BLOOD);

	//		return true;
	//	}
	//}


	return false;
}

//=============================================================================
//�e�ƃI�u�W�F�N�g�̓����蔻�菈��
//=============================================================================
bool CCollision::BulletMap(D3DXVECTOR3 * pos, CObjectX ** pObjectX)
{
	//�}�b�v�̏����擾
	CMap *pMap = CGame::GetMap();

	//�v���C���[(�N�\�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�v���C���[(�N�\�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	int nNumAll = pMap->GetnNumAll();

	for (int nCount = 0; nCount < nNumAll; nCount++)
	{
		if (pObjectX[nCount] != NULL)
		{
			D3DXVECTOR3 Mappos = pObjectX[nCount]->Getpos();

			D3DXVECTOR3 vtxMin = pObjectX[nCount]->GetVtxMin();

			D3DXVECTOR3 vtxMax = pObjectX[nCount]->GetVtxMax();

			if (pos->x > Mappos.x + vtxMin.x
			 && pos->x < Mappos.x + vtxMax.x
			 && pos->y > Mappos.y + vtxMin.y
			 && pos->y < Mappos.y + vtxMax.y
			 && pos->z > Mappos.z + vtxMin.z
			 && pos->z < Mappos.z + vtxMax.z)
			{
				return true;
			}
		}
	}

	return false;
}

//=============================================================================
//�~�̓����蔻�菈��
//=============================================================================
bool CCollision::Circle(D3DXVECTOR3 *pPos, float fRadius, CPlayer *pPlayer)
{
	D3DXVECTOR3 pos = pPlayer->Getpos();

	float PlayerfRadius = 50.0f;

	float circleX = pPos->x - pos.x;
	float circleZ = pPos->z - pos.z;
	float c = 0.0f;

	c = (float)sqrt(circleX * circleX + circleZ * circleZ);

	if (c <= fRadius + PlayerfRadius)
	{
		return true;
	}

	return false;
}

//=============================================================================
//�G�ƃI�u�W�F�N�g�̓����蔻�菈��
//=============================================================================
bool CCollision::Player(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, float fWidthX, float fWidthZ, CPlayer *pPlayer)
{
	if (pPlayer != NULL)
	{
		//�G�̈ʒu�擾
		D3DXVECTOR3 Playerpos = pPlayer->Getpos();

		if (pos->x + fWidthX >= Playerpos.x - 10.0f
		 && pos->x - fWidthX <= Playerpos.x + 10.0f
		 && pos->z + fWidthZ >= Playerpos.z - 10.0f
		 && pos->z - fWidthZ <= Playerpos.z + 10.0f)
		{
			////����======================================
			//if (pos->z >= Playerpos.z - 10.0f
			// && posOld->z <= Playerpos.z - 10.0f)
			//{
			//	return true;
			//}

			////�w��======================================
			//else if (pos->z  <= Playerpos.z + 10.0f
			//	  && posOld->z >= Playerpos.z + 10.0f)
			//{
			//	return true;
			//}

			////������߂荞��
			//else if (pos->x >= Playerpos.x - 10.0f
			//	  && pos->x <= Playerpos.x + 10.0f)
			//{
			//	//��==================================
			//	if (pos->x >= Playerpos.x - 10.0f
			//     && posOld->x <= Playerpos.x - 10.0f)
			//	{
			//		return true;
			//	}

			//	//�E==================================
			//	else if (pos->x <= Playerpos.x + 10.0f
			//		  && posOld->x >= Playerpos.x + 10.0f)
			//	{
			//		return true;
			//	}
			//}

			return true;
		}
	}

	return false;
}

//=============================================================================
//�}�b�v�ɂ��錚���Ƃ̓����蔻��
//=============================================================================
void CCollision::Map(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, CObjectX **pObjectX)
{
	//�}�b�v�̏����擾
	CMap *pMap = CGame::GetMap();

	//�v���C���[(�N�\�f�u)�̏����擾
	CFoot *pFoot = CGame::GetPlayerFoot();

	//�v���C���[(�N�\�f�u)�̏����擾
	CChibi *pChibi = CGame::GetPlayerChibi();

	CPlayer *pPlayer = CGame::GetPlayer();

	int nNumAll = pMap->GetnNumAll();

	for (int nCount = 0; nCount < nNumAll; nCount++)
	{
		if (pObjectX[nCount] != NULL)
		{
		    D3DXVECTOR3 Mappos = pObjectX[nCount]->Getpos();

			D3DXVECTOR3 vtxMin = pObjectX[nCount]->GetVtxMin();

			D3DXVECTOR3 vtxMax = pObjectX[nCount]->GetVtxMax();

			if (pos->x + 20.0f > Mappos.x + vtxMin.x
			 && pos->x - 20.0f < Mappos.x + vtxMax.x
			 && pos->y + 60.0f > Mappos.y + vtxMin.y
			 && pos->y < Mappos.y + vtxMax.y
			 && pos->z + 20.0f > Mappos.z + vtxMin.z
			 && pos->z - 20.0f < Mappos.z + vtxMax.z)
			{
				//�u���b�N�̏�======================================
				if (pos->y <= Mappos.y + vtxMax.y
				 && posOld->y >= Mappos.y + vtxMax.y)
				{
					pos->y = Mappos.y + vtxMax.y;

					if (pFoot->GetbAppr() == true)
					{
						pFoot->SetPos(pos);
						pFoot->SetMoveY(0.0f);
						pFoot->SetbJump(false);
						pFoot->SetbRand(true);
					}
					
					if (pChibi->GetbAppr() == true)
					{
						pChibi->SetPos(pos);
						pChibi->SetMoveY(0.0f);
						pChibi->SetbJump(false);
						pChibi->SetbRand(true);
					}
				}
				/*else
				{
					if (pFoot->GetbAppr() == true)
					{
						pFoot->SetbRand(false);
					}

					if (pChibi->GetbAppr() == true)
					{
						pChibi->SetbRand(false);
					}
				}*/

				//�u���b�N�̉�======================================
				else if (pos->y + 60.0f >= Mappos.y + vtxMin.y
					&& posOld->y + 60.0f <= Mappos.y + vtxMin.y)
				{
					pos->y = Mappos.y + vtxMin.y - 60.0f;

					if (pFoot->GetbAppr() == true)
					{
						pFoot->SetPos(pos);
						pFoot->SetMoveY(0.0f);
					}

					if (pChibi->GetbAppr() == true)
					{
						pChibi->SetPos(pos);
						pChibi->SetMoveY(0.0f);
					}
				}

				//�u���b�N�̍�����==================================
				if (pos->x + 20.0f >= Mappos.x + vtxMin.x
					&& posOld->x + 20.0f <= Mappos.x + vtxMin.x)
				{
					pos->x = Mappos.x + vtxMin.x - 20.0f;

					if (pFoot->GetbAppr() == true)
					{
						pFoot->SetPos(pos);
					}

					if (pChibi->GetbAppr() == true)
					{
						pChibi->SetPos(pos);
					}
				}

				//�u���b�N�̉E����==================================
				if (pos->x - 20.0f <= Mappos.x + vtxMax.x
					&& posOld->x - 20.0f >= Mappos.x + vtxMax.x)
				{
					pos->x = Mappos.x + vtxMax.x + 20.0f;

					if (pFoot->GetbAppr() == true)
					{
						pFoot->SetPos(pos);
					}

					if (pChibi->GetbAppr() == true)
					{
						pChibi->SetPos(pos);
					}
				}
			}
		}
	}
}

bool CCollision::Block(D3DXVECTOR3 * pos, D3DXVECTOR3 * posOld, float fWidthX, float fWidthZ)
{


	return false;
}

//=============================================================================
//���̓����蔻��
//=============================================================================
bool CCollision::Sword(D3DXMATRIX pos, D3DXMATRIX matrix, float flength, CEnemy **pEnemy)
{
	CRenderer *pRenderer = CManager::Getinstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	D3DXMATRIX Matrix;
	D3DXVECTOR3 offPos = { 0.0f, 0.0f, -flength };
	D3DXVECTOR3 Pos = { 0.0f, 0.0f, 0.0f };
	D3DXVECTOR3 offRot = { 0.0f, 0.0f, 0.0f };

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX m_mtxRot, m_mtxTrans;

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&Matrix);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&m_mtxRot, offRot.y, offRot.x, offRot.z);

	D3DXMatrixMultiply(&Matrix, &Matrix, &m_mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&m_mtxTrans, offPos.x, offPos.y, offPos.z);

	D3DXMatrixMultiply(&Matrix, &Matrix, &m_mtxTrans);

	//�Z�o�����p�[�c�̃��[���h�}�g���b�N�X�Ɛe�̃}�g���b�N�X���|�����킹��
	D3DXMatrixMultiply(&Matrix, &Matrix, &matrix);

	Pos.x = Matrix._41;
	Pos.y = Matrix._42;
	Pos.z = Matrix._43;

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &Matrix);

	for (int nCount = 0; nCount < 6; nCount++)
	{
		if (pEnemy[nCount] != NULL)
		{
			D3DXVECTOR3 Enepos = pEnemy[nCount]->Getpos();

			if ((pos._41 >= Enepos.x
			  && Pos.x <= Enepos.x
			  || pos._41 <= Enepos.x
			  && Pos.x >= Enepos.x)
			  && pos._42 >= Enepos.y
			  && Pos.y <= Enepos.y + 100.0f)
			{
				int nLife = pEnemy[nCount]->GetLife();

				nLife -= 30;

				pEnemy[nCount]->SetLife(nLife);

				D3DXVECTOR3 rot = pEnemy[nCount]->GetRot();

				//�p�[�e�B�N���𐶐�
				CParticl::Create({ Enepos.x, Enepos.y + 50.0f, Enepos.z }, { rot.x, rot.y, rot.z }, { 1.0f, 0.5f, 5.0f, 1.0f }, 5.0f, CParticl::TYPEPAR_BLOOD);

				return true;
			}
		}
	}

	return false;
}

//=============================================================================
//�}�b�v�ɂ��錚���Ƃ̓����蔻��
//=============================================================================
void CCollision::MapEnemy(D3DXVECTOR3 * pos, D3DXVECTOR3 * posOld, CObjectX ** pObjectX, CEnemy *penemy)
{
	//�}�b�v�̏����擾
	CMap *pMap = CGame::GetMap();

	int nNumAll = pMap->GetnNumAll();

	for (int nCount = 0; nCount < nNumAll; nCount++)
	{
		if (pObjectX[nCount] != NULL)
		{
			D3DXVECTOR3 Mappos = pObjectX[nCount]->Getpos();

			D3DXVECTOR3 vtxMin = pObjectX[nCount]->GetVtxMin();

			D3DXVECTOR3 vtxMax = pObjectX[nCount]->GetVtxMax();

			if (pos->x + 20.0f > Mappos.x + vtxMin.x
			 && pos->x - 20.0f < Mappos.x + vtxMax.x
			 && pos->y + 60.0f > Mappos.y + vtxMin.y
			 && pos->y < Mappos.y + vtxMax.y
			 && pos->z + 20.0f > Mappos.z + vtxMin.z
			 && pos->z - 20.0f < Mappos.z + vtxMax.z)
			{
				//�u���b�N�̏�======================================
				if (pos->y <= Mappos.y + vtxMax.y
					/*&& posOld->y >= Mappos.y + vtxMax.y*/)
				{
					pos->y = Mappos.y + vtxMax.y;

					penemy->SetPos(pos);
					penemy->SetMoveY(0.0f); 
				}
				//�u���b�N�̉�======================================
				else if (pos->y + 60.0f >= Mappos.y + vtxMin.y
					/*&& posOld->y + 60.0f <= Mappos.y + vtxMin.y*/)
				{
					pos->y = Mappos.y + vtxMin.y - 60.0f;

					penemy->SetPos(pos);
					penemy->SetMoveY(0.0f);
				}

				//�u���b�N�̍�����==================================
				if (pos->x + 20.0f >= Mappos.x + vtxMin.x
					/*&& posOld->x + 20.0f <= Mappos.x + vtxMin.x*/)
				{
					pos->x = Mappos.x + vtxMin.x - 20.0f;

					penemy->SetPos(pos);
					//penemy->SetMoveX(0.0f);
				}
				//�u���b�N�̉E����==================================
				else if (pos->x - 20.0f <= Mappos.x + vtxMax.x
					/*&& posOld->x - 20.0f >= Mappos.x + vtxMax.x*/)
				{
					pos->x = Mappos.x + vtxMax.x + 20.0f;

					penemy->SetPos(pos);
					//penemy->SetMoveX(0.0f);
				}
			}
		}
	}
}
