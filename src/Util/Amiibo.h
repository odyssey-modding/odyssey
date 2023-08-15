#pragma once

#include <basis/seadTypes.h>

namespace al {
class NfpCharacterId;
class NfpInfo;
class IUseMessageSystem;
class IUseSceneObjHolder;
}  // namespace al

class ShopItem {
public:
    class ItemInfo;
};

namespace rs {
void calcSearchAmiiboBit(int*, s32*, s32*, s32);
s32 createCharacterIdS32(const al::NfpCharacterId&);
bool isEnableUseStageSceneAmiibo(const al::NfpInfo&);
bool isExistAmiiboMstxtData(const al::IUseMessageSystem*, const al::NfpInfo&);
const char* getAmiiboMstxtLabel(bool*, const al::IUseMessageSystem*, s32, s32, s32);
bool tryFindAmiiboCostumeItemInfo(ShopItem::ItemInfo**, ShopItem::ItemInfo**, const al::NfpCharacterId&, s32, al::IUseSceneObjHolder*);
void resetHelpAmiibo(al::IUseSceneObjHolder const*);
void getSearchAmiiboData(al::IUseSceneObjHolder const*);  // TODO: find type
void appearCoinCollectHintEffect(al::IUseSceneObjHolder const*);
void killCoinCollectHintEffect(al::IUseSceneObjHolder const*);
}  // namespace rs