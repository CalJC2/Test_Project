cmake_minimum_required(VERSION 3.21)
project(TestProject)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/Vector2.cpp src/Vector2.h src/Player.cpp src/Player.h src/GameObject.cpp src/GameObject.h src/Bullet.cpp src/Bullet.h src/Turret.cpp src/Turret.h src/Camera.cpp src/Camera.h src/Obstacles.cpp src/Obstacles.h src/GameState.cpp src/GameState.h)
add_executable(TestProject ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries(TestProject sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)
