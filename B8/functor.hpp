#ifndef B8_FUNCTOR_HPP
#define B8_FUNCTOR_HPP

#include <iostream>
#include <iterator>
#include "textCorrection.hpp"

class Functor
{
public:
  Functor(size_t lineLength, std::ostream &out);

  ~Functor();

  void operator()(TextCorrection & textCorrection);

private:
  const size_t lineLength_;
  std::string resultLine_;
  std::ostream &out_;

};


#endif
