//
//  imclass.hpp
//  lab05
//
//  Created by Oskar Kaluziak on 03/04/2023.
//

#ifndef imclass_hpp
#define imclass_hpp
#pragma once
#include <stdio.h>
#include "mainclass.hpp"
 
class Sum : public Hotel {
private:
    std::vector<int> price_;
public:
    Sum(std::vector<int> price);
    std::vector<int> price() const override;
    void print_price() const override;
    int sum() const override;
};

#endif /* imclass_hpp */
