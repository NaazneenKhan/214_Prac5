#include "CameraSensor.h"

void CameraSensor::update(const std::string &status)
{
    std::cout << "Camera sensor detected change: " << status << std::endl;
}