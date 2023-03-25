//
// Created by Deepak Shenoy on 2/17/23.
//
#include "Sprite2DComponent.hpp"

    Sprite2DComponent::Sprite2DComponent(std::string filepath) {
        // Constructor
        m_texture.loadFromFile(filepath);
        m_sprite.setTexture(m_texture);
    }

    Sprite2DComponent::~Sprite2DComponent() {
        // Destructor
    }

    void Sprite2DComponent::SetPosition(float x, float y) {
        m_sprite.setPosition(x, y);
    }

    void Sprite2DComponent::Render(sf::RenderWindow& ref) {
        ref.draw(m_sprite);
    }