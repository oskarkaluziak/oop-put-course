//
//  mainclass.hpp
//  lab05
//
//  Created by Oskar Kaluziak on 03/04/2023.
//

#ifndef mainclass_hpp
#define mainclass_hpp
#pragma once
#include <stdio.h>
#include <vector>

class Hotel {
public:
    Hotel () {};
    virtual std::vector<int> price() const = 0;
    virtual void print_price() const = 0;
    virtual int sum() const = 0;
    virtual ~Hotel() {}
};

#endif /* mainclass_hpp */
