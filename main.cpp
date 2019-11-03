#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "snake.h"
#include "board.h"
#include "point.h"
#include "arbitrator.h"
using namespace std;

int main (int argc, char **argv){
  // screen initialization
  SDL_Surface * screen = NULL;
  if(SDL_Init(SDL_INIT_VIDEO)!=0){
  printf("unable to initialize SDL: %s \n",SDL_GetError());
  	return 1;
  }  screen=SDL_SetVideoMode(525,900,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Snaykie", NULL);
  bool game_done = false;
  snake sn;
  board bd;

  bd.showBoard(screen);
  sn.showSnake(screen);
  point * po = new point;
  bd.setPointPos(po->getPointNum());
  SDL_Rect pointPos = bd.get_right_pos_on_map();
  po->showPoint(pointPos,screen);
  SDL_Flip(screen);
  int mouvement = -1;
  SDL_Event event;
  SDL_Event event_holder;
  while(game_done == false){
    event = event_holder;
    SDL_PollEvent(&event);
      switch(event.type){
        case SDL_QUIT: // to quit the game
          game_done = true;
          break;
          case SDL_KEYDOWN:
             if(event.key.keysym.sym == SDLK_RIGHT){
              event_holder = event;
            }else{
              if(event.key.keysym.sym == SDLK_LEFT){
                event_holder = event;
              }else{
                if(event.key.keysym.sym == SDLK_UP){
                  event_holder =event;
                }else{
                  if(event.key.keysym.sym == SDLK_DOWN){
                    event_holder =event;
                  }else{
                    event = event_holder;
                  }
                }
              }
            }
          break;
          case SDL_MOUSEBUTTONDOWN:
          while(SDL_PollEvent(&event) != 0);
          event = event_holder;
          break;
          case SDL_MOUSEMOTION:
          while(SDL_PollEvent(&event) != 0);
          event = event_holder;
          break;
      }
      while(SDL_PollEvent(&event) != 0);
      sn.moveSnake(event);
      bd.showBoard(screen);
      sn.showSnake(screen);
      po->showPoint(pointPos, screen);
      SDL_Flip(screen);
      SDL_Delay(250);
  }
  SDL_FreeSurface(screen);
  SDL_Quit();
  return 0;
}
