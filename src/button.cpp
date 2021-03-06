#include <iostream>
#include "headers/button.h"
#include "headers/widget.h"

namespace Ui{

Button::Button(std::string name, SDL_Rect position, SDL_Surface * img) : Widget(name,position,img){

}
Button :: ~Button(){
  SDL_FreeSurface(hover);
}
void Button :: showHover(SDL_Surface * screen){
  std::cout << "test" << std::endl;
}

void Button::setImageHover(SDL_Surface * h){
  hover = h;
}
void Button :: print(SDL_Surface * screen){
  if(isHovered == true){
    SDL_BlitSurface(hover, NULL, screen, &pos);
  }else{
    SDL_BlitSurface(image, NULL, screen, &pos);
  }
}
};
