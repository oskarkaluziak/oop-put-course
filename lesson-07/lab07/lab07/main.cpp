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
        //1 PRZYPADEK BLEDU - PODSTAWA LUB NUMER MNIEJSZY OD 1
        if (base_ == 1){
            throw std::invalid_argument("Score of that logarithm is undefined");
        }
        //2 PRZYPADEK BLEDU - PODSTAWA=1
        return std::log(number_) / std::log(base_);
        //3 PRZYPADEK DZIALAJACY =  PODSTAWA>1 & NUMER>0
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
    try{
        Logarithm log(base, number);
        double result = log.Calculate();
        std::cout << "the logarithm of " << number << " with base " << base << " is " << result << std::endl;
    //WYKONUJE DZIALANIE LOGARYTMU O ILE NIE ZNAJDZIE WYJATKU I POKAZUJE WYNIK
    }
    
    catch (const std::invalid_argument& e){
        std::cerr << "error: " << e.what() << std::endl;
        return 1;
    //ZNAJDUJE WYJATEK //1 LUB //2 I WYSWIETLA ERROR: Z KODEM BLEDU
    }
    return 0;
    
}
