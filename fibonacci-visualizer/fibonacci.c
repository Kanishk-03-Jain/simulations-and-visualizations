#include <stdio.h>
#include <raylib.h>

#define WIDTH 900
#define HEIGHT 600
#define COUNT 8
#define SCALE 10

int numbers[COUNT + 2];

void drawFibonacciSquare(int currentX, int currentY, int size) {
    DrawRectangle(currentX, currentY, size, size, WHITE);
    DrawRectangle(currentX + 1, currentY + 1, size - 2, size - 2, DARKGRAY);
}

void generateFibonacciNumbers() {
    numbers[0] = 0;
    numbers[1] = 1;

    for (int i = 2; i <= COUNT + 1; i++) {
        numbers[i] = numbers[i - 1] + numbers[i - 2];
    }
}

void drawFibonacciNumbers() {
    int currentX = 450 - SCALE, currentY = 300 - SCALE;

    for (int i = 1; i <= COUNT; i++) {
        int size = numbers[i] * SCALE;
        int nextSize = numbers[i + 1] * SCALE;
        int prevSize = numbers[i - 1] * SCALE;

        drawFibonacciSquare(currentX, currentY, size);

        int rem = (i - 1) % 4;

        Vector2 arcCenter;
        float startAngle, endAngle;

        switch (rem) {
            case 0:
                arcCenter = (Vector2){currentX + size, currentY};
                startAngle = 90;
                endAngle = 180;

                currentX += size;
                currentY -= prevSize;
                break;
            case 1:
                arcCenter = (Vector2){currentX, currentY};
                startAngle = 0;
                endAngle = 90;

                currentX -= prevSize;
                currentY -= nextSize;
                break;
            case 2:
                arcCenter = (Vector2){currentX, currentY + size};
                startAngle = 270;
                endAngle = 360;

                currentX -= nextSize;
                break;
            case 3:
                arcCenter = (Vector2){currentX + size, currentY + size};
                startAngle = 180;
                endAngle = 270;

                currentY += size;
                break;
            default:
                break;
        }

        DrawRingLines(arcCenter, size, size, startAngle, endAngle, 100, WHITE);
    }
}



int main() {
    generateFibonacciNumbers();
    InitWindow(WIDTH, HEIGHT, "Fibonacci Visualizer");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            drawFibonacciNumbers();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}