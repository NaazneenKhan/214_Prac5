#ifndef LIGHTS_H
#define LIGHTS_H

#include "SmartDevices.h"
#include <iostream>

class Lights : public SmartDevices {
public:
    Lights();
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;
    
    bool isOn(){return isOn_;};

    void turnOn();
    void turnOff();

    void adjustForMotion(bool motionDetected) {
        if (motionDetected) {
            performAction("On");
        } else {
            performAction("Off");
        }
    }

private:
    bool isOn_;
};

#endif
