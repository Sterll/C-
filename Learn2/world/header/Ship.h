//
// Created by yanis on 05/10/2023.
//

#ifndef CMAKESFMLPROJECT_SHIP_H
#define CMAKESFMLPROJECT_SHIP_H

#include "../../main.h"
#include "../../event/GlobalEvent.h"

class Ship {
public:
    Ship();
    Ship(float xPos, float yPos, Color fillColor);

    void draw(RenderWindow &window);
    void setPosX(float x);
    void setPosY(float y);
    void setShipLife(int life);
    void setShipVulnerable(bool vulnerable);

    void setPosition(float x, float y);
    void removeShipLife(int life);

    void removeShipPosX(float x);
    void removeShipPosY(float y);

    void addShipPosX(float x);
    void addShipPosY(float y);

    float getPosX();
    float getPosY();
    int getSpeed();
    int getShipLife();
    int getShipRadius();
    bool isVulnerable();

    static Ship* getShip();
};

#endif //CMAKESFMLPROJECT_SHIP_H
