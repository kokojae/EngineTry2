#include "DXUT.h"
#include "Flak.h"
#include "EngineTry2.h"

void Flak::Init()
{
	SetObject(L"PlayerBullet", 5, L"resorce/bullet/bullet.png", { 70,30 }, { 70,30 }, Layer::PLAYER_BULLET);
}

void Flak::Update()
{
	SettingForce();
	AddForce();
	CollisionCheck();
	RangeManagement();
}

void Flak::SettingForce()
{
	force = direction * speed * DXUTGetElapsedTime();
}

void Flak::CollisionCheck()
{
	GameObject* inst = PlaceMeeting({ 0,0 }, Layer::BLOCK | Layer::BLOCK_UP);
	if (inst != nullptr)
	{
		destroy = true;
		return;
	}

	inst = PlaceMeeting({ 0,0 }, Layer::ENEMY | Layer::OBSTACLE);
	if (inst != nullptr)
	{
		Enemy* enemy = dynamic_cast<Enemy*>(inst);
		if (enemy != nullptr)
			enemy->Damaged(damage, this);
		// 장애물 데미지 처리
		destroy = true;
		return;
	}

	inst = PlaceMeeting({ 0,0 }, Layer::ENEMY_BULLET);
	if (inst != nullptr)
	{
		// 적 총알 파괴 처리
		destroy = true;
		return;
	}
}

void Flak::SetBullet(GameObject* a_launcher, D3DXVECTOR2 playerPosition, float a_speed, float a_range, float a_damage)
{
	launcher = a_launcher;
	auto diff = MouseManager::position - playerPosition;
	D3DXVec2Normalize(&direction, &diff);
	speed = a_speed;
	range = a_range;
	damage = a_damage;

	info.degree = D3DXToDegree(atan2(direction.y, direction.x));
}
