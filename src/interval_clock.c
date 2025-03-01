#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "interval_clock.h"

void interval_clock_init(interval_clock_t* interval_clock, double tick_rate) {
  if (tick_rate <= 0) {
    printf("Invalid tick rate\n");
    exit(1);
  }

  interval_clock->tick_interval = 1.0 / tick_rate;
  interval_clock->start_time = clock();
  interval_clock->accumulated_time = 0.0;
}

int interval_clock_update(interval_clock_t* interval_clock) {		
  clock_t current_time = clock();

  double delta_time = (double)(current_time - interval_clock->start_time) / CLOCKS_PER_SEC;  

  interval_clock->accumulated_time += delta_time;

  interval_clock->start_time = current_time;

  int missed_ticks = (int)(interval_clock->accumulated_time / interval_clock->tick_interval);

  interval_clock->accumulated_time -= missed_ticks * interval_clock->tick_interval;

  return missed_ticks;
}
