#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <vector>
#include <iterator>
#include "snake.h"
#include "node.h"
using namespace std;

snake :: snake(){
   int i, numberOnMap = 213;
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
      n.setNumberOnMap(numberOnMap);
      v.push_back(n);
      x = x + 41;
    }else{
      node n;
      n.setX(x);
      n.setY(y);
      n.setBodyImage(body);
      n.setDirection('l');
      n.setNextDirection('l');
      n.setNumberOnMap(numberOnMap);
      v.push_back(n);
      x = x + 41;
    }
    numberOnMap++;
  }
}
void snake :: setLength(int length){
  this->length = length;
}
float snake :: getLength (){
  return this->length;
}

void snake :: showSnake(SDL_Surface * screen){
    for(int i = 0; i<= length-1; i++){
      SDL_Rect pos;
      pos.x = v[i].getX();
      pos.y = v[i].getY();
      SDL_BlitSurface(v[i].getBodyImage(), NULL, screen, &pos);
    }
}
void snake :: update_nodes_num_on_map (char direction, node &n){
    switch(direction){
      case 'u': n.setNumberOnMap(n.getNumberOnMap() - 12);
      break;
      case 'd': n.setNumberOnMap(n.getNumberOnMap()+ 12);
      break;
      case 'r': n.setNumberOnMap(n.getNumberOnMap()+ 1);
      break;
      case 'l': n.setNumberOnMap(n.getNumberOnMap() - 1);
      break;
    }
}
void snake :: update_nodes_num_on_map(node& n, node last_node){
  switch(last_node.getDirection()){
    case 'u': n.setNumberOnMap(last_node.getNumberOnMap() +12);
    break;
    case 'd': n.setNumberOnMap(last_node.getNumberOnMap() -12);
    break;
    case 'r': n.setNumberOnMap(last_node.getNumberOnMap() - 1);
    break;
    case 'l': n.setNumberOnMap(last_node.getNumberOnMap() + 1);
    break;
  }
}
int snake :: moveSnake(SDL_Event event){
  int y,x, z;
  if(event.key.keysym.sym == SDLK_UP){
    if(v[0].getDirection() != 'd'){
      v[0].setDirection('u');
      y = v[0].getY();
      y = y - 43;
      v[0].setY(y);
      update_nodes_num_on_map('u', v[0]);
      z = 1;
    }else{
      v[0].setDirection('d');
      y = v[0].getY();
      y = y + 43;
      v[0].setY(y);
      update_nodes_num_on_map('d', v[0]);
      z =4;
    }
  }else{
    if(event.key.keysym.sym == SDLK_RIGHT){
      if(v[0].getDirection() != 'l'){
        v[0].setDirection('r');
        x = v[0].getX();
        x = x + 41;
        v[0].setX(x);
        update_nodes_num_on_map('r', v[0]);
        z =2;
      }else{
        v[0].setDirection('l');
        x = v[0].getX();
        x = x - 41;
        v[0].setX(x);
        update_nodes_num_on_map('l', v[0]);
        z =3;
      }
    }else{
      if(event.key.keysym.sym == SDLK_LEFT){
        if(v[0].getDirection() != 'r'){
          v[0].setDirection('l');
          x = v[0].getX();
          x = x - 41;
          v[0].setX(x);
          update_nodes_num_on_map('l', v[0]);
          z =3;
        }else{
          v[0].setDirection('r');
          x = v[0].getX();
          x = x + 41;
          v[0].setX(x);
          update_nodes_num_on_map('r', v[0]);
          z =2;
        }
      }else{
        if(event.key.keysym.sym == SDLK_DOWN){
          if(v[0].getDirection() != 'u'){
            v[0].setDirection('d');
            y = v[0].getY();
            y = y + 43;
            v[0].setY(y);
            update_nodes_num_on_map('d', v[0]);
            z =4;
          }else{
            v[0].setDirection('u');
            y = v[0].getY();
            y = y - 43;
            v[0].setY(y);
            update_nodes_num_on_map('u', v[0]);
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
      update_nodes_num_on_map('u', v[i]);
      break;
      case 'r':
      x = v[i].getX();
      x = x + 41;
      v[i].setX(x);
      update_nodes_num_on_map('r', v[i]);
        break;
      case 'l':
      x = v[i].getX();
      x = x - 41;
      v[i].setX(x);
      update_nodes_num_on_map('l', v[i]);
        break;
      case 'd':
      y = v[i].getY();
      y = y + 43;
      v[i].setY(y);
      update_nodes_num_on_map('d', v[i]);
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
  update_nodes_num_on_map(n, last);
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
node snake ::  getNodes(int counter){
  return v[counter];
}
