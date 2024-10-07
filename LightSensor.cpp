#include "LightSensor.h"

void LightSensor::update(const std::string &status)
{
    std::cout << "Light sensor detected change: " << status << std::endl;
}