#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "widget.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <vector>
#include "button.h"
#include "toggle.h"

namespace Ui{

class Menu{
  SDL_Surface * background;
  SDL_Rect pos;
  std::vector <Widget*> ui_components;
public:
  void initialize();
  void print(SDL_Surface * screen);
  void mouseMotion(SDL_Event event);
  int mouseClick(SDL_Event event);
  ~Menu();
};

};
#endif
