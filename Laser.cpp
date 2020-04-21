#include "DXUT.h"
#include "Laser.h"
#include "EngineTry2.h"

void Laser::Init()
{
	SetObject(L"EnemyBullet", 4, L"resorce/bullet/enemymissile.png", { 50,110 }, { 50,110 }, Layer::ENEMY_BULLET);
}

void Laser::CollisionCheck()
{
	GameObject* inst = PlaceMeeting({ 0,0 }, Layer::BLOCK | Layer::BLOCK_UP);
	if (inst != nullptr)
	{
		destroy = true;
		return;
	}

	inst = PlaceMeeting({ 0,0 }, Layer::PLAYER);
	if (inst != nullptr)
	{
		Player* player = dynamic_cast<Player*>(inst);
		if (player != nullptr)
		{
			// 플레이어 데미지 처리
		}
		destroy = true;
		return;
	}
}

void Laser::SetBullet(GameObject* a_launcher, D3DXVECTOR2 playerPosition, float a_speed, float a_range, float a_damage)
{
	launcher = a_launcher;
	auto diff = launcher->position - playerPosition;
	D3DXVec2Normalize(&direction, &diff);
	speed = a_speed;
	range = a_range;
	damage = a_damage;

	info.degree = D3DXToDegree(atan2(direction.y, direction.x));
}
