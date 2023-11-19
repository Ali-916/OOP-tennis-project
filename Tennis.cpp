#include<iostream>
#include "Tennis.hpp"
#include <vector>
#include <random>
using namespace std;

bool isBallAnimatingUp = false; // Variable to control ball animation
bool isBallAnimatingDown = false; // Variable to control ball animation

int random_number = 0;

Unit PlayerUp = {{271,7,30,57}, {220, 40, 50, 50}};
Unit PlayerDown = {{15,7,30,57}  , {220,380,50,50}};
// Unit ball = {{0,0,0,0}, {240, 0, 20, 20}};
bool serve = false;
Unit Temp;

void handleEvents(SDL_Event& event);

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Event& event){

    SDL_RenderCopy(gRenderer, assets, &PlayerUp.srcRect, &PlayerUp.moverRect);
    SDL_RenderCopy(gRenderer, assets, &PlayerDown.srcRect, &PlayerDown.moverRect);
    // SDL_RenderCopy(gRenderer, assets, &ball.srcRect, &ball.moverRect);

    SDL_RenderCopy(gRenderer, assets, &Temp.srcRect, &Temp.moverRect);
    handleEvents(event);
}

bool keysPlayerUp[SDL_NUM_SCANCODES] = {false};
bool keysPlayerDown[SDL_NUM_SCANCODES] = {false};

int A = 0;

//FOR ANOTHER ROUND, MAKE serve == false
void handleEvents(SDL_Event& event) {

// std::random_device rd;
// std::mt19937 gen(rd());

// std::uniform_int_distribution<int> distribution(-35, 35);


if (isBallAnimatingUp)
{
    Temp.moverRect.y= Temp.moverRect.y + A;

    if (A>0 && Temp.moverRect.y >120)
    {Temp.moverRect.x = Temp.moverRect.x  + random_number;}

    if (A<0 && Temp.moverRect.y <120)
    {Temp.moverRect.x = Temp.moverRect.x  + random_number;}
}



    if (event.type == SDL_KEYDOWN) {
        keysPlayerUp[event.key.keysym.scancode] = true;
        keysPlayerDown[event.key.keysym.scancode] = true;

        // Set the spaceKeyPressed flag when space key is pressed
        // if (event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
        //     SpaceKeyPressed = true;
        // }
    } else if (event.type == SDL_KEYUP) {
        keysPlayerUp[event.key.keysym.scancode] = false;
        keysPlayerDown[event.key.keysym.scancode] = false;

        // if (event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
        //     SpaceKeyPressed = false;
        // }
    }

    
    // Update player movements based on key states
    if (keysPlayerUp[SDL_SCANCODE_A] && PlayerUp.moverRect.x >= 140) {
        PlayerUp.moverRect.x -= 20;
    }
    if (keysPlayerUp[SDL_SCANCODE_D] && PlayerUp.moverRect.x <= 330) {
        PlayerUp.moverRect.x += 20;
    }
    if (keysPlayerUp[SDL_SCANCODE_W] && PlayerUp.moverRect.y >= 60) {
        PlayerUp.moverRect.y -= 20;
    }
    if (keysPlayerUp[SDL_SCANCODE_S] && PlayerUp.moverRect.y <= 120) {
        PlayerUp.moverRect.y += 20;
    }
    if (keysPlayerUp[SDL_SCANCODE_SPACE] && serve == false){
        isBallAnimatingUp = true; serve = true;
        random_number = std::rand() % 61 - 30;
        Temp = {{512,155,9,9}, {PlayerUp.moverRect.x, PlayerUp.moverRect.y, 20, 20}}; A = 80;
    }

    if (keysPlayerDown[SDL_SCANCODE_LEFT] && PlayerDown.moverRect.x >= 140) {
        PlayerDown.moverRect.x -= 20;
    }
    if (keysPlayerDown[SDL_SCANCODE_RIGHT] && PlayerDown.moverRect.x <= 330) {
        PlayerDown.moverRect.x += 20;
    }
    if (keysPlayerDown[SDL_SCANCODE_UP] && PlayerDown.moverRect.y >= 280) {
        PlayerDown.moverRect.y -= 20;
    }
    if (keysPlayerDown[SDL_SCANCODE_DOWN] && PlayerDown.moverRect.y <= 350) {
        PlayerDown.moverRect.y += 20;
    }
    if (keysPlayerDown[SDL_SCANCODE_RSHIFT]  && serve == false){
        isBallAnimatingUp = true; serve = true;
        random_number = std::rand() % 61 - 30;
        Temp = {{512,155,9,9}, { PlayerDown.moverRect.x, PlayerDown.moverRect.y , 20, 20}};  A = -80;
    }


}







