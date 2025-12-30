#include "Renderer.h"
#include "Layer.h"

BaseLayer* topmostLayer(const std::vector<BaseLayer*>& layers,double px, double py) {
    for(auto it=layers.rbegin();it!=layers.rend();it++){
        if((*it)->isInside(px,py))return *it;
    }
    return nullptr;
}

void Renderer::render(SDL_Renderer* renderer,int width, int height, const std::vector<BaseLayer*>& layers) {
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            BaseLayer* topLayer=topmostLayer(layers,x,y);
            if(topLayer){
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
            }
            else{
                SDL_SetRenderDrawColor(renderer,0,0,0,255);
            }
       SDL_RenderDrawPoint(renderer,x,y);

        }
    }
}

void Renderer::drawBg(){
    std::cout<<'.';
}
