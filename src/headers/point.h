#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "board.h"
using namespace std;

class point{
  int num_point_on_board;
  SDL_Surface * pointImg;
  SDL_Rect pointPos;
public:
  point(board &);
  int getPointNum(){return this->num_point_on_board;}
  void showPoint(SDL_Surface*);
  SDL_Rect get_xy_point_on_map(board &);
  ~point();
};
#endif
