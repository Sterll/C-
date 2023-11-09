//
// Created by yanis on 04/10/2023.
//

#ifndef CMAKESFMLPROJECT_ASTEROID_H
#define CMAKESFMLPROJECT_ASTEROID_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace sf;

class Asteroid {
public:

    Asteroid();
    Asteroid(float xPos, float yPos, int index);
    ~Asteroid();

    void move(RenderWindow &window, vector<int> &asteroideToRemove);
    void draw(RenderWindow &window);
    void setDestroyed(bool destroyed);

    float getPosX();
    float getPosY();
    int getSpeed();

    int getIndexPos();
    int getRadius();

    bool isDestroyed();

    CircleShape getAsteroid();
private:
    int posX;
    int posY;
    int speed;

    int indexPos;
    int radius;

    bool destroyed = false;
    bool touched = false;

    std::chrono::steady_clock::time_point vulnerabilityTimer;

    CircleShape asteroid;
};

#endif //CMAKESFMLPROJECT_ASTEROID_H
