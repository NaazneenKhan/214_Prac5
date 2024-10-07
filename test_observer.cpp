#include "catch_amalgamated.hpp"
#include "Lights.h"
#include "LightSensor.h"

TEST_CASE("Observer Pattern: Test LightSensor and Lights") {
    Lights* lights = new Lights();
    LightSensor* lightSensor = new LightSensor();

    lights->addDevice(lightSensor);

    SECTION("Turn lights on and check sensor notification") {
        lights->turnOn();
        REQUIRE(lights->isOn());
        // Add additional checks for sensor state
    }

    SECTION("Turn lights off and check sensor notification") {
        lights->turnOff();
        REQUIRE_FALSE(lights->isOn());
        // Add additional checks for sensor state
    }

    delete lightSensor;
    delete lights;
}
