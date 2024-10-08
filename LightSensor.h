#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "Sensors.h"
#include <iostream>
#include <variant>
class LightSensor : public Sensors {
    public:
        void update(SensorUpdate detection) override;
        // void update(double) override;
};

#endif
