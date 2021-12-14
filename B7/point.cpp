#include "point.hpp"
#include <iostream>
#include "../common/flagGuard.hpp"
#include "../common/manipulator.hpp"

std::istream &operator>>(std::istream &in, Point &point)
{
  FlagGuards flagGuards(in);
  in.unsetf(std::ios_base::skipws);
  bool isError = false;

  char openBracket = '\0', semicolon = '\0', closeBracket = '\0';
  in >> ignoreSpace >> openBracket >> ignoreSpace >> point.x >> ignoreSpace >> semicolon
    >> ignoreSpace >> point.y >> ignoreSpace >> closeBracket;

  if (openBracket != '(' || semicolon != ';' || closeBracket != ')' || !in.good())
  {
    in.clear();
    isError = true;
  }

  if (isError)
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}
