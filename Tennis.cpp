#include<iostream>
#include "Tennis.hpp"
#include <vector>
using namespace std;

Unit PlayerUp = {{271,7,30,57}, {220, 40, 50, 50}};
Unit PlayerDown = {{15,7,30,57}  , {220,380,50,50}};
Unit ball = {{0,0,0,0}, {240, 0, 20, 20}};

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets){

    SDL_RenderCopy(gRenderer, assets, &PlayerUp.srcRect, &PlayerUp.moverRect);
    SDL_RenderCopy(gRenderer, assets, &PlayerDown.srcRect, &PlayerDown.moverRect);
    SDL_RenderCopy(gRenderer, assets, &ball.srcRect, &ball.moverRect);

    SDL_RenderCopy(gRenderer, assets, &ball.srcRect, &ball.moverRect);
    ball.moverRect.y= ball.moverRect.y + 80;
}

void handleEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_a:
            if (PlayerUp.moverRect.x>=140)
            {PlayerUp.moverRect.x -= 40;} 
            break;
        case SDLK_d:
            
            if (PlayerUp.moverRect.x<=330){
            PlayerUp.moverRect.x += 40;} 
            break;
        case SDLK_w:
           
            if (PlayerUp.moverRect.y>=60){
            PlayerUp.moverRect.y -= 40;} 
            break;
        case SDLK_s:
            
            if (PlayerUp.moverRect.y<=120)
            {PlayerUp.moverRect.y += 40;} 
            break;
         case SDLK_SPACE:
            ball.srcRect.x = 512; ball.srcRect.y =155 ; ball.srcRect.h = 9 ; ball.srcRect.w = 9;
            break;
        }
    }


    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            if (PlayerDown.moverRect.x>=140)
            {PlayerDown.moverRect.x -= 40;} 
            break;
        case SDLK_RIGHT:
            if (PlayerDown.moverRect.x<=330)
            {PlayerDown.moverRect.x += 40;} 
            break;
        case SDLK_UP:
            if (PlayerDown.moverRect.y>=280)
            {PlayerDown.moverRect.y -= 40;} 
            break;
        case SDLK_DOWN:
            if (PlayerDown.moverRect.y<=350)
            {PlayerDown.moverRect.y += 40;} 
            break;
        }
    }

    
  
    

}




