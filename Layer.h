#pragma once
class Layer
{
public:
	const static int DEFAULT	= 1 << 1;
	const static int BLOCK		= 1 << 2;
	const static int BLOCK_UP	= 1 << 3;
	const static int PLAYER		= 1 << 4;
	const static int ENEMY		= 1 << 5;
	const static int BULLET		= 1 << 6;
};

