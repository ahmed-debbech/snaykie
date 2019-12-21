#include <iostream>
#include "headers/sound.h"
#include <string>
#include <iterator>
using namespace std;

Sound::Sound(){
    char path [128];
    strcpy(path, "resources/sfx/");
    strcat(path, CLICK);
    Mix_Chunk * c = Mix_LoadWAV(path);
    sfx.insert({CLICK, c});

    strcpy(path, "resources/sfx/");
    strcat(path, EAT_ITSELF);
    c = Mix_LoadWAV(path);
    sfx.insert({EAT_ITSELF, c});

    strcpy(path, "resources/sfx/");
    strcat(path, EAT_POINT);
    c = Mix_LoadWAV(path);
    sfx.insert({EAT_POINT, c});

    strcpy(path, "resources/sfx/");
    strcat(path, HOVER);
    c = Mix_LoadWAV(path);
    sfx.insert({HOVER, c});

    strcpy(path, "resources/sfx/");
    strcat(path, LOSE);
    c = Mix_LoadWAV(path);
    sfx.insert({LOSE, c});

    strcpy(path, "resources/sfx/");
    strcat(path, MOUVEMENT);
    c = Mix_LoadWAV(path);
    sfx.insert({MOUVEMENT, c});

    strcpy(path, "resources/sfx/");
    strcat(path, PAUSE);
    c = Mix_LoadWAV(path);
    sfx.insert({PAUSE, c});

    strcpy(path, "resources/sfx/");
    strcat(path, WALL_HIT);
    c = Mix_LoadWAV(path);
    sfx.insert({WALL_HIT, c});
}
Sound::~Sound(){
  for(map<string, Mix_Chunk*> :: iterator it = sfx.begin(); it != sfx.end(); it++){
    Mix_FreeChunk(it->second);
    sfx.erase(it);
  }
}
void Sound::playSound(string chunkName){
  map<string, Mix_Chunk*> :: iterator it;
  it = sfx.find(chunkName);
  Mix_PlayChannel(-1,it->second,0);
}
