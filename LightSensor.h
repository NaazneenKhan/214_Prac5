#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "Sensors.h"
#include <iostream>

class LightSensor : public Sensors {
    public:
        void update(const std::string& status) override;
};

#endif
