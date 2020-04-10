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
		SoundManager::PlaySFX(L"Source/test.wav");

		ObjectManager::Instantiate<Text>({ 0,300 })->SetText(L"방향키 이동 WASD 카메라 조작\n씬이동 스페이스바", { 0.5,0.5 });

		ObjectManager::Instantiate<Block>({ 0,200 });
		ObjectManager::Instantiate<Block>({ 100,200 });
		ObjectManager::Instantiate<Block>({ 200,200 });
		ObjectManager::Instantiate<Block>({ 300,100 });
		ObjectManager::Instantiate<Block>({ 400,200 });
		ObjectManager::Instantiate<Block>({ -100,100 });
		ObjectManager::Instantiate<Block>({ 0,-100 });;

		ObjectManager::Instantiate<Player>();
		break;
	case SceneManager::Scene::Main:
		ObjectManager::Instantiate<Text>({ 0, -100 })->SetText(L"여기는 게임씬", { 0.5,0.5 });
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
