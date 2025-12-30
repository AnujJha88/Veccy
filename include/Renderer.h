#ifndef RENDERER_H
#define RENDERER_H
#include<vector>
#include<SDL2/SDL.h>
#include<iostream>
#include "Layer.h"
class Renderer{
public:
    void render(SDL_Renderer* renderer,int width, int height, const std::vector<BaseLayer*>& layers);
    void drawBg();

};

#endif
