#ifndef CAMERASENSOR_H
#define CAMERASENSOR_H

#include "Sensors.h"
#include <iostream>

class CameraSensor : public Sensors {
    public:
        void update(SensorUpdate detection) override;
        // void update(double) override;

};

#endif
