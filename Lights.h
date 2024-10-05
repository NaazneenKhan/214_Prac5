#ifndef LIGHTS_H
#define LIGHTS_H

#include "SmartDevices.h"

class Lights : public SmartDevices {
public:
    Lights();
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;

private:
    bool isOn;
};

#endif
