#include "functions.h"
#include "Circle.h"
#include "Renderer.h"
#include<SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include<thread>


int main() {

    int screen_width=800,screen_height=600;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window=SDL_CreateWindow("Veccy",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);
    SDL_Renderer* sdl_renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);//


     std::vector<BaseLayer*> layers;
    Circle* c1=new Circle(400,300,50); // Add a circle
    layers.push_back(c1);
    Renderer* my_r=new Renderer();

    bool running=true;
    SDL_Event e;
    double t=0.0;
    double vx=5.0,vy=5.0;
    while(running){
        while(SDL_PollEvent(&e)){
            if(e.type==SDL_QUIT)running=false;
        }

        SDL_SetRenderDrawColor(sdl_renderer,0,0,0,255);
        SDL_RenderClear(sdl_renderer);

        my_r->render(sdl_renderer,800,600,layers);

        if(c1->getX()+c1->getR()>screen_width)vx=-vx;
        if(c1->getX()-c1->getR()<0)vx=-vx;
        if(c1->getY()+c1->getR()>screen_height)vy=-vy;
        if(c1->getY()-c1->getR()<0)vy=-vy;
        c1->setX(c1->getX()+vx);
        c1->setY(c1->getY()+vy);

        SDL_RenderPresent(sdl_renderer);
    SDL_Delay(10);


    }

    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    for (auto l : layers) delete l;

    return 0;
}
