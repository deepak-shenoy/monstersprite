#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <string>

#include "IComponent.hpp"
#include "GameEntity.hpp"
#include "EntityManager.hpp"

int main() {

    // Setup window
    sf::RenderWindow window(sf::VideoMode(800,800), "Deepak's SFML Series");

    std::srand(std::time(nullptr));

    for (int i=0; i<50; i++) {
        std::shared_ptr<GameEntity> test = EntityManager::Instance().CreateEntity("ghost"+std::to_string(i));
        //Sprite2DComponent test1("./assets/images/ghost.png");
        test->AddSpriteComponent2D("./assets/images/ghost.png");

        float xPosition = std::rand()%400;
        float yPosition = std::rand()%400;
        test->SetPosition(xPosition, yPosition);
    }

    float xPosition = 0.0f;

    sf::Clock clock;
    window.setFramerateLimit(60);
    // Main application loop
    while(window.isOpen()){
        // Compute the frame rate
        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f / (currentTime);

        std::cout << "fps: " << fps << std::endl;

        sf::Event event;
        // Handle events
        while(window.pollEvent(event)){
            // Terminate application
            if(event.type == sf::Event::Closed) {
                window.close();
                std::cout << "Handle event closed" << std::endl;
                exit(EXIT_SUCCESS);
            }
        }

        // Clear window
        .gitignore
        // Draw all of our sprites
        EntityManager::Instance().RenderAll(window);
        // Draw sprites
        for(int i = 0; i<50; i++) {
            // Retrieve each of our entities by their name
            std::shared_ptr<GameEntity>  ent = EntityManager::Instance().GetEntity("ghost"+std::to_string(i));
            float x = ent->GetXPosition() + ent->XDirection;
            float y = ent->GetYPosition() + ent->YDirection;
            ent->SetPosition(x,y);
            if(x>400) {
                ent->XDirection *= -1.0f;
            }
            if(x<0) {
                ent->XDirection *= -1.0f;
            }
            if(y>400) {
                ent->YDirection *= -1.0f;
            }
            if(y<0) {
                ent->YDirection *= -1.0f;
            }
        }
        // Finally, we display and put forth our graphics scene.
        window.display();
    }
    return 0;
}
