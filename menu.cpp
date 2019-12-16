#include <iostream>
#include "menu.h"
#include <vector>
#include <typeinfo>
#include "button.h"
#include "toggle.h"
using namespace std;

namespace Ui{

void Menu :: initialize(){
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
      SDL_Surface * buff1 = IMG_Load("resources/menu/play_button_hovered.png");
      if(buff1 == NULL){
        throw "Can't load resources";
      }
      w->setAction(1);
      ((Button*)w)->setImageHover(buff1);
      ((Button *)w)->setFlag(false);
      ui_components.push_back(w);

      //about button init ====
      buff = IMG_Load("resources/menu/about_button.png");
      if(buff != NULL){
        posbut.x = 165; posbut.h = buff->h;
        posbut.y = 257; posbut.w = buff->w;
         w = new Button("aboutbutton", posbut, buff);
         SDL_Surface * buff1 = IMG_Load("resources/menu/about_button_hovered.png");
         if(buff1 == NULL){
           throw "Can't load resources";
         }
         w->setAction(2);
         ((Button*)w)->setImageHover(buff1);
         ((Button *)w)->setFlag(false);
        ui_components.push_back(w);

        //volume toggle init ====
        buff = IMG_Load("resources/menu/volume_button.png");
        if(buff != NULL){
          posbut.x = 469; posbut.h = buff->h;
          posbut.y = 326; posbut.w = buff->w;
           w = new Toggle("volumetoggle", posbut, buff);
           SDL_Surface * buff1 = IMG_Load("resources/menu/volume_button_muted.png");
           if(buff1 == NULL){
             throw "Can't load resources";
           }
           w->setAction(3);
           ((Toggle*)w)->setImageClicked(buff1);
           ((Toggle *)w)->setFlag(false);
           ui_components.push_back(w);
        }else{
          throw "Can't load resources";
        }
      }else{
        throw "Can't load resources";
      }
    }else{
      throw "Can't load resources";
    }
  }else{
    throw "Can't load resources";
  }
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
void Menu :: mouseMotion(SDL_Event event){
  for(int i =0; i<= ui_components.size()-1; i++){
    if(((event.motion.x <= (ui_components[i]->getPos().x + ui_components[i]->getPos().w))
    && (event.motion.x >= ui_components[i]->getPos().x))
    && ((event.motion.y >= ui_components[i]->getPos().y)
    && (event.motion.y <= (ui_components[i]->getPos().y + ui_components[i]->getPos().h)))){
      if(typeid(*(ui_components[i])) == typeid(Button)){
          ((Button*)ui_components[i])->setFlag(true);
      }
    }else{
      if(typeid(*(ui_components[i])) == typeid(Button)){
          ((Button*)ui_components[i])->setFlag(false);
      }
    }
  }
}

int Menu :: mouseClick(SDL_Event event){
  for(int i =0; i<= ui_components.size()-1; i++){
    if(((event.button.x <= (ui_components[i]->getPos().x + ui_components[i]->getPos().w))
    && (event.button.x >= ui_components[i]->getPos().x))
    && ((event.button.y >= ui_components[i]->getPos().y)
    && (event.button.y <= (ui_components[i]->getPos().y + ui_components[i]->getPos().h)))){
      return ui_components[i]->getAction();
    }
  }
  return -1;
}

};
