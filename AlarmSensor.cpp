#include "AlarmSensor.h"

void AlarmSensor::update(SensorUpdate detection)
{
    // std::cout << "Alarm sensor detected change: " << status << std::endl;

  if (std::holds_alternative<bool>(detection)) {
            bool motionDetected = std::get<bool>(detection);
            if (motionDetected) {
                std::cout << "Alarm sensor: Motion detected! Activating alarm." << std::endl;
            } else {
                std::cout << "Alarm sensor: No motion detected. Deactivating alarm." << std::endl;
            }
        }
    
}