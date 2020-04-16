#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	enum class State { PANZER, WHIPPET, HEAVYTANK };
	enum class Item { DOUBLE_JUMP, SPEED_UP, RANGE_INCREASED, THREE_DIRECTION };

	static Player* me;

	State playerState;

	LPDIRECT3DTEXTURE9 panzer;
	LPDIRECT3DTEXTURE9 whippet;
	LPDIRECT3DTEXTURE9 heavyTank;

	float doubleJumpTime;
	float speedUpTime;
	float rangeIncreasedTime;
	float threeDirectionTime;

	bool isDoubleJump;
	bool isSpeedUp;
	bool isRangeIncreased;
	bool isThreeDirection;

	int point;

	void Init();
	void Update();
	void LateUpdate();

	void GetKey();
	void Hspeed();
	void CameraMove();

	void Upgrade();
	void DownGrade();

	void UsingItem(Item item);
	void ItemManagement();
};

