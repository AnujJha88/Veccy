#include "Renderer.h"
#include "Layer.h"

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