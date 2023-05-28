//
//  Square.h
//  chessproj
//
//  Created by Oskar Kaluziak on 24/05/2023.
//

#ifndef Square_h
#define Square_h

class Square {
public:
    Square(int x, int y) : x_(x), y_(y) {}

    int x() const {
        return x_;
    }

    int y() const {
        return y_;
    }

private:
    int x_;
    int y_;
};


#endif /* Square_h */
