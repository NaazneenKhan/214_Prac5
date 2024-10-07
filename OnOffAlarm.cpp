#include "OnOffAlarm.h"

OnOffAlarm::OnOffAlarm(Alarm* alarm) : alarm(alarm) {
   
}

void OnOffAlarm::execute() {
    alarm->performAction("Toggle");
}