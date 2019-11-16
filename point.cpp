#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "point.h"
#include "board.h"
#include <ctime>
#include <cstdlib>
using namespace std;

point :: point(board & b){
  static bool first_time = true;
  this->pointImg = IMG_Load("resources/point.png");
  srand(time(0));
  if(first_time = true){
    this->num_point_on_board = (rand() % 200) + 0;
    first_time = false;
  }else{
    this->num_point_on_board = (rand() % 215) + 0;
  }
  Map ** m = b.getMap();
  bool test = false;
  for(int i = 0; (i<18) && (test == false); i++){
    for(int j = 0; (j<12) && (test == false); j++){
      if(m[i][j].num == this->num_point_on_board){
        pointPos.x = m[i][j].x;
        pointPos.y = m[i][j].y;
        test = true;
      }
    }
  }
}
point :: ~point(){
  SDL_FreeSurface(this->pointImg);
}
void point :: showPoint(SDL_Surface * screen){
  pointPos.h = pointImg->h;
  pointPos.w = pointImg->w;
  SDL_BlitSurface(pointImg, NULL, screen, &pointPos);
}
SDL_Rect point :: get_xy_point_on_map(board& b){
   SDL_Rect pos;
   Map ** m = b.getMap();
  for(int i = 0; i<18; i++){
    for(int j = 0; j<12; j++){
      if(m[i][j].num == this->num_point_on_board){
        pos.x = m[i][j].x;
        pos.y = m[i][j].y;
        return pos;
      }
    }
  }
  pos.x=-1; pos.y=-1;
  return pos;
}
