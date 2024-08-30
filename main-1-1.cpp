#include <iostream>
#include <vector>
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    int numVehicles;
    std::cout << "Enter the number of vehicles you want to park: ";
    std::cin >> numVehicles;

    std::vector<Vehicle*> vehicles;

    for (int i = 0; i < numVehicles; ++i) {
        int type, id;
        std::cout << "Enter vehicle type (1: Car, 2: Bus, 3: Motorbike): ";
        std::cin >> type;
        std::cout << "Enter vehicle ID: ";
        std::cin >> id;

        Vehicle* vehicle = nullptr;

        switch (type) {
        case 1:
            vehicle = new Car(id);
            break;
        case 2:
            vehicle = new Bus(id);
            break;
        case 3:
            vehicle = new Motorbike(id);
            break;
        default:
            std::cout << "Invalid vehicle type." << std::endl;
            --i; // Decrement to not count this invalid entry
            continue;
        }

        vehicles.push_back(vehicle);
    }

    std::cout << "\nParking durations for each vehicle:\n";
    for (const auto& vehicle : vehicles) {
        std::cout << "Vehicle ID: " << vehicle->getID()
                  << ", Parking Duration: " << vehicle->getParkingDuration() << " seconds" << std::endl;
    }

    // Clean up memory
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
