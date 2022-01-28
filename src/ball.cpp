#include <cstdlib>
#include <SDL2/SDL.h>
#include "constants.h"

class Ball{

    private:
        int COLOR[3] = {rand()%256 + 30, rand()%256 + 30, rand()%256 + 30}; // random color
        int BALL_SIZE = 10;

        float x, y;
        Speed speed = {300, 100};
        
        SDL_Rect rect;


    public:
        Ball(){
            x = constants::WINDOW_WIDTH/2 - BALL_SIZE/2;
            y = constants::WINDOW_HEIGHT/2 - BALL_SIZE/2;
            rect = SDL_Rect{ (int)x, (int)y, BALL_SIZE, BALL_SIZE };
        }


        void draw(SDL_Renderer* pRenderer){
            rect.x = (int)x;
            rect.y = (int)y;
            SDL_SetRenderDrawColor(pRenderer, COLOR[0], COLOR[1], COLOR[2], 255);
            SDL_RenderFillRect(pRenderer, &rect);
        }

        void update(double dt){
            float nv_x = rect.x + dt * speed.vx;
            float nv_y = rect.y + dt * speed.vy;

            /* collision with player */
           /* if (){
                dx *= -1;
            }*/

            /* collision with wall */
            if (nv_y < 0){
                speed.vy = abs(speed.vy);
            } else if (nv_y + BALL_SIZE > constants::WINDOW_HEIGHT){
                speed.vy = -abs(speed.vy);
            }

            if (nv_x < 0){
                speed.vx = abs(speed.vx);
            } else if (nv_x + BALL_SIZE > constants::WINDOW_WIDTH){
                speed.vx = -abs(speed.vx);
            }

            x += dt * speed.vx;
            y += dt * speed.vy;
        }

        int isOut(){
            return hasCollisionWallLeft() || hasCollisionWallRight();
        }

        int hasCollisionWallLeft(){
            return rect.x < 0;
        }

        int hasCollisionWallRight(){
            return rect.x + BALL_SIZE > constants::WINDOW_WIDTH;
        }

        Speed getSpeed(){
            return speed;
        }

        void setSpeed(Speed new_speed){
            speed = new_speed;
        }

        SDL_Rect getRect(){
            return rect;
        }
};