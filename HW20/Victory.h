#pragma once
#include <string>
#include <cstdlib> 

class Munchkin;
class Victory
{
public:
	virtual void apply(Munchkin* munchkin) = 0;

	virtual std::string getFullInfo() { return ""; }
};


#include <cstdlib> // Add this include for std::rand

class Victory_LevelUpgrade : public Victory
{
public:
    Victory_LevelUpgrade(int level = std::rand() % 3) : m_levelToUP(level) {} 
    void apply(Munchkin* munchkin) override;
    std::string getFullInfo() override {
        return "Level Up: " + std::to_string(m_levelToUP) + " level(s)";
    }
protected:
    int m_levelToUP;
};

class Victory_RandomModifier : public Victory
{
public:
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return "Random modifier from deck"; }
    
};
class Victory_RandomItem : public Victory
{
public:
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return "Random item from deck"; }
};