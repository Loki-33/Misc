#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Define the grid size
#define GRID_WIDTH 160
#define GRID_HEIGHT 120
#define CELL_SIZE 5

typedef enum {
    EMPTY,
    SAND
} CellType;

typedef struct {
    CellType type;
    Color color;
} Cell;

Cell grid[GRID_WIDTH][GRID_HEIGHT];
Color GetRandomColor() {
    int r = GetRandomValue(0, 255);  //using raylib RandomValue function
    int g = GetRandomValue(0, 255); 
    int b = GetRandomValue(0, 255);  
    return (Color){ r, g, b, 255 };  
}
void UpdateSandParticles() {
    s
    for (int y = GRID_HEIGHT - 1; y >= 0; y--) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (grid[x][y].type == SAND) {
             
                if (y < GRID_HEIGHT - 1 && grid[x][y + 1].type == EMPTY) {
                    
                    grid[x][y + 1] = grid[x][y];
                    grid[x][y].type = EMPTY;
                }
               
                else if (y < GRID_HEIGHT - 1 && x > 0 && grid[x - 1][y + 1].type == EMPTY) {
                    grid[x - 1][y + 1] = grid[x][y];
                    grid[x][y].type = EMPTY;
                }
                else if (y < GRID_HEIGHT - 1 && x < GRID_WIDTH - 1 && grid[x + 1][y + 1].type == EMPTY) {
                    grid[x + 1][y + 1] = grid[x][y];
                    grid[x][y].type = EMPTY;
                }
            }
        }
    }
}

void DrawGridd(void) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (grid[x][y].type != EMPTY) {
                DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, grid[x][y].color);
            } 
        }
    }
}

int main(void) {
  
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Falling Sand Simulation");
    SetTargetFPS(60);

    
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[x][y].type = EMPTY;
            grid[x][y].color = BLANK;
        }
    }

 
    while (!WindowShouldClose()) {
        
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            int gridX = mousePos.x / CELL_SIZE;
            int gridY = mousePos.y / CELL_SIZE;
            
            if (gridX >= 0 && gridX < GRID_WIDTH && gridY >= 0 && gridY < GRID_HEIGHT) {
                grid[gridX][gridY].type = SAND;
                grid[gridX][gridY].color = GetRandomColor();
            }
        }
      
        UpdateSandParticles();

        
        BeginDrawing();
        ClearBackground(BLACK);

        DrawGridd();

        EndDrawing();
    }


    CloseWindow();  

    return 0;
}
