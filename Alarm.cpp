#include "Alarm.h"

Alarm::Alarm() : isOn(false) {
    // Initialize alarm
}

std::string Alarm::getStatus() {
    return isOn ? "on" : "off";
}

void Alarm::performAction(const std::string& action) {
    // Handle actions like "ToggleOn", "ToggleOff", etc.
}

std::string Alarm::getDeviceType() const {
    return "Alarm";
}

void Alarm::activate()
{
    changeStatus("Alarm is ACTIVATED");
}

void Alarm::deactivate()
{
    changeStatus("Alarm is DEACTIVATED");
}
