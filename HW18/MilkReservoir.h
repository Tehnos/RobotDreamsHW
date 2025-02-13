#pragma once
#include <iostream>
class MilkReservoir
{
    //TODO HW: Need to implement MilkReservoir logic to be able to prepare Cappuccino
    //See WaterReservoir for reference, the logic here will be very similar
public:
    void showOperations();
    void receiveInput();
    void fill(float volume) { m_Volume = std::min(volume, MaxVolume); };
    void getMilk(float volume) { m_Volume -= volume; };

    void empty() { m_Volume = 0.0f; };
    float getVolume() { return m_Volume; }
    void update();

    //TODO HW ADDITIONAL: implement milk freshness logic
    //E.g.: start new timer after every empty/fill operation
    //and once this specified time is passed(in seconds/minutes for simplicity to test - mark that milk as gone bad and you can't prepare new Milk-required drinks
    //until the MilkReservoir is emptied and filled once again

private:
    int m_Operation = -1;

    float m_Volume = 0.0f;
    const float MaxVolume = 2.5f;
};