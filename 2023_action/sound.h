//=============================================================================
//
// �T�E���h���� [sound.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//*****************************************************************************
// �T�E���h���̍\���̒�`
//*****************************************************************************
typedef struct
{
	char *pFilename;	// �t�@�C����
	int nCntLoop;		// ���[�v�J�E���g
} SOUNDINFO;

//�T�E���h�N���X
class CSound
{
public:
	CSound();
	~CSound();

	//*****************************************************************************
	// �T�E���h�ꗗ
	//*****************************************************************************
	typedef enum
	{
		SOUND_LABEL_BGM000 = 0,
		SOUND_LABEL_BGM001,
		SOUND_LABEL_BGM002,
		SOUND_LABEL_BGM003,
		SOUND_LABEL_SE00,
		SOUND_LABEL_SE01,
		SOUND_LABEL_SE02,
		SOUND_LABEL_SE03,
		SOUND_LABEL_SE04,
		SOUND_LABEL_SE05,
		SOUND_LABEL_SE06,
		SOUND_LABEL_SE07,
		SOUND_LABEL_SE08,
		SOUND_LABEL_SE09,
		SOUND_LABEL_SE10,
		SOUND_LABEL_MAX
	} SOUND_LABEL;

	HRESULT Init(HWND hWnd);
	void Uninit(void);
	HRESULT Play(SOUND_LABEL label);
	void Stop(SOUND_LABEL label);
	void Stop(void);

	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

private:
	// �T�E���h�̏��
	SOUNDINFO m_aSoundInfo[SOUND_LABEL_MAX] =
	{
		{ "data/SOUND/BGM/game.wav", -1 },     //�Q�[����BGM
		{ "data/SOUND/BGM/result.wav", -1 },   //���U���g��BGM
		{ "data/SOUND/BGM/title.wav", -1 },    //�^�C�g����BGM
		{ "data/SOUND/BGM/tutorial.wav", -1 }, //�`���[�g���A����BGM
		{ "data/SOUND/SE/sword00.wav", 0 },    //���Ő؂鉹
		{ "data/SOUND/SE/sword01.wav", 0 },    //����
		{ "data/SOUND/SE/shot00.wav", 0 },     //
		{ "data/SOUND/SE/shot01.wav", 0 },     //����
		{ "data/SOUND/SE/nobullet.wav", 0 },   //�ʐ؂�
		{ "data/SOUND/SE/looser.wav", 0 },     //�|��鉹
		{ "data/SOUND/SE/bom.wav", 0 },        //������
		{ "data/SOUND/SE/swing.wav", 0 },      //�o�b�g��U�鉹
		{ "data/SOUND/SE/jump.wav", 0 },       //�W�����v
		{ "data/SOUND/SE/asioto.wav", 0 },     //����
		{ "data/SOUND/SE/avoi.wav", 0 },       //���
	}; 

	IXAudio2 *m_pXAudio2 = NULL;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *m_pMasteringVoice = NULL;			// �}�X�^�[�{�C�X
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};	// �\�[�X�{�C�X
	BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^�T�C�Y
};

#endif
