#include "DXUT.h"
#include "MouseManager.h"

bool MouseManager::leftBtn = false;
bool MouseManager::middleBtn = false;
bool MouseManager::rightBtn=false;
D3DXVECTOR2 MouseManager::position = { 0,0 };
RECT MouseManager::rc = { 0,0,0,0 };

RECT* MouseManager::GetMouseRect()
{
	LONG x = position.x;
	LONG y = position.y;

	rc = { x - 1,y - 1,x + 1,y + 1 };

	return &rc;
}
