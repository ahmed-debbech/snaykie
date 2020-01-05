#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <vector>
#include <iterator>
#include "headers/snake.h"
#include "headers/node.h"
using namespace std;

snake :: snake(){
   int i, numberOnMap = 213;
  float x = 387.4;
  float y = 778.4;
  int whatColor = 1;
  length = 3;
  SDL_Surface * body = IMG_Load("resources/body.png");
  SDL_Surface * body2 = IMG_Load("resources/body2.png");
  SDL_Surface * head = IMG_Load("resources/head.png");
  SDL_Surface * tail = IMG_Load("resources/tail.png");
  for(i = 0; i <= length-1; i++){
    if(i == 0){
      node n;
      SDL_Rect pos;
      pos.x = x;
      pos.y = y;
      n.setPosition(pos);
      n.setBodyImage(head);
      n.setDirection('l');
      n.setNextDirection('h');
      n.setNumberOnMap(numberOnMap);
      v.push_back(n);
      x = x + 41;
    }else{
      if(i == length-1){
        node n;
        SDL_Rect pos;
        pos.x = x;
        pos.y = y;
        n.setPosition(pos);
        n.setBodyImage(tail);
        n.setDirection('l');
        n.setNextDirection('l');
        n.setNumberOnMap(numberOnMap);
        v.push_back(n);
        x = x + 41;
      }else{
        node n;
        SDL_Rect pos;
        pos.x = x;
        pos.y = y;
        n.setPosition(pos);
        if(whatColor = 1){
          n.setBodyImage(body2);
          whatColor = 2;
        }else{
          n.setBodyImage(body);
          whatColor = 1;
        }
        n.setDirection('l');
        n.setNextDirection('l');
        n.setNumberOnMap(numberOnMap);
        v.push_back(n);
        x = x + 41;
      }
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
      SDL_Rect pos = v[i].getPosition();
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
void snake :: update_nodes_num_on_map(node& n, const node& last_node){
  node l = last_node;
  int last = l.getNumberOnMap();
  switch(l.getDirection()){
    case 'u': n.setNumberOnMap(last+12);
    break;
    case 'd': n.setNumberOnMap(last -12);
    break;
    case 'r': n.setNumberOnMap(last - 1);
    break;
    case 'l': n.setNumberOnMap(last + 1);
    break;
  }
}
int snake :: moveSnake(SDL_Event event){
  int z;
  SDL_Rect pos;
  if(event.key.keysym.sym == SDLK_UP){
    if(v[0].getDirection() != 'd'){
      v[0].setDirection('u');
      pos = v[0].getPosition();
      pos.y = pos.y - 43;
      v[0].setPosition(pos);
      update_nodes_num_on_map('u', v[0]);
      z = 1;
    }else{
      v[0].setDirection('d');
      pos = v[0].getPosition();
      pos.y = pos.y + 43;
      v[0].setPosition(pos);
      update_nodes_num_on_map('d', v[0]);
      z =4;
    }
  }else{
    if(event.key.keysym.sym == SDLK_RIGHT){
      if(v[0].getDirection() != 'l'){
        v[0].setDirection('r');
        pos = v[0].getPosition();
        pos.x = pos.x + 41;
        v[0].setPosition(pos);
        update_nodes_num_on_map('r', v[0]);
        z =2;
      }else{
        v[0].setDirection('l');
        pos = v[0].getPosition();
        pos.x = pos.x - 41;
        v[0].setPosition(pos);
        update_nodes_num_on_map('l', v[0]);
        z =3;
      }
    }else{
      if(event.key.keysym.sym == SDLK_LEFT){
        if(v[0].getDirection() != 'r'){
          v[0].setDirection('l');
          pos = v[0].getPosition();
          pos.x = pos.x - 41;
          v[0].setPosition(pos);
          update_nodes_num_on_map('l', v[0]);
          z =3;
        }else{
          v[0].setDirection('r');
          pos = v[0].getPosition();
          pos.x = pos.x + 41;
          v[0].setPosition(pos);
          update_nodes_num_on_map('r', v[0]);
          z =2;
        }
      }else{
        if(event.key.keysym.sym == SDLK_DOWN){
          if(v[0].getDirection() != 'u'){
            v[0].setDirection('d');
            pos = v[0].getPosition();
            pos.y = pos.y + 43;
            v[0].setPosition(pos);
            update_nodes_num_on_map('d', v[0]);
            z =4;
          }else{
            v[0].setDirection('u');
            pos = v[0].getPosition();
            pos.y = pos.y - 43;
            v[0].setPosition(pos);
            update_nodes_num_on_map('u', v[0]);
            z =1;
          }
        }else{
          z = -1;
        }
      }
    }
  }
  if(z != -1){
  for(int i = 1; i <= length-1; i++){
    v[i].setDirection(v[i].getNextDirection());
    switch(v[i].getDirection()){
      case 'u':
      pos = v[i].getPosition();
      pos.y = pos.y - 43;
      v[i].setPosition(pos);
      update_nodes_num_on_map('u', v[i]);
      break;
      case 'r':
      pos = v[i].getPosition();
      pos.x = pos.x + 41;
      v[i].setPosition(pos);
      update_nodes_num_on_map('r', v[i]);
        break;
      case 'l':
      pos = v[i].getPosition();
      pos.x = pos.x - 41;
      v[i].setPosition(pos);
      update_nodes_num_on_map('l', v[i]);
        break;
      case 'd':
      pos = v[i].getPosition();
      pos.y = pos.y + 43;
      v[i].setPosition(pos);
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
  SDL_Rect pos = last.getPosition();
  switch(n.getDirection()){
    case 'u': pos.y = pos.y + 43;
              n.setPosition(pos);
    break;
    case 'l': pos.x = pos.x + 41;
              n.setPosition(pos);
    break;
    case 'r': pos.x = pos.x - 41;
              n.setPosition(pos);
    break;
    case 'd': pos.y = pos.y - 43;
              n.setPosition(pos);
    break;
  }
  v.push_back(n);
}
node snake ::  getNodes(int counter){
  return v[counter];
}
