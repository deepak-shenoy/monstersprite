//
// Created by Deepak Shenoy on 2/17/23.
//

#ifndef MONSTERSPRITE_SPRITE2DCOMPONENT_HPP
#define MONSTERSPRITE_SPRITE2DCOMPONENT_HPP
#include <SFML/Graphics.hpp>
#include "IComponent.hpp"

class Sprite2DComponent: public IComponent {
public:
    Sprite2DComponent(std::string filepath) ;
    ~Sprite2DComponent();

    void SetPosition(float x, float y);

    void Render(sf::RenderWindow& ref);

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};

#endif //MONSTERSPRITE_SPRITE2DCOMPONENT_HPP
