#include "Thermostat.h"

Thermostat::Thermostat() : temperature(22) {  // default temperature
    // Initialize thermostat
}

std::string Thermostat::getStatus() {
    return std::to_string(temperature) + "°C";
}

void Thermostat::performAction(const std::string& action) {
    
    if (action == "IncreaseTemp") {
        temperature += 1;
        std::cout << "Thermostat temperature increased to " << temperature << "°C." << std::endl;
    } else if (action == "DecreaseTemp") {
        temperature -= 1;
        std::cout << "Thermostat temperature decreased to " << temperature << "°C." << std::endl;
    } else {
        std::cout << "Unknown action: " << action << std::endl;
    }
    
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



void Thermostat::setTemperature(int temp)
{
    changeStatus("Thermostat set to " + std::to_string(temp) + " degrees");
}
