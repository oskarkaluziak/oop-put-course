//
//  main.cpp
//  lab07new
//
//  Created by Oskar Kaluziak on 08/05/2023.
//

#include <iostream>
#include <cmath>

class Logarithm{
public:
    Logarithm(double base, double number){
            base_ = base;
            number_ = number;
}

    double Calculate() const{
        if (base_ <= 0 || number_ <= 0){
            throw std::invalid_argument("Base and number must be greater than 0.");
        }
        return std::log(number_) / std::log(base_);
    }
private:
    double base_;
    double number_;
};

int main(){
    double base, number;
    std::cout << "base: ";
    std::cin >> base;
    std::cout << "number: ";
    std::cin >> number;
    Logarithm log(base, number);
    try{
        Logarithm log(base, number);
        double result = log.Calculate();
        std::cout << "The logarithm of " << number << " with base " << base << " is " << result << std::endl;
    }
    catch (const std::invalid_argument& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
    
}
