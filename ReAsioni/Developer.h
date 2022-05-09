#include "Dxlib.h"

#include "Map.h"
#include "Oni.h"
#include "Item.h"
#include "Guide.h"
#include "Sign.h"
#include "Quize.h"
#include "OPandED.h"

class DevelopTool {
public:
	void Reset(Basic* basic, Guide* guide, Item* item, HaveItem* havI, MobItem* mobI, ItemShop* shop, UseItem* useI, Map* map, Oni* oni, MobEvent* mob, OPED* oe,
		Player* pl, Quize* quize, Sign* sign) {
		basic->Reset();
		guide->Reset();
		item->Reset();
		mobI->Reset();
		shop->Reset();
		useI->Reset();
		map->Reset();
		oni->Reset();
		mob->Reset();
		oe->Reset();
		pl->Reset();
		quize->Reset();
		sign->Reset();
		havI->Reset();
	}
};
