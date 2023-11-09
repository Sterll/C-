//
// Created by yanis on 05/10/2023.
//

#include "header/Ship.h"

float shipX;
float shipY;
const int shipSpeed = 10;
int shipLife = 3;
const int shipRadius = 75;

bool shipVulnerable = true;

Ship ship;

CircleShape shipF(shipRadius, 3);

enum POWER_UP {
    SHIELD,
    SPEED,
    GIANT_MISSILE,
    LIFE
};

Ship::Ship() {
    shipF.setFillColor(Color::White);
    shipF.setPosition(shipX, shipY);
    ship = *this;
}

Ship::Ship(float xPos, float yPos, Color fillColor) {
    shipF.setFillColor(fillColor);
    shipF.setPosition(xPos, yPos);
    shipX = xPos;
    shipY = yPos;
    ship = *this;
}

void Ship::draw(RenderWindow &window) {
    window.draw(shipF);
}

void Ship::setPosX(float x) {
    shipX = x;
}

void Ship::setPosY(float y) {
    shipY = y;
}

void Ship::setShipLife(int life) {
    shipLife = life;
}

void Ship::setPosition(float x, float y) {
    shipF.setPosition(x, y);
}

void Ship::removeShipLife(int life) {
    shipLife -= life;
}

void Ship::removeShipPosX(float x) {
    shipX -= x;
    setPosition(shipX, shipY);
}

void Ship::removeShipPosY(float y) {
    shipY -= y;
    setPosition(shipX, shipY);
}

float Ship::getPosX() {
    return shipX;
}

float Ship::getPosY() {
    return shipY;
}

int Ship::getSpeed() {
    return shipSpeed;
}

int Ship::getShipLife() {
    return shipLife;
}

int Ship::getShipRadius() {
    return shipRadius;
}


void Ship::addShipPosX(float x) {
    shipX += x;
    setPosition(shipX, shipY);
}

void Ship::addShipPosY(float y) {
    shipY += y;
    setPosition(shipX, shipY);
}

bool Ship::isVulnerable() {
    return shipVulnerable;
}

void Ship::setShipVulnerable(bool value) {
    shipVulnerable = value;
}

Ship* Ship::getShip() {
    return &ship;
}

