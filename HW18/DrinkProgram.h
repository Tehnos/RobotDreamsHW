#pragma once

enum class DrinkProgramStatus
{
	Success = 0,
	LowWater,
	LowMilkLevel,
	CleanNeeded,
	LowGrainsLevel,
	Count
};


class DrinkProgram
{
public:
	DrinkProgram( class CoffeeMachine& context);
	virtual ~DrinkProgram() = default;

	virtual void showInfo() = 0;
	virtual DrinkProgramStatus prepare() = 0;

protected:
	class CoffeeMachine& m_context;
};

//Coffe
class Coffee : public DrinkProgram
{
public:
	Coffee(CoffeeMachine& context) : DrinkProgram(context) {}

	void showInfo() override = 0;
	DrinkProgramStatus prepare() override = 0;
};

class Espresso : public Coffee
{
public:
	Espresso(CoffeeMachine& context) : Coffee(context) {}
	void showInfo() override;
	DrinkProgramStatus prepare() override;
};

class Cappuccino : public Coffee
{
public:
	Cappuccino(CoffeeMachine& context) : Coffee(context) {}
	void showInfo() override;
	DrinkProgramStatus prepare() override;
};

// Tea
class Tea : public DrinkProgram
{
public:
	Tea(CoffeeMachine& context) : DrinkProgram(context) {}

	void showInfo() override = 0;
	DrinkProgramStatus prepare() override = 0;
};

class HotTea : public Tea
{
public:
	HotTea(CoffeeMachine& context) : Tea(context) {}
	void showInfo() override;
	DrinkProgramStatus prepare() override;
};

class ColdTea : public Tea
{
public:
	ColdTea(CoffeeMachine& context) : Tea(context) {}
	void showInfo() override;
	DrinkProgramStatus prepare() override;
};
