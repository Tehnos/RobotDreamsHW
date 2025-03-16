#include "ModifierDeck.h"

#include "Modifier.h"

ModifierDeck::ModifierDeck()
{
	m_modifiersDatabase =
	{
		{new SimpleModifier{3}},
		{new SimpleModifier{3}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{4}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new DoubleMunchkinLevel{}},
		{new DoubleMunchkinLevel{}},
		{new HalvesMonsterLevel{Tribe::Undead}},
		{new HalvesMonsterLevel{Tribe::God}},
		{new HalvesMonsterLevel{Tribe::Alien}},
		{new HalvesMonsterLevel{Tribe::Dragon}}
	};
	m_availableModifiers = m_modifiersDatabase;
}

ModifierDeck::~ModifierDeck()
{
	for (Modifier* modifier : m_modifiersDatabase)
	{
		delete modifier;
	}
	m_modifiersDatabase.clear();
	m_availableModifiers.clear();
}

Modifier* ModifierDeck::generateModifier() const
{
	std::vector<Modifier*> availableModifierCopy = m_availableModifiers;

	if (availableModifierCopy.empty())
	{
		availableModifierCopy = m_availableModifiers;
	}

	unsigned int idx = std::rand() % availableModifierCopy.size();
	Modifier* selectedModifier = availableModifierCopy[idx];
	availableModifierCopy.erase(availableModifierCopy.begin() + idx);

	return selectedModifier;
}

std::vector<Modifier*> ModifierDeck::generateModifiers() const
{
	std::vector<Modifier*> availableModifierCopy = m_availableModifiers;
	std::vector<Modifier*> selectedModifiers;

	if (availableModifierCopy.empty())
	{
		availableModifierCopy = m_availableModifiers;
	}

	for (int i = 0; i < 4; ++i)
	{
		unsigned int idx = std::rand() % availableModifierCopy.size();
		selectedModifiers.push_back(availableModifierCopy[idx]);
		availableModifierCopy.erase(availableModifierCopy.begin() + idx);
	}

	return selectedModifiers;
}



