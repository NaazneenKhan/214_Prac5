#include "ThermostatSensor.h"

void ThermostatSensor::update(const std::string &status)
{
    std::cout << "Thermostat sensor detected change: " << status << std::endl;
}