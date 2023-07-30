#include <al/Library/System/SystemKit.h>
#include "Application.h"

al::SystemKit* alProjectInterface::getSystemKit() {
    return Application::instance()->getSystemKit();
}
