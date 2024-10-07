#ifndef ONOFFCAMERAS_H
#define ONOFFCAMERAS_H

#include "Command.h"
#include "Camera.h"

class OnOffCameras : public Command {
public:
    OnOffCameras(Camera* camera);
    void execute() override;

private:
    Camera* camera;
};

#endif
