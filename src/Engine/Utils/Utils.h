/*
 * Utils.h
 *
 *  Created on: Jan. 8, 2019
 *      Author: serge
 */

#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

#include <string>

static const float EPSILON = 0.0001f;

const float PI = 3.14159f;
const float TWO_PI = 2.0f * PI;

bool IsEqual(float x, float y);

bool IsGreaterThanOrEqual(float x, float y);

bool IsLessThanOrEqual(float x, float y);

float MsToSec(unsigned int milliseconds);

unsigned int GetIndex(unsigned int width, unsigned int r, unsigned int c);

bool StringCompare(const std::string& a, const std::string& b);

float Clamp(float val, float min, float max);
int8_t Clamp(int8_t val, int8_t min, int8_t max);

struct Size {
    unsigned int width = 0, height = 0;
};

#endif /* UTILS_UTILS_H_ */
