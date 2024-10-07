#include "LockDoors.h"

LockDoors::LockDoors(Doors* doors) : doors(doors) {
   
}

void LockDoors::execute() {
    doors->performAction("Toggle");
}