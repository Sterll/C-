//
// Created by yanis on 08/10/2023.
//

#ifndef CMAKESFMLPROJECT_MAP_H
#define CMAKESFMLPROJECT_MAP_H

#include "SFML/Graphics.hpp"
#include "Asteroid.h"
#include "Missile.h"
#include <unordered_map>
#include "Ship.h"
using namespace std;
using namespace sf;

class Map {
public:
    Map(unordered_map<int, Asteroid>*, unordered_map<int, Missile>*);
    ~Map();

    void render(RenderWindow &window, const int &width, const int &height);
    void spawnAsteroide(const int &width, const int &height);
    void spawnMissile();

private:
    unordered_map<int, Asteroid>* asteroids;
    unordered_map<int, Missile>* missiles;

    int intervalle = 3 * 1000;

    int asteroidMaxID = 0;
    int missileMaxID = 0;
};

#endif //CMAKESFMLPROJECT_MAP_H
