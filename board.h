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
  Map m [18][12];
  int pos_head_snake_on_map;
  int pointImgPos;
public:
  board();
  void showBoard(SDL_Surface * screen);
  int getSnakeHeadPos(){return this->pos_head_snake_on_map;};
  void setSnakeHeadPos(int dir);
   int getPointPos(){return this->pointImgPos;};
    void setPointPos(int pointPos){this->pointImgPos = pointPos;};
  SDL_Rect get_right_pos_on_map();
};

#endif
