#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <list>
#include <iterator>
#include "headers/board.h"
using namespace std;

board :: board(){
  position.x = 0;
  position.y = 0;
  image = IMG_Load("resources/board.png");
  int count = 0;
  int x = 13;
  int y = 50;
  m = new Map*[18];
  for(int i = 0; i<18; i++){
    x = 13;
    m[i] = new Map[12];
    for(int j = 0; j<12; j++){
      m[i][j].num = count;
      count++;
      m[i][j].x = x;
      m[i][j].y = y;
      x = x + 41;
    }
    y = y + 43;
  }
}
void board :: showBoard(SDL_Surface * screen){
  SDL_BlitSurface(this->image, NULL, screen, &position);
}
