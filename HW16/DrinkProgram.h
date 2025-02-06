#pragma once

enum class DrinkType
{
    Espresso,
    Cappuccino
};

enum class DrinkProgramStatus
{
    Success = 0,
    LowWater,
    LowMilkLevel,
    CleanNeeded,
    //TODO HW, add new status if needed

    Count
};


class DrinkProgram
{
public:
    DrinkProgram(DrinkType type, class CoffeeMachine& context);

    void showInfo();
    DrinkProgramStatus prepare();

private:
    DrinkType m_drinkType;

    const float EsspressoVolume = 0.05f;
    const float CappuccinoVolume = 0.07f;
    const float CappuccinoMilkVolume = 0.07f;

    class CoffeeMachine& m_context;
};
