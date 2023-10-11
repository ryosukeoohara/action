//===========================================================
//
//�G�f�B�b�g[edit.cpp]
//Author �匴�叫
//
//===========================================================
#include "edit.h"
#include "renderer.h"
#include "manager.h"
#include "input.h"
#include "debugproc.h"
#include "camera.h"
#include "player.h"

#include <stdio.h>
#include<string.h>

//�}�N����`
#define MODEL_SET_TEXT  ("data\\TEXT\\model_set.txt")
#define MODEL  ("data\\TEXT\\model.txt")
#define MOVE   (1.0f)  //�ړ���

//===========================================================
//�R���X�g���N�^
//===========================================================
CEdit::CEdit()
{
	//m_pos = { 0.0f, 0.0f, 0.0f };
	m_nIdx = 0;
	m_nNumAll = 0;
	m_SetModel = 0;
	m_nSelectModel = 0;
	m_mode = MODE_CREATE;
}

//===========================================================
//�f�X�g���N�^
//===========================================================
CEdit::~CEdit()
{

}

//===========================================================
//����������
//===========================================================
HRESULT CEdit::Init(void)
{
	//�S����NULL�����
	for (int nCount = 0; nCount < MAX_MODELSET; nCount++)
	{
		m_apModel[nCount] = NULL;
	}

	//�e�L�X�g�t�@�C���ǂݍ���
	ReadText();

	//X�t�@�C���ǂݍ���
	XLoad();

	return S_OK;
}

//===========================================================
//�I������
//===========================================================
void CEdit::Uninit(void)
{
	for (int nCount = 0; nCount < m_SetModel; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{
			//����������
			m_apModel[nCount]->Uninit();

			m_apModel[nCount] = NULL;
		}
	}

	for (int nCount = 0; nCount < m_nNumAll; nCount++)
	{
		if (m_Model[nCount].m_pTexture != NULL)
		{
			m_Model[nCount].m_pTexture = NULL;
		}
	}

	for (int nCount = 0; nCount < m_nNumAll; nCount++)
	{
		//�e�N�X�`���̏���
		if (m_Model[nCount].m_pMesh != NULL)
		{
			m_Model[nCount].m_pMesh->Release();
			m_Model[nCount].m_pMesh = NULL;
		}
	}

	for (int nCount = 0; nCount < m_nNumAll; nCount++)
	{
		//���_�o�b�t�@�̔j��
		if (m_Model[nCount].m_pBuffMat != NULL)
		{
			m_Model[nCount].m_pBuffMat->Release();
			m_Model[nCount].m_pBuffMat = NULL;
		}
	}

	CObject::Release();
}

//===========================================================
//�X�V����
//===========================================================
void CEdit::Update(void)
{
	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	//�L�[�{�[�h�̏����擾
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	pDebugProc->Print("\n---�G�f�B�b�g�̏��---");
	pDebugProc->Print("\n<<���[�h�̐؂�ւ� : F2>>");

	if (m_mode == MODE_CREATE)
	{//���݂̃��[�h���N���G�C�g���[�h��������

		pDebugProc->Print("\n<<���݂̃��[�h : �N���G�C�g>>");
	}

	if (m_mode == MODE_DELETE)
	{//���݂̃��[�h���f���[�g���[�h��������

		pDebugProc->Print("\n<<���݂̃��[�h : �f���[�g>>");
	}

	for (int nCount = 0; nCount < MAX_MODELSET; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{//�g�p����Ă�����

			//�X�V����
			m_apModel[nCount]->Update();
		}
	}

	if (InputKeyboard->GetTrigger(DIK_F2) == true)
	{//F2�L�[�������ꂽ

		if (m_mode == MODE_CREATE)
		{//���݂̃��[�h���N���G�C�g���[�h��������

			m_mode = MODE_DELETE;  //���[�h���f���[�g�ɂ���
		}

		else if (m_mode == MODE_DELETE)
		{//���݂̃��[�h���f���[�g���[�h��������

			m_mode = MODE_CREATE;  //���[�h���N���G�C�g�ɂ���
		}
	}

	switch (m_mode)
	{
	case MODE_CREATE:  //�z�u

		//���䏈��
		Control();

		break;

	case MODE_DELETE:  //�u�������̏���

		//�Z�b�g�������f������������
		SetModelDelete();

		break;
	}
}

//===========================================================
//�`�揈��
//===========================================================
void CEdit::Draw(void)
{
	for (int nCount = 0; nCount < MAX_MODELSET; nCount++)
	{
		if (m_apModel[nCount] != NULL)
		{//�g�p����Ă�����

			//�`�揈��
			m_apModel[nCount]->Draw();
		}
	}

	//�f�o�C�X�̎擾
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//���u�����f�B���O�����Z���v�ɐݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX m_mtxRot, m_mtxTrans;

	//���݂̃}�e���A���ۑ��p
	D3DMATERIAL9 matDef;

	//�}�e���A���f�[�^�ւ̃|�C���^
	D3DXMATERIAL *pMat;

	if (m_mode == MODE_CREATE)
	{//���݂̃��[�h���N���G�C�g���[�h��������

		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_Model[m_nIdx].m_mtxWorld);

		//�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&m_mtxRot, m_Model[m_nIdx].m_rot.y, m_Model[m_nIdx].m_rot.x, m_Model[m_nIdx].m_rot.z);

		D3DXMatrixMultiply(&m_Model[m_nIdx].m_mtxWorld, &m_Model[m_nIdx].m_mtxWorld, &m_mtxRot);

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&m_mtxTrans, m_Model[m_nIdx].m_pos.x, m_Model[m_nIdx].m_pos.y, m_Model[m_nIdx].m_pos.z);

		D3DXMatrixMultiply(&m_Model[m_nIdx].m_mtxWorld, &m_Model[m_nIdx].m_mtxWorld, &m_mtxTrans);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &m_Model[m_nIdx].m_mtxWorld);

		//���݂̃}�e���A�����擾
		pDevice->GetMaterial(&matDef);

		//�}�e���A���f�[�^�ւ̃|�C���^���擾
 		pMat = (D3DXMATERIAL*)m_Model[m_nIdx].m_pBuffMat->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)m_Model[m_nIdx].m_dwNumMat; nCntMat++)
		{
			pMat[nCntMat].MatD3D.Diffuse.a = 0.2f;

			//�}�e���A���̐ݒ�
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, *&m_Model[m_nIdx].m_pTexture[nCntMat]);

			//���f��(�p�[�c)�̕`��
			m_Model[m_nIdx].m_pMesh->DrawSubset(nCntMat);
		}

		//�ۑ����Ă����}�e���A����߂�
		pDevice->SetMaterial(&matDef);
	}

	//���u�����f�B���O�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//===========================================================
//�Z�[�u����
//===========================================================
void CEdit::Save(void)
{
	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	FILE * pFile;

	pFile = fopen(MODEL, "w");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		fprintf(pFile, "SCRIPT\n");

		fprintf(pFile, "\n");

		for (int nCount = 0; nCount < m_SetModel; nCount++)
		{
			D3DXVECTOR3 pos = m_apModel[nCount]->Getpos();  //�ʒu�擾
			D3DXVECTOR3 rot = m_apModel[nCount]->GetRot();  //�����擾

			fprintf(pFile, "MODELSET\n");
			fprintf(pFile, "    TYPE = %d\n", m_apModel[nCount]->GetType());        //���
			fprintf(pFile, "    POS = %.2f %.2f %.2f\n", pos.x, pos.y, pos.z);      //�ʒu
			fprintf(pFile, "    ROT = %.2f %.2f %.2f\n", rot.x, rot.y, rot.z);      //����
			fprintf(pFile, "END_MODELSET\n");
			fprintf(pFile, "\n");
		}

		fprintf(pFile, "END_SCRIPT\n");

		//�t�@�C�������
		fclose(pFile);
	}

	pDebugProc->Print("\n�ۑ�������`");
}

//===========================================================
//X�t�@�C�����[�h����
//===========================================================
void CEdit::XLoad(void)
{
	for (int nCount = 0; nCount < m_nNumAll; nCount++)
	{
		int nNumVtx;      //���_��
		DWORD dwSizeFVF;  //���_�t�H�[�}�b�g�̃T�C�Y
		BYTE *pVtxBuff;   //���_�o�b�t�@�ւ̃|�C���^

						  //�f�o�C�X�̎擾
		CRenderer *pRenderer = CManager::GetRenderer();
		LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

		//X�t�@�C���ǂݍ���
		D3DXLoadMeshFromX(m_Model[nCount].m_filename,
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&m_Model[nCount].m_pBuffMat,
			NULL,
			&m_Model[nCount].m_dwNumMat,
			&m_Model[nCount].m_pMesh);

		//���_�����擾
		nNumVtx = m_Model[nCount].m_pMesh->GetNumVertices();

		//���_�t�H�[�}�b�g�̃T�C�Y���擾
		dwSizeFVF = D3DXGetFVFVertexSize(m_Model[nCount].m_pMesh->GetFVF());

		if (m_Model[nCount].m_pTexture == NULL)
		{
			m_Model[nCount].m_pTexture = new LPDIRECT3DTEXTURE9[(int)m_Model[nCount].m_dwNumMat];
		}

		//�}�e���A���ւ̃|�C���^
		D3DXMATERIAL *pMat;

		//�}�e���A�����ɑ΂���|�C���^���擾
		pMat = (D3DXMATERIAL*)m_Model[nCount].m_pBuffMat->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)m_Model[nCount].m_dwNumMat; nCntMat++)
		{
			if (pMat[nCntMat].pTextureFilename != NULL)
			{//�e�N�X�`�������݂���

				D3DXCreateTextureFromFile(pDevice,
					pMat[nCntMat].pTextureFilename,
					&m_Model[nCount].m_pTexture[nCntMat]);
			}
			else
			{
				m_Model[nCount].m_pTexture[nCntMat] = NULL;
			}
		}

		//���_�o�b�t�@�����b�N
		m_Model[nCount].m_pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

		for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
		{
			D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;     //���_���W�̑��

														   //�ŏ��l-------------------------------------------------
			if (m_Model[nCount].m_vtxMini.x > vtx.x)
			{
				m_Model[nCount].m_vtxMini.x = vtx.x;
			}

			if (m_Model[nCount].m_vtxMini.y > vtx.y)
			{
				m_Model[nCount].m_vtxMini.y = vtx.y;
			}

			if (m_Model[nCount].m_vtxMini.z > vtx.z)
			{
				m_Model[nCount].m_vtxMini.z = vtx.z;
			}

			//�ő�l-------------------------------------------------
			if (m_Model[nCount].m_vtxMax.x < vtx.x)
			{
				m_Model[nCount].m_vtxMax.x = vtx.x;
			}

			if (m_Model[nCount].m_vtxMax.y < vtx.y)
			{
				m_Model[nCount].m_vtxMax.y = vtx.y;
			}

			if (m_Model[nCount].m_vtxMax.z < vtx.z)
			{
				m_Model[nCount].m_vtxMax.z = vtx.z;
			}

			pVtxBuff += dwSizeFVF;    //���_�t�H�[�}�b�g�̃T�C�Y���|�C���^��i�߂�
		}

		//���_�o�b�t�@���A�����b�N
		m_Model[nCount].m_pMesh->UnlockVertexBuffer();
	}
}

//===========================================================
//�}�b�v�t�@�C�����[�h����
//===========================================================
void CEdit::TEXTLoad(void)
{
	char aString[128] = {};
	char aComment[128] = {};
	int nCntModel = 0;
	int ntype = 0;

	FILE *pFile;   //�t�@�C���|�C���^��錾

	pFile = fopen(MODEL, "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		fscanf(pFile, "%s", &aString[0]);

		if (strcmp("SCRIPT", aString) == 0)
		{
			while (strcmp("END_SCRIPT", aString) != 0)
			{
				fscanf(pFile, "%s", &aString[0]);

				if (strcmp("MODELSET", aString) == 0)
				{
					while (strcmp("END_MODELSET", aString) != 0)
					{
						fscanf(pFile, "%s", &aString[0]);

						if (strcmp("TYPE", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);   //=
							fscanf(pFile, "%d", &ntype);     //���
						}

						if (strcmp("POS", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);          //=
							fscanf(pFile, "%f", &m_Model[ntype].m_pos.x);  //�ʒu
							fscanf(pFile, "%f", &m_Model[ntype].m_pos.y);  //�ʒu
							fscanf(pFile, "%f", &m_Model[ntype].m_pos.z);  //�ʒu
						}

						if (strcmp("ROT", aString) == 0)
						{
							fscanf(pFile, "%s", &aString);          //=
							fscanf(pFile, "%f", &m_Model[ntype].m_rot.x);  //�ʒu
							fscanf(pFile, "%f", &m_Model[ntype].m_rot.y);  //�ʒu
							fscanf(pFile, "%f", &m_Model[ntype].m_rot.z);  //�ʒu

																		   //�I�u�W�F�N�gX�𐶐�
							m_apModel[m_SetModel] = CObjectX::Create(m_Model[ntype].m_pos, m_Model[ntype].m_rot, m_Model[ntype].m_filename);

							//��ސݒ�
							m_apModel[m_SetModel]->SetIdxModel(ntype);

							m_SetModel++;  //�J�E���g�A�b�v
						}
					}
				}  //NUM_MODEL�̂�����
			}
		}

		//�t�@�C�������
		fclose(pFile);
	}
}

//===========================================================
//�e�L�X�g�t�@�C���ǂݍ���
//===========================================================
void CEdit::ReadText(void)
{
	char aString[128] = {};
	char aComment[128] = {};
	int nCntModel = 0;

	FILE *pFile;   //�t�@�C���|�C���^��錾

	pFile = fopen(MODEL_SET_TEXT, "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		fscanf(pFile, "%s", &aString[0]);

		if (strcmp("SCRIPT", aString) == 0)
		{
			while (strcmp("END_SCRIPT", aString) != 0)
			{
				fscanf(pFile, "%s", &aString[0]);

				if (strcmp("NUM_MODEL", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%d", &m_nNumAll);  //���f���̑���

				}  //NUM_MODEL�̂�����

				if (strcmp("MODEL_FILENAME", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%s", &m_Model[nCntModel].m_filename[0]);  //���f���̖��O
					m_Model[nCntModel].m_nType = nCntModel;

					nCntModel++;

				}  //MODEL_LILENAME�̂�����
			}
		}

		//�t�@�C�������
		fclose(pFile);
	}
}

//===========================================================
//���䏈��
//===========================================================
void CEdit::Control(void)
{
	//�L�[�{�[�h�̏����擾
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	//�J�����擾
	CCamera *pCamera = CManager::GetCamera();

	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	//�J�����̌����擾
	D3DXVECTOR3 CameraRot = pCamera->GetRot();

	if (InputKeyboard->GetTrigger(DIK_1) == true)
	{//1�L�[�������ꂽ

		if (m_nIdx > -1)
		{//�C���f�b�N�X�ԍ���-1���傫���Ƃ�

			m_nIdx -= 1;  //�C���f�b�N�X�ԍ�����߂�
		}

		if (m_nIdx < 0)
		{//�C���f�b�N�X�ԍ���0��菬�����Ƃ�

			m_nIdx = m_nNumAll - 1;  //�C���f�b�N�X�ԍ��𑍐�-1�ɂ���
		}
	}

	if (InputKeyboard->GetTrigger(DIK_2) == true)
	{//2�L�[�������ꂽ

		if (m_nIdx < m_nNumAll)
		{//�C���f�b�N�X�ԍ���������菬�����Ƃ�

			m_nIdx += 1;  //�C���f�b�N�X�ԍ�����i�߂�
		}

		if (m_nIdx >= m_nNumAll)
		{//�C���f�b�N�X�ԍ��������ȏ�ɂȂ����Ƃ�

			m_nIdx = 0;  //�C���f�b�N�X�ԍ���0�ɂ���
		}
	}

	if (InputKeyboard->GetTrigger(DIK_L) == true)
	{//ENTER�L�[�������ꂽ

		for (int nCount = 0; nCount < MAX_MODELSET; nCount++)
		{
			if (m_apModel[nCount] == NULL)
			{//�g�p����Ă��Ȃ��Ƃ�

			 //�I�u�W�F�N�gX�𐶐�
				m_apModel[nCount] = CObjectX::Create(m_Model[m_nIdx].m_pos, m_Model[m_nIdx].m_rot, m_Model[m_nIdx].m_filename);

				//��ސݒ�
				m_apModel[nCount]->SetIdxModel(m_nIdx);

				//�������J�E���g�A�b�v
				m_SetModel++;

				break;
			}
		}
	}

	if (InputKeyboard->GetTrigger(DIK_F7) == true)
	{//F8�L�[�������ꂽ

		for (int nCount = 0; nCount < m_SetModel; nCount++)
		{
			if (m_apModel[nCount] != NULL)
			{//�g�p����Ă���Ƃ�

			 //�I������
				m_apModel[nCount]->Uninit();

				//���������J��
				delete m_apModel[nCount];

				//�g�p���Ă��Ȃ���Ԃɂ���
				m_apModel[nCount] = NULL;
			}
		}

		m_SetModel = 0;
	}

	if (InputKeyboard->GetTrigger(DIK_F8) == true)
	{//F8�L�[�������ꂽm_Model[m_nIdx].m_move

	 //�O���t�@�C�������o��
		Save();
	}

	if (InputKeyboard->GetTrigger(DIK_F9) == true)
	{//F8�L�[�������ꂽm_Model[m_nIdx].m_move

	 //�}�b�v�t�@�C���ǂݍ���
		TEXTLoad();
	}

	//��Ɉړ�----------------------------------------------
	if (InputKeyboard->GetPress(DIK_UP) == true)
	{//W�L�[�������ꂽ

		m_Model[m_nIdx].m_move.y += cosf(CameraRot.y) * MOVE;
	}
	//���Ɉړ�----------------------------------------------
	else if (InputKeyboard->GetPress(DIK_DOWN) == true)
	{//S�L�[�������ꂽ

		m_Model[m_nIdx].m_move.y -= cosf(CameraRot.y) * MOVE;
	}

	//�E�Ɉړ�----------------------------------------------
	if (InputKeyboard->GetPress(DIK_RIGHT) == true)
	{//D�L�[����������

		//�ړ���
		m_Model[m_nIdx].m_move.x += sinf(CameraRot.y + (-D3DX_PI * 0.5f)) * MOVE;
	}
	//���Ɉړ�----------------------------------------------
	else if (InputKeyboard->GetPress(DIK_LEFT) == true)
	{//A�L�[����������

		//�ړ���
		m_Model[m_nIdx].m_move.x += sinf(CameraRot.y + (D3DX_PI * 0.5f)) * MOVE;
	}

	if (InputKeyboard->GetPress(DIK_U) == true)
	{//U�L�[��������

		m_Model[m_nIdx].m_rot.y += 0.01f;
	}

	if (InputKeyboard->GetPress(DIK_I) == true)
	{//I�L�[��������

		m_Model[m_nIdx].m_rot.y -= 0.01f;
	}

	if (InputKeyboard->GetTrigger(DIK_O) == true)
	{//O�L�[��������

		m_Model[m_nIdx].m_rot.y = 0.0f;
	}

	if (m_Model[m_nIdx].m_rot.y > D3DX_PI)
	{
		m_Model[m_nIdx].m_rot.y = -D3DX_PI;
	}

	else if (m_Model[m_nIdx].m_rot.y < -D3DX_PI)
	{
		m_Model[m_nIdx].m_rot.y = D3DX_PI;
	}

	//�ړ��ʂ��X�V(����������)--------------------------------------------
	m_Model[m_nIdx].m_move.x += (0.0f - m_Model[m_nIdx].m_move.x) * 0.5f;
	m_Model[m_nIdx].m_move.y += (0.0f - m_Model[m_nIdx].m_move.y) * 0.5f;

	//�ړ��ʉ��Z
	m_pos.x += m_Model[m_nIdx].m_move.x;
	m_pos.y += m_Model[m_nIdx].m_move.y;

	//�ʒu����
	m_Model[m_nIdx].m_pos = m_pos;

	pDebugProc->Print("\n<< �I�u�W�F�N�g�̈ʒu�FX��<%f>,Y��<%f>,Z��<%f> >>", m_Model[m_nIdx].m_pos.x, m_Model[m_nIdx].m_pos.y, m_Model[m_nIdx].m_pos.z);
	pDebugProc->Print("\n<< �I�u�W�F�N�g�̌����FX��<%f>,Y��<%f>,Z��<%f> >>", m_Model[m_nIdx].m_rot.x, m_Model[m_nIdx].m_rot.y, m_Model[m_nIdx].m_rot.z);
	pDebugProc->Print("\n<< ���݂̃I�u�W�F�N�g�̔ԍ��F%d/%d >>", m_nIdx, m_nNumAll);
	pDebugProc->Print("\n<< �ݒu�����I�u�W�F�N�g�̐��F%d >>", m_SetModel);
	pDebugProc->Print("\n<< �z�u���Z�b�g�FF7 >>");
	pDebugProc->Print("\n<< �O���t�@�C�������o���FF8 >>");
	pDebugProc->Print("\n<< �O���t�@�C���ǂݍ��݁FF9 >>");
	pDebugProc->Print("\n<< ���f���̐��� : U/I >>");
	pDebugProc->Print("\n<< ���f���̌������Z�b�g : O >>");
}

//===========================================================
//�Z�b�g�������f������������
//===========================================================
void CEdit::SetModelDelete(void)
{
	//�L�[�{�[�h�̏����擾
	CInputKeyboard *InputKeyboard = CManager::GetKeyBoard();

	//�f�o�b�O�v���b�N�̏����擾
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	if (InputKeyboard->GetTrigger(DIK_1) == true)
	{//1�L�[�������ꂽ

		if (m_nSelectModel > -1)
		{//�C���f�b�N�X�ԍ���-1���傫���Ƃ�

			m_nSelectModel -= 1;  //�C���f�b�N�X�ԍ�����߂�
		}
	}

	if (m_nSelectModel < 0)
	{//�C���f�b�N�X�ԍ���0��菬�����Ƃ�

		m_nSelectModel = m_SetModel - 1;  //�C���f�b�N�X�ԍ��𑍐�-1�ɂ���
	}

	if (InputKeyboard->GetTrigger(DIK_2) == true)
	{//2�L�[�������ꂽ

		if (m_nSelectModel < m_SetModel)
		{//�C���f�b�N�X�ԍ���������菬�����Ƃ�

			m_nSelectModel += 1;  //�C���f�b�N�X�ԍ�����i�߂�
		}
	}

	if (m_nSelectModel >= m_SetModel)
	{//�C���f�b�N�X�ԍ��������ȏ�ɂȂ����Ƃ�

		m_nSelectModel = 0;  //�C���f�b�N�X�ԍ���0�ɂ���
	}

	if (InputKeyboard->GetTrigger(DIK_DELETE) == true)
	{//delete�L�[��������

		if (m_apModel[m_nSelectModel] != NULL)
		{//�g�p����Ă�����

		 //����������
			m_apModel[m_nSelectModel]->Uninit();

			//�g�p���Ă��Ȃ���Ԃɂ���
			m_apModel[m_nSelectModel] = NULL;

			//�J�E���g�_�E��
			m_SetModel--;
		}

		for (int nCount = 0; nCount < m_SetModel; nCount++)
		{
			if (m_apModel[nCount] == NULL && m_apModel[nCount + 1] != NULL)
			{//���݂̃J�E���g���g�p����Ă��Ȃ����A���̃J�E���g���g�p����Ă���Ƃ�

			 //���
				m_apModel[nCount] = m_apModel[nCount + 1];

				//���̃J�E���g���g�p���Ă��Ȃ���Ԃɂ���
				m_apModel[nCount + 1] = NULL;
			}
		}
	}

	if (m_SetModel > 0)
	{
		pDebugProc->Print("\n<< �폜����I�u�W�F�N�g�̔ԍ��F%d/%d >>", m_nSelectModel, m_SetModel);
	}

	if (m_SetModel <= 0)
	{
		pDebugProc->Print("\n<< �폜�ł���I�u�W�F�N�g�͂���܂��� >>");
	}
}