#ifndef COLOR_H
#define COLOR_H

/**
 * @struct color_t
 * @brief Represents an RGB color_t with red, green, and blue components.
 *
 * The color_t struct is used to define colors in an RGB color_t space,
 * where each component is an integer ranging from 0 to 255.
 */
typedef struct {
    int r;
    int g;
    int b;
} color_t;

/**
 * @brief Generates a random RGB color.
 *
 * This function creates a Color struct with randomly generated red, 
 * green, and blue values between 0 and 255.
 *
 * @return A Color struct containing a randomly generated color.
 */
color_t color_generate_random();

/**
 * @brief Calculates the luminance of a given color_t using the W3C formula.
 *
 * Luminance is a measure of the brightness of a color_t. This function computes 
 * the luminance using the formula:
 *
 *    luminance = 0.2126 * R + 0.7152 * G + 0.0722 * B
 *
 * where R, G, and B are the normalized (0 to 1) values of the color_t components.
 *
 * @param color The color_t whose luminance is to be calculated.
 * @return A double representing the luminance value (0 to 1).
 */
double color_luminance_calculate(color_t color);

/**
 * @brief Adjusts the luminance of a color_t while preserving its hue.
 *
 * This function modifies the brightness of the input color_t to match a 
 * specified target luminance. The adjustment factor is computed as:
 *
 *    factor = targetLuminance / currentLuminance
 *
 * Each color_t component is then scaled by this factor while ensuring 
 * the values remain within the 0-255 range.
 *
 * @param color The input color_t.
 * @param targetLuminance The desired luminance value (0 to 1).
 * @return A new color_t struct with adjusted luminance.
 */
color_t color_luminance_adjust(color_t color, double targetLuminance);

/**
 * @brief Linearly interpolates between two values.
 *
 * This function performs a linear interpolation between two numbers
 * based on a given interpolation factor t:
 *
 *    result = start + (end - start) * t
 *
 * @param start The starting value.
 * @param end The ending value.
 * @param t The interpolation factor (0 to 1).
 * @return The interpolated value.
 */
double lerp(double start, double end, double t);

/**
 * @brief Linearly interpolates between two colors.
 *
 * This function computes an interpolated color_t between two given colors 
 * based on an interpolation factor t. Each component is interpolated 
 * separately using linear interpolation.
 *
 * @param color1 The starting color_t.
 * @param color2 The ending color_t.
 * @param t The interpolation factor (0 to 1).
 * @return The interpolated color_t as a color_t struct.
 */
color_t color_interpolate(color_t color1, color_t color2, double t);

/**
 * @brief Generates a gradient between two colors.
 *
 * This function creates a gradient of colors between two specified colors.
 * It generates a specified number of steps and fills an array with
 * interpolated colors.
 *
 * @param gradient An array of color_t structs to store the gradient (size must be at least `steps`).
 * @param color1 The starting color_t of the gradient.
 * @param color2 The ending color_t of the gradient.
 * @param steps The number of colors in the gradient.
 */
void color_gradient_init(color_t *gradient, color_t color1, color_t color2, int steps);

#endif