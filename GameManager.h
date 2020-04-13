#pragma once
class Player;

class GameManager
{
public:
	static Player* player;

	static double changeTime;

	static void Init();
	static void Update();
};

