#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
using namespace std;

class point{
  int num_point_on_board;
public:
  int getPointNum(){return this->num_point_on_board;}
  void setPointNum(int num){this->num_point_on_board = num;}

};
#endif
