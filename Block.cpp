#include "DXUT.h"
#include "Block.h"
#include "EngineTry2.h"

void Block::Init()
{
	switch (SceneManager::currentScene)
	{
	case SceneManager::Scene::Stage1:
		SetObject(L"Block", 0, L"resorce/ground/stage1/nomal.png", { 320,320 }, { 320,320 }, Layer::BLOCK);
		break;
	case SceneManager::Scene::Stage2:
		SetObject(L"Block", 0, L"resorce/ground/stage2/nomal.png", { 320,320 }, { 320,320 }, Layer::BLOCK);
		break;
	default:
		break;
	}	
}
