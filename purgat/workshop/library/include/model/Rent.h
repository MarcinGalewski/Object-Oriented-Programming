//
// Created by student on 07.04.23.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "string"
#include <boost/date_time.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "typedefs.h"
#include "model/Client.h"
#include "model/Vehicle.h"

namespace pt = boost::posix_time;

class  Client;

class Rent {
private:
    boost::uuids::uuid id;
    ClientPtr client;
    VehiclePtr vehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    double rentCost = 0;

public:
    Rent(boost::uuids::uuid id, ClientPtr client, VehiclePtr vehicle, const pt::ptime &beginTime);

    virtual ~Rent();

    std::string getRentInfo() const;

    const boost::uuids::uuid &getId() const;

    ClientPtr getClient() const;

    VehiclePtr getVehicle() const;

    const pt::ptime &getBeginTime() const;

    const pt::ptime &getEndTime() const;

    unsigned int getRentDays() const;

    double getRentCost() const;

    void endRent(pt::ptime endTime);
};


#endif //CARRENTAL_RENT_H
