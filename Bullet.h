#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	D3DXVECTOR2 direction;
	float speed;
	float range;

	virtual void SetBullet(D3DXVECTOR2 a_directionfloat,float a_speed, float a_range) = 0;
};

