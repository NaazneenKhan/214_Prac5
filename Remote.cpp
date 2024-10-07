#include "Remote.h"

Remote::Remote() : currentCommand(nullptr) {
    // Constructor implementation
}

void Remote::setCommand(MarcoRoutine* command) {
    currentCommand = command;
}

void Remote::pressButton() {
    if (currentCommand) {
        currentCommand->execute();
    }
}