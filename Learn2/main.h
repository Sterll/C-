//
// Created by yanis on 04/10/2023.
//

#ifndef CMAKESFMLPROJECT_MAIN_H
#define CMAKESFMLPROJECT_MAIN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "event/GlobalEvent.h"
#include "world/header/Missile.h"
#include "world/header/Asteroid.h"
#include <chrono>
#include <thread>
#include <unordered_map>
#include <vector>
#include <string>
#include "world/header/map.h"

#include <list>

using namespace std;
using namespace sf;

void spawnAsteroide();

void loadFont();
void updateScore();
void removeMissile(int index);
void removeAsteroid(int index);

unordered_map<int, Asteroid> getAsteroidList();
unordered_map<int, Missile> getMissileList();

int getWidth();
int getHeight();

void checkBtn();

int getAsteroidMaxID();
int getMissileMaxID();

Text* getTScore();
Text* getTLife();

#endif //CMAKESFMLPROJECT_MAIN_H
