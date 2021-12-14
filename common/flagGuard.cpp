#include "flagGuard.hpp"

FlagGuards::FlagGuards(std::istream &in) :
  flags_(in.flags()),
  in_(in)
{}

FlagGuards::~FlagGuards()
{
  in_.flags(flags_);
}
