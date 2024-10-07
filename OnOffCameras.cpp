#include "OnOffCameras.h"

OnOffCameras::OnOffCameras(Camera* camera) : camera(camera) {
    
}

void OnOffCameras::execute() {
    camera->performAction("Toggle");
}