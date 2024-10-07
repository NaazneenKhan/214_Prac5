#ifndef ONOFFALARM_H
#define ONOFFALARM_H

#include "Command.h"
#include "Alarm.h"

class OnOffAlarm : public Command {
public:
    OnOffAlarm(Alarm* alarm);
    void execute() override;

private:
    Alarm* alarm;
};

#endif
