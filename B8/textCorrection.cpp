#include "textCorrection.hpp"

TextCorrection::TextCorrection(std::string line, typeOfElement type) :
        data_(std::move(line)),
        type_(type)
{}

