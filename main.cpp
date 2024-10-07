#include<iostream>

#include "SmartThermostat.h"           
#include "Thermostat.h"               
#include "SmartThermostatIntegrator.h"
#include "CompositeRoom.h"
#include "Lights.h"
#include "Doors.h"
#include "Thermostat.h"
#include "Alarm.h"
#include "Camera.h"

void TestComposite (){
    std::cout << "Composite Testing\n";

    Lights* light1 = new Lights();
    Lights* light2 = new Lights();
    Doors* door1 = new Doors();
    Thermostat* thermostat = new Thermostat();
    Alarm* alarm = new Alarm();
    Camera* camera = new Camera();

    // Create composite room and add devices
    CompositeRoom* livingRoom = new CompositeRoom();
    livingRoom->addDevice(light1);
    livingRoom->addDevice(light2);
    livingRoom->addDevice(door1);
    livingRoom->addDevice(thermostat);
    livingRoom->addDevice(alarm);
    livingRoom->addDevice(camera);

    // Test getStatus before any actions
    std::cout << "Living Room Status: " << livingRoom->getStatus() << std::endl;

    // Perform actions on the composite room (all devices)
    livingRoom->performAction("On");
    std::cout << "Living Room Status after turning on lights: " << livingRoom->getStatus() << std::endl;

    livingRoom->performAction("Lock");
    std::cout << "Living Room Status after locking doors: " << livingRoom->getStatus() << std::endl;

    livingRoom->performAction("IncreaseTemp");
    std::cout << "Living Room Status after increasing temperature: " << livingRoom->getStatus() << std::endl;

    // Cleanup
    delete light1;
    delete light2;
    delete door1;
    delete thermostat;
    delete alarm;
    delete camera;
    delete livingRoom;

}

void TestAdapter (){
    std::cout << "Adapter Testing\n";

    Thermostat* oldThermostat = new Thermostat();

    SmartThermostat* smartThermo = new SmartThermostatIntegrator(oldThermostat);

    std::cout << "Setting old thermostat to 25 degrees." << std::endl;
    smartThermo->setTemperature(25);  
    std::cout << "Smart Thermostat Temperature: " << smartThermo->getTemperature() << " degrees." << std::endl;

    std::cout << "Setting old thermostat to 18 degrees." << std::endl;
    smartThermo->setTemperature(18);  
    std::cout << "Smart Thermostat Temperature: " << smartThermo->getTemperature() << " degrees." << std::endl;

    delete smartThermo;
    
}

void TestComponent3(){
    
}

void TestComponent4 (){
    
}

int main(){
   
   TestComposite();
   TestAdapter();
//    TestComponent3();
//    TestComponent4();


    return 0;
}