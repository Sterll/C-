//
// Created by yanis on 04/10/2023.
//

#include "header/Asteroid.h"
#include "../main.h"
#include "header/Ship.h"

Asteroid::Asteroid() {
    posX = 0;
    posY = 0;
    speed = 0;
    radius = 0;
    asteroid = CircleShape(radius);
    asteroid.setPosition(posX, posY);
}

Asteroid::Asteroid(float xPos, float yPos, int index) {
    posX = xPos;
    posY = yPos;
    speed = 2;
    radius = 30;
    asteroid = CircleShape(radius);
    asteroid.setPosition(posX, posY);
    asteroid.setFillColor(Color(156, 156,156));
    indexPos = index;
}

Asteroid::~Asteroid() {

}

void Asteroid::move(RenderWindow &window, vector<int> &asteroideToRemove) {
    if(destroyed) return;
    posY += speed;
    asteroid.setPosition(posX, posY);
    draw(window);
    if (!(Ship::getShip()->isVulnerable())) {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - vulnerabilityTimer).count();

        if (elapsedTime >= 2) {
            Ship::getShip()->setShipVulnerable(true); // Rétablissez la vulnérabilité après 2 secondes
        }
    } else {
        for (int x = posX; x <= posX + radius * 2; ++x) {
            for (int y = posY; y <= posY + radius * 2; ++y) {
                if(x >= Ship::getShip()->getPosX() && x <= Ship::getShip()->getPosX() + Ship::getShip()->getShipRadius() * 2 && y >= Ship::getShip()->getPosY() && y <= Ship::getShip()->getPosY() + Ship::getShip()->getShipRadius() * 2){
                    if(Ship::getShip()->isVulnerable()){
                        touched = true;
                    }
                }
            }
        }
        if(touched){
            touched = false;
            setDestroyed(true);
            Ship::getShip()->setShipVulnerable(false);
            Ship::getShip()->removeShipLife(1);
            getTLife()->setString("Vie : " + to_string(Ship::getShip()->getShipLife()));
            if (Ship::getShip()->getShipLife() == 0){
                cout << "Game Over" << endl;
                window.close();
            } else {
                vulnerabilityTimer = std::chrono::steady_clock::now();
            }
        }
    }
}

void Asteroid::draw(RenderWindow &window) {
    window.draw(asteroid);
}

float Asteroid::getPosX() {
    return posX;
}

float Asteroid::getPosY() {
    return posY;
}

int Asteroid::getSpeed() {
    return speed;
}

int Asteroid::getIndexPos() {
    return indexPos;
}

int Asteroid::getRadius() {
    return radius;
}

CircleShape Asteroid::getAsteroid() {
    return asteroid;
}

void Asteroid::setDestroyed(bool destroyed) {
    Asteroid::destroyed = destroyed;
}

bool Asteroid::isDestroyed() {
    return destroyed;
}