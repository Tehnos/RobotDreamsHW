#include "ItemDeck.h"
#include <fstream>

#include "Item.h"
#include <iostream>

ItemDeck::ItemDeck()
{
	//TODO: Move item's database to file in format:
	// type;name; params for the type
	//For example:
	//UndeadWeapon;"Holy Grenade";4		//should call UndeadWeapon("Holy Grenade", 4);
	//TODO: Setup more items of diferent types
	m_itemsDataBase =
	{ new Weapon{"The Sword of DOOM", 5},
	new UndeadWeapon{"Stinky knife", 2},
	new UndeadWeapon{"Holy grenade", 4},
	new MagicWeapon{"HOLLY MOLLY", 4},
	new HolySword{"Sword of justice", 7},
	new Weapon{"Sharp Spoon", 1},
	new Weapon{"Half-Eaten Sword", 2},
	new Weapon{"Rubber Club", 2},
	new Weapon{"Wooden Boomerang", 3},
	new Weapon{"Sooty Crossbow", 3},
	new MagicWeapon{"Magic Bow", 4},
	new Weapon{"Double-Sided Axe", 5},
	new HolySword{"Holy Hand Grenade", 6},
	new Weapon{"Giant Fist of Doom", 7},
	new ElvenWeapon{"Elven Longsword", 8},
	new CursedWeapon{"Cursed Demonic Scythe", 9},
	new SciFiWeapon{"Plasma Blaster", 5},
	new LegendaryWeapon{"Sword of Swords", 6},
	new DragonSlayerWeapon{"Dragon-Slaying Crossbow", 5},
	new LegendaryWeapon{"Axe of the Ancient Gods", 4},
	new SciFiWeapon{"Cosmic Laser 3000", 8},
	new Armor{"Blonde Wig Helmet", 1},
	new Armor{"Turtle Shell Armor", 2},
	new Armor{"Scaly Armor", 4},
	new Armor{"Spiked Plate Mail", 5},
	new Shield{"Enchanted Shield", 6},
	new Armor{"Cybernetic Exosuit", 10},
	new HolyArmor{"Holy Armor", 12}
	};
}
ItemDeck::~ItemDeck()
{
	for (Item* itemDeck : m_itemsDataBase)
	{
		delete itemDeck;
	}
}

std::vector<Item*> ItemDeck::generateItems() const
{
	std::vector<Item*> handAndArmors;

	if (m_itemsDataBase.empty())
	{
		return handAndArmors;
	}

	const int count = 2;
	std::vector<int> usedIndices;

	while (handAndArmors.size() < count && usedIndices.size() < m_itemsDataBase.size())
	{
		int index = std::rand() % m_itemsDataBase.size();

		if (std::find(usedIndices.begin(), usedIndices.end(), index) == usedIndices.end())
		{
			handAndArmors.push_back(m_itemsDataBase[index]);
			usedIndices.push_back(index);
		}
	}

	return handAndArmors;
}
