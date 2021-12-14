#include "functor.hpp"

Functor::Functor(size_t lineLength, std::ostream &out):
  lineLength_(lineLength),
  resultLine_(),
  out_(out)
{}

Functor::~Functor()
{
  if(!resultLine_.empty())
  {
    out_ << resultLine_ << '\n';
  }
}

void Functor::operator()(TextCorrection &text)
{
  if (text.type_ == TextCorrection::WORD || text.type_ == TextCorrection::NUMBER)
  {
    if (resultLine_.size() + text.data_.length() + 1 > lineLength_)
    {
      out_ << resultLine_ << '\n';
      resultLine_.clear();
    }
    else if (!resultLine_.empty())
    {
      resultLine_ += " ";
    }
    resultLine_ += text.data_;
  }
  else
  {
    if (((text.type_ == TextCorrection::PUNCTUATION && text.data_[1] == '-') &&
        ((resultLine_.size() + 4) > lineLength_)) || (((resultLine_.size() + 1) > lineLength_)))
    {
      size_t lastSpace = resultLine_.find_last_of(' ');
      size_t amountOfSymbols = resultLine_.size() - lastSpace;
      std::string temp = resultLine_.substr(lastSpace, amountOfSymbols);
      resultLine_.erase(lastSpace, amountOfSymbols);
      temp.erase(0, 1);

      out_ << resultLine_ << '\n';
      resultLine_ = temp;
    }
    if (text.type_ == TextCorrection::PUNCTUATION && text.data_[1] == '-')
    {
      resultLine_ += " ";
    }

    resultLine_ += text.data_;
  }
}
