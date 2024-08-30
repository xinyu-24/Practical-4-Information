#include "Vehicle.h"

Vehicle::Vehicle(int id) : ID(id) {
    timeOfEntry = std::time(nullptr); // Set time of entry to current time
}

int Vehicle::getID() const {
    return ID;
}
