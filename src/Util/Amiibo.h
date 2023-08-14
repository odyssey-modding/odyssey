#pragma once

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
void calcSearchAmiiboBit(int*, int*, int*, int);
int createCharacterIdS32(al::NfpCharacterId const&);
bool isEnableUseStageSceneAmiibo(al::NfpInfo const&);
bool isExistAmiiboMstxtData(al::IUseMessageSystem const*, al::NfpInfo const&);
const char* getAmiiboMstxtLabel(bool*, al::IUseMessageSystem const*, int, int, int);
bool tryFindAmiiboCostumeItemInfo(ShopItem::ItemInfo**, ShopItem::ItemInfo**, al::NfpCharacterId const&, int, al::IUseSceneObjHolder*);
void resetHelpAmiibo(al::IUseSceneObjHolder const*);
void getSearchAmiiboData(al::IUseSceneObjHolder const*);  // TODO: find type
void appearCoinCollectHintEffect(al::IUseSceneObjHolder const*);
void killCoinCollectHintEffect(al::IUseSceneObjHolder const*);
}  // namespace rs