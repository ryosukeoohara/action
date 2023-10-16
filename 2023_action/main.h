//===========================================================
//
//�|���S�����o�����[main.h]
//Author �匴�叫
//
//===========================================================
#ifndef _MAIN_H_     //���̃}�N������`����ĂȂ�������
#define _MAIN_H_     //2�d�C���N���[�h��h�~�̃}�N�����`����

#define CLASS_NAME        "windowclass"            //�E�C���h�E�N���X�̖��O
#define DIRECTINPUT_VERSION (0x0800)               //�r���g���̌x���Ώ��p�}�N��
#include<Windows.h>
#include<Xinput.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include "d3dx9.h"
#include "dinput.h"  //���͏����ɕK�v
#include "xaudio2.h" //�T�E���h�����ɕK�v   

typedef struct
{
	D3DXVECTOR3 pos;   //�ʒu
	float rhw;
	D3DCOLOR col;      //�F
	D3DXVECTOR2 tex;   //�e�N�X�`���̍��W
} VERTEX_2D;

//���_���[3D]�̍\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;    //�ʒu
	D3DXVECTOR3 nor;    //�@���x�N�g��
	D3DCOLOR    col;
	D3DXVECTOR2 tex;
} VERTEX_3D;

//���C�u�����̃����N
#pragma comment(lib,"d3d9.lib")                    //�`�揈���ɕK�v
#pragma comment(lib,"d3dx9.lib")                   //[d3d9.lib]�̊g�����C�u����
#pragma comment(lib,"dxguid.lib")                  //Direct�R���|�[�l���g(���i)�g�p�ɕK�v
#pragma comment(lib,"winmm.lib")                   //�V�X�e�������擾�ɕK�v
#pragma comment(lib,"dinput8.lib")                 //���͏����ɕK�v

//===========================================================
//�}�N����`
//===========================================================
#define SCREEN_WIDTH      (1280)                   //�E�C���h�E�ɕ�
#define SCREEN_HEIGHT     (720)                    //�E�C���h�E�̍���
#define FVF_VERTEX_2D     (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define FVF_VERTEX_3D     (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)

#endif