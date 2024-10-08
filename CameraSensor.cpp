#include "CameraSensor.h"
#include <variant>
void CameraSensor::update(SensorUpdate detection)
{
    // std::cout << "Camera sensor detected change: " << status << std::endl;
   if (std::holds_alternative<bool>(detection)) {
            bool motionDetected = std::get<bool>(detection);
            if (motionDetected) {
                std::cout << "Camera sensor: Motion detected! Starting recording." << std::endl;
            } else {
                std::cout << "Camera sensor: No motion detected. Stopping recording." << std::endl;
            }
        }
    
}