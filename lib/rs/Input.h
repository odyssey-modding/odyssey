#pragma once

namespace al {
class IUseSceneObjHolder;
}

namespace rs {

bool isHoldUiCancel(const al::IUseSceneObjHolder*);
bool isHoldUiDecide(const al::IUseSceneObjHolder*);
bool isHoldUiSelect(const al::IUseSceneObjHolder*);
bool isHoldUiL(const al::IUseSceneObjHolder*);
bool isHoldUiR(const al::IUseSceneObjHolder*);
bool isHoldUiY(const al::IUseSceneObjHolder*);
bool isHoldUiUp(const al::IUseSceneObjHolder*);
bool isHoldUiDown(const al::IUseSceneObjHolder*);
bool isHoldUiRight(const al::IUseSceneObjHolder*);
bool isHoldUiLeft(const al::IUseSceneObjHolder*);

}