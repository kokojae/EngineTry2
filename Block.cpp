#include "DXUT.h"
#include "Block.h"

void Block::Init()
{
	SetObject(L"Block", 0, L"Source/block.png", { 100,100 }, { 100,100 }, Layer::BLOCK);
	info.color = D3DCOLOR_ARGB(180, 255, 30, 0);
}
