#ifndef CAMERA_H
#define CAMERA_H

#include "SmartDevices.h"
#include <iostream>

class Camera : public SmartDevices {
public:
    Camera();
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;

private:
    bool isOn;
};

#endif
