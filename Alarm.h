#ifndef ALARM_H
#define ALARM_H

#include "SmartDevices.h"

class Alarm : public SmartDevices {
public:
    Alarm();
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;

private:
    bool isOn;
};

#endif
