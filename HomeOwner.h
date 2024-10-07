#ifndef HOMEOWNER_H
#define HOMEOWNER_H

#include "Remote.h"
#include "SmartDevices.h"
#include <vector>

class HomeOwner {
private:
    Remote* remote;
    std::vector<SmartDevices*> devices;  // List of smart devices the homeowner can control

public:
    HomeOwner();
    ~HomeOwner();

    void addDevice(SmartDevices* device);         // Adds a smart device
    void removeDevice(SmartDevices* device);      // Removes a smart device
    void executeCommand(const std::string& command);  // Executes a command via remote
    void checkStatus();                           // Display status of all devices
};

#endif

