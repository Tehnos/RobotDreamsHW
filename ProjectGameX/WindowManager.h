#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include "IResizable.h"

class WindowManager
{
public:
    static WindowManager& getInstance()
    {
        static WindowManager instance;
        return instance;
    }
    void initialize(sf::RenderWindow* window) { m_window = window; updateView(); }
    void registerResizable(IResizable* obj) { m_resizables.push_back(obj); }
    void unregisterResizable(IResizable* obj) { m_resizables.erase(std::remove(m_resizables.begin(), m_resizables.end(), obj), m_resizables.end()); }
    void handleResizeEvent(const sf::Event::Resized& resized)
    {
        if (!m_window) return;
        m_window->setView(sf::View(sf::FloatRect({ 0, 0 }, { static_cast<float>(resized.size.x), static_cast<float>(resized.size.y) })));
        notifyResize({ resized.size.x, resized.size.y });
    }
    sf::RenderWindow* getWindow() const { return m_window; }
    void notifyResize(sf::Vector2u newSize)
    {
        if (!m_window) return;
        m_window->setView(sf::View(sf::FloatRect({ 0, 0 },
            { static_cast<float>(newSize.x), static_cast<float>(newSize.y) })));

        for (auto* obj : m_resizables)
        {
            obj->onResize(newSize);
        }
    }

private:
    WindowManager() = default;
    void updateView()
    {
        if (m_window)
        {
            sf::Vector2u size = m_window->getSize();
            m_window->setView(sf::View(sf::FloatRect({ 0, 0 }, { (float)size.x, (float)size.y })));
        }
    }

    sf::RenderWindow* m_window = nullptr;
    std::vector<IResizable*> m_resizables;
};