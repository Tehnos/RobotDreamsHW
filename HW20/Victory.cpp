#include "Victory.h"
#include "Munchkin.h"
#include "ItemDeck.h"


void Victory_LevelUpgrade::apply(Munchkin* munchkin)
{
	munchkin->updateLevelBy(+m_levelToUP);
}

void Victory_RandomModifier::apply(Munchkin* munchkin)
{
	munchkin->addModifiers();
}

void Victory_RandomItem::apply(Munchkin* munchkin)
{
	munchkin->randomItem();
}
