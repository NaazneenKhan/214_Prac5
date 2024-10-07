#include "catch_amalgamated.hpp"
#include "SmartThermostat.h"
#include "SmartThermostatIntegrator.h"
#include "Thermostat.h"

// Test Adapter functionality
TEST_CASE("Adapter Pattern: Smart Thermostat Integration") {
    Thermostat* oldThermostat = new Thermostat();
    SmartThermostat* smartThermo = new SmartThermostatIntegrator(oldThermostat);

    SECTION("Setting temperature to 25 degrees") {
        smartThermo->setTemperature(25);
        REQUIRE(smartThermo->getTemperature() == 25);
    }

    SECTION("Setting temperature to 18 degrees") {
        smartThermo->setTemperature(18);
        REQUIRE(smartThermo->getTemperature() == 18);
    }

    delete smartThermo;
}
