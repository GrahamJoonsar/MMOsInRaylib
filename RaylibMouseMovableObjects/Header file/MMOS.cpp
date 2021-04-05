#include "MMOS.h"
#include "raylib.h"

float distance(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void MouseMovableObject::draw(){
    DrawCircle(x, y, radius, color);
}

void MouseMovableObject::move(){
    if (distance(x, y, GetMouseX(), GetMouseY()) < radius && IsMouseButtonPressed(0) && !moving){
        selfMoving = true;
        moving = true;
    }
    if (IsMouseButtonReleased(0) && selfMoving){
        selfMoving = false;
        moving = false;
    }
    if (selfMoving){
        x = GetMouseX();
        y = GetMouseY();
    }
}