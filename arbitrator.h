#ifndef ARBITRATOR_H
#define ARBITRATOR_H

#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <vector>
#include <iterator>
using namespace std;

class arbitrator{
  SDL_Surface * gameover;
  int pointScore;
public:
  arbitrator();
  bool eat_check(int snake_pos, int point_pos);
  bool crash_board_check(int snake_pos);
  void print_points_on_board(SDL_Surface * screen);
  void update_points();
  void print_gameover(SDL_Surface * screen);
};


#endif
