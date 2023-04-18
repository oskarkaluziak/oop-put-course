//
//  main.cpp
//  lab05
//
//  Created by Oskar Kaluziak on 17/04/2023.
//
//
/*
You are asked to implement a new currency class that will extend the abstract class Currency. The new class should be named after a currency of your choice (e.g., Euro, Yen, Pound, etc.). The implementation should include the following:
I. II.
A constructor that takes two arguments representing this currency abbreviation and amount of money it stores.
An implementation of the abstract methods in the Currency class:
A. Abbreviation: returns the currency abbreviation (e.g., "EUR" for Euro)
B. ConvertedToDollars: takes one argument representing Cantor object and returns the current amount of your
currency in USD based on the exchange rate
C. Amount: returns about of money in original currency.
   III. Additional methods or fields as needed.
You should also create a main function that creates an instance of the new currency class, sets the amount to a value of your choice, and prints out the abbreviation and amount in both the original currency and USD.
You can use FakeUsdCantor as source of exchange rate information.
Submission:
Submit a C++ file with the implementation of the new currency class and the main function. Make sure the code is properly formatted and documented.
Also, provide a brief description of the implemented class and any design decisions made.
*/

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <iostream>
#include <map>

class Cantor {
 public:
  Cantor() = default;
  virtual ~Cantor() = default;

  virtual double Rate(const std::string& abbreviation) const = 0;
};

class Currency {
 public:
  Currency() = default;
  virtual ~Currency() = default;

  virtual double ConvertedToDollars(const Cantor& cantor) const = 0;
  virtual std::string Abbreviation() const = 0;
  virtual double Amount() const = 0;
};
class FakeUsdCantor : public Cantor {
public:
 FakeUsdCantor() {
   // rates_ map with values for ten most popular currencies relative to USD
   rates_ = {
     {"EUR", 0.85},
     {"JPY", 110.66},
     {"GBP", 0.73},
     {"CHF", 0.91},
     {"CAD", 1.25},
     {"AUD", 1.34},
     {"CNY", 6.47},
     {"HKD", 7.78},
     {"NZD", 1.44},
     {"KRW", 1153.89}
   };
 }
double Rate(const std::string& abbreviation) const override {
        auto it = rates_.find(abbreviation);
        if (it != rates_.end()) {
          return it->second;
        }
        // Handle error case when currency abbreviation is not found
        return 0.0;
      }

     private:
      std::map<std::string, double> rates_;
    };

class Yen: public Currency {
        
    public:
        std::string abbreviation;
        double amount;
        Yen(std::string abbreviation, double amount) : abbreviation(abbreviation), amount(amount) {}
        std::string Abbreviation() const override {
            return abbreviation;
          }
        double ConvertedToDollars(const Cantor& cantor) const override {
            return amount/ cantor.Rate(abbreviation);
        }
        double Amount() const override {
            return amount;
        }
        void SetAmount(double amount) {
            this->amount = amount;
        }
        void PrintInfo(const FakeUsdCantor& cantor) const {
            std::cout << "Original currency: " << abbreviation << " " << amount << std::endl;
            std::cout << "USD currency: " << "USD " << ConvertedToDollars(cantor) << std::endl;
    }
    };
int main() {
    FakeUsdCantor myCurrency;
    Yen ye("JPY", 500.0);
    ye.PrintInfo(myCurrency);

    
    
    return 0;
}
