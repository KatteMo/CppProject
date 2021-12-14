#ifndef B7_SQUARE_HPP
#define B7_SQUARE_HPP

#include "shape.hpp"

class Square : public Shape
{
public:
  explicit Square(const Point &point);

  void draw(std::ostream &out) const override;
};


#endif
