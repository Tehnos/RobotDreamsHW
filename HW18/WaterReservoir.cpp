#include "WaterReservoir.h"
#include <iostream>

void WaterReservoir::showOperations()
{
    std::cout << "\n--- Current water level: " << getVolume() << "l out of " << MaxVolume << "l max ---\n";
    std::cout << "1. Empty reservoir\n";
    std::cout << "2. Fill up with water\n";
    std::cout << "3. Back to main\n";
}

void WaterReservoir::receiveInput()
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

void WaterReservoir::update()
{
    switch (m_Operation)
    {
    case 1:
        m_Volume = 0.0f;
        std::cout << "Reservoir emptied.\n";
        break;
    case 2:
    {
        float newVolume = 0.0f;
        std::cout << "Filling...\n";
        while (true)
        {
            std::cout << "How much have you filled up? (Max: " << MaxVolume << "l) ";
            if (std::cin >> newVolume && newVolume >= 0.0f && newVolume <= MaxVolume)
            {
                m_Volume = newVolume; 
                std::cout << "Reservoir filled to " << m_Volume << "l.\n";
                break;
            }
            else
            {
                std::cout << "Invalid input. Please enter a number between 0 and " << MaxVolume << ".\n";
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