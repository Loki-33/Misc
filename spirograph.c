#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "raylib.h"
#include <math.h>

#define MAX_ITER 100000
#define WIDTH 800
#define HEIGHT 600


void DrawSpirograph(float R, float r, float d, int points, Color color) {
    Vector2 prevPoint = { 0 }; 
    for (int i = 0; i < points; i++) {
        float t = (2 * PI * i) / points; 

        
        float x = (R - r) * cos(t) + d * cos(((R - r) / r) * t);
        float y = (R - r) * sin(t) - d * sin(((R - r) / r) * t);

        Vector2 currentPoint = { 400 + x, 300 + y }; 
        Color color = (Color){(i*5)%255, (i*4)%255, (i*20)%255, 255};
       
        if (i > 0) {
            DrawLineV(prevPoint, currentPoint, color);
        }

        prevPoint = currentPoint; 
    }
}


int main(){
	const int screenWidth = WIDTH;
    const int screenHeight = HEIGHT;
    InitWindow(screenWidth, screenHeight, "SPIROGRAPH SET");
   	float R =130;
   	float r = 5;
   	float d=100;
   	int points=5000;

    SetTargetFPS(60);               
    while (!WindowShouldClose())    
    {
    
        BeginDrawing();
		ClearBackground(BLACK);
		
		DrawSpirograph(R, r, d, points, WHITE);
        EndDrawing();
       
    }

    CloseWindow();        


	return 0;
}
