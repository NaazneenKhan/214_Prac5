#ifndef DOORS_H
#define DOORS_H

#include "SmartDevices.h"

class Doors : public SmartDevices {
public:
    Doors();
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;

    void lock();
    void unlock();

private:
    bool isLocked;
};

#endif