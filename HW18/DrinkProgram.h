#pragma once

enum class DrinkType
{
	Espresso,
	Cappuccino,
	HotTea,
	ColdTea
};

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
	DrinkProgram(DrinkType type, class CoffeeMachine& context);
	virtual ~DrinkProgram() = default;

	virtual void showInfo() = 0;
	virtual DrinkProgramStatus prepare() = 0;

protected:
	DrinkType m_drinkType;
	class CoffeeMachine& m_context;
};

//Coffe
class Coffee :public DrinkProgram
{
public:
	Coffee(DrinkType type, class CoffeeMachine& context) :DrinkProgram(type, context) {}

	void showInfo() override;
	DrinkProgramStatus prepare() override;
protected:
	virtual DrinkProgramStatus prepareEspresso();
	virtual DrinkProgramStatus prepareCappuccino();
};


class Esspresso : public Coffee
{
public:
	Esspresso(CoffeeMachine& context) :Coffee(DrinkType::Espresso, context) {}
};


class Cappuccino : public Coffee
{
public:
	Cappuccino(CoffeeMachine& context) :Coffee(DrinkType::Cappuccino, context) {}
};


//Tea
class Tea : public DrinkProgram
{
public:
	Tea(DrinkType type, class CoffeeMachine& context) :DrinkProgram(type, context) {}

	void showInfo() override;
	DrinkProgramStatus prepare() override;
protected:
	virtual DrinkProgramStatus prepareHotTea();
	virtual DrinkProgramStatus prepareColdTea();
};

class HotTea : public Tea
{
public:
	HotTea(CoffeeMachine& context) :Tea(DrinkType::HotTea, context) {}
};

class ColdTea : public Tea
{
public:
	ColdTea(CoffeeMachine& context) :Tea(DrinkType::ColdTea, context) {}
};