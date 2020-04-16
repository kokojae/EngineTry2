#include "DXUT.h"
#include "Enemy.h"
#include "EngineTry2.h"

void Enemy::Damaged(float damage, Bullet* bullet)
{
	hp -= damage;
	if (hp <= 0)
	{
		destroy = true;
		Player* player = dynamic_cast<Player*>(bullet->launcher);
		if (player != nullptr)
		{
			player->point = point;
		}
	}
}
