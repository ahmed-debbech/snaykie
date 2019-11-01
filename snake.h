#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <vector>
#include <iterator>
using namespace std;
class node{
  SDL_Rect position;
  SDL_Surface * body;
  char dir;
  char nextDir;
public:
  void setX(float x);
  float getX();
  void setY(float y);
  float getY();
  char getDirection();
  void setNextDirection(char nextDir);
  char getNextDirection();
  void setDirection(char dir);
  void setBodyImage(SDL_Surface * body);
  SDL_Surface * getBodyImage();
};

class snake{
  int length;
  SDL_Surface * head;
  vector <node> v;
public:
  snake();
  void setLength(int length);
  float getLength ();
  void showSnake(SDL_Surface * screen);
  void moveSnake(SDL_Event event);
};
#endif
