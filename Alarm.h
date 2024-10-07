#ifndef ALARM_H
#define ALARM_H

#include "SmartDevices.h"
#include <iostream>

class Alarm : public SmartDevices {
public:
    Alarm();
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;

    void activate();
    void deactivate();

private:
    bool isOn;
};

#endif
