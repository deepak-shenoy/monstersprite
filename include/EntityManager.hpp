//
// Created by Deepak Shenoy on 2/17/23.
//

#ifndef MONSTERSPRITE_ENTITYMANAGER_HPP
#define MONSTERSPRITE_ENTITYMANAGER_HPP

#include <unordered_map>
#include <memory>
#include "GameEntity.hpp"
#include <string>

// This is a singleton for now - until we decide otherwise
// This will make use of the factor method pattern
class EntityManager{
public:
    static EntityManager& Instance() {
        static EntityManager* instance = new EntityManager;
        return *instance;
    }

    // To create a new entity
    // And then add it to our container data structure
    std::shared_ptr<GameEntity>CreateEntity(std::string name){
        // Create a new entity
        std::shared_ptr<GameEntity> newEntity = std::make_shared<GameEntity>(name);
        // Store entity in our collection
        m_entities.insert(std::make_pair(name, newEntity));
        // Return our new entity to the client
        return newEntity;
    };

    // Retrieve an entity
    std::shared_ptr<GameEntity> GetEntity(std::string name) {
        return m_entities[name];
    };

    void RenderAll(sf::RenderWindow& ref){
        for(auto it = m_entities.begin(); it!=m_entities.end(); it++){
            std::string entityname = it->first;
            it->second->Render(ref);
        }
    }

private:
    EntityManager(){}
    ~EntityManager(){}

    std::unordered_map<std::string, std::shared_ptr<GameEntity>> m_entities;

};

#endif //MONSTERSPRITE_ENTITYMANAGER_HPP
