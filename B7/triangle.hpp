#ifndef B7_TRIANGLE_HPP
#define B7_TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  explicit Triangle(const Point &point);

  void draw(std::ostream &out) const override;
};


#endif
