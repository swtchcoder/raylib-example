#include <stdlib.h>
#include <time.h>

#include "raylib.h"

#include "interval_clock.h"

#define TICK_RATE 20

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

#define RECTANGLE_WIDTH  200
#define RECTANGLE_HEIGHT 100
#define RECTANGLE_SPEED  15

int main() {
  srand(time(NULL));
  
  interval_clock_t physic_clock;
  interval_clock_init(&physic_clock, TICK_RATE);

  // objects
  int box_width = SCREEN_WIDTH - RECTANGLE_WIDTH;
  int box_height = SCREEN_HEIGHT - RECTANGLE_HEIGHT;

  Vector2 rectangle_position_actual = {
    rand() % box_width, 
    rand() % box_height
  };
  Vector2 rectangle_position_previous = rectangle_position_actual;
  Vector2 rectangle_speed_vector = {RECTANGLE_SPEED, RECTANGLE_SPEED};

  // window
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bouncing rectangle");
  SetWindowMinSize(RECTANGLE_WIDTH, RECTANGLE_HEIGHT);

  while (!WindowShouldClose()) {
    if (IsWindowResized()) {
      box_width  = GetScreenWidth() - RECTANGLE_WIDTH;
      box_height = GetScreenHeight() - RECTANGLE_HEIGHT;
    }

    // timing
    int missed_ticks = interval_clock_update(&physic_clock);
    for (int i = 0; i < missed_ticks; i++) {
      if (rectangle_position_actual.x > box_width) rectangle_position_actual.x = box_width;
      if (rectangle_position_actual.y > box_height) rectangle_position_actual.y = box_height;

      rectangle_position_previous = rectangle_position_actual;
      Vector2 next = {
        rectangle_position_actual.x + rectangle_speed_vector.x, 
        rectangle_position_actual.y + rectangle_speed_vector.y
      };

      if (next.x < 0 || next.x > box_width)  rectangle_speed_vector.x *= -1;
      if (next.y < 0 || next.y > box_height) rectangle_speed_vector.y *= -1;

      rectangle_position_actual.x += rectangle_speed_vector.x;
      rectangle_position_actual.y += rectangle_speed_vector.y;
    }
    
    // interpolation
    float alpha = physic_clock.accumulated_time / physic_clock.tick_interval;
    if (alpha > 1.0f) alpha = 1.0f;

    float interpolatedX = rectangle_position_previous.x * (1 - alpha) + rectangle_position_actual.x * alpha;
    float interpolatedY = rectangle_position_previous.y * (1 - alpha) + rectangle_position_actual.y * alpha;

    // drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangle(interpolatedX, interpolatedY, RECTANGLE_WIDTH, RECTANGLE_HEIGHT, RED);

    DrawFPS(10, 10);
    EndDrawing();

    continue;
  }

  CloseWindow();

  return 0;
}