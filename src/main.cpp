#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "headers/snake.h"
#include "headers/board.h"
#include "headers/point.h"
#include "headers/arbitrator.h"
#include "headers/menu.h"
#include "SDL/SDL_mixer.h"
#include "headers/sound.h"

using namespace std;

int main (int argc, char **argv){
  // screen initialization
  SDL_Surface * screen = NULL;
  if(SDL_Init(SDL_INIT_VIDEO)!=0){
    cout << "ERROR: Unable to initialize SDL" << endl;
  	return 1;
  }
  //Initialize SDL SOUND
   if( Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
     cout << "ERROR: Unable to initialize SDL SOUNDS" << endl;
       return 1;
   }
  int choice = 0;
  do{
    Sound * s = new Sound();
  screen = SDL_SetVideoMode(500,350,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Snaykie", NULL);
  Ui::Menu * official_menu = new Ui::Menu;
  try{
    official_menu->initialize(M_OFFICIAL_MENU);
  }catch(string e){
    cout << e << endl;
    return 0; // quit the program
  }
  choice = 0;
  SDL_Event event;
  do{
    official_menu->print(screen);
    SDL_Flip(screen);
    while(SDL_PollEvent(&event) == 1){
      switch(event.type){
        case SDL_QUIT: return 0; //quit game
        break;
        case SDL_MOUSEMOTION:
        official_menu->mouseMotion(event, s);
        break;
        case SDL_MOUSEBUTTONDOWN:
        choice = official_menu->mouseClick(event,s);
        //if volume button is pressed
        if(choice == -1){
          if(s->getMuted() == true){
            s->setMuted(false);
          }else{
            s->setMuted(true);
          }
        }
        break;
      }
    }
  }while(choice <= 0);
  delete official_menu;
  bool game_done = false;
  snake * sn = NULL;
  board * bd = NULL;
  arbitrator * arb = NULL;
  point * po = NULL;
  int mouvement = -1;
  SDL_Event event_holder;
  int dir;
  bool firstTime = true;

  switch(choice){
    case 1:
      //begin game play initialization
      SDL_FreeSurface(screen);
      screen = SDL_SetVideoMode(525,900,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
      SDL_WM_SetCaption("Snaykie", NULL);
      bd = new board();
      sn = new snake();
      arb = new arbitrator();
      po = new point(*bd);
      bd->showBoard(screen);
      sn->showSnake(screen);
      po->showPoint(screen);
      arb->print_points_on_board(screen);
      SDL_Flip(screen);
      //end game play initialization
      //game loop
      while(game_done == false){
        SDL_PollEvent(&event);
          switch(event.type){
            case SDL_QUIT: // to quit the game
              return 0;
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
              if(event.key.keysym.sym == SDLK_b){
                game_done = true;
              }
              break;
          }
          if(firstTime == false){
            dir = sn->moveSnake(event);
            //if none event from the above happened
            //then make one depending on the head node direction
              if(dir == -1){
                SDL_Event ev;
                ev.type = SDL_KEYDOWN;
                switch(sn->getNodes(0).getDirection()){
                  case 'u': ev.key.keysym.sym = SDLK_UP;
                  break;
                  case 'd': ev.key.keysym.sym = SDLK_DOWN;
                  break;
                  case 'l': ev.key.keysym.sym = SDLK_LEFT;
                  break;
                  case 'r': ev.key.keysym.sym = SDLK_RIGHT;
                  break;
                }
                dir = sn->moveSnake(ev);
              }
            bd->showBoard(screen);
            sn->showSnake(screen);
            po->showPoint(screen);
            arb->print_points_on_board(screen);
            //check for win
            if(arb->eat_check(sn->getNodes(0).getNumberOnMap(), po->getPointNum()) == true){
              delete po;
              po = new point(*bd);
              sn->addExtraBody();
              sn->setLength(sn->getLength() + 1);
              arb->update_points();
              s->playSound(EAT_POINT);
            }else{
              if(arb->detectCollWithBoard(*sn)== true){
                 s->playSound(WALL_HIT);
                arb->print_gameover_menu(screen,event);
                SDL_Flip(screen);
                game_done = true;
              }
              if(arb->detectCollWithItself(*sn) == true){
                s->playSound(EAT_ITSELF);
                arb->print_gameover_menu(screen,event);
                SDL_Flip(screen);
                game_done = true;
              }
            }
            SDL_Flip(screen);
            SDL_Delay(200);
            while(SDL_PollEvent(&event) != 0);
        }
      }
      delete bd;
      delete sn;
      delete arb;
      delete po;
    break;
    case 2:
      SDL_Surface * about = NULL;
      about = IMG_Load("resources/menu/menu_about.png");
      SDL_Rect pos;
      pos.x= 0; pos.y = 0; pos.h = about->h; pos.w = about->w;
      SDL_BlitSurface(about , NULL, screen, &pos);
      SDL_Flip(screen);
      SDL_Delay(5000);
      SDL_FreeSurface(about);
    break;
  }
  delete s;
}while(choice > 0); //while the choice of the user is always not a quit button
  SDL_FreeSurface(screen);
  SDL_CloseAudio();
  SDL_Quit();
  return 0;
}
