#include "LightSensor.h"
#include <variant>
void LightSensor::update(SensorUpdate detection)
{
    // std::cout << "Light sensor detected change: " << status << std::endl;

    if (std::holds_alternative<bool>(detection)) {
            bool motionDetected = std::get<bool>(detection);
            if (motionDetected) {
                std::cout << "Light sensor: Motion detected! Turning on lights." << std::endl;
            } else {
                std::cout << "Light sensor: No motion detected. Turning off lights." << std::endl;
            }
        }
}