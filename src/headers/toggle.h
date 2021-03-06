#ifndef TOGGLE_H
#define TOGGLE_H
#include <iostream>
#include "widget.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

namespace Ui{

class Toggle : public Widget{
  SDL_Surface * onClickImg;
  bool isClicked;
public:
  Toggle(std::string name, SDL_Rect position, SDL_Surface * img); // it will initialize base class as well
  void showOnClickImg(SDL_Surface * screen);
  void setImageClicked(SDL_Surface*);
  void setFlag(bool f){isClicked = f;}
  bool getFlag() { return isClicked;}
  void print(SDL_Surface * screen);
  ~Toggle();
};

};
#endif
