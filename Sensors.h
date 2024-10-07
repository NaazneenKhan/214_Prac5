#ifndef SENSORS_H
#define SENSORS_H

#include <string>

class Sensors {
    public:
        virtual void update(const std::string& status) = 0;
        virtual ~Sensors() = default;
};

#endif
