#include "CompositeRoom.h"

CompositeRoom::CompositeRoom()
{
}

void CompositeRoom::addDevice(SmartDevices* device) {
    devices.push_back(device);
}

void CompositeRoom::removeDevice(SmartDevices* device) {
    // Remove device from vector
}

std::string CompositeRoom::getStatus() {
    // Aggregate and return the status of all devices in the room
    return "Composite Room Status";
}

void CompositeRoom::performAction(const std::string& action) {
    // Perform the action on all devices in the room
}

std::string CompositeRoom::getDeviceType() const {
    return "Composite Room";
}