#include "Munchkin.h"
#include "Item.h"
#include "Modifier.h"

void Munchkin::updateLevelBy(int levels)
{
    if (m_level + levels <= 0)
    {
        m_level = 1;
    }
    else
    {
        m_level += levels;
    }

}

void Munchkin::addItem(Item* item)
{
    m_items.push_back(item);
}

void Munchkin::addItems(const std::vector<Item*>& items)
{
    m_items = items;
}

const std::vector<Item*>& Munchkin::getItems() const
{
    return m_items;
}

Modifier* Munchkin::popModifier(int idx)
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return nullptr;
    }

    Modifier* modifier = m_modifiers[idx];
    m_modifiers.erase(m_modifiers.begin() + idx);
    return modifier;
}
void Munchkin::addModifiers()
{
    if (m_modifiers.empty())
    {
        return;
    }

    std::srand(std::time(0));
    int index = std::rand() % m_modifiers.size();

    Modifier* newModifier = m_modifiers[index]; 
    m_modifiers.push_back(newModifier);
}
void Munchkin::removeModifierFromHand()
{
    if (m_modifiers.empty())
    {
        return;
    }

    std::srand(std::time(0));
    int index = std::rand() % m_modifiers.size();

    Modifier* modifier = m_modifiers[index];
    m_modifiers.erase(m_modifiers.begin() + index);

    delete modifier;
}
void Munchkin::randomItem()
{
    if (m_items.empty())
    {
        return;
    }

    std::srand(std::time(0));
    int index = std::rand() % m_items.size();

    Item* newItem = m_items[index]; 
    m_items.push_back(newItem);
}
void Munchkin::removeItemEquipped()
{
    if (m_items.empty())
    {
        return; 
    }

    std::srand(std::time(0)); 
    int index = std::rand() % m_items.size();

    Item* item = m_items[index];
    m_items.erase(m_items.begin() + index);

    delete item; 
}
void Munchkin::removeEquippedItemWithHighestPower()
{
    if (m_items.empty())
    {
        return; 
    }

    Item* itemWithHighestPower = nullptr;
    int maxPower = -1;

    for (Item* item : m_items)
    {
        if (Weapon* weapon = dynamic_cast<Weapon*>(item))
        {
            if (weapon->getBasePower() > maxPower)
            {
                maxPower = weapon->getBasePower();
                itemWithHighestPower = weapon;
            }
        }
    }

    if (itemWithHighestPower != nullptr)
    {
        auto it = std::find(m_items.begin(), m_items.end(), itemWithHighestPower);
        if (it != m_items.end())
        {
            m_items.erase(it);
            delete itemWithHighestPower; 
        }
    }
}
