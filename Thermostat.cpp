#include "Thermostat.h"

Thermostat::Thermostat() : temperature(22) {  // default temperature
    // Initialize thermostat
}

std::string Thermostat::getStatus() {
    return std::to_string(temperature) + "°C";
}

void Thermostat::performAction(const std::string& action) {
    // Handle actions like "IncreaseTemp", "DecreaseTemp", etc.
}

std::string Thermostat::getDeviceType() const {
    return "Thermostat";
}

void Thermostat::setSmartTemperature(double temp) // for adapter
{
    temperature = temp;

}

double Thermostat::getSmartTemperature() const // for adapter 
{
    return temperature;
}
