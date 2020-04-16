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

	void RangeManagement();

	virtual void SetBullet(GameObject* a_launcher, D3DXVECTOR2 playerPosition, float a_speed, float a_range, float a_damage) = 0;
};

