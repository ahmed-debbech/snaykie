#ifndef ARBITRATOR_H
#define ARBITRATOR_H
#define MAX_U 45
#define MAX_R 500
#define MAX_L 13
#define MAX_D 800
#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <vector>
#include <iterator>
#include "board.h"
#include "snake.h"
using namespace std;

class arbitrator{
  SDL_Surface * gameover;
  int pointScore;
public:
  arbitrator();
  bool eat_check(int snake_pos, int point_pos);
  void print_points_on_board(SDL_Surface * screen);
  void update_points();
  void print_gameover(SDL_Surface * screen);
  bool detectCollWithBoard(snake&);
  bool detectCollWithItself(snake & );
};


#endif
