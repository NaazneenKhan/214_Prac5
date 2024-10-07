#ifndef ALARMSENSOR_H
#define ALARMSENSOR_H

#include "Sensors.h"
#include <iostream>

class AlarmSensor : public Sensors {
    public:
        void update(SensorUpdate detection) override;
        // void update(double) override;
};

#endif
