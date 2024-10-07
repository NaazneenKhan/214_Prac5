#ifndef ONOFFLIGHTS_H
#define ONOFFLIGHTS_H

#include "Command.h"
#include "Lights.h"

class OnOffLights : public Command {
public:
    OnOffLights(Lights* lights);
    void execute() override;

private:
    Lights* lights;
};

#endif
