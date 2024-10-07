#include "Camera.h"

Camera::Camera() : isOn(false) {
    // Initialize camera
}

std::string Camera::getStatus() {
    return isOn ? "on" : "off";
}

void Camera::performAction(const std::string& action) {
    // Handle actions like "ToggleOn", "ToggleOff", etc.
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
