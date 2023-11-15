//===========================================================
//
//�|���S�����o�����[object.cpp]
//Author �匴�叫
//
//===========================================================
#include "object.h"
#include "renderer.h"
#include "manager.h"
#include "debugproc.h"
#include "camera.h"

CObject *CObject::m_apObjct[MAX_OBJECT] = {};
int CObject::m_nNumAll = 0;

////================================================================
////�R���X�g���N�^
////================================================================
//CObject::CObject()
//{
//	if (m_nNumAll < MAX_OBJECT)
//	{
//		for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
//		{
//			if (m_apObjct[nCntObject] == NULL)
//			{//�g�p����Ă��Ȃ�������
//
//				m_apObjct[nCntObject] = this;  //�������g����
//				m_nID = nCntObject;  //�������g��ID
//				m_nNumAll++;         //�������J�E���g�A�b�v
//				break;
//			}
//		}
//	}
//}
//
////================================================================
////�f�X�g���N�^
////================================================================
//CObject::~CObject()
//{
//	
//}
//
////================================================================
////���ׂẴI�u�W�F�N�g�̔j��
////================================================================
//void CObject::ReleaseAll(void)
//{
//	for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
//	{
//		if (m_apObjct[nCntObject] != NULL)
//		{
//			//�I������
//			m_apObjct[nCntObject]->Uninit();
//		}
//	}
//}
//
////================================================================
////���ׂẴI�u�W�F�N�g�̍X�V
////================================================================
//void CObject::UpdateAll(void)
//{
//	for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
//	{
//		if (m_apObjct[nCntObject] != NULL)
//		{
//			//�X�V����
//			m_apObjct[nCntObject]->Update();
//		}
//	}
//
//	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();
//
//	pDebugProc->Print("\n\n�I�u�W�F�N�g�̑����F%d", m_nNumAll);
//}
//
////================================================================
////���ׂẴI�u�W�F�N�g�̕`��
////================================================================
//void CObject::DrawAll(void)
//{
//	CCamera *pCamera = CManager::Getinstance()->GetCamera();
//
//	if (pCamera != NULL)
//	{
//		//�J�����̐ݒ�
//		pCamera->SetCamera();
//	}
//	
//	for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
//	{
//		if (m_apObjct[nCntObject] != NULL)
//		{
//			//�`�揈��
//			m_apObjct[nCntObject]->Draw();
//		}
//	}
//}
//
////================================================================
////�I�u�W�F�N�g�̔j��
////================================================================
//void CObject::Release(void)
//{
//	int nIdx = m_nID;
//
//	//�I�u�W�F�N�g�̔j��
//	if (m_apObjct[nIdx] != NULL)
//	{
//		//���������J��
//		delete m_apObjct[nIdx];
//
//		//�g�p���Ă��Ȃ���Ԃɂ���
//		m_apObjct[nIdx] = NULL;
//
//		m_nNumAll--;    //�������J�E���g�_�E��
//	}
//}
//
////================================================================
////�I�u�W�F�N�g�̎擾
////================================================================
//CObject *CObject::Getobject(int nIdx)
//{
//	return m_apObjct[nIdx];
//}

//================================================================
//�e�N�X�`���擾
//================================================================
//void CObject::BindTexture(LPDIRECT3DTEXTURE9 m_Texture)
//{
//	m_pTexture = m_Texture;
//}

CObject *CObject::m_pTop = NULL;
CObject *CObject::m_pCur = NULL;

//================================================================
//�R���X�g���N�^
//================================================================
CObject::CObject()
{
	m_bDeath = false;

	CObject *pObject = m_pTop;

	if (m_pTop == NULL)
	{
		m_pTop = this;

		m_pCur = this;
	}
	else if (m_pTop != NULL)
	{
		m_pPrev = m_pCur;
		m_pPrev->m_pNext = this;
		m_pCur = this;
	}
}

//================================================================
//�f�X�g���N�^
//================================================================
CObject::~CObject()
{

}

//================================================================
//���ׂẴI�u�W�F�N�g�̔j��
//================================================================
void CObject::ReleaseAll(void)
{
	CObject *pobject = m_pTop;

	while (pobject != NULL)
	{
		CObject *pObjectNext = pobject->m_pNext;

		if (pobject->m_bDeath == true)
		{
			pobject->m_pPrev->m_pNext = pobject->m_pNext;

			if (pobject->m_pNext != NULL)
			{
				pobject->m_pNext->m_pPrev = pobject->m_pPrev;
			}
			else
			{
				m_pCur = pobject->m_pPrev;
			}

			delete pobject;
			pobject = NULL;
		}

		pobject = pObjectNext;
	}
}

//================================================================
//���ׂẴI�u�W�F�N�g�̍X�V
//================================================================
void CObject::UpdateAll(void)
{
	CObject *pObject = m_pTop;

	while (pObject != NULL)
	{
		CObject *pObjectNext = pObject->m_pNext;

		pObject->Update();
		pObject = pObjectNext;
	}

	CObject *pobject = m_pTop;

	while (pobject != NULL)
	{
		CObject *pObjectNext = pobject->m_pNext;

		if (pobject->m_bDeath == true)
		{
			pobject->m_pPrev->m_pNext = pobject->m_pNext;

			if (pobject->m_pNext != NULL)
			{
				pobject->m_pNext->m_pPrev = pobject->m_pPrev;
			}
			else
			{
				m_pCur = pobject->m_pPrev;
			}

			delete pobject;
			pobject = NULL;
		}

		pobject = pObjectNext;
	}

	CDebugProc *pDebugProc = CManager::Getinstance()->GetDebugProc();

	pDebugProc->Print("\n\n�I�u�W�F�N�g�̑����F%d", m_nNumAll);
}

//================================================================
//���ׂẴI�u�W�F�N�g�̕`��
//================================================================
void CObject::DrawAll(void)
{
	CCamera *pCamera = CManager::Getinstance()->GetCamera();

	//�J�����̐ݒ�
	pCamera->SetCamera();

	CObject *pObject = m_pTop;

	while (pObject != NULL)
	{
		CObject *pObjectNext = pObject->m_pNext;

		pObject->Draw();
		pObject = pObjectNext;
	}
}

//================================================================
//�I�u�W�F�N�g�̔j��
//================================================================
void CObject::Release(void)
{
	CObject *pObject = this;

	if (pObject->m_bDeath == false)
	{
		pObject->m_bDeath = true;
	}
}

//================================================================
//�I�u�W�F�N�g�̎擾
//================================================================
CObject *CObject::Getobject(int nIdx)
{
	return m_apObjct[nIdx];
}