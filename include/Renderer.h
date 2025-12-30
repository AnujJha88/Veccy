#ifndef RENDERER_H
#define RENDERER_H
#include<vector>
#include<iostream>
#include "Layer.h"
class Renderer{
public:
    void render(int width, int height, const std::vector<BaseLayer*>& layers);
    void drawBg();

};

#endif
