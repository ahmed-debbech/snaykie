#ifndef SOUND_H
#define SOUND_H

#define CLICK "click.wav"
#define EAT_ITSELF "eatitself.wav"
#define EAT_POINT "eatpoint.wav"
#define HOVER "hover.wav"
#define LOSE "lose.wav"
#define MOUVEMENT "mouvement.wav"
#define PAUSE "pause.wav"
#define WALL_HIT "wallhit.wav"

#include "SDL/SDL_mixer.h"
#include <map>

using namespace std;

class Sound{
    map <string, Mix_Chunk*> sfx;
public:
  Sound();
  void playSound(string chunkName);
  ~Sound();
};
#endif
