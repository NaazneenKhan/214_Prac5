#ifndef LOCKDOORS_H
#define LOCKDOORS_H

#include "Command.h"
#include "Doors.h"

class LockDoors : public Command {
public:
    LockDoors(Doors* doors);
    void execute() override;

private:
    Doors* doors;
};

#endif
