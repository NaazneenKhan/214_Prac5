#include "Lights.h"

Lights::Lights() : isOn_(false) {
    // lights are initially off
}

std::string Lights::getStatus() {
    return isOn_ ? "on" : "off";
}

void Lights::performAction(const std::string& action) {
    if (action == "On") {
        isOn_ = true;
        std::cout << "Light is turned on." << std::endl;
    } else if (action == "Off") {
        isOn_ = false;
        std::cout << "Light is turned off." << std::endl;
    } else if (action == "Toggle") {
        isOn_ = !isOn_;
        std::cout << "Light toggled to " << (isOn_ ? "on" : "off") << "." << std::endl;
    } else {
        std::cout << "Unknown action: " << action << std::endl;
    }
}

std::string Lights::getDeviceType() const {
    return "Light";
}



void Lights::turnOn()
{
   changeStatus("Light is ON"); 
}

void Lights::turnOff()
{
    changeStatus("Light is OFF");
}
