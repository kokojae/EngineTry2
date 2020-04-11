#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	static Player* me;

	D3DXVECTOR2 camera_position;

	void Init();
	void Update();
	void LateUpdate();

	void GetKey();
	void Hspeed();
	void CameraMove();
};

