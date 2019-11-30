#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <vector>
#include <iterator>
#include "node.h"

using namespace std;

class snake{
  int length;
  SDL_Surface * head;
  vector <node> v;
  int pos_head_snake_on_map;
  void update_nodes_num_on_map(char, node&);
  void update_nodes_num_on_map(node&, const node&);
public:
  snake();
  void setLength(int length);
  float getLength ();
  void addExtraBody();
  void showSnake(SDL_Surface * screen);
  int moveSnake(SDL_Event event);
  node getNodes(int);
  void show(){
    cout << "************************" << endl;
    cout << "************************" << endl;
    for(int i=0;i <= v.size()-1; i++){
      if(i == 0){ cout << "HEAD --> ";}
      cout << i << ": " << v[i].getNumberOnMap() << endl;
    }
  }
};
#endif
