#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <list>
#include <iterator>
#include "snake.h"
#include "board.h"
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
  SDL_Flip(screen);
  while(game_done == false){
  }
  SDL_FreeSurface(screen);
  SDL_Quit();
  return 0;
}
