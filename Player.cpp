#include "DXUT.h"
#include "Player.h"
#include "EngineTry2.h"

Player* Player::me = nullptr;

void Player::Init()
{
	me = this;
	SetObject(L"Player", 10, L"Source/player.png", { 100,100 }, { 80,80 }, Layer::PLAYER);
}

void Player::Update()
{
	GetKey();
	Hspeed();
	Gravity();
}

void Player::LateUpdate()
{
	CameraMove();
}

void Player::GetKey()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		SceneManager::LoadScene(SceneManager::Scene::Main);
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (hspeed > -5)
			hspeed -= 0.5f;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (hspeed < 5)
			hspeed += 0.5f;
	}
	if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
	{
		hspeed -= hspeed / 20;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (PlaceMeeting({ 0,10 }, Layer::BLOCK))
		{
			SoundManager::PlaySFX(L"Source/Jump.wav");
			vspeed = -15;
		}
	}

	if (GetAsyncKeyState('W'))
		Camera::scale -= Camera::scale * 0.2;
	if (GetAsyncKeyState('S'))
		Camera::scale += Camera::scale * 0.2;
	if (GetAsyncKeyState('D'))
		Camera::degree += 5;
	if (GetAsyncKeyState('A'))
		Camera::degree -= 5;
}

void Player::Hspeed()
{
	if (PlaceMeeting({ hspeed,0 }, Layer::BLOCK) != nullptr)
	{
		hspeed = 0;
	}
	else
	{
		position.x += hspeed;
	}
}

void Player::Gravity()
{
	vspeed += 0.5f;

	if (PlaceMeeting({ 0,vspeed }, Layer::BLOCK) != nullptr)
	{
		vspeed = 0;
	}
	else
	{
		position.y += vspeed;
	}
}

void Player::CameraMove()
{

	Camera::position += (position - Camera::position) / 30;
}
