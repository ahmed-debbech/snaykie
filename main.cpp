#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "snake.h"
#include "board.h"
#include "point.h"
#include "arbitrator.h"
#include "menu.h"
using namespace std;

int main (int argc, char **argv){
  // screen initialization
  SDL_Surface * screen = NULL;
  if(SDL_Init(SDL_INIT_VIDEO)!=0){
  printf("ERROR: Unable to initialize SDL: %s \n",SDL_GetError());
  	return 1;
  }
  //initializing screen
  screen = SDL_SetVideoMode(500,350,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Snaykie", NULL);
  Ui::Menu official_menu;
  try{
    official_menu.initialize();
  }catch(string e){
    cout << e << endl;
    return 1; // quit the program
  }
  bool quit_menu = false;
  SDL_Event event;
  //handle menu events
  do{
    official_menu.print(screen);
    SDL_Flip(screen);
    while(SDL_PollEvent(&event) == 1){
      switch(event.type){
        case SDL_QUIT: return 1; //quit game
        break;
        case SDL_MOUSEMOTION:
        official_menu.mouseMotion(event);
        break;
        case SDL_MOUSEBUTTONDOWN:
        break;
      }
    }
  }while(quit_menu == false);
  //begin game play initialization
  bool game_done = false;
  snake sn;
  board bd;
  arbitrator arb;
  bd.showBoard(screen);
  sn.showSnake(screen);
  point * po = new point(bd);
  po->showPoint(screen);
  arb.print_points_on_board(screen);
  SDL_Flip(screen);
  int mouvement = -1;
  SDL_Event event_holder;
  int dir;
  bool firstTime = true;
  //end game play initialization
//game loop
  while(game_done == false){
    SDL_PollEvent(&event);
      switch(event.type){
        case SDL_QUIT: // to quit the game
          game_done = true;
          break;
          case SDL_MOUSEBUTTONDOWN:
          while(SDL_PollEvent(&event) != 0);
          event = event_holder;
          break;
          case SDL_MOUSEMOTION:
          while(SDL_PollEvent(&event) != 0);
          event = event_holder;
          break;
          case SDL_KEYDOWN: firstTime = false;
          break;
      }
      if(firstTime == false){
        dir = sn.moveSnake(event);
        //if none event from the above happened
        //then make one depending on the head node direction
          if(dir == -1){
            SDL_Event ev;
            ev.type = SDL_KEYDOWN;
            switch(sn.getNodes(0).getDirection()){
              case 'u': ev.key.keysym.sym = SDLK_UP;
              break;
              case 'd': ev.key.keysym.sym = SDLK_DOWN;
              break;
              case 'l': ev.key.keysym.sym = SDLK_LEFT;
              break;
              case 'r': ev.key.keysym.sym = SDLK_RIGHT;
              break;
            }
            dir = sn.moveSnake(ev);
          }
        bd.showBoard(screen);
        sn.showSnake(screen);
        po->showPoint(screen);
        arb.print_points_on_board(screen);
        //check for win
        if(arb.eat_check(sn.getNodes(0).getNumberOnMap(), po->getPointNum()) == true){
          delete po;
          po = new point(bd);
          sn.addExtraBody();
          sn.setLength(sn.getLength() + 1);
          arb.update_points();
        }else{
          if(arb.detectCollWithBoard(sn)== true){
            arb.print_gameover(screen);
            SDL_Flip(screen);
            SDL_Delay(3000);
            game_done = true;
          }
          if(arb.detectCollWithItself(sn) == true){
            arb.print_gameover(screen);
            SDL_Flip(screen);
            SDL_Delay(3000);
            game_done = true;
          }
        }
        SDL_Flip(screen);
        sn.show();
        SDL_Delay(200);
        while(SDL_PollEvent(&event) != 0);
    }
  }
  SDL_FreeSurface(screen);
  SDL_Quit();
  return 0;
}
