//
// Created by yanis on 04/10/2023.
//
#include "header/Missile.h"
#include "../main.h"

Missile::Missile() {
    posX = 0;
    posY = 0;
    speed = 0;
    missile = RectangleShape(Vector2f(5, 10));
    missile.setPosition(posX, posY);

}

Missile::Missile(float xPos, float yPos, int index) {
    posX = xPos;
    posY = yPos;
    speed = 11;
    missile = RectangleShape(Vector2f(5, 25));
    missile.setPosition(posX, posY);
    indexPos = index;
}

Missile::~Missile() {

}

void Missile::move(unordered_map<int, Asteroid> &asteroid, RenderWindow &window, vector<int> &missilesToRemove, vector<int> &asteroideToRemove) {
    if(!isAlreadyDestroyed){
        posY -= speed;
        if(posY <= 0){
            isAlreadyDestroyed = true;
            missilesToRemove.push_back(indexPos);
            return;
        }
        for(auto &ast : asteroid){
            if(ast.second.isDestroyed()){
                continue;
            }
            if(posX >= ast.second.getPosX() && posX <= ast.second.getPosX() + (ast.second.getAsteroid().getRadius() * 2) && posY <= ast.second.getPosY() + (ast.second.getAsteroid().getRadius() * 2)){
                updateScore();
                missilesToRemove.push_back(indexPos);
                asteroideToRemove.push_back(ast.second.getIndexPos());
                ast.second.setDestroyed(true);
                isAlreadyDestroyed = true;
                return;
            }
        }
        missile.setPosition(posX, posY);
        draw(window);
    }
}

void Missile::draw(RenderWindow &window) {
    window.draw(missile);
}

float Missile::getPosX() {
    return posX;
}

float Missile::getPosY() {
    return posY;
}

int Missile::getSpeed() {
    return speed;
}

int Missile::getIndexPos() {
    return indexPos;
}

RectangleShape Missile::getMissile() {
    return missile;
}

bool Missile::isAlreadyDestroy() {
    return isAlreadyDestroyed;
}

void Missile::setPosX(float x) {
    posX = x;
}

void Missile::setPosY(float y) {
    posY = y;
}

void Missile::setIsAlreadyDestroy(bool isAlreadyDestroy) {
    isAlreadyDestroyed = isAlreadyDestroy;
}

void Missile::setPosition(float x, float y) {
    posX = x;
    posY = y;
    missile.setPosition(posX, posY);
}