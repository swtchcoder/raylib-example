#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "color.h"

color_t color_generate_random() {
  color_t color;
  color.r = rand() % 256;
  color.g = rand() % 256;
  color.b = rand() % 256;

  return color;
}

double color_luminance_calculate(color_t color) {
  double r = color.r / 255.0;
  double g = color.g / 255.0;
  double b = color.b / 255.0;
  
  return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

color_t color_luminance_adjust(color_t color, double target_luminance) {
  double current_luminance = color_luminance_calculate(color);
  printf("%f\n", current_luminance);
  if (fabs(current_luminance - target_luminance) < 0.01) {
    return color;
  }
  
  double factor = target_luminance / current_luminance;

  color_t adjusted_color;
  adjusted_color.r = fmin(255, (int)(color.r * factor));
  adjusted_color.g = fmin(255, (int)(color.g * factor));
  adjusted_color.b = fmin(255, (int)(color.b * factor));

  return adjusted_color;
}

double lerp(double start, double end, double t) {
  return start + (end - start) * t;
}

color_t color_interpolate(color_t color1, color_t color2, double t) {
  color_t result;
  result.r = (int)floor(lerp(color1.r, color2.r, t));
  result.g = (int)floor(lerp(color1.g, color2.g, t));
  result.b = (int)floor(lerp(color1.b, color2.b, t));

  return result;
}

void color_gradient_init(color_t* gradient, color_t color1, color_t color2, int steps) {
  for (int i = 0; i < steps; i++) {
      double t = (double)i / (steps - 1);
      gradient[i] = color_interpolate(color1, color2, t);
  }
}
