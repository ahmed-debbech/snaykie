#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "board.h"

using namespace std;

class node{
  SDL_Rect position;
  int numberOfPosOnMap;
  SDL_Surface * body;
  char dir;
  char nextDir;
public:
  SDL_Rect getPosition(){ return position;}
  void setPosition(SDL_Rect pos){ this->position = pos;}
  char getDirection();
  void setNextDirection(char nextDir);
  char getNextDirection();
  void setDirection(char dir);
  void setBodyImage(SDL_Surface * body);
  SDL_Surface * getBodyImage();
  void setNumberOnMap(int num){this->numberOfPosOnMap = num;}
  int getNumberOnMap(){
    return numberOfPosOnMap;
  }
};
#endif
