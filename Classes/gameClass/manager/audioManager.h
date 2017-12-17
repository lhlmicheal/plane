#ifndef _AUDIO_MANAGER_H
#define _AUDIO_MANAGER_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;

#define MUSIC_BG_SENCE_UI "music/music_ui.mp3"
#define MUSIC_BG_SENCE_FIHT "music/music_fight.mp3"
#define EFFECT_BEAT "music/beat.mp3"
#define EFFECT_BOOM "music/boom.mp3"
#define EFFECT_BULLET "music/bullet.mp3"
#define EFFECT_BUTTON "music/button.mp3"
#define EFFECT_CONGRATULATE "music/congratulate.mp3"
#define EFFECT_DEAD "music/dead.mp3"
#define EFFECT_GET_COIN "music/get_coin.mp3"
#define EFFECT_GET_GEM "music/get_gem.mp3"
#define EFFECT_GET_INVINCIBLE "music/get_invincible.mp3"
#define EFFECT_MON_DEAD "music/mon_die.mp3"
#define EFFECT_WARNNING "music/warn.mp3"
using namespace std;
class AudioManager : public CCObject
{
public:
	AudioManager();
	~AudioManager();
	static AudioManager* getInstance();

	SimpleAudioEngine *audioEngin;

	int curEffectId;
	float cureffect_vol;
	float curmusic_vol;
	//////“Ù–ßøÿ÷∆/////
	void playEffect(string effectpath, bool isLoop =false);

	void pauseEffect(int effectId);
	void resumeEffect(int effectId);
	void stopEffect(int effectId);
	void stopAllEffects();
	void proLoadEffect(std::string filePathmane);

	float getEffEctVolume();
	void setEffectVolume(float vol); 
	//////±≥æ∞“Ù¿÷øÿ÷∆//////
	void proloadBackGroundMusic(std::string filepath);
	void playBackGroundMusic(std::string filepath, bool isLoop = true);
	void pauseBackGroundMusic();
	void resumeBackGroundMusic();
	void stopBackGroundMusic(bool isRelease);
	
	void setBackGroundMusicVolume(float vol);
	float getBackGroundMusicVolume();




};
#endif