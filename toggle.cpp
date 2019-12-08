#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include "toggle.h"
#include "widget.h"

namespace Ui{

Toggle :: Toggle(std::string name, SDL_Rect position, SDL_Surface * img) : Widget(name,position,img){

}
Toggle :: ~Toggle(){
  SDL_FreeSurface(onClickImg);
}
void Toggle :: showOnClickImg(SDL_Surface * screen){
  
}


};
