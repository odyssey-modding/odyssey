#pragma once

namespace al {
class MessageSystem;
class IUseMessageSystem {
public:
    virtual const al::MessageSystem* getMessageSystem(void) const;
};
}
