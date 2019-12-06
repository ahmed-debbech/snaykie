#include <iostream>
#include "menu.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "button.h"
#include <vector>
#include "button.h"
#include "widget.h"

using namespace std;

namespace Ui{

bool Menu :: initialize(){
  background = IMG_Load("resources/menu/menu_back.png");
  pos.x = 0; pos.y = 0;
  pos.h = background->h;
  pos.w = background->w;
  SDL_Surface * buff = NULL;
  SDL_Rect pos;
  Widget * w = NULL;
  //play button init ====
  buff = IMG_Load("resources/menu/play_button.png");
  pos.x = 142; pos.h = buff->h;
  pos.y = 180; pos.w = buff->w;
  w = new Button("playbutton", pos, buff);
  ui_components.push_back(w);
  //about button init ====
  buff = IMG_Load("resources/menu/play_button.png");
  pos.x = 142; pos.h = buff->h;
  pos.y = 257; pos.w = buff->w;
   w = new Button("aboutbutton", pos, buff);
  ui_components.push_back(w);
}
void Menu :: print(SDL_Surface * screen){
  SDL_BlitSurface(background, NULL, screen, &pos);
  for(int i=0; i<=ui_components.size()-1;i++){
    ui_components[i]->print(screen);
  }
}

Menu :: ~Menu(){
  SDL_FreeSurface(background);
  for(int i =0; i <= ui_components.size()-1; i++){
    delete ui_components[i];
  }
}
};
