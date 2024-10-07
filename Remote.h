#ifndef REMOTE_H
#define REMOTE_H

#include "MarcoRoutine.h"

class Remote {
public:
    Remote();
    void setCommand(MarcoRoutine* command);
    void pressButton();
    
private:
    MarcoRoutine* currentCommand;
};

#endif
