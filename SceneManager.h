#pragma once
class SceneManager
{
public:
	enum class Scene { Intro, Main, HowTo, Rank, Credit, Stage1, Stage2 };
	
	static Scene currentScene;

	static void LoadScene(Scene scene);
};

