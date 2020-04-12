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
		for (int i = -10; i < 10; i++)
		{
			ObjectManager::Instantiate<Block>({ static_cast<float>(i * 320),400 });
		}

		GameManager::player = ObjectManager::Instantiate<Player>();
		break;
	case SceneManager::Scene::Stage2:
		for (int i = -10; i < 10; i++)
		{
			ObjectManager::Instantiate<Block>({ static_cast<float>(i * 320),400 });
		}

		GameManager::player = ObjectManager::Instantiate<Player>();
		break;
	default:
		break;
	}
}
