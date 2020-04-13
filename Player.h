#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	enum class State { PANZER, WHIPPET, HEAVYTANK };

	static Player* me;

	State playerState;

	LPDIRECT3DTEXTURE9 panzer;
	LPDIRECT3DTEXTURE9 whippet;
	LPDIRECT3DTEXTURE9 heavyTank;

	void Init();
	void Update();
	void LateUpdate();

	void GetKey();
	void Hspeed();
	void CameraMove();

	void Upgrade();
	void DownGrade();
};

