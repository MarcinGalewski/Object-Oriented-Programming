//
// Created by student on 07.04.23.
//
#include "algorithm"

#include "model/Rent.h"
#include "exceptions/RentException.h"

Rent::Rent(boost::uuids::uuid id, ClientPtr client, VehiclePtr vehicle, const pt::ptime &beginTime)
: id(id), client(client), vehicle(vehicle), beginTime(beginTime) {
    if(beginTime == pt::not_a_date_time)
        Rent::beginTime = pt::second_clock::local_time();
}

Rent::~Rent() {

}

std::string Rent::getRentInfo() const {
    std::stringstream beginTimeString;
    beginTimeString << beginTime;

    std::stringstream endTimeString;
    endTimeString << endTime;

    return "Rent: \n" + boost::uuids::to_string(id) +
    " begin time: " + beginTimeString.str() + " end time: " + endTimeString.str() + "\n"
    + client->getClientInfo() + "\n" + vehicle->getVehicleInfo() + "\n";
}

const boost::uuids::uuid &Rent::getId() const {
    return id;
}

ClientPtr Rent::getClient() const {
    return client;
}

VehiclePtr Rent::getVehicle() const {
    return vehicle;
}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

unsigned int Rent::getRentDays() const {
    pt::time_period rentTime(beginTime, endTime);
    if(endTime == pt::not_a_date_time ||
    (rentTime.length().hours() == 0 && rentTime.length().minutes() == 0))
        return 0;
    else
        return rentTime.length().hours() / 24 + 1;

}

double Rent::getRentCost() const {
    return rentCost;
}

void Rent::endRent(pt::ptime endTime) {
    if(Rent::endTime == pt::not_a_date_time) {
        if (endTime == pt::not_a_date_time)
            Rent::endTime = pt::second_clock::local_time();
        else if (endTime < beginTime)
            Rent::endTime = beginTime;
        else
            Rent::endTime = endTime;

        rentCost = getRentDays() * vehicle->getBasePrice();
        rentCost -= client->applyDiscount(rentCost);
        if(rentCost < 0) rentCost = 0;
    }
}







