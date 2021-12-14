#ifndef B8_TEXTCORRECTION_HPP
#define B8_TEXTCORRECTION_HPP

#include <iostream>
#include <string>

class TextCorrection
{
public:
  enum typeOfElement
  {
    WORD,
    NUMBER,
    PUNCTUATION,
    UNKNOWN
  };

  std::string data_;
  typeOfElement type_;

  TextCorrection(std::string line, typeOfElement type);
};

#endif
