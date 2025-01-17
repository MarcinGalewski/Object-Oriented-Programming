//
// Created by student on 11.05.23.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "string"
#include <boost/date_time.hpp>
#include "model/Client.h"
#include "model/Vehicle.h"

namespace pt = boost::posix_time;

class Client;

class Rent {
private:
    unsigned int id;
    Client* client;
    Vehicle* vehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    unsigned int rentCost = 0;

public:
    Rent(unsigned int id, Client *client, Vehicle *vehicle, const pt::ptime &beginTime);

    virtual ~Rent();

    std::string getRentInfo() const;

    unsigned int getId() const;

    Client *getClient() const;

    Vehicle *getVehicle() const;
    const pt::ptime &getBeginTime() const;

    const pt::ptime &getEndTime() const;

    unsigned int getRentDays() const;

    unsigned int getRentCost() const;


    void endRent(pt::ptime endTime);
};


#endif //CARRENTAL_RENT_H