#include "CoffeeGrainContainer.h"
#include<iostream>

void CoffeeGrainContainer::showOperations()
{
    std::cout << "\n--- Current grains level: " << getGrains() << "g out of " << m_maxCapacityGrains << "g max, container with used coffee beans: "<<m_usedGrains << "g out of " <<m_maxCapacityUsedgrains<< "---\n";
    std::cout << "1. Empty container\n";
    std::cout << "2. Fill up with grains\n";
    std::cout << "3. Back to main\n";
}

void CoffeeGrainContainer::receiveInput()
{
    while (true)
    {
        std::cout << "Choice: ";
        if (std::cin >> m_Operation && m_Operation >= 1 && m_Operation <= 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
        }
    }
}

void CoffeeGrainContainer::update()
{
    switch (m_Operation)
    {
    case 1:
        empty();
        break;
    case 2:
    {
        float newVolume = 0.0f;
        std::cout << "Filling...\n";
        while (true)
        {
            std::cout << "How much have you filled up? (Max: " << m_maxCapacityGrains << "g) ";
            if (std::cin >> newVolume && newVolume >= 0.0f && newVolume <= m_maxCapacityGrains)
            {
                fillGrains(newVolume);
                std::cout << "Reservoir filled to " << getGrains() << "g.\n";
                break;
            }
            else
            {
                std::cout << "Invalid input. Please enter a number between 0 and " << m_maxCapacityGrains << ".\n";
                std::cin.clear();
                while (std::cin.get() != '\n')
                    continue;
            }
        }
        break;
    }
    case 3:
    default:
        break;
    }
}
void CoffeeGrainContainer::grindGrains(float amount)
{
    if (m_usedGrains + amount <= m_maxCapacityUsedgrains)
    {
        m_usedGrains += amount;
        std::cout << "Grinding " << amount << "g of coffee grains...\n";
    }
    else
    {
        std::cout << "Cannot grind. Coffee grains container is full!\n";
    }
}
