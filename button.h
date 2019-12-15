#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "widget.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

namespace Ui{

class Button : public Widget{
  SDL_Surface * hover;
  bool isHovered;
public:
    void showHover(SDL_Surface * screen);
    Button(std::string name, SDL_Rect position, SDL_Surface * img); // it will initialize base class as well
    void setImageHover(SDL_Surface *);
    void setFlag(bool f){isHovered = f;}
    bool getFlag() { return isHovered;}
   ~Button();
};


};
#endif
