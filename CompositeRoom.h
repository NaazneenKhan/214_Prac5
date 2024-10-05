#ifndef COMPOSITEROOM_H
#define COMPOSITEROOM_H

#include "SmartDevices.h"
#include <vector>
#include <string>

class CompositeRoom : public SmartDevices {
public:
    CompositeRoom();
    void addDevice(SmartDevices* device);
    void removeDevice(SmartDevices* device);
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;

private:
    std::vector<SmartDevices*> devices;
};

#endif
