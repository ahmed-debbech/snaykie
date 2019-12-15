#include <iostream>
#include "widget.h"

namespace Ui{


Widget :: ~Widget(){
  SDL_FreeSurface(image);
}
void Widget :: print (SDL_Surface*screen){
  SDL_BlitSurface(image, NULL, screen, &pos);
}
};
