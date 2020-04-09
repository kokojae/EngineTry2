#pragma once
#include <iostream>
#include <map>
#include "SDKsound.h"

class SoundManager
{
public:
	static CSoundManager* SFXManager;

	static std::map<std::wstring, CSound*> SFXMap;

	static void Init();

	static CSound* SearchSFX(std::wstring path);
	static void PlaySFX(std::wstring path, bool isBGM = false);
	static void EndSFX(std::wstring path);
	static void EndAllSFX();
};

