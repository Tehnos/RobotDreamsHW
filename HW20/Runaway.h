#pragma once
#include <string>

//forwad declaration
class Munchkin;

class Runaway
{
public:
	virtual void apply(Munchkin* munchkin) = 0;

	virtual std::string getFullInfo() { return ""; }
};

class Runaway_LevelDowngrade : public Runaway
{
public:
	Runaway_LevelDowngrade(int level = 1) : m_levelToDowngrade(level) {}
	void apply(Munchkin* munchkin) override;
	 std::string getFullInfo() override {
        return "Level Downgrade: " + std::to_string(m_levelToDowngrade) + " level(s)";
    }
protected:
	int m_levelToDowngrade;
};

class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
	Runaway_LevelDowngradeIf(int level, int minimalMunchkinLevel)
		: Runaway_LevelDowngrade(level), m_minimalMunchkinLevelToApply(minimalMunchkinLevel) {
	}

	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override 
	{
		return "Level Downgrade If: " + std::to_string(m_levelToDowngrade) +
			" level(s) if Munchkin level >= " + std::to_string(m_minimalMunchkinLevelToApply);
	}
private:
	int m_minimalMunchkinLevelToApply;
};

//Remove a card from hand(modifier) at random
class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
	void apply(Munchkin* munchkin) override;

	std::string getFullInfo() override {return "Remove a random modifier from hand";}
};


//Item 
// MUNCHKIN
// ACTIVE DECK
// DEACTIVED DECK

//Random item removal
class Runaway_ItemEquipedRemoval : public Runaway
{
public:
	void apply(Munchkin* munchkin) override;

	std::string getFullInfo() override {return "Remove a random equipped item";}
};

//Remove equiped item from Outfit with biggest base power
class Runaway_BiggestBonusCardRemoval : public Runaway
{
public:
	void apply(Munchkin* munchkin) override;
	
	std::string getFullInfo() override {return "Removed equipped item with the biggest base power";}
};

