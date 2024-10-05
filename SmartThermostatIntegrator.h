#ifndef SmartThermostatIntegrator_H
#define SmartThermostatIntegrator_H

#include "Thermostat.h"
#include "SmartThermostat.h"

class SmartThermostatIntegrator : public SmartThermostat{

    private:
        Thermostat* oldThermostat;

    public:
        SmartThermostatIntegrator(Thermostat* thermostat);

        void setTemperature(double temp) override;
        double getTemperature() const override;

        ~SmartThermostatIntegrator();


};

#endif

