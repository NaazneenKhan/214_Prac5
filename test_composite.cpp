#define CATCH_CONFIG_MAIN  // This tells Catch2 to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "HomeOwner.h"
#include "Lights.h"
#include "Doors.h"
#include "Alarm.h"
#include "Camera.h"
#include "Thermostat.h"

// Test Composite functionality
TEST_CASE("Composite Pattern: HomeOwner controlling devices") {
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

    SECTION("Turn on lights and lock doors") {
        owner->executeCommand("On");
        owner->executeCommand("Lock");
        REQUIRE(livingRoomLights->isOn()); 
        REQUIRE(frontDoor->isLocked());    
    }

    SECTION("Turn off lights and unlock doors") {
        owner->executeCommand("Off");
        owner->executeCommand("Unlock");
        REQUIRE_FALSE(livingRoomLights->isOn());
        REQUIRE_FALSE(frontDoor->isLocked());
    }

    delete owner;
    delete livingRoomLights;
    delete frontDoor;
    delete homeAlarm;
    delete securityCamera;
    delete homeThermostat;
}


