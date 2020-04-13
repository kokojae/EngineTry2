#pragma once
#include "GameObject.h"
#include "Player.h"

class Item :
	public GameObject
{
public:
	Player::Item item;

	void Update()override;

	virtual void SetItem(Player::Item a_item) = 0;
};

