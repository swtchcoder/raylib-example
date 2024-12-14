#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <raylib.h>


int main() {
  const unsigned int seed = time(NULL);
  srand(seed);
  printf("seed: %d\n", seed);

  const unsigned int screenWidth = 800;
  const unsigned int screenHeight = 600;

  Rectangle* rect = malloc(sizeof(Rectangle));
  if (rect == NULL) {
    printf("Failed to allocate memory\n");
    return 1;
  }

  rect->width = 200;
  rect->height = 100;
  
  const unsigned int surfaceWidth = screenWidth - rect->width;
  const unsigned int surfaceHeight = screenHeight - rect->height;

  rect->x = rand() % surfaceWidth;
  rect->y = rand() % surfaceHeight;

  Vector2 next = {0, 0};
  Vector2 translation = {5, 5};

  InitWindow(screenWidth, screenHeight, "Bouncing rectangle");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    next.x = rect->x + translation.x;
    next.y = rect->y + translation.y;

    translation.x += (next.x < 0) * 10 + (next.x > surfaceWidth) * -10;
    translation.y += (next.y < 0) * 10 + (next.y > surfaceHeight) * -10;

    rect->x += translation.x;
    rect->y += translation.y;

    BeginDrawing();
      ClearBackground(RAYWHITE);

      DrawRectangle(rect->x, rect->y, rect->width, rect->height, RED);
    EndDrawing();
  }

  CloseWindow();
  free(rect);

  return 0;
}