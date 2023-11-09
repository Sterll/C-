//
// Created by yanis on 04/10/2023.
//

#ifndef CMAKESFMLPROJECT_MISSILE_H
#define CMAKESFMLPROJECT_MISSILE_H

#include "SFML/Graphics.hpp"
#include "Asteroid.h"
#include <list>
#include <unordered_map>

using namespace sf;

class Missile {

public:
    Missile();
    Missile(float xPos, float yPos, int index);
    ~Missile();

    void move(unordered_map<int, Asteroid> &asteroid, RenderWindow &window, vector<int> &missilesToRemove, vector<int> &asteroideToRemove);
    void draw(RenderWindow &window);
    void setPosX(float x);
    void setPosY(float y);
    void setIsAlreadyDestroy(bool isAlreadyDestroy);
    void setPosition(float x, float y);

    float getPosX();
    float getPosY();
    int getSpeed();

    int getIndexPos();
    bool isAlreadyDestroy();

    RectangleShape getMissile();

private:
    int posX;
    int posY;
    int speed;

    int indexPos;

    bool isAlreadyDestroyed = false;

    RectangleShape missile;
};

#endif //CMAKESFMLPROJECT_MISSILE_H
