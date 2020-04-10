#include "DXUT.h"
#include "SceneManager.h"
#include "EngineTry2.h"

SceneManager::Scene SceneManager::currentScene = SceneManager::Scene::Intro;

void SceneManager::LoadScene(Scene scene)
{
	currentScene = scene;

	Camera::position = { 0,0 };
	Camera::degree = 0;
	Camera::scale = 1;

	ObjectManager::Clear();
	SoundManager::EndAllSFX();

	switch (scene)
	{
	case SceneManager::Scene::Intro:
		ObjectManager::Instantiate<Text>()->SetText(L"Test", { 0.4,0.4 });
		break;
	case SceneManager::Scene::Main:
		break;
	case SceneManager::Scene::HowTo:
		break;
	case SceneManager::Scene::Rank:
		break;
	case SceneManager::Scene::Credit:
		break;
	case SceneManager::Scene::Stage1:
		break;
	case SceneManager::Scene::Stage2:
		break;
	default:
		break;
	}
}
