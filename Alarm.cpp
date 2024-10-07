#include "Alarm.h"

Alarm::Alarm() : isOn(false) {
    // alarm is initially off
}

std::string Alarm::getStatus() {
    return isOn ? "on" : "off";
}

void Alarm::performAction(const std::string& action) {
    
    if (action == "On") {
        isOn = true;
        std::cout << "Alarm is turned on." << std::endl;
    } else if (action == "Off") {
        isOn = false;
        std::cout << "Alarm is turned off." << std::endl;
    } else if (action == "Toggle") {
        isOn = !isOn;
        std::cout << "Alarm toggled to " << (isOn ? "on" : "off") << "." << std::endl;
    } else {
        std::cout << "Unknown action: " << action << std::endl;
    }

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
