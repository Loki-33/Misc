#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "raylib.h"
#define MAX_ITER 1000
#define ZOOM 200.0

int main(){
	const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "MADELBROT SET");

    double offsetx = -screenWidth/2;
    double offsety = -screenHeight/2;
    double scale = 1.0;
    

    SetTargetFPS(60);               
    while (!WindowShouldClose())    
    {
        if (IsKeyDown(KEY_UP)) scale *= 1.05;
        if (IsKeyDown(KEY_DOWN)) scale /= 1.05;

        BeginDrawing();
		ClearBackground(BLACK);

		for (int y=0;y<screenHeight;y++){
			for (int x=0;x<screenWidth;x++){

				double real = (x+offsetx)/(ZOOM*scale);
				double imag = (y+offsety)/(ZOOM*scale);

				complex double c = real+imag*I;
				complex double z = 0;
				int iter;

				for (iter=0;iter<MAX_ITER;iter++){
					if (cabs(z) > 2.0)break;
					z = z*z+c;

					if (iter<MAX_ITER){
					Color color = (Color){(iter*5)%255, (iter*10)%255, (iter*20)%255, 255};
					DrawPixel(x, y, color);
				}
				}
			}
		}          	

        EndDrawing();
       
    }

    CloseWindow();        


	return 0;
}
