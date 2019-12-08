#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include "widget.h"
#include <string>

namespace Ui{


Widget :: ~Widget(){
  SDL_FreeSurface(image);
}
void Widget :: print (SDL_Surface*screen){
  SDL_BlitSurface(image, NULL, screen, &pos);
}
};
