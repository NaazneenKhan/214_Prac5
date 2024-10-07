#include "Lights.h"

Lights::Lights() : isOn(false) {
    // lights are initially off
}

std::string Lights::getStatus() {
    return isOn ? "on" : "off";
}

void Lights::performAction(const std::string& action) {
    if (action == "On") {
        isOn = true;
        std::cout << "Light is turned on." << std::endl;
    } else if (action == "Off") {
        isOn = false;
        std::cout << "Light is turned off." << std::endl;
    } else if (action == "Toggle") {
        isOn = !isOn;
        std::cout << "Light toggled to " << (isOn ? "on" : "off") << "." << std::endl;
    } else {
        std::cout << "Unknown action: " << action << std::endl;
    }
}

std::string Lights::getDeviceType() const {
    return "Light";
}