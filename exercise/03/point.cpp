#include "point.h"

point::point(int x, int y): x_(x), y_(y)
{
}

bool point::operator==(const point& other)
{
  return x_ == other.x_ && y_ == other.y_;
}

bool point::operator!=(const point& other)
{
  return !(*this == other);
}

bool point::operator<(const point& other)
{
  if (other.x_ != x_)
    return _x < other.x_;
  return  y_ < other.y_;
}
