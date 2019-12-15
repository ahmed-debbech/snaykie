#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <string>

namespace Ui{

class Widget{
  protected :
  std::string objName;
  SDL_Rect pos;
  SDL_Surface * image;

public:
  Widget(std::string name, SDL_Rect position, SDL_Surface * img){
    objName = name;
    pos=position;
    image=img;
  }
  void setName(std::string obj){ objName = obj;}
  std::string getName(){ return objName;}
  void setPos(SDL_Rect p){ pos = p;}
  SDL_Rect getPos(){ return pos;}
  virtual void print(SDL_Surface*)=0;
  virtual ~Widget();
};

};
#endif
