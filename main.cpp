#include<iostream>
#include "HomeOwner.h"    
#include "Lights.h"        
#include "Doors.h"
#include "Alarm.h"
#include "Camera.h"
#include "Thermostat.h"
#include "Remote.h"
#include "SmartThermostat.h"
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
#include "MarcoRoutine.h"
#include "OnOffLights.h"
#include "LockDoors.h"
#include "OnOffAlarm.h"
#include "OnOffCameras.h"
#include "IncDecTemp.h"

void TestComposite() {
    HomeOwner* owner = new HomeOwner();

    Lights* livingRoomLights = new Lights();
    Doors* frontDoor = new Doors();
    Alarm* homeAlarm = new Alarm();
    Camera* securityCamera = new Camera();
    Thermostat* homeThermostat = new Thermostat();

    owner->addDevice(livingRoomLights);
    owner->addDevice(frontDoor);
    owner->addDevice(homeAlarm);
    owner->addDevice(securityCamera);
    owner->addDevice(homeThermostat);

    std::cout << "\nTurning on the lights and locking the door..." << std::endl;
    owner->executeCommand("On");
    owner->executeCommand("Lock");    
    
    owner->checkStatus();

    std::cout << "\nTurning off the lights and unlocking the door..." << std::endl;
    owner->executeCommand("Off");
    owner->executeCommand("Unlock");

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

void TestCommand() {
    Lights* lights = new Lights();
    Doors* doors = new Doors();
    Alarm* alarm = new Alarm();
    Camera* camera = new Camera();
    Thermostat* thermostat = new Thermostat();


    OnOffLights* lightsCommand = new OnOffLights(lights);
    LockDoors* lockDoorsCommand = new LockDoors(doors);
    OnOffAlarm* alarmCommand = new OnOffAlarm(alarm);
    OnOffCameras* cameraCommand = new OnOffCameras(camera);
    IncDecTemp* tempIncreaseCommand = new IncDecTemp(thermostat, true);
    IncDecTemp* tempDecreaseCommand = new IncDecTemp(thermostat, false);    

    
    MarcoRoutine* goodnightRoutine = new MarcoRoutine();
    goodnightRoutine->addProcedure(lightsCommand);
    goodnightRoutine->addProcedure(lockDoorsCommand);
    goodnightRoutine->addProcedure(alarmCommand);
    goodnightRoutine->addProcedure(cameraCommand);

   
    Remote* remote = new Remote();

    // Setting a command (Goodnight routine) and executing it
    remote->setCommand(goodnightRoutine);
    remote->pressButton();

   
    delete lightsCommand;
    delete lockDoorsCommand;
    delete alarmCommand;
    delete cameraCommand;
    delete tempIncreaseCommand;
    delete tempDecreaseCommand;
    delete goodnightRoutine;
    delete remote;
    delete lights;
    delete doors;
    delete alarm;
    delete camera;
    delete thermostat;

}

void TestObserver() {

    
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

int main() {
    
    std::cout << "Testing Composite:" << std::endl;
    TestComposite();

    std::cout << "\nTesting Adapter:" << std::endl;
    TestAdapter();

    std::cout << "\nTesting Command:" << std::endl;
    TestCommand();

    std::cout << "\nTesting Observer:" << std::endl; 
    TestObserver();

    return 0;
}
