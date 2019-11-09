#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <list>
#include <iterator>
#include "arbitrator.h"
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
    SDL_Color color = {230, 0, 0};
    if (TTF_Init() < 0) {
      printf("Error openning ttf\n");
    }else{
      police = TTF_OpenFont("resources/font.ttf", 20);
      if (police == NULL) {
        printf("Error in opening font file\n");
      }else{
        sprintf(ch, "%d", this->pointScore);
        value=TTF_RenderText_Solid(police, ch, color);
        TTF_CloseFont(police);
        TTF_Quit();
      }
      valuePos.x = 96;
      valuePos.y = 13;
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
bool arbitrator :: crash_board_check(int snake_pos){
    bool test = false;
    if((snake_pos < 0) || (snake_pos > 215)){
      test = true;
    }else{
      test = false;
    }
    return test;
}
