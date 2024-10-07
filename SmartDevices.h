#ifndef SMARTDEVICES_H
#define SMARTDEVICES_H

#include <string>
#include <iostream>
#include <vector>
#include "Sensors.h"

// class Sensors;

class SmartDevices {
public:
    virtual ~SmartDevices() {}
    virtual std::string getStatus() = 0;
    virtual void performAction(const std::string& action) = 0;
    virtual std::string getDeviceType() const = 0;


    private:
        std::vector<Sensors*> sensors;  
        std::string deviceStatus;   

    public:
        void addDevice(Sensors* sensor);
        void removeDevice(Sensors* sensor);
        // void notifyDevices();
        void changeStatus(const std::string& newStatus);


        void notifySensors(bool motionDetected);  // For motion-based sensors
    void notifySensors(double outsideTemperature);  // For thermostat
};

#endif
