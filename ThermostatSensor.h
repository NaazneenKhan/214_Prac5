#ifndef THERMOSTATSENSOR_H
#define THERMOSTATSENSOR_H

#include "Sensors.h"
#include <iostream>

class ThermostatSensor : public Sensors {
    public:
        void update(const std::string& status) override;
};

#endif
