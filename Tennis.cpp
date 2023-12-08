#include<iostream>
#include "Tennis.hpp"
#include <vector>
#include <random>
#include "game.hpp"
using namespace std;

bool Running = true;
bool isBallAnimatingUp = false; // Variable to control ball animation
bool isBallAnimatingDown = false; // Variable to control ball animation
int random_number = 0;
bool UpServe , DownServe  , Flag= false;
int x; int y;
int uphl=0;
int uphr=0;
int ups=0;
bool UpHit = false; bool DownHit = false;
Unit PlayerUp = {{271,7,30,57}, {220*2, 40*2, 50*2, 50*2}};
Unit PlayerDown = {{15,7,30,57}  , {220*2,380*2,50*2,50*2}};
Unit ScoreBoard = {{16,344,52,326},{50,160,100,600}};
Unit UpScore = {{0,0,0,0} , {100,200,35,35}};
Unit DownScore = {{0,0,0,0,} , {100,700,35,35}};
Unit Winner = {{0,0,0,0} , {0,0,0,0}};

int A = 0;
bool serve = false;
Unit Temp;
void handleEvents(SDL_Event& event);

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Event& event){
    
    SDL_RenderCopy(gRenderer, assets, &PlayerUp.srcRect, &PlayerUp.moverRect);
    SDL_RenderCopy(gRenderer, assets, &PlayerDown.srcRect, &PlayerDown.moverRect);
    SDL_RenderCopy(gRenderer, assets, &ScoreBoard.srcRect, &ScoreBoard.moverRect);
    SDL_RenderCopy(gRenderer, assets, &UpScore.srcRect, &UpScore.moverRect);
    SDL_RenderCopy(gRenderer, assets, &DownScore.srcRect, &DownScore.moverRect);
    SDL_RenderCopy(gRenderer, assets, &Winner.srcRect, &Winner.moverRect);

    if (UpServe==true && PlayerUp.count <4){PlayerUp.Fly({271,7,30,57} , {271,135,35,57} , {330,135,31,57} , {391,137,30,55});}
    if (DownServe==true && PlayerDown.count<4){PlayerDown.Fly({15,7,30,57} , {195,135,45,57} , {15,200,43,56} , {72,200,39,56});}
    Temp.moverRect.y = Temp.moverRect.y + A;
    if (A>0 && Temp.moverRect.y >120*2)
    {
        Temp.moverRect.x = Temp.moverRect.x  + random_number*2;
    }

    if (A<0 && Temp.moverRect.y <120*2)
    {  
        Temp.moverRect.x = Temp.moverRect.x  + random_number*2; 
    }
    SDL_RenderCopy(gRenderer, assets, &Temp.srcRect, &Temp.moverRect);
    handleEvents(event);
   
}

bool keysPlayerUp[SDL_NUM_SCANCODES] = {false};
bool keysPlayerDown[SDL_NUM_SCANCODES] = {false};


//FOR ANOTHER ROUND, MAKE serve == false
void handleEvents(SDL_Event& event) {

    if (UpScore.Score==3 || DownScore.Score==3){Running = false;}


if (isBallAnimatingUp)
{
    // Temp.moverRect.y= Temp.moverRect.y + A;

    // if (A>0 && Temp.moverRect.y >120*2)
    // {
    //     Temp.moverRect.x = Temp.moverRect.x  + random_number*2;
    // }

    // if (A<0 && Temp.moverRect.y <120*2)
    // {  
    //     Temp.moverRect.x = Temp.moverRect.x  + random_number*2; 
    // }
}

    if (event.type == SDL_KEYDOWN) {
        keysPlayerUp[event.key.keysym.scancode] = true;
        keysPlayerDown[event.key.keysym.scancode] = true;

    } else if (event.type == SDL_KEYUP) {
        keysPlayerUp[event.key.keysym.scancode] = false;
        keysPlayerDown[event.key.keysym.scancode] = false;
    }
     if (event.type == SDL_QUIT) {
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                // Use mouseX and mouseY as needed
                printf("Left click at (%d, %d)\n", mouseX, mouseY);}}

    // Update player movements based on key states
    if (keysPlayerUp[SDL_SCANCODE_A] && PlayerUp.moverRect.x >= 140*2 && Running == true) {
        PlayerUp.moverRect.x -= 20*2;
    }
    if (keysPlayerUp[SDL_SCANCODE_D] && PlayerUp.moverRect.x <= 330*2 && Running == true) {
        PlayerUp.moverRect.x += 20*2;
    }
    if (keysPlayerUp[SDL_SCANCODE_W] && PlayerUp.moverRect.y >= 60*2 && Running == true) {
        PlayerUp.moverRect.y -= 20*2;
    }
    if (keysPlayerUp[SDL_SCANCODE_S] && PlayerUp.moverRect.y <= 120*2 && Running == true) {
        PlayerUp.moverRect.y += 20*2;
    }
    if (keysPlayerUp[SDL_SCANCODE_SPACE] && serve == false && Running == true){
        isBallAnimatingUp = true; serve = true;UpServe =  true;
         if (PlayerUp.moverRect.x - Temp.moverRect.x > 0)
            {
            //HIT TO RIGHT
            random_number = 5;
            }
        else if (PlayerUp.moverRect.x - Temp.moverRect.x > 0) {random_number = -5;}
        else {random_number = 0;}

        Temp = {{512,155,9,9}, {PlayerUp.moverRect.x, PlayerUp.moverRect.y, 20*2, 20*2}}; A = 30*2;
        
        UpHit = true; DownHit = false;
        
    }

    if (keysPlayerDown[SDL_SCANCODE_LEFT] && PlayerDown.moverRect.x >= 140*2 && Running == true) {
        PlayerDown.moverRect.x -= 20*2;
    }
    if (keysPlayerDown[SDL_SCANCODE_RIGHT] && PlayerDown.moverRect.x <= 330*2 && Running == true) {
        PlayerDown.moverRect.x += 20*2;
    }
    if (keysPlayerDown[SDL_SCANCODE_UP] && PlayerDown.moverRect.y >= 280*2 && Running == true) {
        PlayerDown.moverRect.y -= 20*2;
    }
    if (keysPlayerDown[SDL_SCANCODE_DOWN] && PlayerDown.moverRect.y <= 350*2 && Running == true) {
        PlayerDown.moverRect.y += 20*2;
    }
    if (keysPlayerDown[SDL_SCANCODE_RSHIFT]  && serve == false  && Running == true){
        isBallAnimatingUp = true; serve = true;
        // random_number = std::rand() % 10 - 10;
        Temp = {{512,155,9,9}, { PlayerDown.moverRect.x, PlayerDown.moverRect.y , 20*2, 20*2}};  A = -30*2;
        DownServe = true;
        UpHit = false ; DownHit = true;

    }

    if (UpServe == false && DownServe == true)
    {
     //PLAYER DOWN HITTED THE BALL    
    
     if (abs(Temp.moverRect.x -PlayerUp.moverRect.x) < 40*2 && abs(Temp.moverRect.y - PlayerUp.moverRect.y) <40*2   )
        {
            A = A * -1; UpServe = true ; DownServe = false; Flag = false; UpHit = false; DownHit = true; PlayerUp.count = 0;
        }
    if (Flag == false){y = PlayerUp.moverRect.x - Temp.moverRect.x; Flag = true;}
        
    if (y>-20*2 && y>20*2)
    {
        random_number = 0;
        
    }
    else if (y>0)
    {
        random_number = -5;
        
    }
    else 
    {
        random_number = 5;
    }
    
    }

    if (UpServe == true && DownServe == false)
    {
     //PLAYER UP HITTED THE BALL
     if (abs(Temp.moverRect.x -PlayerDown.moverRect.x) < 40*2 && abs(Temp.moverRect.y - PlayerDown.moverRect.y) <30*2   )
        {
            A = A * -1; UpServe = false ; DownServe = true; Flag = false; UpHit = true; DownHit = false; PlayerDown.count = 0;
        }

    if (Flag == false){x = PlayerDown.moverRect.x - Temp.moverRect.x;Flag = true;}
    
    
    if (x>-20*2 && x>20*2)
    {
        //STRAIGHT HIT 
        random_number = 0;
    }

    else if (x>0)
    {
        random_number = 5;
        
    }
    else 
    {
        random_number = -5;
    }
    }

// this part handles score handling and everything ... but contains coordinates error 
//     if ((Temp.moverRect.x <280 || Temp.moverRect.x >660) && DownServe == true and UpServe == false)
//     {UpScore.Score++;DownServe = false;serve = false;}
//     if (Temp.moverRect.y < 100 && DownServe == true && UpServe == false){DownScore.Score++;DownServe = false;serve = false;}
//    std::cout << Temp.srcRect.x << "  ";
//     if ((Temp.moverRect.x <280 || Temp.moverRect.x >660) && DownServe == false and UpServe == true)
//     {DownScore.Score++;UpServe = false;serve=false;}
//     if (Temp.moverRect.y > 900 && UpServe == true && DownServe == false){UpScore.Score++;UpServe = false;serve=false;}
    
    //PLAYER UP SCORES A POINT:
    // if (UpServe == false && DownServe == true && (Temp.moverRect.x <280 || Temp.moverRect.x >660))
    // {UpServ}
    // else if (UpServe==true && DownServe==false && Temp.moverRect.y >900)
    // {UpScore.Score++; UpServe=false;serve = false;}



    if (DownScore.Score == 0){DownScore.srcRect = {113,363,16,20};}
    else if (DownScore.Score == 1){DownScore.srcRect = {158,362,14,21};}
    else if (DownScore.Score == 2){DownScore.srcRect = {201,362,15,21};}
    else if (DownScore.Score == 3) {DownScore.srcRect = {245,363,15,20};}

    if (UpScore.Score == 0){UpScore.srcRect = {113,363,16,20};}
    else if (UpScore.Score == 1){UpScore.srcRect = {158,362,14,21};}
    else if (UpScore.Score == 2){UpScore.srcRect = {201,362,15,21};}
    else if (UpScore.Score == 3) {UpScore.srcRect = {245,363,15,20};}

    //winner display;
    if (UpScore.Score == 3)
    {
        Winner = {{292,337,379,310} , {400, 300, 100*2, 100*2}};
    }
    else if (DownScore.Score == 3)
    {
        Winner = {{292,337,379,310}  , {400,500,100*2,100*2}};
    }


}
