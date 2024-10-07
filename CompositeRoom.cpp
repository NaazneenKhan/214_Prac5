#include "CompositeRoom.h"
#include <algorithm>

CompositeRoom::CompositeRoom(){
}

void CompositeRoom::addDevice(SmartDevices* device) {
    devices.push_back(device);
}

void CompositeRoom::removeDevice(SmartDevices* device) {
    auto it = std::remove(devices.begin(), devices.end(), device);
    if (it != devices.end()) {
        devices.erase(it, devices.end());
    }
}

std::string CompositeRoom::getStatus() {
    std::string status = "Composite Room Status: \n";
    for (SmartDevices* device : devices) {
        status += device->getDeviceType() + ": " + device->getStatus() + "\n";
    }
    return status;
}

void CompositeRoom::performAction(const std::string& action) {
    for (SmartDevices* device : devices) {
        device->performAction(action);
    }
}

std::string CompositeRoom::getDeviceType() const {
    return "Composite Room";
}