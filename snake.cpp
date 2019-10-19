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
char node :: getDirection(){
  return this->dir;
}
void node :: setDirection(char dir){
  this->dir = dir;
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
    n.setDirection('o');
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
    }
}
int snake :: moveSnake(SDL_Event event){
  if(event.key.keysym.sym == SDLK_UP){
    int y;
    int nodes_counter = 0; bool test = false;
      while((test == false) && (nodes_counter <= length-1)){
          if(v[nodes_counter].getDirection() == 'u'){
             y = v[nodes_counter].getY();
            y = y - 43;
            v[nodes_counter].setY(y);
          }else{
            v[nodes_counter].setDirection('u');
             y = v[nodes_counter].getY();
            y = y - 43;
            v[nodes_counter].setY(y);
            test = true;
          }
          nodes_counter++;
      }
      for(int i = nodes_counter; i<=length-1; i++){
          switch(v[i].getDirection()){
            case 'r':
            v[i].setDirection('u');
             y = v[i].getY();
            y = y - 43;
            v[i].setY(y);
            test = true;
              break;
            case 'l':
            v[i].setDirection('u');
            y = v[i].getY();
            y = y - 43;
            v[i].setY(y);
            test = true;
              break;
          }
      }
    return 1;
  }else{
    if(event.key.keysym.sym == SDLK_RIGHT){
      int x = v[0].getX();
      x = x + 41;
      v[0].setX(x);
      return 2;
    }else{
      if(event.key.keysym.sym == SDLK_LEFT){
        int x = v[0].getX();
        x = x - 41;
        v[0].setX(x);
        return 3;
      }else{
        if(event.key.keysym.sym == SDLK_DOWN){
          int y = v[0].getY();
          y = y + 43;
          v[0].setY(y);
          return 4;
        }else{
          return -1;
        }
      }
    }
  }
}
