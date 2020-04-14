#include "DXUT.h"
#include "Flak.h"

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
		// 利 单固瘤 贸府
		// 肚绰
		// 厘局拱 单固瘤 贸府
		destroy = true;
		return;
	}

	inst = PlaceMeeting({ 0,0 }, Layer::ENEMY_BULLET);
	if (inst != nullptr)
	{
		// 利 醚舅 颇鲍 贸府
		destroy = true;
		return;
	}
}

void Flak::SetBullet(D3DXVECTOR2 playerPosition, float a_speed, float a_range, float a_damage)
{
	auto diff = MouseManager::position - playerPosition;
	D3DXVec2Normalize(&direction, &diff);
	speed = a_speed;
	range = a_range;

	info.degree = D3DXToDegree(atan2(direction.y, direction.x));
}
