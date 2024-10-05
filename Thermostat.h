#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevices.h"

class Thermostat : public SmartDevices {
public:
    Thermostat();
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;

private:
    int temperature;
};

#endif
