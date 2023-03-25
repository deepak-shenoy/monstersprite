add_library(comps OBJECT Sprite2DComponent.cpp SpriteComponent.cpp)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
target_include_directories(comps PUBLIC ../include)
target_link_libraries(comps sfml-system sfml-window sfml-graphics sfml-audio sfml-network)