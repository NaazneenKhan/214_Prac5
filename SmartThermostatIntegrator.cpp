#include "SmartThermostatIntegrator.h"

SmartThermostatIntegrator::SmartThermostatIntegrator(Thermostat *thermostat) : oldThermostat(thermostat)
{
}

void SmartThermostatIntegrator::setTemperature(double temp)
{
    oldThermostat->setSmartTemperature(temp);
}

double SmartThermostatIntegrator::getTemperature() const
{
    return oldThermostat->getSmartTemperature();
}


SmartThermostatIntegrator::~SmartThermostatIntegrator()
{
    delete oldThermostat;
}
