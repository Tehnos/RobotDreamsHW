#include "Fight.h"

#include "Item.h"
#include "Modifier.h"
#include "Munchkin.h"
#include "Monster.h"
#include "Runaway.h"

void Fight::start()
{
	m_result = FightResult::InProgress;
	
	calculateMunchkinPower();	//m_munckin -> GetLevel + m_items[]
	calculateMonsterPower();	//getPower()
}

void Fight::applyModifier(int choice)
{
	Modifier* modifier = m_munchkin->popModifier(choice);
	if (modifier == nullptr)
	{
		//#TODO: Give some assert/warning in debug to user that modifier is null so something is wrong
		return;
	}

	modifier->apply(m_munchkin, m_monster);

	m_MunchkinPower += modifier->getMunchkinModifier();
	m_monsterPower += modifier->getMonsterModifier();
}

void Fight::runawayFlow()
{
	Runaway* policy = m_monster->getRunawayPolicy();
	policy->apply(m_munchkin);

	m_result = FightResult::MonsterWon;
}

void Fight::victoryFlow()
{
	
	Victory* policy = m_monster->getVictoryPolicy();
	policy->apply(m_munchkin);
	m_result = FightResult::MunchkinWon;

}

void Fight::calculateMunchkinPower()
{
	m_MunchkinPower += m_munchkin->getLevel();
	for (Item* item : m_munchkin->getItems())
	{
		m_MunchkinPower += item->getPower(m_monster->getTribe());
	}
}

void Fight::calculateMonsterPower()
{
	m_monsterPower = m_monster->getLevel();

	//EXTEND if needed
}
