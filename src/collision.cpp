#include <cstdlib>
#include <SDL2/SDL.h>
#include "constants.h"


void collidRect(SDL_Rect rect1, speed* v1, SDL_Rect rect2, speed* v2);

void collidRect(SDL_Rect rect1, speed* v1, SDL_Rect rect2, speed* v2){
    SDL_Rect intersect;
    if (SDL_IntersectRect(&rect1, &rect2, &intersect) == SDL_TRUE){

    }
}

