#include "DXUT.h"
#include "EnemyAlpha.h"

void EnemyAlpha::Init()
{
	SetObject(L"EnemyAlpha", 10, L"resorce/enemy/enemy1.png", { 200,100 }, { 200,100 }, Layer::ENEMY);
	hp = 100;
	point = 100;
}

void EnemyAlpha::Update()
{
	Hovering();
	AddForce();
}
