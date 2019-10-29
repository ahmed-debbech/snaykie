#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <list>
#include <iterator>
#include "board.h"
using namespace std;

board :: board(){
  position.x = 0;
  position.y = 0;
  pos_head_snake_on_map = 213;
  image = IMG_Load("resources/board.png");
  int count = 0;
  int x = 13;
  int y = 50;
  for(int i = 0; i<18; i++){
    x = 13;
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
SDL_Rect board :: get_right_pos_on_map(){
  int i=0,j=0; SDL_Rect pos;
  for(int i = 0; i<18; i++){
    for(int j = 0; j<12; j++){
      if(m[i][j].num == this->pointImgPos){
        pos.x = m[i][j].x;
        pos.y = m[i][j].y;
        return pos;
      }
    }
  }
  pos.x=-1; pos.y=-1;
  return pos;
}
void board :: showBoard(SDL_Surface * screen){
  SDL_BlitSurface(this->image, NULL, screen, &position);
}
