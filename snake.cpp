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
char node :: getNextDirection(){
  return this->nextDir;
}
void node :: setNextDirection(char nextDir){
  this->nextDir = nextDir;
}



void snake :: setLength(int length){
  this->length = length;
}
float snake :: getLength (){
  return this->length;
}

snake :: snake(){
   int i;
  float x = 387.4;
  float y = 778.4;
  length = 3;
  SDL_Surface * body = IMG_Load("resources/body.png");
  SDL_Surface * head = IMG_Load("resources/head.png");
  for(i = 0; i <= length-1; i++){
    if(i == 0){
      node n;
      n.setX(x);
      n.setY(y);
      n.setBodyImage(head);
      n.setDirection('l');
      n.setNextDirection('h');
      v.push_back(n);
      x = x + 41;
    }else{
      node n;
      n.setX(x);
      n.setY(y);
      n.setBodyImage(body);
      n.setDirection('l');
      n.setNextDirection('l');
      v.push_back(n);
      x = x + 41;
    }
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
  int y,x, z ;
  if(event.key.keysym.sym == SDLK_UP){
    if(v[0].getDirection() != 'd'){
      v[0].setDirection('u');
      y = v[0].getY();
      y = y - 43;
      v[0].setY(y);
      z =1;
    }else{
      v[0].setDirection('d');
      y = v[0].getY();
      y = y + 43;
      v[0].setY(y);
      z =4;
    }
  }else{
    if(event.key.keysym.sym == SDLK_RIGHT){
      if(v[0].getDirection() != 'l'){
        v[0].setDirection('r');
        x = v[0].getX();
        x = x + 41;
        v[0].setX(x);
        z =2;
      }else{
        v[0].setDirection('l');
        x = v[0].getX();
        x = x - 41;
        v[0].setX(x);
        z =3;
      }
    }else{
      if(event.key.keysym.sym == SDLK_LEFT){
        if(v[0].getDirection() != 'r'){
          v[0].setDirection('l');
          x = v[0].getX();
          x = x - 41;
          v[0].setX(x);
          z =3;
        }else{
          v[0].setDirection('r');
          x = v[0].getX();
          x = x + 41;
          v[0].setX(x);
          z =2;
        }
      }else{
        if(event.key.keysym.sym == SDLK_DOWN){
          if(v[0].getDirection() != 'u'){
            v[0].setDirection('d');
            y = v[0].getY();
            y = y + 43;
            v[0].setY(y);
            z =4;
          }else{
            v[0].setDirection('u');
            y = v[0].getY();
            y = y - 43;
            v[0].setY(y);
            z =1;
          }
        }else{
          z =-1;
        }
      }
    }
  }
  if(z != -1){
  for(int i = 1; i <= length-1; i++){
    v[i].setDirection(v[i].getNextDirection());
    switch(v[i].getDirection()){
      case 'u':
      y = v[i].getY();
      y = y - 43;
      v[i].setY(y);
      break;
      case 'r':
      x = v[i].getX();
      x = x + 41;
      v[i].setX(x);
        break;
      case 'l':
      x = v[i].getX();
      x = x - 41;
      v[i].setX(x);
        break;
      case 'd':
      y = v[i].getY();
      y = y + 43;
      v[i].setY(y);
      break;
    }
    v[i].setNextDirection(v[i-1].getDirection());
  }
}
return z;
}
void snake :: addExtraBody(){
  node n,last;
  n.setBodyImage(IMG_Load("resources/body.png"));
  last=v[length-1];
  n.setNextDirection(last.getDirection());
  n.setDirection(last.getDirection());
  switch(n.getDirection()){
    case 'u': n.setY(last.getY() + 43);
              n.setX(last.getX());
    break;
    case 'l': n.setX(last.getX() + 41);
              n.setY(last.getY());
    break;
    case 'r': n.setX(last.getX() - 41);
              n.setY(last.getY());
    break;
    case 'd': n.setY(last.getY() - 43);
              n.setX(last.getX());
    break;
  }
  v.push_back(n);
}
