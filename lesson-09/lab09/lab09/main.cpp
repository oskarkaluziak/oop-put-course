//
//  main.cpp
//  lab09
//
//  Created by Oskar Kaluziak on 22/05/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

class IntegerSequence{
public:
    virtual ~IntegerSequence() = default;
    virtual std::vector<int> Numbers() = 0;
};

class IntegerVectors : public IntegerSequence{
private:
    std::vector<int> numbers_;
public:
    explicit IntegerVectors(const std::vector<int>& numbers) : numbers_(numbers){}
    std::vector<int> Numbers() override{
        return numbers_;
    }
};

class PosSequence : public IntegerSequence{
private:
    std::vector<int> numbers_;
public:
    explicit PosSequence(std::vector<int> numbers) : numbers_(numbers){}
    std::vector<int> Numbers() override{
        std::vector<int> posNumbers;
        for (int nmbr : numbers_){
            if (nmbr >= 0){
                posNumbers.push_back(nmbr);
            }
        }

    return posNumbers;
    }
};

class EvenSequence : public IntegerSequence{
private:
    IntegerSequence* sequence_;
public:
    explicit EvenSequence(IntegerSequence* sequence) : sequence_(sequence){}
    std::vector<int> Numbers() override{
        std::vector<int> onNumbers = sequence_->Numbers();
        std::vector<int> evenNumbers;
        for(int nmbr : onNumbers){
            if(nmbr % 2 == 0 ){
                evenNumbers.push_back(nmbr);
            }
        }
    return evenNumbers;
    }
        
};

class SortSequence : public IntegerSequence{
private:
    IntegerSequence* sequence_;
public:
    explicit SortSequence(IntegerSequence* sequence) : sequence_(sequence){}
    std::vector<int> Numbers() override{
        std::vector<int> onNumbers = sequence_->Numbers();
        std::vector<int> sortNumbers;
        for(int nmbr : onNumbers){
            sort(onNumbers.begin(), onNumbers.end());
        }
    return sortNumbers;
    }
};
int main(){
    std::vector<int> numbers;
    int nmbr;
    IntegerVectors sequence(numbers);
    while (std::cin >> nmbr){
            numbers.push_back(nmbr);
        }
    for (int nmbr : numbers){
        IntegerSequence* endSequence = new EvenSequence(new SortSequence(new PosSequence(&sequence)));
        std::cout << nmbr << std::endl;
        std::cout << " " << std::endl;
    }
    return 0;
}
