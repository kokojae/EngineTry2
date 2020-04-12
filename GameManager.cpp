#include "DXUT.h"
#include "GameManager.h"
#include "EngineTry2.h"

Player* GameManager::player = nullptr;

void GameManager::Init()
{
	SceneManager::LoadScene(SceneManager::Scene::Intro);
}

void GameManager::Update()
{
	if (GetAsyncKeyState(VK_F1))
	{

	}
	if (GetAsyncKeyState(VK_F2))
	{

	}
	if (GetAsyncKeyState(VK_F3))
	{

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
