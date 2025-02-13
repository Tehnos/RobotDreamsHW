#pragma once
#include <iostream>
class MilkReservoir
{
public:
    void showOperations();
    void receiveInput();
    void fill(float volume) { m_Volume = std::min(volume, MaxVolume); };
    void getMilk(float volume) { m_Volume -= 0.07f; };

    void empty() { m_Volume = 0.0f; };
    float getVolume() { return m_Volume; }
    void update();

private:
    int m_Operation = -1;

    float m_Volume = 0.0f;
    const float MaxVolume = 2.5f;
};