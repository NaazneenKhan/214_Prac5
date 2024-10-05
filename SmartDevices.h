#ifndef SMARTDEVICES_H
#define SMARTDEVICES_H

#include <string>

class SmartDevices {
public:
    virtual ~SmartDevices() {}
    virtual std::string getStatus() = 0;
    virtual void performAction(const std::string& action) = 0;
    virtual std::string getDeviceType() const = 0;
};

#endif
