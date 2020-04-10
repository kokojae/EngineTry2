#include "DXUT.h"
#include "GraphicManager.h"
#include "EngineTry2.h"

LPD3DXSPRITE GraphicManager::sprite = nullptr;
ID3DXFont* GraphicManager::font = nullptr;

void GraphicManager::Init()
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &sprite);
	D3DXCreateFont(DXUTGetD3D9Device(), 70, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
		L"Arial", &font);
}

void GraphicManager::Render()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	ObjectManager::Render();
	sprite->End();
}

void GraphicManager::Release()
{
	font->Release();
	sprite->Release();
}

void GraphicManager::TextureRender(TextureInfo info, D3DXVECTOR2 position)
{
	D3DXMATRIX mat, pos, rad, sca, cen;

	D3DXMatrixTranslation(&pos, position.x, position.y, 0);
	D3DXMatrixRotationZ(&rad, D3DXToRadian(info.degree));
	D3DXMatrixScaling(&sca, info.scale.x, info.scale.y, 1);
	D3DXMatrixTranslation(&cen, -info.center.x, -info.center.y, 0);

	mat = cen * sca * rad * pos;

	if (info.cameraOn)
		mat *= Camera::GetCamMat();

	sprite->SetTransform(&mat);

	DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
	DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
	DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);

	RECT rc = { info.size.x * info.index,0,info.size.x * (info.index + 1),info.size.y };

	sprite->Draw(info.texture, &rc, NULL, NULL, info.color);
}

void GraphicManager::TextRender(std::wstring text, D3DXVECTOR2 position, D3DXVECTOR2 scale, bool isUI)
{
	D3DXMATRIX mat, pos, sca;

	D3DXMatrixTranslation(&pos, position.x, position.y, 0);
	D3DXMatrixScaling(&sca, scale.x, scale.y, 1);

	mat = sca * pos;

	if (!isUI)
		Camera::GetCamMat();

	sprite->SetTransform(&mat);

	font->DrawText(sprite, text.c_str(), -1, NULL, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
}
