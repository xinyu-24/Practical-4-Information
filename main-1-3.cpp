#include <iostream>
#include "ParkingLot.h"

int main() {
    ParkingLot parkingLot(10);  // Create a parking lot with a capacity of 10 vehicles

    // Simulate parking vehicles
    std::string vehicleTypes[3] = {"Car", "Bus", "Motorbike"};
    int vehicleCounts[3] = {5, 3, 2};  // 5 Cars, 3 Buses, 2 Motorbikes

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < vehicleCounts[i]; j++) {
            if (!parkingLot.parkVehicle(vehicleTypes[i])) {
                break;  // Stop parking if the lot is full
            }
        }
    }

    // Count and display the number of vehicles that have overstayed for more than 15 seconds
    int overstayingCount = parkingLot.countOverstayingVehicles(15);
    std::cout << "Number of vehicles overstaying for more than 15 seconds: " << overstayingCount << std::endl;

    return 0;
}

