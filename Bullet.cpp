#include "DXUT.h"
#include "Bullet.h"

void Bullet::Update()
{
	SettingForce();
	AddForce();
	CollisionCheck();
	RangeManagement();
}

void Bullet::SettingForce()
{
	force = direction * speed * DXUTGetElapsedTime();
}

void Bullet::RangeManagement()
{
	range -= DXUTGetElapsedTime();
	if (range <= 0)
		destroy = true;
}
