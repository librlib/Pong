#include <cstdlib>
#include <SDL2/SDL.h>
#include "constants.h"

const int PLAYER_WIDTH = 15;
const int PLAYER_HEIGHT = 70;

const float PLAYER_SPEED = 300;

const int PLAYER_R = 24;
const int PLAYER_G = 154;
const int PLAYER_B = 218;
const int PLAYER_ALPHA = 255;

class Player{
    private:
        // int x, y, w, h;
        SDL_Rect rect;
        int speed{ 0 };
        float x, y;

    public:

        Player(float x, float y){
            this->x = x;
            this->y = y;
            rect = SDL_Rect{(int)x, (int)y, PLAYER_WIDTH, PLAYER_HEIGHT };
        }

        void draw(SDL_Renderer* pRenderer){
            rect.x = (int)x;
            rect.y = (int)y;
            SDL_SetRenderDrawColor(pRenderer, PLAYER_R, PLAYER_G, PLAYER_B, PLAYER_ALPHA);
            SDL_RenderFillRect(pRenderer, &rect);
        }

        void move(double dt){
            float nv_y = y + dt * speed;

            if (!(nv_y < 10 || nv_y + PLAYER_HEIGHT > constants::WINDOW_HEIGHT - 10)){
                y = nv_y;
            }
        }

        void setDirection(int direction){
            if (direction < 0){
                speed = PLAYER_SPEED;
            } else if (direction == 0) {
                speed = 0;
            } else {
                speed = -1 * PLAYER_SPEED;
            }

        }
};