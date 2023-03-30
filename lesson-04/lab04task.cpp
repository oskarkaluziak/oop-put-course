// object-oriented programming
//
// Radisson Hotel Group comparison status program
//
// made by Oskar Kałuziak
//
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

class Hotel {
private:
    std::string name;
    double avgRoomPrice;
    double minRoomPrice;
    double occPercentage;
    double guestReview;
    int totalNumOfRooms;
public:
    Hotel() {
        name = "Radisson Hotel Group";
        avgRoomPrice = 0.0;
        minRoomPrice = 0.0;
        occPercentage = 0.0;
        guestReview = 0.0;
        totalNumOfRooms = 0;
    };
    Hotel(const std::string n, double avg, double min, double occ, double gue, int total) {
        name = n;
        avgRoomPrice = avg;
        minRoomPrice = min;
        occPercentage = occ;
        guestReview = gue;
        totalNumOfRooms = total;
    };
    void setName(const std::string n) { name = n; }
    void setAvgRoomPrice(double p) { avgRoomPrice = p; }
    void setMinRoomPrice(double p) { minRoomPrice = p; }
    void setOccPercentage(double p) { occPercentage = p; }
    void setGuestReview(double p) { guestReview = p; }
    void setTotalNumOfRooms(int n) { totalNumOfRooms = n; }
    std::string getName() const { return name; }
    double getAvgRoomPrice() const { return avgRoomPrice; }
    double getMinRoomPrice() const { return minRoomPrice; }
    double getOccPercentage() const { return occPercentage; }
    double getGuestReview() const { return guestReview; }
    int getTotalNumOfRooms() const { return totalNumOfRooms; }
    void printStatus() const {
        std::cout << "Hotel name: " << getName() << std::endl;
        std::cout << "Average room price: " << getAvgRoomPrice() << std::endl;
        std::cout << "Minimum room price: " << getMinRoomPrice() << std::endl;
        std::cout << "Occupancy percentage: " << getOccPercentage() << "%" << std::endl;
        std::cout << "Guest Review: " << getGuestReview() << std::endl;
        std::cout << "Total number of rooms: " << getTotalNumOfRooms() << std::endl;
    }
};

int main() {
    
        unsigned int i;
        std::cout << "Radisson Hotel Group comparison status program\n\n" << std::endl;
        
        Hotel hotel1("Radisson Blu in Swinoujscie ☆☆☆☆☆ (1)", 1429.31, 1029.11, 58.92, 9.1, 344);
        hotel1.printStatus();
        std::cout << std::endl;
        
        Hotel hotel2("Radisson Collection in Warsaw ☆☆☆☆☆ (2)", 929.31, 811.10, 78.34, 8.9, 309);
        hotel2.printStatus();
        std::cout << std::endl;
        
        Hotel hotel3("Park inn by Radisson in Poznan ☆☆☆☆ (3)", 581.70, 419.49, 63.21, 8.4, 154);
        hotel3.printStatus();
        std::cout << std::endl;
