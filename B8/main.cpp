#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include "iterator.hpp"
#include "functor.hpp"

const size_t DEFAULT_LENGTH = 40;
const size_t MIN_LENGTH = 25;

int main(int argc, char *argv[])
{
  try
  {
    if ((argc != 1) && (argc != 3))
    {
      throw std::invalid_argument("Error: wrong amount of argc entered!\n");
    }

    size_t lengthOfLine = DEFAULT_LENGTH;
    if (argv[1] != nullptr)
    {
      if (strcmp(argv[1], "--line-width") != 0)
      {
        throw std::invalid_argument("Error: incorrect argument entered!");
      }

      if (std::stoi(argv[2]) < static_cast<int>(MIN_LENGTH))
      {
        throw std::invalid_argument("Error: incorrect argument entered!");
      }
      lengthOfLine = std::stoi(argv[2]);
  }

    Functor functor(static_cast<size_t>(lengthOfLine), std::cout);
    std::for_each(InputIterator(std::cin), InputIterator(), std::ref(functor));
  }
catch (const std::exception &except)
{
  std::cerr << except.what() << '\n';
  return 1;
}
catch (...)
{
  std::cerr << "Unknown error!" << std::endl;
  return 2;
}

return 0;
}

