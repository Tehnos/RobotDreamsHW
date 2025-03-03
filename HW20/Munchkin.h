#pragma once
#include <vector>
#include <string>
#include <ctime> 

class Item;
class Modifier;

using uint = unsigned int;

class Munchkin
{
public:
	Munchkin() = default;
	Munchkin(const std::string& name) : m_name(name) {}

	void setName(const std::string& name) { m_name = name; }
	const std::string& getName() const { return m_name; }

	int getLevel() const { return m_level; } // used by FIGHT
	void updateLevelBy(int levels);	//used by VICTORY FLOW

	void addItem(Item* item);
	void addItems(const std::vector<Item*>& items);
	const std::vector<Item*>& getItems() const;

	Modifier* popModifier(int idx);
	void addModifiers();
	const std::vector<Modifier*>& getModifiers() const { return m_modifiers; }	//FOR UI ONLY
	void addModifiers(const std::vector<Modifier*>& modifiers) { m_modifiers = modifiers; }

	void removeModifierFromHand();
	void randomItem();
	void removeItemEquipped();
	void removeEquippedItemWithHighestPower();

private:
	uint m_level = 1;
	std::string m_name;

	std::vector<Item*> m_items;
	std::vector<Modifier*> m_modifiers;
};