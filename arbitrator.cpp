#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <list>
#include <iterator>
#include "arbitrator.h"
#include "snake.h"
using namespace std;

arbitrator :: arbitrator(){
  pointScore = 0;
  gameover = IMG_Load("resources/gameover.png");
}
bool arbitrator :: eat_check(int snake_pos, int point_pos){
  if(snake_pos == point_pos){
      return true;
  }else{
    return false;
  }
}
void arbitrator :: print_points_on_board(SDL_Surface * screen){
  char ch[128];
    SDL_Surface *value = NULL;
    SDL_Rect valuePos;
    TTF_Font *police = NULL;
    SDL_Color color = {220, 20, 60};
    if (TTF_Init() < 0) {
      printf("Error openning ttf\n");
    }else{
      police = TTF_OpenFont("resources/font.ttf", 30);
      if (police == NULL) {
        printf("Error in opening font file\n");
      }else{
        sprintf(ch, "%d", this->pointScore);
        value=TTF_RenderText_Solid(police, ch, color);
        TTF_CloseFont(police);
        TTF_Quit();
      }
      valuePos.x = 96;
      valuePos.y = 2;
      SDL_BlitSurface(value, NULL, screen, &valuePos);
    }
}
void arbitrator :: update_points(){
  pointScore++;
}
void arbitrator :: print_gameover(SDL_Surface * screen){
  SDL_Rect pos;
  pos.x = 112;
  pos.y = 277;
  pos.h = gameover->h;
  pos.w = gameover->w;
    SDL_BlitSurface(gameover, NULL, screen, &pos);
}
bool arbitrator :: detectCollWithBoard(snake& s){
  SDL_Rect head_pos;
  head_pos.x = s.getNodes(0).getX();
  head_pos.y = s.getNodes(0).getY();
  if((head_pos.x < 10) || (head_pos.x > 512) || (head_pos.y > 821) || (head_pos.y < 40)){
    return true;
  }
  return false;
}

bool arbitrator :: detectCollWithItself (snake & s){
  bool collision = false;
  int i = 1;
  while((i <= s.getLength()) && (collision == false)){
    if(s.getNodes(i).getNumberOnMap() == s.getNodes(0).getNumberOnMap()){
      collision = true;
    }else{
      collision = false;
      i++;
    }
  }
return collision;
}
