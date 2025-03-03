#include "MonsterDeck.h"

#include "Monster.h"
#include "Runaway.h"

MonsterDeck::MonsterDeck()
{
	m_monstersDatabase =
	{
	new Monster{"Crazy Joe", 4, Tribe::Human,new Runaway_LevelDowngrade{1},new Victory_LevelUpgrade},
new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5},new Victory_RandomItem},
new Monster{"Vampire", 15, Tribe::Undead, new Runaway_LevelDowngrade{1},new Victory_LevelUpgrade},
new Monster{"Ancient Lich", 16, Tribe::Undead, new Runaway_ItemEquipedRemoval,new Victory_RandomModifier},
new Monster{"Fire Elemental", 17, Tribe::God, new Runaway_ModifierFromHandRemoval,new Victory_RandomModifier},
new Monster{"Giant Cthulhu", 18, Tribe::God, new Runaway_BiggestBonusCardRemoval,new Victory_RandomModifier},
new Monster{"Demonic Overlord", 19, Tribe::Undead, new Runaway_ModifierFromHandRemoval,new Victory_RandomItem},
new Monster{"Black Pegasus", 15, Tribe::Dragon, new Runaway_LevelDowngrade{1},new Victory_RandomModifier},
new Monster{"Ancient Wyvern", 18, Tribe::Dragon, new Runaway_BiggestBonusCardRemoval,new Victory_RandomItem},
new Monster{"Fire Drake", 14, Tribe::Dragon, new Runaway_LevelDowngrade{1},new Victory_RandomModifier},
new Monster{"Terrifying Mimic", 14, Tribe::Human, new Runaway_LevelDowngrade{1},new Victory_LevelUpgrade},
new Monster{"Goblin King", 13, Tribe::Orc, new Runaway_ItemEquipedRemoval,new Victory_LevelUpgrade},
new Monster{"Cosmic Rodent", 12, Tribe::Alien, new Runaway_BiggestBonusCardRemoval,new Victory_RandomItem},
new Monster{"Martian Warlord", 16, Tribe::Alien, new Runaway_ModifierFromHandRemoval,new Victory_RandomModifier},
new Monster{"Xenovore Queen", 14, Tribe::Alien, new Runaway_LevelDowngrade{1},new Victory_LevelUpgrade},
new Monster{"Orc Brute", 11, Tribe::Orc, new Runaway_ModifierFromHandRemoval,new Victory_LevelUpgrade},
new Monster{"Lazy Ghoul", 10, Tribe::Zombie, new Runaway_ItemEquipedRemoval,new Victory_LevelUpgrade},
new Monster{"Green Snot Monster", 9, Tribe::Zombie, new Runaway_ModifierFromHandRemoval, new Victory_LevelUpgrade},
new Monster{"Rotten Corpse", 12, Tribe::Zombie, new Runaway_ItemEquipedRemoval,new Victory_LevelUpgrade},
new Monster{"Plague Walker", 11, Tribe::Zombie, new Runaway_ModifierFromHandRemoval,new Victory_RandomItem},
new Monster{"Squid of Terror", 7, Tribe::Undead, new Runaway_ItemEquipedRemoval,new Victory_LevelUpgrade},
new Monster{"Vampire Ducks", 8, Tribe::Undead, new Runaway_ModifierFromHandRemoval,new Victory_LevelUpgrade}

	};
	m_availableMonsters = m_monstersDatabase;
}

MonsterDeck::~MonsterDeck()
{
	for (Monster* monster : m_monstersDatabase)
	{
		delete monster;
	}
	m_monstersDatabase.clear();
}


Monster* MonsterDeck::generateMonster() const
{
	static std::vector<Monster*> availableMonstersCopy = m_availableMonsters;

	if (availableMonstersCopy.empty())
	{
		availableMonstersCopy = m_availableMonsters;
	}

	const int choice = std::rand() % availableMonstersCopy.size();
	Monster* selectedMonster = availableMonstersCopy[choice];

	availableMonstersCopy.erase(availableMonstersCopy.begin() + choice);

	return selectedMonster;
}