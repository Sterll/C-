#include "main.h"
#include "utils/TextBuilder.h"
#include "world/header/Ship.h"

const int width = 1360;
const int height = 768;

int score = 0;

Font font;
Text TScore;
Text TLife;

GlobalEvent globalEvent;

unordered_map<int, Missile> missiles;
unordered_map<int, Asteroid> asteroids;

Map world = Map(&asteroids, &missiles);

int main(){
    score = 0;

    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(width, height, 64), "Quantum - Learning", Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    loadFont();
    new Ship(width / 2 - 75,  height - 150, Color::White);

    TScore = TextBuilder(font, "Score : " + to_string(score)).setCharacterSize(24).setFillColor(Color::White).setPosition(width / 2, 10).getText();
    TLife = TextBuilder(font, "Vie : " + to_string(Ship::getShip()->getShipLife())).setCharacterSize(24).setFillColor(Color::White).setPosition(width / 2, 40).getText();

    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            globalEvent.InputHandler(event, window);
            checkBtn();
        }
        window.clear(Color::Black);
        window.draw(TScore);
        window.draw(TLife);

        world.render(window, width, height);

        window.display();
    }

    return 0;
}

void updateScore(){
    score++;
    TScore.setString("Score : " + to_string(score));
}

void loadFont(){
    if(!font.loadFromFile("res/poppins.ttf")){
        cout << "Error when we try to load font" << endl;
    }
}

void checkBtn(){
    if(globalEvent.getButton().enter){
        world.spawnMissile();
    }
    if(globalEvent.getButton().q){
        if(Ship::getShip()->getPosX() > 0) Ship::getShip()->removeShipPosX(Ship::getShip()->getSpeed());
    }
    if(globalEvent.getButton().d){
        if(Ship::getShip()->getPosX() < width - (Ship::getShip()->getShipRadius() * 2)) Ship::getShip()->addShipPosX(Ship::getShip()->getSpeed());
    }
}

void removeMissile(int index){
    missiles.erase(index);
}

void removeAsteroid(int index){
    asteroids.erase(index);
}

unordered_map<int, Asteroid> getAsteroidList(){
    return asteroids;
}

unordered_map<int, Missile> getMissileList(){
    return missiles;
}

int getWidth(){
    return width;
}

int getHeight(){
    return height;
}

Text* getTScore(){
    return &TScore;
}

Text* getTLife(){
    return &TLife;
}