#include <iostream>
#include "menu.h"
#include <vector>
#include "button.h"
#include "toggle.h"
using namespace std;

namespace Ui{

bool Menu :: initialize(){
  background = IMG_Load("resources/menu/menu_back.png");
  if(background != NULL){
    pos.x = 0; pos.y = 0;
    pos.h = background->h;
    pos.w = background->w;
    SDL_Surface * buff = NULL;
    SDL_Rect posbut;
    Widget * w = NULL;
    //play button init ====
    buff = IMG_Load("resources/menu/play_button.png");
    if(buff != NULL){
      posbut.x = 165; posbut.h = buff->h;
      posbut.y = 180; posbut.w = buff->w;
      w = new Button("playbutton", posbut, buff);
      ui_components.push_back(w);
      //about button init ====
      buff = IMG_Load("resources/menu/about_button.png");
      if(buff != NULL){
        posbut.x = 165; posbut.h = buff->h;
        posbut.y = 257; posbut.w = buff->w;
         w = new Button("aboutbutton", posbut, buff);
        ui_components.push_back(w);
        init = true;
        //volume toggle init ====
        buff = IMG_Load("resources/menu/volume_button.png");
        if(buff != NULL){
          posbut.x = 469; posbut.h = buff->h;
          posbut.y = 326; posbut.w = buff->w;
           w = new Toggle("volumetoggle", posbut, buff);
          ui_components.push_back(w);
          init = true;
        }else{
          init = false;
        }
      }else{
        init = false;
      }
    }else{
      init = false;
    }
  }else{
    init = false;
  }
  return init;
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
