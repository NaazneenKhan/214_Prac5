#include "IncDecTemp.h"

IncDecTemp::IncDecTemp(Thermostat* thermostat, bool increase) : thermostat(thermostat), increase(increase) {

}

void IncDecTemp::execute() {
    if (increase) {
        thermostat->performAction("IncreaseTemp");
    } else {
        thermostat->performAction("DecreaseTemp");
    }
}