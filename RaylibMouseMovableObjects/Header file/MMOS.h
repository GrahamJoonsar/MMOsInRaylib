/*
*******NOTE*******
* I am using notepad++ for raylib as I have not been able to get VSCode to work, so I can't compile this
* with the main program to see if it works, but I believe it should.
*******ENDNOTE*******
*/

#pragma once
#include "raylib.h"

float distance(float x1, float y1, float x2, float y2);

bool moving = false;

class MouseMovableObject{
    public:
        float x, y, radius;
        bool selfMoving = false;
        Color color;
    void draw();
    void move();
};