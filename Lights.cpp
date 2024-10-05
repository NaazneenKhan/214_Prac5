#include "Lights.h"

Lights::Lights() : isOn(false) {
    // Initialize lights
}

std::string Lights::getStatus() {
    return isOn ? "on" : "off";
}

void Lights::performAction(const std::string& action) {
    // Handle actions like "ToggleOn", "ToggleOff", etc.
}

std::string Lights::getDeviceType() const {
    return "Light";
}