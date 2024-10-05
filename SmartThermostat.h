#ifndef SMARTTHERMOSTAT_H
#define SMARTTHERMOSTAT_H

class SmartThermostat {
public:
    virtual void setTemperature(double temp) = 0;
    virtual double getTemperature() const = 0;
    virtual ~SmartThermostat() = default;
};

#endif