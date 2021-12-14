#ifndef B8_ITERATOR_HPP
#define B8_ITERATOR_HPP

#include <iostream>
#include <iterator>
#include "textCorrection.hpp"

class InputIterator : public std::iterator<std::input_iterator_tag, TextCorrection>
{
public:
  explicit InputIterator(std::istream &);

  InputIterator();

  TextCorrection &operator*();

  TextCorrection *operator->();

  InputIterator &operator++();

  InputIterator operator++(int);

  bool operator==(const InputIterator &) const;

  bool operator!=(const InputIterator &) const;

private:
  std::istream *in_;
  bool isNormal_;
  TextCorrection current_;

  void parseText();

  void readWord();

  void readNumber();

  void readDash();
};


#endif
