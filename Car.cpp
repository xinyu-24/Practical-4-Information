#include "Car.h"
#include <ctime>

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    std::time_t currentTime = std::time(nullptr);
    double duration = std::difftime(currentTime, timeOfEntry);
    return static_cast<int>(duration * 0.9); // 10% reduction
}
