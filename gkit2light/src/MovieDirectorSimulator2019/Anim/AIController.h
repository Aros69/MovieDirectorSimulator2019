#ifndef MOVIEDIRECTORSIMULATOR2019_AICONTROLLER_H
#define MOVIEDIRECTORSIMULATOR2019_AICONTROLLER_H

#include <CharacterController.h>

class AIController : public CharacterController {
public:
    AIController();

    ~AIController();

    virtual void update(const float dt) override;

private:
    double timeSinceLastChange=0;
    int lastInput;
};


#endif //MOVIEDIRECTORSIMULATOR2019_AICONTROLLER_H
