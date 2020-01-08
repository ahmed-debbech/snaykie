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
  length = 3;
  SDL_Surface * body = IMG_Load("resources/body.png");
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
        n.setBodyImage(body);
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
void snake :: transformNode(node * n){
  SDL_FreeSurface(n->getBodyImage());
  if(n->getNextDirection() != n->getDirection()){
    switch(n->getDirection()){
      case 'u':
        switch(n->getNextDirection()){
          case 'l': n->setBodyImage(IMG_Load("resources/uptoleft.png"));
          break;
          case 'r': n->setBodyImage(IMG_Load("resources/uptoright.png"));
          break;
        }
      break;
      case 'd':
        switch(n->getNextDirection()){
          case 'l': n->setBodyImage(IMG_Load("resources/downtoleft.png"));
          break;
          case 'r': n->setBodyImage(IMG_Load("resources/downtoright.png"));
          break;
        }
      break;
      case 'r':
        switch(n->getNextDirection()){
          case 'u': n->setBodyImage(IMG_Load("resources/lefttoup.png"));
          break;
          case 'd': n->setBodyImage(IMG_Load("resources/lefttodown.png"));
          break;
        }
      break;
      case 'l':
        switch(n->getNextDirection()){
          case 'u': n->setBodyImage(IMG_Load("resources/righttoup.png"));
          break;
          case 'd': n->setBodyImage(IMG_Load("resources/righttodown.png"));
          break;
        }
      break;
    }
  }else{
    n->setBodyImage(IMG_Load("resources/body.png"));
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
    if(i != length-1){ //if it is NOT the tail
      transformNode(&v[i]);
    }
  }
}
return z;
}
void snake :: pushTailNode(){
  node last = v[length-1];
  SDL_Rect pos;
  pos.x= last.getPosition().x;
  pos.y = last.getPosition().y;
  switch(last.getDirection()){
    case 'u': pos.y += 43;
    break;
    case 'd': pos.y -= 43;
    break;
    case 'r': pos.x -= 41;
    break;
    case 'l': pos.x += 41;
    break;
  }
  v[length].setPosition(pos);
}
void snake :: addExtraBody(){
  node n,last;
  last=v[length-2];
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
  vector <node> :: iterator it = v.begin();
  for(int i=0; i<=length-2; i++){
    ++it;
  }
  v.insert(it,n);
  pushTailNode();
}
node snake ::  getNodes(int counter){
  return v[counter];
}
