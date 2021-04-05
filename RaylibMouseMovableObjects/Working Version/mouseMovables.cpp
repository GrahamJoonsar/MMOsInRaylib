#include "raylib.h"
#include <math.h>
//#include "MMOS.h"

const int screenWidth = 500;
const int screenHeight = 500;
bool moving = false;

float distance(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

class MouseMovableObject{
    public:
        float x, y, radius;
        bool selfMoving = false;
        Color color;
    void draw(){
        DrawCircle(x, y, radius, color);
    }
    void move(){
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
};

const int mmosPerRow = 100;

MouseMovableObject mmo;
MouseMovableObject mmos[int((screenWidth/mmosPerRow) * (screenHeight/mmosPerRow))];

void genMMOs(){
    mmo.color = RED;
    mmo.radius = 20;
    int index = 0;
    for (int x = mmosPerRow/2; x < screenWidth; x += mmosPerRow){
        for(int y = mmosPerRow/2; y < screenHeight; y += mmosPerRow){
            mmo.x = x;
            mmo.y = y;
            mmos[index++] = mmo;
        }
    }
}

int main(void){
    
    InitWindow(screenWidth, screenHeight, "Mouse Movables Test"); // Initializing the window

    SetTargetFPS(60);
    
    genMMOs();
    
    while (!WindowShouldClose()) // Main game loop
    {
        BeginDrawing();

        ClearBackground(WHITE);
        
        for (int i = 0; i < (screenWidth/mmosPerRow) * (screenHeight/mmosPerRow); i++){
            mmos[i].draw();
            mmos[i].move();
        }

        EndDrawing();
    }

    CloseWindow();
}