#include "Doors.h"

Doors::Doors() : isLocked_(false) {
    // door are intially open 
}

std::string Doors::getStatus() {
    return isLocked_ ? "locked" : "unlocked";
}

void Doors::performAction(const std::string& action) {

    if (action == "Lock") {
        isLocked_ = true;
        std::cout << "Doors are locked." << std::endl;
    } else if (action == "Unlock") {
        isLocked_ = false;
        std::cout << "Doors are unlocked." << std::endl;
    } else if (action == "Toggle") {
        isLocked_ = !isLocked_;
        std::cout << "Doors toggled to " << (isLocked_ ? "locked" : "unlocked") << "." << std::endl;
    } else {
        std::cout << "Unknown action: " << action << std::endl;
    }
}

std::string Doors::getDeviceType() const {
    return "Door";
}

void Doors::lock()
{
    changeStatus("Door is LOCKED");
}

void Doors::unlock()
{
    changeStatus("Door is UNLOCKED");
}
