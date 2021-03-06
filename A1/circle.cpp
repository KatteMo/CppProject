#include "circle.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>

Circle::Circle(double radius, const point_t &center) :
  radius_(radius),
  pos_(center)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Invalid radius:  " + std::to_string(radius));
  }
}

void Circle::move(const point_t &center)
{
  pos_ = center;
}

void Circle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{2 * radius_, 2 * radius_, pos_};
}

void Circle::printInform() const
{
  std::cout << "Circle radius: " << radius_
      << "; Circle center: (" << pos_.x << ", " << pos_.y << ") \n";
}

void Circle::printFrameInform() const
{
  std::cout << "Rect frame information:   width = " << getFrameRect().width
      << "; height = " << getFrameRect().height << "; center = (" << getFrameRect().pos.x
      << ", " << getFrameRect().pos.y << ')' << std::endl;
}

point_t Circle::getCenter() const
{
  return pos_;
}




