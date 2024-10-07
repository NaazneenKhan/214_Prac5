#ifndef HOMEOWNER_H
#define HOMEOWNER_H

#include "Remote.h"
#include "SmartDevices.h"
#include <vector>

class HomeOwner {
private:
    Remote* remote;
    std::vector<SmartDevices*> devices;  

public:
    HomeOwner();
    ~HomeOwner();

    void addDevice(SmartDevices* device);        
    void removeDevice(SmartDevices* device);     
    void executeCommand(const std::string& command);  
    void checkStatus();                          
};

#endif

