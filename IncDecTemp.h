#ifndef INCDECTEMP_H
#define INCDECTEMP_H

#include "Command.h"
#include "Thermostat.h"

class IncDecTemp : public Command {
public:
    IncDecTemp(Thermostat* thermostat, bool increase);
    void execute() override;

private:
    Thermostat* thermostat;
    bool increase;  // true to increase, false to decrease
};

#endif
