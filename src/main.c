#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "raylib.h"

#define TICK_RATE 20

int main() {
  // timing
  float tick_interval = 1.0 / (double)TICK_RATE;

  clock_t start_time = clock();
  clock_t current_time;

  double elapsed_time;
  double leftover_time = 0.0;


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
  
  unsigned int surfaceWidth = screenWidth - rect->width;
  unsigned int surfaceHeight = screenHeight - rect->height;

  rect->x = rand() % surfaceWidth;
  rect->y = rand() % surfaceHeight;

  Vector2 actual = {rect->x, rect->y};
  Vector2 previous = actual;
  Vector2 translation = {5, 5};

  InitWindow(screenWidth, screenHeight, "Bouncing rectangle");
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);

  while (!WindowShouldClose()) {
    // timing
    current_time = clock();
    elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
    start_time = current_time;
    leftover_time += elapsed_time; 

    while (leftover_time >= tick_interval) {
      previous = actual;
      Vector2 next = {
        actual.x + translation.x, 
        actual.y + translation.y
      };

      if (next.x < 0 || next.x > surfaceWidth) translation.x *= -1;
      if (next.y < 0 || next.y > surfaceHeight) translation.y *= -1;

      actual.x += translation.x;
      actual.y += translation.y;

      leftover_time -= tick_interval;
    }

    // interpolation
    float alpha = leftover_time / tick_interval;

    float interpolatedX = previous.x * (1 - alpha) + actual.x * alpha;
    float interpolatedY = previous.y * (1 - alpha) + actual.y * alpha;

    // drawing
    BeginDrawing();
      ClearBackground(RAYWHITE);

      DrawRectangle(interpolatedX, interpolatedY, rect->width, rect->height, RED);

      DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
  free(rect);

  return 0;
}