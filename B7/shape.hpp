#ifndef B7_SHAPE_H
#define B7_SHAPE_H

#include <iostream>
#include <memory>
#include <string>
#include "point.hpp"

class Shape
{
public:
  explicit Shape(const Point &point);

  virtual ~Shape() = default;

  using shapePtr = std::shared_ptr<const Shape>;

  bool isMoreLeft(const shapePtr &shape) const;

  bool isUpper(const shapePtr &shape) const;

  virtual void draw(std::ostream &out) const = 0;

protected:
  Point center_;
};

Shape::shapePtr shapeType(const std::string &type, const Point &point);

std::istream &operator>>(std::istream &in, Shape::shapePtr &shape);
std::ostream &operator<<(std::ostream &out, const Shape::shapePtr &shape);

#endif
