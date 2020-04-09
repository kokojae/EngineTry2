#include "DXUT.h"
#include "SoundManager.h"

CSoundManager* SoundManager::SFXManager = nullptr;

std::map<std::wstring, CSound*> SoundManager::SFXMap = std::map<std::wstring, CSound*>();

void SoundManager::Init()
{
	SFXManager = new CSoundManager;
	SFXManager->Initialize(DXUTGetHWND(), DSSCL_PRIORITY);
	SFXManager->SetPrimaryBufferFormat(2, 22050, 16);
}

CSound* SoundManager::SearchSFX(std::wstring path)
{
	CSound* SFX;

	if (SFXMap.count(path))
	{
		SFX = SFXMap.find(path)->second;
	}
	else
	{
		SFXManager->Create(&SFX, const_cast<LPWSTR>(path.c_str()), 0, GUID_NULL);

		SFXMap[path] = SFX;
	}

	return SFX;
}

void SoundManager::PlaySFX(std::wstring path, bool isBGM)
{
	CSound* SFX = SearchSFX(path);

	if (isBGM)
	{
		SFX->Play(0, DSBPLAY_LOOPING);
	}
	else
	{
		SFX->Reset();
		SFX->Play(0, NULL);
	}
}

void SoundManager::EndSFX(std::wstring path)
{
	std::map<std::wstring, CSound*>::iterator it;
	it = SFXMap.find(path);

	if (it != SFXMap.end())
	{
		it->second->Stop();
		it->second->Reset();
	}
}

void SoundManager::EndAllSFX()
{
	std::map<std::wstring, CSound*>::iterator it;
	it = SFXMap.begin();

	while (it != SFXMap.end())
	{
		it->second->Stop();
		(it++)->second->Reset();
	}
}
