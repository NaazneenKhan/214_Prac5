#include "HomeOwner.h"
#include <iostream>
#include <algorithm>

HomeOwner::HomeOwner() {
    remote = new Remote(); 
}

HomeOwner::~HomeOwner() {
    delete remote;
    for (SmartDevices* device : devices) {
        delete device;
    }
    devices.clear();
}

void HomeOwner::addDevice(SmartDevices* device) {
    devices.push_back(device);
    std::cout << "Device added: " << device->getDeviceType() << std::endl;
}

void HomeOwner::removeDevice(SmartDevices* device) {
    auto it = std::find(devices.begin(), devices.end(), device);
    if (it != devices.end()) {
        devices.erase(it);
        std::cout << "Device removed: " << device->getDeviceType() << std::endl;
    }
}

void HomeOwner::executeCommand(const std::string& command) {
    std::cout << "Executing command: " << command << std::endl;
    for (SmartDevices* device : devices) {
        device->performAction(command);  
    }
}

void HomeOwner::checkStatus() {
    std::cout << "Checking status of all devices:" << std::endl;
    for (SmartDevices* device : devices) {
        std::cout << device->getDeviceType() << " - " << device->getStatus() << std::endl;
    }
}
