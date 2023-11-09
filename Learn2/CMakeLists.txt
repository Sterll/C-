cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Learn2 main.cpp
        event/GlobalEvent.cpp
        event/GlobalEvent.h
        main.h
        utils/TextBuilder.h
        utils/TextBuilder.cpp
        world/header/Missile.h
        world/Missile.cpp
        world/header/Asteroid.h
        world/Asteroid.cpp
        world/Ship.cpp
        world/header/Ship.h
        world/Ship.cpp
        world/map.cpp
        world/header/map.h
)
target_link_libraries(Learn2 PRIVATE sfml-graphics)
target_compile_features(Learn2 PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET Learn2
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Learn2>
            VERBATIM)
endif()

install(TARGETS Learn2)