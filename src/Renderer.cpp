#include "Renderer.h"
#include "Layer.h"

BaseLayer* topmostLayer(const std::vector<BaseLayer*>& layers,double px, double py) {
    for(auto it=layers.rbegin();it!=layers.rend();it++){
        if((*it)->isInside(px,py))return *it;
    }
    return nullptr;
}

void Renderer::render(int width, int height, const std::vector<BaseLayer*>& layers) {
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            BaseLayer* topLayer=topmostLayer(layers,x,y);
            if(topLayer){
                std::cout<<topLayer->getIcon();
            }
            else{
                drawBg();
            }
        }
        std::cout<<'\n';
    }
}

void Renderer::drawBg(){
    std::cout<<'.';
}
