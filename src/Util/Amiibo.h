#pragma once

#include <basis/seadTypes.h>

namespace al {
struct NfpCharacterId;
struct NfpInfo;
class IUseMessageSystem;
class IUseSceneObjHolder;
}  // namespace al

class SearchAmiiboData;

class ShopItem {
public:
    struct ItemInfo;
};

namespace rs {
void calcSearchAmiiboBit(s32*, s32*, s32*, s32);
s32 createCharacterIdS32(const al::NfpCharacterId&);
bool isEnableUseStageSceneAmiibo(const al::NfpInfo&);
bool isExistAmiiboMstxtData(const al::IUseMessageSystem*, const al::NfpInfo&);
const char* getAmiiboMstxtLabel(bool*, const al::IUseMessageSystem*, s32, s32, s32);
bool tryFindAmiiboCostumeItemInfo(ShopItem::ItemInfo**, ShopItem::ItemInfo**, const al::NfpCharacterId&, s32, al::IUseSceneObjHolder*);
void resetHelpAmiibo(const al::IUseSceneObjHolder*);
SearchAmiiboData *getSearchAmiiboData(const al::IUseSceneObjHolder*);
void appearCoinCollectHintEffect(const al::IUseSceneObjHolder*);
void killCoinCollectHintEffect(const al::IUseSceneObjHolder*);
}  // namespace rs