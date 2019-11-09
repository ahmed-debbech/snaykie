#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "point.h"
#include <ctime>
#include <cstdlib>
using namespace std;

point :: point(){
  static bool first_time = true;
  this->pointImg = IMG_Load("resources/point.png");
  srand(time(0));
  if(first_time = true){
    this->num_point_on_board = (rand() % 200) + 0;
    first_time = false;
  }else{
    this->num_point_on_board = (rand() % 215) + 0;
  }
}
point :: ~point(){
  //increment the points text;
  SDL_FreeSurface(this->pointImg);
}
void point :: showPoint(SDL_Rect pos, SDL_Surface*screen){
  pointPos.x = pos.x;
  pointPos.y = pos.y;
  pointPos.h = pointImg->h;
  pointPos.w = pointImg->w;
  SDL_BlitSurface(pointImg, NULL, screen, &pointPos);
}
