#include "DrinkProgram.h"
#include "CoffeeMachine.h"
#include <chrono>
#include <thread>

DrinkProgram::DrinkProgram(DrinkType type, CoffeeMachine& context) : 
    m_drinkType(type), 
    m_context(context) {}


void Coffee::showInfo()
{
    switch (m_drinkType)
    {
    case DrinkType::Espresso:
        std::cout << "Espresso!";
        break;
    case DrinkType::Cappuccino:
        std::cout << "Cappuccino!";
        break;
    default:
        break;
    }
}

DrinkProgramStatus Coffee::prepare()
{
    switch (m_drinkType)
    {
    case DrinkType::Espresso:
        return prepareEspresso();
    case DrinkType::Cappuccino:
        return prepareCappuccino();
    default:
        return DrinkProgramStatus::Success;
    }
}

DrinkProgramStatus Coffee::prepareEspresso()
{
    if (m_context.getCoffeeGrainsContainer().needsCleaning() == true)
    {
        return DrinkProgramStatus::CleanNeeded;
    }
    const float EsspressoVolume = 0.05f;
    const float EsspressoCoffeegrainsVolume = 0.01f;
    if (m_context.getWaterReservoir().getVolume() < EsspressoVolume)
    {
        return DrinkProgramStatus::LowWater;
    }
    else if (m_context.getCoffeeGrainsContainer().getGrains() < EsspressoCoffeegrainsVolume)
    {
        return DrinkProgramStatus::LowGrainsLevel;
    }
    else if (m_context.getCoffeeGrainsContainer().needsCleaning())
    {
        return DrinkProgramStatus::CleanNeeded;
    }

    m_context.getWaterReservoir().useWater(EsspressoVolume);
    m_context.getCoffeeGrainsContainer().useGrains(EsspressoCoffeegrainsVolume);

    m_context.getCoffeeGrainsContainer().grindGrains(EsspressoCoffeegrainsVolume);
    std::cout << "\n\nGrrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\nPreparing... Espresso... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 5; i > 3; i--)
    {
        std::cout << i << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "..Hanging... ";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "DONE!\n\n";

    return DrinkProgramStatus::Success;
}

DrinkProgramStatus Coffee::prepareCappuccino()
{
    if (m_context.getCoffeeGrainsContainer().needsCleaning() == true)
    {
        return DrinkProgramStatus::CleanNeeded;
    }
    const float CappuccinoVolume = 0.07f;
    const float CappuccinoMilkVolume = 0.07f;
    const float  CappuccinoCoffeeGrainsVolume = 320.f;
    if (m_context.getWaterReservoir().getVolume() < CappuccinoVolume)
    {
        return DrinkProgramStatus::LowWater;
    }
    else if (m_context.getMilkReservoir().getVolume() < CappuccinoMilkVolume)
    {
        return DrinkProgramStatus::LowMilkLevel;
    }
    else if (m_context.getCoffeeGrainsContainer().getGrains() < CappuccinoCoffeeGrainsVolume)
    {
        return DrinkProgramStatus::LowGrainsLevel;
    } 

    m_context.getWaterReservoir().useWater(CappuccinoVolume);
    m_context.getMilkReservoir().getMilk(CappuccinoMilkVolume);
    m_context.getCoffeeGrainsContainer().useGrains(CappuccinoCoffeeGrainsVolume);


    m_context.getCoffeeGrainsContainer().grindGrains(CappuccinoCoffeeGrainsVolume);
    std::cout << "\n\nGrrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\nPreparing... Cappuccino... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Adding water...";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Adding milk...";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Making milk foam.... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 5; i > 3; i--)
    {
        std::cout << i << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "..Hanging... ";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "DONE!\n\n";

    return DrinkProgramStatus::Success;

};

void Tea::showInfo()
{

    switch (m_drinkType)
    {
    case DrinkType::HotTea:
        std::cout << "Hot tea!";
        break;
    case DrinkType::ColdTea:
        std::cout << "Cold tea!";
        break;
    default:
        break;
    }
}
DrinkProgramStatus Tea::prepare()
{
    switch (m_drinkType)
    {
    case DrinkType::HotTea:
        return prepareHotTea();
    case DrinkType::ColdTea:
        return prepareColdTea();
    default:
        return DrinkProgramStatus::Success;
    }
}

DrinkProgramStatus Tea::prepareHotTea()
{
    const float HotTeaVolume = 0.3f;
    if (m_context.getWaterReservoir().getVolume() < HotTeaVolume)
    {
        return DrinkProgramStatus::LowWater;
    }

    m_context.getWaterReservoir().useWater(HotTeaVolume);

    std::cout << "\n\nGrrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\nPreparing... Heating the water.. ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 5; i > 3; i--)
    {
        std::cout << i << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "..Hanging... ";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "DONE!\n\n";

    return DrinkProgramStatus::Success;
}

DrinkProgramStatus Tea::prepareColdTea()
{
    const float ColdTeaVolume = 0.37f;
    if (m_context.getWaterReservoir().getVolume() < ColdTeaVolume)
    {
        return DrinkProgramStatus::LowWater;
    }

    m_context.getWaterReservoir().useWater(ColdTeaVolume);

    std::cout << "\n\nGrrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\nPreparing... Pouring iced tea.. ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 5; i > 3; i--)
    {
        std::cout << i << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "..Hanging... ";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "DONE!\n\n";

    return DrinkProgramStatus::Success;
}
