#pragma once

class IResizable
{
public:
    virtual ~IResizable() = default;
    virtual void onResize(sf::Vector2u newSize) = 0;
}; 
