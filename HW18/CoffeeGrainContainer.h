#pragma once
#include <iostream>

class CoffeeGrainContainer
{
public:
	CoffeeGrainContainer() :m_maxCapacityGrains(500.f), m_maxCapacityUsedgrains(300.f), m_usedGrains(0.0f), m_currentGrains(0.0f) {}
	void showOperations();
	void receiveInput();
	void update();

	void fillGrains(float volume) { m_currentGrains = std::min(volume, m_maxCapacityGrains); }
	float getGrains() const { return m_currentGrains; }
	void useGrains(float grains) { m_currentGrains -= grains; m_usedGrains += grains; };
	void empty() { m_usedGrains = 0.0f;  std::cout << "Cleaning used coffee grains...\n"; };
	void grindGrains(float amount);
	bool hasEnoughGrains(float requiredGrains) const{return m_currentGrains >= requiredGrains;}
	bool needsCleaning() const{	return m_usedGrains >= m_maxCapacityUsedgrains; }

private:
	int m_Operation = -1;
	float m_maxCapacityGrains;
	float m_maxCapacityUsedgrains;
	float m_usedGrains;
	float m_currentGrains;
};

