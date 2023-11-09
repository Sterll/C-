//
// Created by yanis on 08/10/2023.
//

#include "header/map.h"

auto dernierTemps = chrono::steady_clock::now();

Map::Map(unordered_map<int, Asteroid>* asteroid, unordered_map<int, Missile>* missile){
    asteroids = asteroid;
    missiles = missile;
}

Map::~Map() {

}

void Map::render(RenderWindow &window, const int &width, const int &height) {
    Ship::getShip()->draw(window);
    spawnAsteroide(width, height);
    std::vector<int> missilesToRemove;
    std::vector<int> asteroidsToRemove;

    // DESSINER LES ASTEROIDES ET LES MISSILES
    if(!asteroids->empty()){
        for(auto &asteroid : *asteroids){
            asteroid.second.move(window, asteroidsToRemove);
        }
    }
    if(!missiles->empty()){
        for(auto &missile : *missiles){
            missile.second.move(*asteroids, window, missilesToRemove, asteroidsToRemove);
        }
    }

    // SUPPRIMER LES ASTEROIDES ET LES MISSILES
    for (int index : missilesToRemove) {
        missiles->erase(index);
    }
    for (int index : asteroidsToRemove) {
        asteroids->erase(index);
    }
}

void Map::spawnAsteroide(const int &width, const int &height){
    auto tempsActuel = std::chrono::steady_clock::now();
    auto tempsEcoule = std::chrono::duration_cast<std::chrono::milliseconds>(tempsActuel - dernierTemps).count();
    if (tempsEcoule >= intervalle) {
        asteroids->insert({asteroidMaxID, Asteroid(rand() % width, 0, asteroidMaxID)});
        asteroidMaxID++;
        if(intervalle >= 500) intervalle -= 100;
        dernierTemps = tempsActuel;
    }
}

void Map::spawnMissile(){
    missiles->insert({missileMaxID, Missile(Ship::getShip()->getPosX() + Ship::getShip()->getShipRadius() - 1, Ship::getShip()->getPosY() + Ship::getShip()->getShipRadius(), missileMaxID)});
    missileMaxID++;
}