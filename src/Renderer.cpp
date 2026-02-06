#include "Renderer.h"

BaseLayer *topmostLayer(const std::vector<BaseLayer *> &layers, double px, double py)
{
    for (auto it = layers.rbegin(); it != layers.rend(); it++)
    {
        if ((*it)->isInside(px, py))
            return *it;
    }
    return nullptr;
}

Color bgColor = {0, 0, 0, 255};
Color pixelColor(int x, int y, const std::vector<BaseLayer *> &layers)
{
   Color finalColor = {0, 0, 0, 255};
   for(auto layer : layers){
      if(layer->isInside(x, y)){
        float alpha = layer->getColor().a / 255.0f;
        finalColor.r = finalColor.r * (1 - alpha) + layer->getColor().r * alpha;
        finalColor.g = finalColor.g * (1 - alpha) + layer->getColor().g * alpha;
        finalColor.b = finalColor.b * (1 - alpha) + layer->getColor().b * alpha;
      }
   }
   return finalColor;
}

void Renderer::render(SDL_Renderer *renderer, int width, int height, const std::vector<BaseLayer *> &layers)
{
    static SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);

    uint32_t *pixels = new uint32_t[width * height];

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Color col = pixelColor(x, y, layers);
            // ARGB8888 expects: (a << 24) | (r << 16) | (g << 8) | b
            pixels[y * width + x] = (col.a << 24) | (col.r << 16) | (col.g << 8) | col.b;
        }
    }

    SDL_UpdateTexture(texture, NULL, pixels, width * sizeof(uint32_t));
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    delete[] pixels;
}

void Renderer::drawBg()
{
    std::cout << '.';
}


bool Renderer::BboxCollision(BaseLayer* obj1, BaseLayer* obj2){
    BoundingBox bbox1=obj1->getBbox();
    BoundingBox bbox2=obj2->getBbox();
    if (bbox1.maxX < bbox2.minX || bbox1.minX > bbox2.maxX) return false;
    if (bbox1.maxY < bbox2.minY || bbox1.minY > bbox2.maxY) return false;

    return true; // The boxes overlap!

}

void Renderer::ResolveCollision(BaseLayer* obj1, BaseLayer* obj2){
    //TODO
    //Need to do normal calculation for collision
    //then reverse the speeds along the normal so that's more weird math in code
    double dx=obj1->getX()-obj2->getX();
    double dy=obj1->getY()-obj2->getY();

    double distance= sqrt(dx*dx+dy*dy);
    double normalX=dx/distance;
    double normalY=dy/distance;

    double relativeVelocityX=obj1->getVX()-obj2->getVX();
    double relativeVelocityY=obj1->getVY()-obj2->getVY();

    double projectedVelocity=normalX*relativeVelocityX+normalY*relativeVelocityY;//dot product of normal with the re;ative vel.

    if ( projectedVelocity> 0) return;
    double restitution=0.9f;
    double impulse=-(1.0+restitution)*projectedVelocity;
    impulse/=2;//(equal masses)
    obj1->setVX(obj1->getVX()+normalX*impulse);
    obj1->setVY(obj1->getVY()+normalY*impulse);
    obj2->setVX(obj2->getVX()-normalX*impulse);
    obj2->setVY(obj2->getVY()-normalY*impulse);
}

bool Renderer::NarrowCollision(BaseLayer* obj1, BaseLayer* obj2){
    char typeA=obj1->getIcon();
    char typeB=obj2->getIcon();
    if(typeA=='C' && typeB=='C'){
        Circle* c1=static_cast<Circle*>(obj1);
        Circle* c2=static_cast<Circle*>(obj2);
        double dx=c1->getX()-c2->getX();
        double dy=c1->getY()-c2->getY();
        double dist=dx*dx+dy*dy;
        double combinedRadius=c1->getR()+c2->getR();
        return dist<combinedRadius*combinedRadius;
    }
    else if((typeA=='R' && typeB=='C')||(typeB=='R'&& typeA=='C')){
        Circle* c = (typeA == 'C') ? static_cast<Circle*>(obj1) : static_cast<Circle*>(obj2);
        Rectangle* r = (typeA == 'R') ? static_cast<Rectangle*>(obj1) : static_cast<Rectangle*>(obj2);

        double closestX=std::max(r->getX(),std::min(c->getX(), r->getX() + r->getW()));
        double closestY=std::max(r->getY(),std::min(c->getY(), r->getY() + r->getH()));

        double dx=c->getX()-closestX;
        double dy=c->getY()-closestY;
        double dist=dx*dx+dy*dy;
        double combinedRadius=c->getR();
        return dist<combinedRadius*combinedRadius;
    }
    else if(typeA=='R' && typeB=='R') return true;
    return false;
}
