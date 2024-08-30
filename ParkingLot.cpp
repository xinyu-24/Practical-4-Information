#include "ParkingLot.h"
#include <algorithm> // For std::find_if
#include <iterator>  // For std::distance

ParkingLot::ParkingLot(int capacity) : maxCapacity(capacity), count(0) {
    vehicles = new Vehicle*[maxCapacity]; // Allocate array
}

ParkingLot::~ParkingLot() {
    delete[] vehicles; // Free allocated memory
}

int ParkingLot::getCount() const {
    return count;
}

void ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (count < maxCapacity) {
        vehicles[count++] = vehicle; // Park the vehicle and increment count
        std::cout << "Vehicle ID " << vehicle->getID() << " parked." << std::endl;
    } else {
        std::cout << "The lot is full!" << std::endl;
    }
}

void ParkingLot::unparkVehicle(int id) {
    auto it = std::find_if(vehicles, vehicles + count, [id](Vehicle* v) { return v->getID() == id; });

    if (it != vehicles + count) {
        // Vehicle found, remove it
        int index = std::distance(vehicles, it);
        delete vehicles[index]; // Free memory for the vehicle
        vehicles[index] = vehicles[count - 1]; // Move last vehicle to the current spot
        vehicles[count - 1] = nullptr; // Nullify the last spot
        --count; // Decrement count
        std::cout << "Vehicle ID " << id << " has been removed from the lot." << std::endl;
    } else {
        std::cout << "Vehicle not in the lot." << std::endl;
    }
}
