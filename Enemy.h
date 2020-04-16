#pragma once
#include "GameObject.h"
class Bullet;

class Enemy :
	public GameObject
{
public:
	float hp;
	int point;

	virtual void Damaged(float damage, Bullet* bullet);
};

