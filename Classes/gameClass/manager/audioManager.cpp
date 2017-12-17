#include "audioManager.h"
static AudioManager* _audiomanager = NULL;

AudioManager * AudioManager::getInstance()
{
	if( _audiomanager == NULL)
	{
		_audiomanager = new AudioManager();

	}
	return _audiomanager;
}
AudioManager::AudioManager()
{
	audioEngin = SimpleAudioEngine::sharedEngine();
}
AudioManager::~AudioManager()
{
	if(_audiomanager != NULL)
	{
		delete _audiomanager;
		_audiomanager = NULL;
	}
}
void AudioManager::proLoadEffect(std::string filePathmane)
{
	audioEngin->preloadEffect(filePathmane.c_str());
}
void AudioManager::playEffect(string effectpath , bool isLoop)
{
	curEffectId = audioEngin->playEffect(effectpath.c_str(),isLoop);
}
void AudioManager::pauseEffect(int effectId)
{
	audioEngin->pauseEffect(curEffectId);
}
void AudioManager::resumeEffect(int effectId)
{
	audioEngin->resumeEffect(curEffectId);
}
void AudioManager::stopEffect(int effectId)
{
	audioEngin->stopEffect(curEffectId);
}
void AudioManager::stopAllEffects()
{
	audioEngin->stopAllEffects();
}
float AudioManager::getEffEctVolume()
{
	return cureffect_vol = audioEngin->getEffectsVolume();
}
void AudioManager::setEffectVolume(float vol)
{
	cureffect_vol = vol;
	audioEngin->setEffectsVolume(cureffect_vol);
} 
void AudioManager::proloadBackGroundMusic(string path)
{
	audioEngin->preloadBackgroundMusic(path.c_str());
}
void AudioManager::playBackGroundMusic(string path,bool isloop)
{
	audioEngin->playBackgroundMusic(path.c_str(),isloop);
}
void AudioManager::pauseBackGroundMusic()
{
	audioEngin->pauseBackgroundMusic();
}
void AudioManager::resumeBackGroundMusic()
{
	audioEngin->resumeBackgroundMusic();
}
void AudioManager::stopBackGroundMusic(bool isrelease)
{
	audioEngin->stopBackgroundMusic(isrelease);
}
	
void AudioManager::setBackGroundMusicVolume(float vol)
{
	curmusic_vol = vol;
	audioEngin ->setBackgroundMusicVolume(curmusic_vol);
}
float AudioManager::getBackGroundMusicVolume()
{
	return curmusic_vol = audioEngin->getBackgroundMusicVolume();
}