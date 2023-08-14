#include "ProjectInterface.h"
#include "Application.h"

// It's possible that this was accidentally not inlined, and any other functions in here was.
// I would bet that this namespace has a lot more in it for debug. Probably hostio.
al::SystemKit* alProjectInterface::getSystemKit() {
    return Application::instance()->getSystemKit();
}
