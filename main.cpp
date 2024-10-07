#include<iostream>

#include "SmartThermostat.h"           
#include "Thermostat.h"               
#include "SmartThermostatIntegrator.h"
#include "Lights.h"
#include "LightSensor.h"
#include "Doors.h"
#include "DoorSensor.h"
#include "Alarm.h"
#include "AlarmSensor.h"
#include "Camera.h"
#include "CameraSensor.h"
#include "ThermostatSensor.h"

void TestComponent1 (){

}

void TestComponent2 (){

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
    Lights* light = new Lights();
    Doors* door = new Doors();
    Alarm* alarm = new Alarm();
    Camera* camera = new Camera();
    Thermostat* thermostat = new Thermostat();

   
    LightSensor* lightSensor = new LightSensor();
    DoorSensor* doorSensor = new DoorSensor();
    AlarmSensor* alarmSensor = new AlarmSensor();
    CameraSensor* cameraSensor = new CameraSensor();
    ThermostatSensor* thermostatSensor = new ThermostatSensor();

    
    light->addDevice(lightSensor);
    door->addDevice(doorSensor);
    alarm->addDevice(alarmSensor);
    camera->addDevice(cameraSensor);
    thermostat->addDevice(thermostatSensor);

 
    light->turnOn();   
    door->lock();      
    alarm->activate(); 
    camera->startRecording(); 
    thermostat->setTemperature(22); 

   
    delete lightSensor;
    delete doorSensor;
    delete alarmSensor;
    delete cameraSensor;
    delete thermostatSensor;
    delete light;
    delete door;
    delete alarm;
    delete camera;
    delete thermostat;
}

int main(){
   
//    TestComponent1();
   TestComponent2();
//    TestComponent3();
   TestComponent4();


    return 0;
}