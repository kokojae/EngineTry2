#include "DXUT.h"
#include "GameObject.h"
#include "EngineTry2.h"

void GameObject::Init()
{
}

void GameObject::Update()
{
}

void GameObject::LateUpdate()
{
}

void GameObject::Render()
{
	DrawSelf();
}

void GameObject::Release()
{
}

void GameObject::DrawSelf()
{
	GraphicManager::TextureRender(info, position);
}

GameObject* GameObject::PlaceMeeting(D3DXVECTOR2 vector, int layer)
{
	collider.enable = false;
	GameObject* inst = ObjectManager::ColliderCheck(GetRect(vector), layer);
	collider.enable = true;
	return inst;
}

bool GameObject::IsClicked(MouseManager::Key key)
{
	switch (key)
	{
	case MouseManager::Key::LEFT:
		if (MouseManager::leftBtn) break;
		else return false;
	case MouseManager::Key::MIDDLE:
		if (MouseManager::middleBtn) break;
		else return false;
	case MouseManager::Key::RIGHT:
		if (MouseManager::rightBtn) break;
		else return false;
	case MouseManager::Key::ANY:
		break;
	default:
		break;
	}

	return IntersectRect(&RECT(), GetRect(), MouseManager::GetMouseRect());
}

void GameObject::SetObject(std::wstring objectName, int objectZ, std::wstring path, D3DXVECTOR2 textureSize, D3DXVECTOR2 colliderSize, int layer, D3DXVECTOR2 objectScale)
{
	name = objectName;
	z = objectZ;
	SetTexture(path, textureSize, objectScale);	
	SetCollider({ colliderSize.x * objectScale.x, colliderSize.y * objectScale.y }, layer);
}

void GameObject::SetTexture(std::wstring path, D3DXVECTOR2 textureSize, D3DXVECTOR2 textureScale)
{
	info.texture = TextureManager::LoadTexture(path);
	info.size = textureSize;
	info.center = textureSize / 2;
	info.scale = textureScale;
}

void GameObject::SetCollider(D3DXVECTOR2 colliderSize, int layer)
{
	collider.size = colliderSize;
	collider.center = colliderSize / 2;
	collider.layer = layer;
}

RECT* GameObject::GetRect(D3DXVECTOR2 vector)
{
	rc.left		= (position - collider.center + vector).x;
	rc.top		= (position - collider.center + vector).y;
	rc.right	= (position - collider.center + vector + collider.size).x;
	rc.bottom	= (position - collider.center + vector + collider.size).y;
	return &rc;
}
