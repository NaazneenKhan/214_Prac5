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
    bool isOn(){return isOn_;};

    void activate();
    void deactivate();

    void adjustForMotion(bool motionDetected) {
        if (motionDetected) {
            performAction("On");  // Activate alarm if motion is detected
        } else {
            performAction("Off");  // Deactivate alarm if no motion is detected
        }
    }

private:
    bool isOn_;
};

#endif
