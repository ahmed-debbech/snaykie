#ifndef MENU_H
#define MENU_H
#define M_GAME_OVER 2
#define M_OFFICIAL_MENU 1

#include <iostream>
#include "widget.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <vector>
#include "button.h"
#include "toggle.h"
#include "sound.h"

namespace Ui{

class Menu{
  SDL_Surface * background;
  SDL_Rect pos;
  std::vector <Widget*> ui_components;
public:
  void initialize(int x);
  void print(SDL_Surface * screen);
  void mouseMotion(SDL_Event event, Sound * s);
  int mouseClick(SDL_Event event, Sound * s);
  ~Menu();
};

};
#endif
