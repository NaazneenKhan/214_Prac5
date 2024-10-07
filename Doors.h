#ifndef DOORS_H
#define DOORS_H

#include "SmartDevices.h"
#include<iostream>

class Doors : public SmartDevices {
public:
    Doors();
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;
    bool isLocked(){return isLocked_;};
    

    void lock();
    void unlock();

private:
    bool isLocked_;
};

#endif