#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <iterator>
 using namespace std;

class board{
  SDL_Rect position;
  SDL_Surface * image;
public:
  board();
  void showBoard(SDL_Surface * screen);
};
#endif