#include "DXUT.h"
#include "Camera.h"
#include "EngineTry2.h"

D3DXVECTOR2 Camera::position = { 0,0 };
float Camera::degree = 0;
float Camera::scale = 1;
D3DXVECTOR2 Camera::shake = { 1,1 };

D3DXMATRIX Camera::GetCamMat()
{
	D3DXMATRIX mat, pos, rot, sca, scr;

	D3DXMatrixTranslation(&pos, -position.x, -position.y, 0);
	D3DXMatrixRotationZ(&rot, D3DXToRadian(degree));
	D3DXMatrixScaling(&sca, 1 / scale, 1 / scale, 1);
	D3DXMatrixTranslation(&scr, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);

	mat = pos * sca * rot * scr;

	return mat;
}
