#include "Camera.h"

Camera::Camera() : isOn(false) {
    // camerma is initially off
}

std::string Camera::getStatus() {
    return isOn ? "on" : "off";
}

void Camera::performAction(const std::string& action) {
    if (action == "On") {
        isOn = true;
        std::cout << "Camera is turned on." << std::endl;
    } else if (action == "Off") {
        isOn = false;
        std::cout << "Camera is turned off." << std::endl;
    } else if (action == "Toggle") {
        isOn = !isOn;
        std::cout << "Camera toggled to " << (isOn ? "on" : "off") << "." << std::endl;
    } else {
        std::cout << "Unknown action: " << action << std::endl;
    }
}

std::string Camera::getDeviceType() const {
    return "Camera";
}

void Camera::startRecording()
{
    changeStatus("Camera is RECORDING");
}

void Camera::stopRecording()
{
    changeStatus("Camera STOPPED RECORDING");
}
