#include "DoorSensor.h"

void DoorSensor::update(SensorUpdate detection)
{
    // std::cout << "Door sensor detected change: " << status << std::endl;
    if (std::holds_alternative<bool>(detection)) {
            bool doorOpened = std::get<bool>(detection);
            if (doorOpened) {
                std::cout << "Door sensor: Door is opened." << std::endl;
            } else {
                std::cout << "Door sensor: Door is closed." << std::endl;
            }
        }
}