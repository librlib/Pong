#include <SDL2/SDL.h>
#include <cstdlib>
#include "constants.h"
#include "player.cpp"
#include "ball.cpp"


// Player control
const int PLAYER_LEFT_UP = SDLK_a;
const int PLAYER_LEFT_DOWN = SDLK_q;
const int PLAYER_RIGHT_UP = SDLK_p;
const int PLAYER_RIGHT_DOWN = SDLK_m;

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Window* pWindow{ nullptr };
    SDL_Renderer* pRenderer{ nullptr };
    
    if (SDL_CreateWindowAndRenderer(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT,SDL_WINDOW_SHOWN|SDL_RENDERER_PRESENTVSYNC, &pWindow, &pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    SDL_SetWindowTitle(pWindow, "Ching Chang Pong");

    bool isOpen{ true };
    SDL_Event event;

    uint64_t startTime = SDL_GetPerformanceCounter();
    uint64_t currTime;
    double elapsedTime;
    
    Player playerL(20,10);

    Ball ball;
    // SDL_Rect interRect{ 0, 0, 0 ,0 };
    // SDL_IntersectRect(&(rectangles[0]), &(rectangles[1]), &interRect);

    while (isOpen) {
        SDL_Delay(16);

        // Gestion des evenements
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym)
                {
                    case PLAYER_LEFT_UP:
                        playerL.setDirection(1);
                        printf("up");
                        break;
                    case PLAYER_LEFT_DOWN:
                        playerL.setDirection(-1);
                        printf("down");
                        break;
                }
            }
            else if (event.type == SDL_KEYUP)
            {
                switch(event.key.keysym.sym)
                {
                    case PLAYER_LEFT_UP:
                    case PLAYER_LEFT_DOWN:
                        playerL.setDirection(0);
                        printf("neutre");
                        break;
                }
            }
            else if (event.type == SDL_QUIT){
                isOpen = false;
            }
        }
        currTime = SDL_GetPerformanceCounter();

        elapsedTime = static_cast<double>(
            (currTime - startTime) / static_cast<double>(SDL_GetPerformanceFrequency())
        );

        // Make the player move
        playerL.move(elapsedTime);

        Speed ballSpeed = ball.getSpeed();
        collidRect(ball.getRect(), &ballSpeed, , );

        ball.setSpeed(ballSpeed);
        ball.update(elapsedTime);
        if (ball.isOut()){
            // end of the game
            if (ball.hasCollisionWallLeft()){
                // Player Right has won
                //printf("Player Right is the WINNER !!!!\n");
            }
            else if (ball.hasCollisionWallRight()){
                // Player Left has won
                //printf("Player Left is the WINNER !!!!\n");
                
            }
        }


        // Reset the render window
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(pRenderer);




        
        ball.draw(pRenderer);
        playerL.draw(pRenderer);

        SDL_RenderPresent(pRenderer);

        startTime = currTime;
    }

    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return EXIT_SUCCESS;
}
