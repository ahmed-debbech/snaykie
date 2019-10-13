#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <vector>
#include <iterator>
#include "snake.h"
using namespace std;
void node :: setX(float x){
  this->position.x = x;
}
void node :: setY(float y){
  this->position.y = y;
}
float node :: getX(){
  return this->position.x;
}
float node :: getY(){
  return this->position.y;
}
void node :: setBodyImage(SDL_Surface * body){
  this->body = body;
}
SDL_Surface * node :: getBodyImage(){
  return body;
}
void snake :: setLength(int length){
  this->length = length;
}
float snake :: getLength (){
  return this->length;
}
snake :: snake(){
   int i;
  float x = 388.4;
  float y = 778.4;
  length = 3;
  SDL_Surface * body = IMG_Load("resources/body.png");
  for(i = 1; i <= 3; i++){
    node n;
    n.setX(x);
    n.setY(y);
    n.setBodyImage(body);
    v.push_back(n);
    x = x + 41;
  }
}
void snake :: showSnake(SDL_Surface * screen){
    for(int i = 0; i<= length-1; i++){
      SDL_Rect pos;
      pos.x = v[i].getX();
      pos.y = v[i].getY();
      SDL_BlitSurface(v[i].getBodyImage(), NULL, screen, &pos);
      cout << v[i].getBodyImage() << endl;
    }
}
