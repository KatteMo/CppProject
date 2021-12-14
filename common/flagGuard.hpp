#ifndef B7_FLAGGUARD_HPP
#define B7_FLAGGUARD_HPP

#include <istream>

class FlagGuards
{
public:
  explicit FlagGuards(std::istream &);

  virtual ~FlagGuards();

private:
  std::ios::fmtflags flags_;
  std::istream &in_;
};


#endif
