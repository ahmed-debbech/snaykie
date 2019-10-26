#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
using namespace std;

class point{
  int num_point_on_board;
  SDL_Surface * pointImg;
  SDL_Rect pointPos;
public:
  point();
  int getPointNum(){return this->num_point_on_board;}
  void showPoint(SDL_Rect pos, SDL_Surface * screen);
  ~point();
};
#endif
