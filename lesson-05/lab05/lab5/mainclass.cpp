//
//  mainclass.cpp
//  lab04xd
//
//  Created by Oskar Kaluziak on 03/04/2023.
//

#include "mainclass.hpp"
#include "imclass.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Park Inn by Radisson - 3 day stay\n ";
    std::cout << "Price for stay per every day:\n ";
    std::cout << "1d  2d  3d\n ";
    std::vector<int> my_price = {766, 596, 604};
    const Hotel* obj = new Sum(my_price);
    std::vector<int> returned_price = obj->price();
    for (auto val : returned_price) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    obj->print_price();
    std::cout << "Full price for whole stay: " << obj->sum() << ""  << std::endl;
    
    delete obj;
    return 0;
}
