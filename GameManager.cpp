#include "DXUT.h"
#include "GameManager.h"
#include "EngineTry2.h"

Player* GameManager::player = nullptr;
double GameManager::changeTime = 0;

void GameManager::Init()
{
	SceneManager::LoadScene(SceneManager::Scene::Stage1);

	changeTime = DXUTGetTime();
}

void GameManager::Update()
{
	if (GetAsyncKeyState(VK_F1))
	{

	}
	if (GetAsyncKeyState(VK_F2))
	{
		if ((changeTime + 0.5) <= DXUTGetTime())
		{
			changeTime = DXUTGetTime();
			player->Upgrade();
		}
	}
	if (GetAsyncKeyState(VK_F3))
	{
		if ((changeTime + 0.5) <= DXUTGetTime())
		{
			changeTime = DXUTGetTime();
			player->DownGrade();
		}
	}
	if (GetAsyncKeyState(VK_F4))
	{
		SceneManager::LoadScene(SceneManager::Scene::Main);
	}
	if (GetAsyncKeyState(VK_F5))
	{
		SceneManager::LoadScene(SceneManager::Scene::Stage1);
	}
	if (GetAsyncKeyState(VK_F6))
	{
		SceneManager::LoadScene(SceneManager::Scene::Stage2);
	}
}
