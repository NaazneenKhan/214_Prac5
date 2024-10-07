#include<iostream>
#include "HomeOwner.h"     // Include HomeOwner class
#include "Lights.h"        // Include specific smart device implementations
#include "Doors.h"
#include "Alarm.h"
#include "Camera.h"
#include "Thermostat.h"
#include "Remote.h"
#include "SmartThermostat.h"
#include "SmartThermostatIntegrator.h"

void TestComposite() {
    HomeOwner* owner = new HomeOwner();

    // Create some smart devices (lights, doors, alarm, etc.)
    Lights* livingRoomLights = new Lights();
    Doors* frontDoor = new Doors();
    Alarm* homeAlarm = new Alarm();
    Camera* securityCamera = new Camera();
    Thermostat* homeThermostat = new Thermostat();

    // Add devices to the homeowner's control
    owner->addDevice(livingRoomLights);
    owner->addDevice(frontDoor);
    owner->addDevice(homeAlarm);
    owner->addDevice(securityCamera);
    owner->addDevice(homeThermostat);

    // Execute some commands through HomeOwner
    std::cout << "\nTurning on the lights and locking the door..." << std::endl;
    owner->executeCommand("On");       // Turns on all applicable devices
    owner->executeCommand("Lock");     // Locks the door
    
    // Check the status of all devices
    owner->checkStatus();

    // Turn off lights and unlock doors
    std::cout << "\nTurning off the lights and unlocking the door..." << std::endl;
    owner->executeCommand("Off");
    owner->executeCommand("Unlock");

    // Check status again
    owner->checkStatus();

    delete owner;
}

void TestAdapter() {
   
    Thermostat* oldThermostat = new Thermostat();
    SmartThermostat* smartThermo = new SmartThermostatIntegrator(oldThermostat);

    std::cout << "\nAdapter Testing:" << std::endl;
    std::cout << "Setting old thermostat to 25 degrees." << std::endl;
    smartThermo->setTemperature(25);  
    std::cout << "Smart Thermostat Temperature: " << smartThermo->getTemperature() << " degrees." << std::endl;

    std::cout << "Setting old thermostat to 18 degrees." << std::endl;
    smartThermo->setTemperature(18);  
    std::cout << "Smart Thermostat Temperature: " << smartThermo->getTemperature() << " degrees." << std::endl;

    delete smartThermo;
}

void TestComponent3() {
    // You could test specific commands or MacroRoutine here
}

void TestComponent4() {
    // You could test the Observer pattern here
}

int main() {
    std::cout << "Testing Composite:" << std::endl;
    TestComposite();

    std::cout << "\nTesting Adapter:" << std::endl;
    TestAdapter();

    // You can uncomment these when implementing additional tests for other components
    // TestComponent3();
    // TestComponent4();

    return 0;
}
