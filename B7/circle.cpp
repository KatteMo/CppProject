#include "circle.hpp"

Circle::Circle(const Point &point) :
  Shape(point)
{}

void Circle::draw(std::ostream &out) const
{
  out << "CIRCLE (" << this->center_.x << ';' << this->center_.y << ")\n";
}
