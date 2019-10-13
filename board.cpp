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
  image = IMG_Load("resources/board.png");
}
void board :: showBoard(SDL_Surface * screen){
  SDL_BlitSurface(this->image, NULL, screen, &position);
}
