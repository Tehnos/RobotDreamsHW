#pragma once
#include <vector>

class Item;

class ItemDeck
{
public:
	ItemDeck();
	~ItemDeck();

	std::vector<Item*> generateItems() const;

	void writeFile(const char* fileName) const;

private:
	std::vector<Item*> m_itemsDataBase;
};