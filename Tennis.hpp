#include<SDL.h>

#include <thread>
#include <chrono>

// Using std::this_thread::sleep_for

void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets, SDL_Event& event);
void handleEvents(SDL_Event& event);

class Unit{
    public:
    SDL_Rect srcRect, moverRect; 
    int Score=0;
    int count = 0;

    void Fly(SDL_Rect A , SDL_Rect B , SDL_Rect C , SDL_Rect D)
    {
        if (srcRect.x==A.x && srcRect.y==A.y && srcRect.w==A.w && srcRect.h==A.h){srcRect = B;}
        else if (srcRect.x==B.x && srcRect.y==B.y && srcRect.w==B.w && srcRect.h==B.h){srcRect = C;}
        else if (srcRect.x==C.x && srcRect.y==C.y && srcRect.w==C.w && srcRect.h==C.h){srcRect = D;}
        else if (srcRect.x =D.x , srcRect.y = D.y , srcRect.w = D.w , srcRect.h = D.h){srcRect = A;}
        count++;
    }







};