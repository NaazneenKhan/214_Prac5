#include "catch_amalgamated.hpp"
#include "Lights.h"
#include "Doors.h"
#include "OnOffLights.h"
#include "LockDoors.h"

TEST_CASE("Command Pattern: Test Remote Commands") {
    Lights* lights = new Lights();
    Doors* doors = new Doors();
    
    OnOffLights* lightsCommand = new OnOffLights(lights);
    LockDoors* lockDoorsCommand = new LockDoors(doors);

    SECTION("Lights on and off commands") {
        lightsCommand->execute();
        REQUIRE(lights->isOn());  // Assuming Lights class has isOn() method

        lightsCommand->execute(); // Toggle again
        REQUIRE_FALSE(lights->isOn());
    }

    SECTION("Lock and unlock doors commands") {
        lockDoorsCommand->execute();
        REQUIRE(doors->isLocked()); // Assuming Doors class has isLocked() method

        lockDoorsCommand->execute(); // Toggle again
        REQUIRE_FALSE(doors->isLocked());
    }

    delete lightsCommand;
    delete lockDoorsCommand;
    delete lights;
    delete doors;
}
