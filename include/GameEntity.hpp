//
// Created by Deepak Shenoy on 2/17/23.
//

#ifndef MONSTERSPRITE_GAMEENTITY_H
#define MONSTERSPRITE_GAMEENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <ctime>
#include "IComponent.hpp"
#include "Sprite2DComponent.hpp"

class GameEntity{
public:
    GameEntity(std::string name) {
        // Constructor
        m_name = name;
        XDirection = (rand()%5 + 1) - 3;
        YDirection = (rand()%5 + 1) - 3;
    }
    ~GameEntity() {
        // Destructor
    }

    void SetPosition(float x, float y){
        m_x = x;
        m_y = y;
        for(int i=0; i< m_components.size(); i++){
            m_components[i]->SetPosition(m_x, m_y);
        }
    }

    float GetXPosition() const {  // Use const because we are not modifying anything
        return m_x;
    }

    float GetYPosition() const {
        return m_y;
    }

    // Add Component
    void AddSpriteComponent2D(std::string filename) {
        std::shared_ptr<Sprite2DComponent> sprite2DComponent = std::make_shared<Sprite2DComponent>(filename);
        m_components.push_back(sprite2DComponent);
    }

    // Walk through all the 'renderable' components
    void Render(sf::RenderWindow& ref) {
        for(int i=0; i< m_components.size(); i++){
            m_components[i]->Render(ref);
        }
    }
public:
    float XDirection = 1.0f;
    float YDirection = 1.0f;

private:
    float m_x, m_y; // Positions of our game entity
    std::string m_name;
    std::vector<std::shared_ptr<IComponent>> m_components;
};


#endif //"MONSTERSPRITE_GAMEENTITY_H"
