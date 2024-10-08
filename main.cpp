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

    // Simulate motion detection for lights and alarm
    std::cout << "\nSimulating motion detection...\n";

    // Notify sensors from each smart device
    light->notifySensors(true); // motion detected 
    light->adjustForMotion(true);
    alarm->notifySensors(true);  // motion detected 
    alarm->adjustForMotion(true); 
    camera->notifySensors(true); //motion detected 
    camera->adjustForMotion(true); 

    // // Simulate door opening
    std::cout << "\nSimulating door opening...\n";
    door->notifySensors(true);    // Notify attached sensors of door opened
    door->adjustForDoorOpen(true);

    // Simulate no motion
    std::cout << "\nSimulating no motion...\n";
    light->notifySensors(false); // no motion detected
    light->adjustForMotion(false);
    alarm->notifySensors(false);  // no motion detected
    alarm->adjustForMotion(false); 
    camera->notifySensors(false); // no motion detected
    camera->adjustForMotion(false); 

     // // Simulate door closing and locking after it was opened
    std::cout << "\nSimulating door closing...\n";
    door->notifySensors(false);    // Notify attached sensors of door opened
    door->adjustForDoorOpen(false);
    

    // // Simulate hot outside temperature
    std::cout << "\nSimulating hot outside temperature...\n";
    thermostat->notifySensors(35.0);  // Outside temperature is hot
    thermostat->adjustForOutsideTemp(35.0);

    // // Simulate cold outside temperature
    std::cout << "\nSimulating cold outside temperature...\n";
    thermostat->notifySensors(10.0);  // Outside temperature is cold
    thermostat->adjustForOutsideTemp(10.0);

    // // light->turnOn();   
    // // door->lock();      
    // // alarm->activate(); 
    // // camera->startRecording(); 
    // // thermostat->setTemperature(22); 

   
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


void DemoScenario() {
    std::cout << "Starting Home Automation Scenario...\n" << std::endl;

    // Step 1: Homeowner prepares for bed - composite pattern usage
    std::cout << "Step 1: Homeowner prepares for bed.\n" << std::endl;
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

    std::cout << "Turning on the lights and locking the door...\n" << std::endl;
    owner->executeCommand("On");
    owner->executeCommand("Lock");
    
    std::cout << "Checking device status...\n";
    owner->checkStatus();

    // Step 2: Homeowner realizes they left the lights on, adapts to the smart thermostat
    std::cout << "\nStep 2: Adapting to smart thermostat and adjusting temperature.\n" << std::endl;
    Thermostat* oldThermostat = new Thermostat();
    SmartThermostat* smartThermo = new SmartThermostatIntegrator(oldThermostat);

    std::cout << "Smart Thermostat activated, setting to 25 degrees.\n";
    smartThermo->setTemperature(25);
    std::cout << "Smart Thermostat Temperature: " << smartThermo->getTemperature() << " degrees.\n";

    // Step 3: Homeowner activates Goodnight routine
    std::cout << "\nStep 3: Homeowner activates Goodnight routine.\n" << std::endl;
    Lights* lights = new Lights();
    Doors* doors = new Doors();
    Alarm* alarm = new Alarm();
    Camera* camera = new Camera();
    Thermostat* thermostat = new Thermostat();

    OnOffLights* lightsCommand = new OnOffLights(lights);
    LockDoors* lockDoorsCommand = new LockDoors(doors);
    OnOffAlarm* alarmCommand = new OnOffAlarm(alarm);
    OnOffCameras* cameraCommand = new OnOffCameras(camera);
    MarcoRoutine* goodnightRoutine = new MarcoRoutine();
    goodnightRoutine->addProcedure(lightsCommand);
    goodnightRoutine->addProcedure(lockDoorsCommand);
    goodnightRoutine->addProcedure(alarmCommand);
    goodnightRoutine->addProcedure(cameraCommand);

    Remote* remote = new Remote();
    remote->setCommand(goodnightRoutine);
    std::cout << "Executing Goodnight routine...\n" << std::endl;
    remote->pressButton();

    // Step 4: Sensors detect motion and temperature changes
    std::cout << "\nStep 4: Sensors detect changes in the environment.\n" << std::endl;

    LightSensor* lightSensor = new LightSensor();
    DoorSensor* doorSensor = new DoorSensor();
    AlarmSensor* alarmSensor = new AlarmSensor();
    CameraSensor* cameraSensor = new CameraSensor();
    ThermostatSensor* thermostatSensor = new ThermostatSensor();

    lights->addDevice(lightSensor);
    doors->addDevice(doorSensor);
    alarm->addDevice(alarmSensor);
    camera->addDevice(cameraSensor);
    thermostat->addDevice(thermostatSensor);

    // Simulating sensor actions
    std::cout << "Simulating motion detection and response:\n" << std::endl;
    lights->notifySensors(true);
    lights->adjustForMotion(true);
    alarm->notifySensors(true);
    alarm->adjustForMotion(true);
    camera->notifySensors(true);
    camera->adjustForMotion(true);

    std::cout << "\nSimulating hot outside temperature...\n";
    thermostat->notifySensors(35.0);
    thermostat->adjustForOutsideTemp(35.0);

    std::cout << "\nSimulating cold outside temperature...\n";
    thermostat->notifySensors(10.0);
    thermostat->adjustForOutsideTemp(10.0);

    // Cleanup
    delete owner;
    delete smartThermo;
    delete lightsCommand;
    delete lockDoorsCommand;
    delete alarmCommand;
    delete cameraCommand;
    delete goodnightRoutine;
    delete remote;
    delete lightSensor;
    delete doorSensor;
    delete alarmSensor;
    delete cameraSensor;
    delete thermostatSensor;
    delete lights;
    delete doors;
    delete alarm;
    delete camera;
    delete thermostat;

    std::cout << "\nHome Automation Scenario completed.\n" << std::endl;
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


   // DemoScenario();

    return 0;
}
