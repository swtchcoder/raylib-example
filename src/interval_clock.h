#ifndef INTERVAL_CLOCK_H
#define INTERVAL_CLOCK_H

#include <time.h>

/**
 * @brief Structure for managing a custom clock for fixed time intervals.
 *
 * This structure is used to track and manage the elapsed time and tick intervals 
 * for a custom clock system. It allows for controlling the timing of events 
 * and can be used for game loops, physics updates, and other time-dependent tasks.
 */
typedef struct {
  double tick_interval;
  clock_t start_time;
 	double accumulated_time;
} interval_clock_t;

/**
 * @brief Initializes the custom clock with a specified tick rate.
 *
 * This function sets up the custom clock with the specified tick rate. It calculates 
 * the time interval between each tick, and initializes other time-related parameters.
 *
 * @param interval_clock Pointer to the interval_clock_t structure to initialize.
 * @param tick_rate The desired tick rate, i.e., the number of ticks per second.
 * 
 * @note The tick rate must be greater than zero.
 */
void interval_clock_init(interval_clock_t* interval_clock, double tick_rate);

/**
 * @brief Updates the custom clock and calculates the number of missed ticks.
 *
 * This function is responsible for updating the custom clock by calculating the 
 * elapsed time since the last update. It also tracks the number of missed ticks, 
 * which occurs if the updates are slower than the tick rate. The number of missed 
 * ticks is returned so that other parts of the system can handle skipped updates.
 *
 * @param interval_clock Pointer to the interval_clock_t structure to update.
 * 
 * @return The number of missed ticks that occurred since the last update.
 */
int interval_clock_update(interval_clock_t* interval_clock);

#endif
