#include "AlarmSensor.h"

void AlarmSensor::update(const std::string &status)
{
    std::cout << "Alarm sensor detected change: " << status << std::endl;
}