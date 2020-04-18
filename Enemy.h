#pragma once
#include "GameObject.h"
class Bullet;

class Enemy :
	public GameObject
{
public:
	float hp;
	int point;
	bool isIncrease = true;

	virtual void Damaged(float damage, Bullet* bullet);

	void Hovering();
};

