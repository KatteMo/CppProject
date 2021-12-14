#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include "shape.hpp"

void task2()
{
  std::vector<Shape::shapePtr> shapes{std::istream_iterator<Shape::shapePtr>(std::cin),
      std::istream_iterator<Shape::shapePtr>()};

  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::invalid_argument("Error: there was a problem reading the data in task 2!\n");
  }

  std::cout << "Original:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape::shapePtr>(std::cout));

  std::cout << "Left-Right:\n";
  std::sort(shapes.begin(), shapes.end(), std::bind(&Shape::isMoreLeft, std::bind(&Shape::shapePtr::operator*,
      std::placeholders::_1), std::placeholders::_2));
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape::shapePtr>(std::cout));

  std::cout << "Right-Left:\n";
  std::reverse(shapes.begin(), shapes.end());
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape::shapePtr>(std::cout));

  std::cout << "Top-Bottom:\n";

  std::sort(shapes.begin(), shapes.end(), std::bind(&Shape::isUpper, std::bind(&Shape::shapePtr::operator*,
      std::placeholders::_1), std::placeholders::_2));
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape::shapePtr>(std::cout));

  std::cout << "Bottom-Top:\n";
  std::reverse(shapes.begin(), shapes.end());
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape::shapePtr>(std::cout));
}


