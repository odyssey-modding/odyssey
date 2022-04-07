#pragma once

namespace al {
class KeyRepeatCtrl {
public:
    KeyRepeatCtrl();
    void init(int initialMaxWait, int maxWait);
    void reset();
    void update(bool up, bool down);
    bool isDown() const;
    bool isUp() const;
private:
    int mInitialMaxWait; // FIXME: good name this shit up
    int mMaxWait;
    int mUpCounter;
    int mDownCounter;
    char mCounter;
};
}