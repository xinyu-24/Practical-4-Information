#include <iostream>
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
    ParkingLot parkingLot(10); // Create a parking lot with a capacity of 10
    int choice;

    while (true) {
        std::cout << "\nChoose a vehicle to park (1: Car, 2: Bus, 3: Motorbike, 0: Exit): ";
        std::cin >> choice;

        if (choice == 0) {
            break; // Exit the loop
        }

        int id;
        std::cout << "Enter vehicle ID: ";
        std::cin >> id;

        Vehicle* vehicle = nullptr;

        switch (choice) {
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
            continue; // Continue to the next iteration
        }

        parkingLot.parkVehicle(vehicle);
    }

    // Unpark a vehicle
    int idToUnpark;
    std::cout << "Enter the ID of the vehicle you want to unpark: ";
    std::cin >> idToUnpark;
    parkingLot.unparkVehicle(idToUnpark);

    return 0;
}
