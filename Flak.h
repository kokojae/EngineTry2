#pragma once
#include "Bullet.h"
class Flak :
	public Bullet
{
public:
	void Init()override;
	void Update()override;

	void SettingForce();
	void CollisionCheck();

	void SetBullet(D3DXVECTOR2 playerPosition, float a_speed, float a_range, float a_damage)override;
};

