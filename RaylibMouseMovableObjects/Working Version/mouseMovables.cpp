#include "raylib.h"
#include <math.h>
//#include "MMOS.h"

const int screenWidth = 500;
const int screenHeight = 500;
bool moving = false; // This is neccesary so that multiple MMOs can't move at the same time

float distance(float x1, float y1, float x2, float y2){ // Distance formula
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

class MouseMovableObject{ // The MMO class
    public:
        float x, y, radius; // This can change depending on what you want to draw
        bool selfMoving = false; // This shoud not change
        Color color; 
    void draw(){ 
        DrawCircle(x, y, radius, color); // This should change depending on what you want to draw
    }
    void move(){ // This should not change
        if (distance(x, y, GetMouseX(), GetMouseY()) < radius && IsMouseButtonPressed(0) && !moving){ // Mouse Down
            selfMoving = true;
            moving = true;
        }
        if (IsMouseButtonReleased(0) && selfMoving){ // Mouse up
            selfMoving = false;
            moving = false;
        }
        if (selfMoving){ // While mouse down
            x = GetMouseX();
            y = GetMouseY();
        }
    }
};

/**********CODE FOR EXAMPLE**********/

const int mmosPerRow = 100; // spacing inbetween the MMOs

MouseMovableObject mmo;
MouseMovableObject mmos[int((screenWidth/mmosPerRow) * (screenHeight/mmosPerRow))];

void genMMOs(){ // This generates the MMOs for the example
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

/**********END CODE FOR EXAMPLE**********/

int main(void){
    
    InitWindow(screenWidth, screenHeight, "Mouse Movables Test"); // Initializing the window

    SetTargetFPS(60);
    
    genMMOs(); // Generating the MMOs for the example
    
    while (!WindowShouldClose()) // Main game loop
    {
        BeginDrawing();

        ClearBackground(WHITE);
        
        for (int i = 0; i < (screenWidth/mmosPerRow) * (screenHeight/mmosPerRow); i++){ // Drawing all of the MMOs
            mmos[i].draw();
            mmos[i].move();
        }

        EndDrawing();
    }

    CloseWindow();
}
