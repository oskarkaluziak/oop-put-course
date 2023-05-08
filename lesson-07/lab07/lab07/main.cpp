//
//  main.cpp
//  lab07
//
//  Created by Oskar Kaluziak on 08/05/2023.
//

#include <iostream>
#include <cmath>
#include <stdexcept>

class Logarithm {
public:
  Logarithm(double base, double number) {
    base_ = base;
    number_ = number;
  }

  double Calculate() const {
    if (base_ <= 0 || number_ <= 0) {
      throw std::invalid_argument("Number must be greater than 0.");
    }
    return std::log(number_) / std::log(base_);
  }

private:
  double base_;
  double number_;
};

