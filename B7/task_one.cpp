#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <functional>

void task1()
{
  std::transform(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(),
    std::ostream_iterator<double>(std::cout, " "), std::bind(std::multiplies<>(), std::placeholders::_1, M_PI));

  if ((!std::cin.eof()) && (std::cin.fail()))
  {
    throw std::invalid_argument("Error: there was a problem reading the data!\n");
  }

}


