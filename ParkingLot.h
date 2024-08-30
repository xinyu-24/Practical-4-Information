#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <iostream>
#include "Vehicle.h"

class ParkingLot {
private:
    Vehicle** vehicles; // Dynamic array of pointers to Vehicle objects
    int maxCapacity;    // Maximum number of vehicles that can be parked
    int count;          // Current number of vehicles parked

public:
    ParkingLot(int capacity);
    ~ParkingLot();

    int getCount() const;
    void parkVehicle(Vehicle* vehicle);
    void unparkVehicle(int id);
};

#endif // PARKINGLOT_H
