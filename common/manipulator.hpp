#ifndef B7_MANIPULATOR_HPP
#define B7_MANIPULATOR_HPP

#include <cctype>
#include <istream>

std::istream &ignoreSpace(std::istream& in)
{
  while(!in.eof() && std::isblank(in.peek()))
  {
    in.ignore();
  }
  return in;
}
#endif
