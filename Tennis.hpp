#include<SDL.h>


void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
void handleEvents(SDL_Event& event);

struct Unit{
SDL_Rect srcRect, moverRect;
};