#include "DXUT.h"
#include "Player.h"
#include "EngineTry2.h"

Player* Player::me = nullptr;

void Player::Init()
{
	me = this;
	playerState = State::PANZER;

	SetObject(L"Player", 10, L"resorce/player/player1.png", { 300,150 }, { 300,150 }, Layer::PLAYER, { 0.7,0.7 });

	panzer = TextureManager::LoadTexture(L"resorce/player/player1.png");
	whippet = TextureManager::LoadTexture(L"resorce/player/player2.png");
	heavyTank = TextureManager::LoadTexture(L"resorce/player/player3.png");
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

void Player::Upgrade()
{
	switch (playerState)
	{
	case Player::State::PANZER:
		playerState = State::WHIPPET;
		info.texture = whippet;
		break;
	case Player::State::WHIPPET:
		playerState = State::HEAVYTANK;
		info.texture = heavyTank;
		break;
	default:
		break;
	}
}

void Player::DownGrade()
{
	switch (playerState)
	{
	case Player::State::WHIPPET:
		playerState = State::PANZER;
		info.texture = panzer;
		break;
	case Player::State::HEAVYTANK:
		playerState = State::WHIPPET;
		info.texture = whippet;
		break;
	default:
		break;
	}
}
