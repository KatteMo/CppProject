#ifndef BULANOV_EGOR_CIRCLE_H
#define BULANOV_EGOR_CIRCLE_H

#include "shape.hpp"

class Circle : public Shape
{
public:
  explicit Circle(const Point &point);

  void draw(std::ostream &out) const override;
};


#endif
