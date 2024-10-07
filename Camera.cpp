#include "Camera.h"

Camera::Camera() : isOn_(false) {
    // camerma is initially off
}

std::string Camera::getStatus() {
    return isOn_ ? "on" : "off";
}

void Camera::performAction(const std::string& action) {
    if (action == "On") {
        isOn_ = true;
        std::cout << "Camera is turned on." << std::endl;
    } else if (action == "Off") {
        isOn_ = false;
        std::cout << "Camera is turned off." << std::endl;
    } else if (action == "Toggle") {
        isOn_ = !isOn_;
        std::cout << "Camera toggled to " << (isOn_ ? "on" : "off") << "." << std::endl;
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
