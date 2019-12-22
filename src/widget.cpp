#include <iostream>
#include "headers/widget.h"

namespace Ui{


Widget :: ~Widget(){
  SDL_FreeSurface(image);
}
};
