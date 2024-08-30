#include "Motorbike.h"
#include <ctime>

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    std::time_t currentTime = std::time(nullptr);
    double duration = std::difftime(currentTime, timeOfEntry);
    return static_cast<int>(duration * 0.85); // 15% reduction
}
