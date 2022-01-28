#ifndef CONSTANTS_H
#define CONSTANTS_H

typedef struct my_speed {
    int vx, vy;
} Speed;

// define your own namespace to hold constants
namespace constants
{
    const int WINDOW_WIDTH{ 800 };
    const int WINDOW_HEIGHT{ 600 };
}
#endif