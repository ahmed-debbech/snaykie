#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <list>
#include <iterator>
#include "board.h"
using namespace std;

arbitrator :: arbitrator(){
  pointScore = 0;
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
        fclose(f)
      }
      valuePos.x = 96;
      valuePos.y = 13;
      SDL_BlitSurface(value, NULL, screen, &valuePos);
    }
}
void arbitrator :: update_points(){
  pointScore++;
}
