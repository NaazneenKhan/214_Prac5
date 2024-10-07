#include "ThermostatSensor.h"

void ThermostatSensor::update(SensorUpdate detection)
{
    // std::cout << "Thermostat sensor detected change: " << status << std::endl;

    if (std::holds_alternative<double>(detection)) {
            double outsideTemperature = std::get<double>(detection);
            if (outsideTemperature > 30.0) {
                std::cout << "Thermostat sensor: It's too hot outside! Adjusting thermostat." << std::endl;
            } else if (outsideTemperature < 15.0) {
                std::cout << "Thermostat sensor: It's too cold outside! Adjusting thermostat." << std::endl;
            } else {
                std::cout << "Thermostat sensor: Outside temperature is comfortable." << std::endl;
            }
        }
    
}