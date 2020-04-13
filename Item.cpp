#include "DXUT.h"
#include "Item.h"
#include "EngineTry2.h"

void Item::Update()
{
	GameObject* inst = PlaceMeeting({ 0,0 }, Layer::PLAYER);
	Player* player = dynamic_cast<Player*>(inst);

	if (player != nullptr)
		player->UsingItem(item);
}
