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

	doubleJumpTime = 0;
	speedUpTime = 0;
	rangeIncreasedTime = 0;
	threeDirectionTime = 0;

	isDoubleJump = false;
	isSpeedUp = false;
	isRangeIncreased = false;
	isThreeDirection = false;
}

void Player::Update()
{
	ItemManagement();
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

void Player::UsingItem(Item item)
{
	switch (item)
	{
	case Player::Item::DOUBLE_JUMP:
		doubleJumpTime = 10;
		isDoubleJump = true;
		break;
	case Player::Item::SPEED_UP:
		speedUpTime = 10;
		isSpeedUp = true;
		break;
	case Player::Item::RANGE_INCREASED:
		rangeIncreasedTime = 10;
		isRangeIncreased = true;
		break;
	case Player::Item::THREE_DIRECTION:
		threeDirectionTime = 10;
		isThreeDirection = true;
		break;
	}
}

void Player::ItemManagement()
{
	if (doubleJumpTime < 0)
	{
		doubleJumpTime = 0;
		isDoubleJump = false;
	}
	else
	{
		doubleJumpTime -= DXUTGetElapsedTime();
	}

	if (speedUpTime < 0)
	{
		speedUpTime = 0;
		isSpeedUp = false;
	}
	else
	{
		speedUpTime -= DXUTGetElapsedTime();
	}

	if (rangeIncreasedTime < 0)
	{
		rangeIncreasedTime = 0;
		isRangeIncreased = false;
	}
	else
	{
		rangeIncreasedTime -= DXUTGetElapsedTime();
	}

	if (threeDirectionTime < 0)
	{
		threeDirectionTime = 0;
		isThreeDirection = false;
	}
	else
	{
		threeDirectionTime -= DXUTGetElapsedTime();
	}

}
