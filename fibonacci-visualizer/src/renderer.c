#include "../include/renderer.h"
#include "../include/fibonacci.h"
#include <raylib.h>

void drawFibonacciSquare(int currentX, int currentY, int size) {
  DrawRectangle(currentX, currentY, size, size, WHITE);
  DrawRectangle(currentX + 1, currentY + 1, size - 2, size - 2, DARKGRAY);
}

void drawFibonacciNumbers() {
  int currentX = (WIDTH / 2) - SCALE, currentY = (HEIGHT / 2) - SCALE;

  for (int i = 1; i <= COUNT; i++) {
    int size = numbers[i] * SCALE;
    int nextSize = numbers[i + 1] * SCALE;
    int prevSize = numbers[i - 1] * SCALE;

    drawFibonacciSquare(currentX, currentY, size);

    int rem = (i - 1) % 4;

    Vector2 arcCenter = {0, 0};
    float startAngle = 0.0f, endAngle = 0.0f;

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
