#ifndef MARCOROUTINE_H
#define MARCOROUTINE_H

#include "Command.h"
#include <vector>

class MarcoRoutine : public Command {
public:
    MarcoRoutine();
    void execute() override;
    void addProcedure(Command* command);
    void removeProcedure(Command* command);

private:
    std::vector<Command*> procedures;
};

#endif
