#include <algorithm>
#include "shape.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "square.hpp"

Shape::Shape(const Point &point) :
  center_(point)
{}

bool Shape::isMoreLeft(const Shape::shapePtr &shape) const
{
  return this->center_.x < shape->center_.x;
}

bool Shape::isUpper(const Shape::shapePtr &shape) const
{
  return this->center_.y > shape->center_.y;
}

Shape::shapePtr shapeType(const std::string &type, const Point &point)
{
  if (type == "CIRCLE")
  {
    return std::make_shared<const Circle>(point);
  } else if (type == "SQUARE")
  {
    return std::make_shared<const Square>(point);
  } else if (type == "TRIANGLE")
  {
    return std::make_shared<const Triangle>(point);
  } else
  {
    return nullptr;
  }
}

std::ostream &operator<<(std::ostream &out, const Shape::shapePtr &shape)
{
  shape->draw(out);
  return out;
}

std::istream &operator>>(std::istream &in, Shape::shapePtr &shape)
{
  std::string sType;
  in >> std::ws;

  if(in.peek() == EOF)
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  while (in.peek() != '(' && !std::isblank(in.peek()))
  {
    if (in.peek() == '\n')
    {
      in.setstate(std::ios::failbit);
      break;
    }

    sType += in.get();
  }

  Point point;
  in >> point;
  if (in.fail())
  {
    return in;
  }

  shape = shapeType(sType, point);

  if (shape == nullptr)
  {
    in.setstate(std::ios::eofbit);
  }

  return in;

}


