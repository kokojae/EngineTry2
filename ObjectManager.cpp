#include "DXUT.h"
#include "ObjectManager.h"
#include "EngineTry2.h"

std::list<GameObject*> ObjectManager::objectList = std::list<GameObject*>();

void ObjectManager::Update()
{
	std::list<GameObject*>::iterator it = objectList.begin();

	while (it != objectList.end())
	{
		GameObject* inst = it._Ptr->_Myval;

		if (inst->destroy)
		{
			inst->Release();
			objectList.erase(it++);
			delete inst;
			continue;
		}

		inst->Update();
		it++;
	}
}

void ObjectManager::LateUpdate()
{
	for (GameObject* inst : objectList)
	{
		if (inst->destroy)
			continue;
		inst->LateUpdate();
	}
}

void ObjectManager::Render()
{
	for (GameObject* inst : objectList)
	{
		if (inst->destroy)
			continue;
		inst->Render();
	}
}

void ObjectManager::Release()
{
	std::list<GameObject*>::iterator it = objectList.begin();

	while (it != objectList.end())
	{
		GameObject* inst = it._Ptr->_Myval;

		inst->Release();
		objectList.erase(it++);
		delete inst;
	}
}

void ObjectManager::Clear()
{
	for (GameObject* inst : objectList)
	{
		inst->destroy = true;
	}
}

GameObject* ObjectManager::ColliderCheck(RECT* objectRect, int layer)
{
	for (GameObject* inst : objectList)
	{
		if (!(layer & inst->collider.layer))
			continue;
		if (!inst->collider.enable)
			continue;
		if (inst->destroy)
			continue;

		if (IntersectRect(&RECT(), objectRect, inst->GetRect()))
			return inst;
	}
	return nullptr;
}

GameObject* ObjectManager::SearchObject(std::wstring objectName)
{
	for (GameObject* inst : objectList)
	{
		if (inst->name == objectName)
			return inst;
	}
	return nullptr;
}

bool Sort(const GameObject* a, const GameObject* b)
{
	return a->z < b->z;
}
