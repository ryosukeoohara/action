//=============================================================================
//
// �����蔻�菈�� [collision.h]
// Author : �匴�@�叫
//
//=============================================================================
#ifndef _CONLLISION_H_
#define _CONLLISION_H_

//=============
//�O���錾
//=============
class CEnemyWeak;
class CEnemyBoss;
class CPlayer;
class CEnemy;
class CBullet;
class CObjectX;


//�R���W�����N���X
class CCollision
{
public:
	CCollision();
	~CCollision();

	HRESULT Init(void);
	void Uninit(void);

	bool Enemy(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, float fWidthX, float fWidthZ, CEnemy *pEnemy);  //�G�Ƃ̓����蔻��(�v���C���[�)
	bool BulletEnemy(D3DXVECTOR3 *pos, float fWidthX, float fWidthY, CEnemy **pEnemy);     //�e�Ƃ̓����蔻��
	bool BulletPlayer(D3DXVECTOR3 *pos, float fWidthX, float fWidthZ, CPlayer *pPlayer);  //�e�Ƃ̓����蔻��
	bool BulletMap(D3DXVECTOR3 *pos, CObjectX **pObjectX);       //�e�ƌ����̓����蔻��
	bool Punch(D3DXVECTOR3 *pos, float fWidthX, float fWidthZ);  //�G�Ƃ��Ԃ��̓����蔻��
	bool Circle(D3DXVECTOR3 *pos, float fRadius, CPlayer *pPlayer);  //�~�̓����蔻��
	//bool CollisionItem(D3DXVECTOR3 *pos, float fWidthX, float fWidthZ, CItem::TYPE type, CPlayer *pPlayer);    //�A�C�e���ƃv���C���[�̓����蔻��
	//bool Enemy(D3DXVECTOR3 *pos, float fWidthX, float fWidthZ, CEnemy *pEnemy);    //�A�C�e���ƃv���C���[�̓����蔻��
	bool Knife(D3DXVECTOR3 *pos, D3DXVECTOR3 rot, float fRadius, CEnemy **pEnemy);
	bool kugibat(D3DXVECTOR3 *pos, CPlayer *pPlayer);    //�A�C�e���ƃv���C���[�̓����蔻��
	bool Player(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, float fWidthX, float fWidthZ, CPlayer *pPlayer);  //�Ղꂢ��[�Ƃ̓����蔻��
	void Map(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, CObjectX **pObjectX);  //�}�b�v�ɂ��錚���Ƃ̓����蔻��
	bool Block(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, float fWidthX, float fWidthZ);  //�u���b�N�Ƃ̔���
	
private:

};
#endif // !_CONLLISION_H_