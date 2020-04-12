#include "DXUT.h"
#include "Player.h"
#include "EngineTry2.h"

Player* Player::me = nullptr;

void Player::Init()
{
	me = this;
	SetObject(L"Player", 10, L"resorce/player/player1.png", { 300,150 }, { 300,150 }, Layer::PLAYER, { 0.7,0.7 });
}

void Player::Update()
{
	GetKey();
	Hspeed();
	Gravity();
	AddForce();
}

void Player::LateUpdate()
{
	CameraMove();
}

void Player::GetKey()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (force.x > -5)
			force.x -= 0.5f;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (force.x < 5)
			force.x += 0.5f;
	}
	if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
	{
		force.x -= force.x / 20;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (PlaceMeeting({ 0,10 }, Layer::BLOCK))
		{
			force.y = -15;
		}
	}
}

void Player::Hspeed()
{
	if (PlaceMeeting({ force.x,0 }, Layer::BLOCK) != nullptr)
	{
		force.x = 0;
	}
}

void Player::CameraMove()
{
	Camera::position.x += (position.x - Camera::position.x) / 30;
}
