//
//  imclass.cpp
//  lab04xd
//
//  Created by Oskar Kaluziak on 03/04/2023.
//
#include "mainclass.hpp"
#include "imclass.hpp"
#include <iostream>
#include <numeric>

Sum::Sum(std::vector<int> full_price) : price_(full_price) {}

std::vector<int> Sum::price() const {
    return price_;
}

void Sum::print_price() const {
    std::cout << "Addition components: ";
    for (auto val : price_) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int Sum::sum() const {
    return std::accumulate(price_.begin(), price_.end(), 0);
}

