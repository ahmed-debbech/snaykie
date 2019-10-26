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
  this->pointImg = IMG_Load("resources/point.png");
  srand(time(0));
    this->num_point_on_board = (rand() % 215) + 0;
    cout << this->num_point_on_board << endl;
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
