#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "node.h"

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
char node :: getDirection(){
  return this->dir;
}
void node :: setDirection(char dir){
  this->dir = dir;
}
char node :: getNextDirection(){
  return this->nextDir;
}
void node :: setNextDirection(char nextDir){
  this->nextDir = nextDir;
}
