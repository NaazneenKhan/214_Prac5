#ifndef SENSORS_H
#define SENSORS_H

#include <string>
#include <variant>

using SensorUpdate = std::variant<bool, double>;

class Sensors {
    public:
        virtual void update(SensorUpdate detection) = 0;
        virtual ~Sensors() = default;
        // virtual void update(double temp) = 0;
};

#endif
