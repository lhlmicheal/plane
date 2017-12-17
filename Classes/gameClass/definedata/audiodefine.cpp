#include "audiodefine.h"
#include <stdlib.h>
static AudioDefineData* audiodefine = NULL;
AudioDefineData* AudioDefineData::sharedData()
{
	if(audiodefine == NULL)
	{
		audiodefine = new AudioDefineData();
	}
	return audiodefine;
}