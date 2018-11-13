#pragma once
#include <windows.h>

class color {
public:
  color(double red = 0.0, double green = 0.0, double blue = 0.0);
  bool operator==(const color& other) const;
  double get_red() const;
  double get_green() const;
  double get_blue() const;
  void set_red(double red);
  void set_green(double green);
  void set_blue(double blue);
  COLORREF get_color_ref() const;
  double get_luminance() const;
private:
  double red_;
  double green_;
  double blue_;
};