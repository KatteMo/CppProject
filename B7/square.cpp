#include "square.hpp"

Square::Square(const Point &point) :
  Shape(point)
{}

void Square::draw(std::ostream &out) const
{
  out << "SQUARE (" << this->center_.x << ';' << this->center_.y << ")\n";
}
