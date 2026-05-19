#include <raylib.h>

#include "../include/fibonacci.h"
#include "../include/renderer.h"

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