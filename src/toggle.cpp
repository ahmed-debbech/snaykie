#include <iostream>
#include "headers/toggle.h"
#include "headers/widget.h"

namespace Ui{

Toggle :: Toggle(std::string name, SDL_Rect position, SDL_Surface * img) : Widget(name,position,img){

}
Toggle :: ~Toggle(){
  SDL_FreeSurface(onClickImg);
}
void Toggle :: showOnClickImg(SDL_Surface * screen){

}

void Toggle::setImageClicked(SDL_Surface * i){
  onClickImg = i;
}

void Toggle :: print(SDL_Surface * screen){
  if(isClicked == true){
    SDL_BlitSurface(onClickImg, NULL, screen, &pos);
  }else{
    SDL_BlitSurface(image, NULL, screen, &pos);
  }
}
};
