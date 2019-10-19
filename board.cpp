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
  for(int i = 0; i<18; i++){
    for(int j = 0; j<12; j++){
      map[i][j] = count;
      count++;
    }
  }
}
void board :: showBoard(SDL_Surface * screen){
  SDL_BlitSurface(this->image, NULL, screen, &position);
}
