#include "MarcoRoutine.h"

MarcoRoutine::MarcoRoutine() {
    // Constructor implementation
}

void MarcoRoutine::execute() {
    for (Command* cmd : procedures) {
        cmd->execute();
    }
}

void MarcoRoutine::addProcedure(Command* command) {
    procedures.push_back(command);
}

void MarcoRoutine::removeProcedure(Command* command) {
    // Remove command from procedures
}