#include "DoorSensor.h"

void DoorSensor::update(const std::string &status)
{
    std::cout << "Door sensor detected change: " << status << std::endl;
}