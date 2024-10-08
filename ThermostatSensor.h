#ifndef THERMOSTATSENSOR_H
#define THERMOSTATSENSOR_H

#include "Sensors.h"
#include <iostream>
#include <variant>
class ThermostatSensor : public Sensors {
    public:
        void update(SensorUpdate detection) override;
        // void update(bool detected) override;
};

#endif
