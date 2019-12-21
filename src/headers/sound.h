#ifndef SOUND_H
#define SOUND_H

#include "SDL/SDL_mixer.h"
#include <vector>

using namespace std;

class Sound{
    vector <Mix_Chunk*> sfx;
public:
  Sound();
  void playSound();
  ~Sound();
};
