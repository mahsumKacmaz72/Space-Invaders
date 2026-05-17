cmake_minimum_required(VERSION 3.21)

project(SpaceInvaders LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SFML_ROOT "C:/SFML" CACHE PATH "SFML installation directory")
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML" CACHE PATH "SFML CMake package directory")

if(MINGW AND EXISTS "${SFML_ROOT}/lib/sfml-graphics.lib" AND NOT EXISTS "${SFML_ROOT}/lib/libsfml-graphics.dll.a")
    message(FATAL_ERROR
        "C:/SFML appears to be an MSVC SFML package, but CMake is using MinGW. "
        "Configure with a Visual Studio generator, for example: "
        "cmake -S . -B build -G \"Visual Studio 18 2026\" -A x64"
    )
endif()

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(SpaceInvaders
    main.cpp
   
    "include/oyuncu.hpp" "src/oyuncu.cpp"
    "include/mermi.hpp" "src/mermi.cpp"
      )

target_link_libraries(SpaceInvaders PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

if(WIN32)
    add_custom_command(TARGET SpaceInvaders POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${SFML_ROOT}/bin"
                "$<TARGET_FILE_DIR:SpaceInvaders>"
        COMMENT "Copying SFML DLLs next to the executable"
    )
endif()
