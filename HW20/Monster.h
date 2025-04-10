#pragma once
#include <string>
#include "Tribe.h"
#include "Runaway.h"
#include "Victory.h"

class Runaway;

class Monster
{
public:
	Monster(const std::string& name, int level = 1, Tribe tribe = Tribe::Human, Runaway* policy = nullptr, Victory* vpolicy = nullptr)
		: m_name(name), m_level(level), m_tribe(tribe), m_RunawayPolicy(policy), m_VictoryPolicy(vpolicy){
	}

	Tribe getTribe() const { return m_tribe; }
	unsigned int getLevel() const { return m_level; }	//for FIGHT USAGE
	void cutLevelx2()  { m_level/=2; }	//for FIGHT USAGE
	const std::string& getName() const { return m_name; }

	Runaway* getRunawayPolicy() const { return m_RunawayPolicy; }	//used by fight to punish player for being sucks
	Victory* getVictoryPolicy() const { return m_VictoryPolicy; }	//used by fight to reward player for being good
	std::string getFullInfo() const { return "Monster " + getName() + ", " + m_RunawayPolicy->getFullInfo(); }
	std::string getVictoryInfo() const { return "You kill Monster " + getName() + ", and get " + m_VictoryPolicy->getFullInfo(); }

private:
	unsigned int m_level = 1;
	Tribe m_tribe = Tribe::Human;
	std::string m_name;

	//#TODO: Add bonus victory policy for losing to munchkin similar to Runaway policies
	Runaway* m_RunawayPolicy = nullptr;
	Victory* m_VictoryPolicy = nullptr;
};

//LOSING FLOW:
//Runaway* newRunaway = monster->getRunaway();
//newRunaway->apply(m_munchkin);