#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

 using namespace std;

typedef struct{
  int num;
  int y;
  int x;
}Map;
class board{
  SDL_Rect position;
  SDL_Surface * image;
  Map ** m;
public:
  board();
  void showBoard(SDL_Surface * screen);
  Map ** getMap(){ return m;}
};

#endif
