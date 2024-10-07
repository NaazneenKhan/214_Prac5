#include "MarcoRoutine.h"

MarcoRoutine::MarcoRoutine() {
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
    auto it = std::find(procedures.begin(), procedures.end(), command);
    if (it != procedures.end()) {
        procedures.erase(it);
    }
}