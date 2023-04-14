//
// Created by student on 07.04.23.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include "string"

class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented = false;

public:
    Vehicle(const std::string &plateNumber, unsigned int basePrice);

    virtual ~Vehicle();

    std::string getVehicleInfo() const;

    const std::string &getPlateNumber() const;

    unsigned int getBasePrice() const;

    bool isRented() const;

    void setPlateNumber(const std::string &plateNumber);

    void setBasePrice(unsigned int basePrice);

    void setRented(bool rented);
};


#endif //CARRENTAL_VEHICLE_H