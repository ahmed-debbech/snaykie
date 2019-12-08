#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include "button.h"
#include "widget.h"

namespace Ui{

Button::Button(std::string name, SDL_Rect position, SDL_Surface * img) : Widget(name,position,img){

}
Button :: ~Button(){
  SDL_FreeSurface(hover);
}
void Button :: showHover(SDL_Surface * screen){
  std::cout << "test" << std::endl;
}

};
