#ifndef DOORSENSOR_H
#define DOORSENSOR_H

#include "Sensors.h"
#include <iostream>

class DoorSensor : public Sensors {
    public:
        void update(const std::string& status) override;
};

#endif
