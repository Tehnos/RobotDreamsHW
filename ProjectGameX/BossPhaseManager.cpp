#include "BossPhaseManager.h"
#include "BossPhase.h"

BossPhaseManager::BossPhaseManager(Boss* boss)
    : m_boss(boss)
{
    setPhase(BossPhaseId::PhaseOne);
}

void BossPhaseManager::update(float dt)
{
    if (m_currentPhase)
    {
        m_currentPhase->update(*m_boss, dt);
    }
}

void BossPhaseManager::setPhase(BossPhaseId phaseId)
{
    if (m_currentPhase)
    {
        m_currentPhase->onExit(*m_boss);
    }
    m_currentPhaseId = phaseId;
    m_boss->setCurrentPhaseId(phaseId);

    switch (phaseId)
    {
    case BossPhaseId::PhaseOne:
        m_currentPhase = std::make_unique<BossPhase1>();
        break;
    case BossPhaseId::PhaseTwo:
        m_currentPhase = std::make_unique<BossPhase2>();
        break;
    case BossPhaseId::PhaseThree:
        m_currentPhase = std::make_unique<BossPhase3>();
        break;
    case BossPhaseId::Dead:
        m_currentPhase = nullptr;
        break;
    }

    if (m_currentPhase)
    {
        m_currentPhase->onEnter(*m_boss);
    }
}
