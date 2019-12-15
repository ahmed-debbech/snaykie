#include <iostream>
#include "widget.h"

namespace Ui{


Widget :: ~Widget(){
  SDL_FreeSurface(image);
}
};
