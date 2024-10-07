#include "SmartDevices.h"

void SmartDevices::addDevice(Sensors *sensor)
{
    sensors.push_back(sensor);
}

void SmartDevices::removeDevice(Sensors *sensor)
{
    sensors.erase(std::remove(sensors.begin(), sensors.end(), sensor), sensors.end());
}

void SmartDevices::notifyDevices()
{
    for (Sensors* sensor : sensors) {
            sensor->update(deviceStatus); 
        }
}

void SmartDevices::changeStatus(const std::string &newStatus)
{
    deviceStatus = newStatus;
    notifyDevices();
}
