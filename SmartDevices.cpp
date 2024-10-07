#include "SmartDevices.h"
#include "LightSensor.h"
#include "AlarmSensor.h"
#include "ThermostatSensor.h"
#include"CameraSensor.h"
#include "DoorSensor.h"

#include <algorithm>

void SmartDevices::addDevice(Sensors *sensor)
{
    sensors.push_back(sensor);
}

void SmartDevices::removeDevice(Sensors *sensor)
{
    sensors.erase(std::remove(sensors.begin(), sensors.end(), sensor), sensors.end());
}

// void SmartDevices::notifyDevices()
// {
//     for (Sensors* sensor : sensors) {
//             sensor->update(deviceStatus); 
//         }
// }

void SmartDevices::changeStatus(const std::string &newStatus)
{
    deviceStatus = newStatus;

    // Call notifySensors based on the device status (example for motion detection)
    if (deviceStatus == "Door Opened") {
        notifySensors(true); // Assuming motion is detected
    } else {
        notifySensors(false); // No motion detected
    }
}

// Notify sensors based on type
void SmartDevices::notifySensors(bool motionDetected) {
    for (Sensors* sensor : sensors) {
        if (LightSensor* lightSensor = dynamic_cast<LightSensor*>(sensor)) {
            lightSensor->update(SensorUpdate(motionDetected)); // Use the new variant type
        } else if (AlarmSensor* alarmSensor = dynamic_cast<AlarmSensor*>(sensor)) {
            alarmSensor->update(SensorUpdate(motionDetected));
        } else if (CameraSensor* cameraSensor = dynamic_cast<CameraSensor*>(sensor)) {
            cameraSensor->update(SensorUpdate(motionDetected));
        } else if (DoorSensor* doorSensor = dynamic_cast<DoorSensor*>(sensor)) {
            doorSensor->update(SensorUpdate(motionDetected));
        }
    
}
}

// Notify sensors for thermostat based on temperature
void SmartDevices::notifySensors(double outsideTemperature) {
    for (Sensors* sensor : sensors) {
        if (ThermostatSensor* thermostatSensor = dynamic_cast<ThermostatSensor*>(sensor)) {
            thermostatSensor->update(SensorUpdate(outsideTemperature)); // Use the new variant type
        }
    }
}