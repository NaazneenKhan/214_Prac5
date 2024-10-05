#include "Doors.h"

Doors::Doors() : isLocked(false) {
    // Initialize door
}

std::string Doors::getStatus() {
    return isLocked ? "locked" : "unlocked";
}

void Doors::performAction(const std::string& action) {
    // Handle actions like "Lock", "Unlock", etc.
}

std::string Doors::getDeviceType() const {
    return "Door";
}