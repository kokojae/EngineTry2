#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	GameObject* launcher;

	D3DXVECTOR2 direction;
	float speed;
	float range;
	float damage;

	void Update()override;

	void SettingForce();
	void RangeManagement();

	virtual void CollisionCheck() = 0;

	virtual void SetBullet(GameObject* a_launcher, D3DXVECTOR2 playerPosition, float a_speed, float a_range, float a_damage) = 0;
};

