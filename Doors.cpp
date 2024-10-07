#include "Doors.h"

Doors::Doors() : isLocked(false) {
    // door are intially open 
}

std::string Doors::getStatus() {
    return isLocked ? "locked" : "unlocked";
}

void Doors::performAction(const std::string& action) {

    if (action == "Lock") {
        isLocked = true;
        std::cout << "Doors are locked." << std::endl;
    } else if (action == "Unlock") {
        isLocked = false;
        std::cout << "Doors are unlocked." << std::endl;
    } else if (action == "Toggle") {
        isLocked = !isLocked;
        std::cout << "Doors toggled to " << (isLocked ? "locked" : "unlocked") << "." << std::endl;
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
