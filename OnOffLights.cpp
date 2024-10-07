#include "OnOffLights.h"

OnOffLights::OnOffLights(Lights* lights) : lights(lights) {
   
}

void OnOffLights::execute() {
    lights->performAction("Toggle");
}