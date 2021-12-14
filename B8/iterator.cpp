#include "iterator.hpp"
#include <istream>

const size_t MAX_ELEMENT_LENGTH = 20;

InputIterator::InputIterator(std::istream &in) :
  in_(&in),
  isNormal_(true),
  current_("", TextCorrection::UNKNOWN)
{
  parseText();
}

InputIterator::InputIterator() :
  in_(nullptr),
  isNormal_(false),
  current_("", TextCorrection::UNKNOWN)
{}

TextCorrection &InputIterator::operator*()
{
  return current_;
}

TextCorrection *InputIterator::operator->()
{
  return &current_;
}

InputIterator &InputIterator::operator++()
{
  parseText();
  return *this;
}

InputIterator InputIterator::operator++(int)
{
  InputIterator *iterator = this;
  parseText();
  return *iterator;
}

bool InputIterator::operator==(const InputIterator &other) const
{
  return (isNormal_ == other.isNormal_) && (!isNormal_ || in_ == other.in_);
}

bool InputIterator::operator!=(const InputIterator &other) const
{
  return !(operator==(other));
}

void InputIterator::parseText()
{
  (*in_) >> std::ws;
  char first = in_->get();
  char second = in_->peek();

  if ((*in_).fail())
  {
    isNormal_ = false;
    return;
  }

  if (isalpha(first))
  {
    in_->unget();
    readWord();
  } else if (isdigit(first) || ((first == '-' || first == '+') && isdigit(second)))
  {
    in_->unget();
    readNumber();
  } else if (ispunct(first))
  {
    if (current_.data_.empty())
    {
      throw std::invalid_argument("Error: text can't start with punctuation!");
    }
    if (current_.type_ == TextCorrection::PUNCTUATION)
    {
      if (current_.data_ == "," && first == '-')
      {
        in_->unget();
        readDash();
        return;
      }
      else
      {
        throw std::invalid_argument("Error: punctuation can't be after another punctuation");
      }
    }
    if (first == '-')
    {
      in_->unget();
      readDash();
    }
    else
    {
      std::string temp;
      temp.push_back(first);
      current_ = std::move(TextCorrection(std::move(temp), TextCorrection::PUNCTUATION));
    }
  }
}

void InputIterator::readWord()
{
  std::string word;
  word.push_back(in_->get());
  while (isalpha(in_->peek()) || in_->peek() == '-')
  {
    char curr = in_->get();
    if (word.length() >= MAX_ELEMENT_LENGTH)
    {
      throw std::invalid_argument("Error: length of word can not be more than 20!");
    }
    if (curr == '-' && in_->peek() == '-')
    {
      throw std::invalid_argument("Error: invalid type of word!");
    }
    word.push_back(curr);
  }

  current_ = std::move(TextCorrection(std::move(word), TextCorrection::WORD));
}

void InputIterator::readNumber()
{
  std::string number;
  size_t countOfDotes = 0;
  number.push_back(in_->get());
  while (isdigit(in_->peek()) || in_->peek() == '.')
  {
    if (number.length() >= MAX_ELEMENT_LENGTH)
    {
      throw std::invalid_argument("Error: length of number can not be more than 20!");
    }
    char curr = in_->get();
    if (curr == '.')
    {
      countOfDotes++;
      if (countOfDotes > 1)
      {
        throw std::invalid_argument("to long number!");
      }
    }
    number.push_back(curr);
  }

  current_ = std::move(TextCorrection(std::move(number), TextCorrection::NUMBER));
}

void InputIterator::readDash()
{
  size_t countOfDash = 0;
  while (in_->peek() == '-')
  {
    in_->get();
    countOfDash++;
  }

  if (countOfDash != 3)
  {
    throw std::invalid_argument("Error: wrong type of dash!");
  }

  current_ = std::move(TextCorrection("---", TextCorrection::PUNCTUATION));
}


