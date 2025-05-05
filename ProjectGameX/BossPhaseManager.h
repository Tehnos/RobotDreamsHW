#pragma once
#include "BossPhaseId.h"
#include <memory>

class Boss;
class BossPhase;

class BossPhaseManager
{
public:
    BossPhaseManager(Boss* boss);

    void update(float dt);
    void setPhase(BossPhaseId phaseId);

private:
    Boss* m_boss;
    std::unique_ptr<BossPhase> m_currentPhase;
    BossPhaseId m_currentPhaseId = BossPhaseId::PhaseOne;
};