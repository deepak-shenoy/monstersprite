//
// Created by Deepak Shenoy on 2/17/23.
//

#ifndef MONSTERSPRITE_ICOMPONENT_HPP
#define MONSTERSPRITE_ICOMPONENT_HPP

#include <SFML/Graphics.hpp>

class IComponent {
public:
    virtual ~IComponent() {}
    virtual void Render(sf::RenderWindow& ref) {};
    virtual void SetPosition(float x, float y) {};
};

#endif //MONSTERSPRITE_ICOMPONENT_HPP
