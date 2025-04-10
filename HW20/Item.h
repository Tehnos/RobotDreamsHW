#pragma once
#include "Tribe.h"
#include <string>

class Item
{
public:
	virtual int getPower(Tribe monsterTribeModifier) const { return 0; }
	virtual int getBasePower() const { return 0; }

	void setName(const std::string& name) { m_name = name; }
	const std::string getName() const { return m_name; }
	virtual std::string getFullInfo() const = 0;

protected:
	std::string m_name;
	//other fields like description, image, category

private:
};

class Weapon : public Item
{
public:
	Weapon(const std::string& name, int power) : m_power(power)
	{
		setName(name);
	}

	int getBasePower() const override
	{
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: None\n";
	}

protected:
	int m_power = 0;
};

class UndeadWeapon : public Weapon
{
public:
	UndeadWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Undead:
			return m_power * 2;
		case Tribe::Human:
		case Tribe::Zombie:
		default:
			return m_power;
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs UNDEADS!\n";
	}
};

class MagicWeapon : public Weapon
{
public:
	MagicWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Human:
			return m_power * 0.8f;
		case Tribe::Undead:
		case Tribe::Zombie:
		case Tribe::God:
			return m_power * 2;
		default:
			return m_power;
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs GODS BUT x0.8 vs HUMANS!\n";
	}
};
class HolySword : public Weapon
{
public:
	HolySword(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Human:
		case Tribe::Undead:
		case Tribe::Zombie:
			return m_power * 6;
		case Tribe::God:
		default:
			return m_power;
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x6 vs Zombie\n";
	}
};
class CursedWeapon : public Weapon
{
public:
	CursedWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		return m_power * -1; 
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: Cursed! Reduces power!\n";
	}
};

class SciFiWeapon : public Weapon
{
public:
	SciFiWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		if (monsterTribeModifier == Tribe::Alien)
			return m_power * 2;
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs ALIENS!\n";
	}
};

class ElvenWeapon : public Weapon
{
public:
	ElvenWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		if (monsterTribeModifier == Tribe::Orc)
			return m_power * 2;
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs ORCS!\n";
	}
};

class DragonSlayerWeapon : public Weapon
{
public:
	DragonSlayerWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		if (monsterTribeModifier == Tribe::Dragon)
			return m_power * 3;
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x3 vs DRAGONS!\n";
	}
};

class LegendaryWeapon : public Weapon
{
public:
	LegendaryWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		return m_power * 2; 
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: Legendary! Always x2 power!\n";
	}
};
class Armor : public Item
{
public:
	Armor(const std::string& name, int defense) : m_defense(defense)
	{
		setName(name);
	}

	virtual int getBasePower() const override
	{
		return m_defense;
	}

	virtual int getPower(Tribe) const override
	{
		return m_defense;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", defense: " + std::to_string(getBasePower()) + ", type: Armor\n";
	}

protected:
	int m_defense = 1;
};

class Shield : public Armor
{
public:
	Shield(const std::string& name, int defense) : Armor(name, defense) {}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", defense: " + std::to_string(getBasePower()) + ", type: Shield (Blocks more damage!)\n";
	}
};

class HolyArmor : public Armor
{
public:
	HolyArmor(const std::string& name, int defense) : Armor(name, defense) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Undead:
		case Tribe::God:
			return m_defense * 2;
		default:
			return m_defense;
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", defense: " + std::to_string(getBasePower()) + ", type: Holy Armor (x2 vs UNDEADS & DEMONS!)\n";
	}
};
