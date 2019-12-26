#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <list>
#include <iterator>
#include "headers/arbitrator.h"
#include "headers/snake.h"
#include "headers/sound.h"

using namespace std;

arbitrator :: arbitrator(){
  pointScore = 0;
  m.initialize(M_GAME_OVER);
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
int arbitrator :: print_gameover_menu(SDL_Surface * screen){
  try{
    m.initialize(M_GAME_OVER);
  }catch(string s){
    cout << "ERROR: " << s << endl;
    return 0;
  }
  int choice = 0;
  Sound * s = new Sound();
  SDL_Event event;
  do{
    SDL_PollEvent(event);
    m.print(screen);
    switch(event.type){
      case SDL_QUIT: return 0;
      break;
      case SDL_MOUSEMOTION:
            m.mouseMotion(event,s);
      break;
      case SDL_MOUSEBUTTONDOWN:
            choice = m.mouseClick(event, s);
      break;
    }
  }while(choice <= 0);
  delete s;
  return choice;
}
bool arbitrator :: detectCollWithBoard(snake& s){
  SDL_Rect head_pos;
  head_pos = s.getNodes(0).getPosition();
  if((head_pos.x < MAX_L) || (head_pos.x > MAX_R)){
    return true;
  }else{
    if((head_pos.y > MAX_D) || (head_pos.y < MAX_U)){
      return true;
    }
  }
  return false;
}

bool arbitrator :: detectCollWithItself (snake & s){
  bool collision = false;
  int i = 1;
  while((i <= s.getLength()-1) && (collision == false)){
    if(s.getNodes(i).getNumberOnMap() == s.getNodes(0).getNumberOnMap()){
      collision = true;
    }else{
      i++;
    }
  }
return collision;
}
