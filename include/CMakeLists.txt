#include_directories(${SFML_INCLUDE_DIRS})
add_library(heads OBJECT EntityManager.hpp GameEntity.hpp IComponent.hpp Sprite2DComponent.hpp)
include_directories(${SFML_INCLUDE_DIRS})
target_include_directories(heads PUBLIC .)