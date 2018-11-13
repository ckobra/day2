#include "stdafx.h"
#include "color.h"

namespace {
  // Convert to [0, 1.0] range 
  double to_correct_value(const double input) {
    if (input > 1.0) return 1.0;
    if (input < 0.0) return 0.0;
    return input;
  }
}

color::color(double red, double green, double blue) {
  red_ = to_correct_value(red);
  green_ = to_correct_value(green);
  blue_ = to_correct_value(blue);
}

bool color::operator==(const color& other) const {
  return red_ == other.red_ && green_ == other.green_ && blue_ == other.blue_;
}

double color::get_red() const {
  return red_;
}

double color::get_green() const {
  return green_;
}

double color::get_blue() const {
  return blue_;
}

void color::set_red(const double red) {
  red_ = to_correct_value(red);
}

void color::set_green(const double green) {
  green_ = to_correct_value(green);
}

void color::set_blue(const double blue) {
  blue_ = to_correct_value(blue);
}

COLORREF color::get_color_ref() const {
  return RGB(static_cast<BYTE>(255 * red_), static_cast<BYTE>(255 * green_), static_cast<BYTE>(255 * blue_));
}

double color::get_luminance() const {
  return red_ * 0.2126 + green_ * 0.7152 + blue_ * 0.0722;
}