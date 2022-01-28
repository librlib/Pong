#include <cstdlib>
#include <SDL2/SDL.h>

#define WIDTH_MAX 800

class Rectangle{
    private:
        // int x, y, w, h;
        SDL_Rect rect;
        int speed;
    
    public:
        Rectangle(){

        }

        Rectangle(int x, int y, int w, int h, int speed){
            rect = SDL_Rect{ x, y, w, h };
            
            this->speed = speed;
        }

        void draw(SDL_Renderer* pRenderer){
            SDL_SetRenderDrawColor(pRenderer, 24, 157, 218, 255);
            SDL_RenderDrawRect(pRenderer, &rect);
        }

        void move(double dt){
            int dx = speed * dt;
            rect.x += dx; 
            if (rect.x + rect.w >= WIDTH_MAX) {
                rect.x = 0;
            }
            if (rect.x < 0){
                rect.x = WIDTH_MAX;
            }
        }
};