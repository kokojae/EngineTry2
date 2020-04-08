#pragma once
class MouseManager
{
public:
	enum class Key { LEFT, MIDDLE, RIGHT, ANY };

	static bool leftBtn;
	static bool middleBtn;
	static bool rightBtn;
	static D3DXVECTOR2 position;
	static RECT rc;

	static RECT* GetMouseRect();
};

