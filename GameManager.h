#pragma once
class Player;

class GameManager
{
public:
	static Player* player;

	static void Init();
	static void Update();
};

