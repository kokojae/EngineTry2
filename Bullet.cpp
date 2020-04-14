#include "DXUT.h"
#include "Bullet.h"

void Bullet::RangeManagement()
{
	range -= DXUTGetElapsedTime();
	if (range <= 0)
		destroy = true;
}
