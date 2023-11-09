//
// Created by yanis on 04/10/2023.
//
#include "GlobalEvent.h"

GlobalEvent::GlobalEvent() {
    button.z = button.q = button.s = button.d = button.attack = button.escape = false;
}

void GlobalEvent::InputHandler(Event event, RenderWindow &window){
    if(event.type == Event::Closed){
        onClose(event, window);
    }
    if(event.type == Event::KeyPressed){
        onKeyPressed(event, window);
    }
    if(event.type == Event::KeyReleased){
        onKeyReleased(event, window);
    }
    if(event.type == Event::MouseButtonPressed){
        onMousePressed(event, window);
    }
    if(event.type == Event::MouseButtonReleased){
        onMouseReleased(event, window);
    }
}

void GlobalEvent::onKeyPressed(Event event, RenderWindow &window){
    switch (event.key.code) {
        case Keyboard::Z:
            button.z = true;
            break;
        case Keyboard::Q:
            button.q = true;
            break;
        case Keyboard::S:
            button.s = true;
            break;
        case Keyboard::D:
            button.d = true;
            break;
        case Keyboard::Escape:
            button.escape = true;
            break;
        case Keyboard::Enter:
            button.enter = true;
            break;
        default:
            break;
    }
}

void GlobalEvent::onKeyReleased(Event event, RenderWindow &window){
    switch (event.key.code) {
        case Keyboard::Z:
            button.z = false;
            break;
        case Keyboard::Q:
            button.q = false;
            break;
        case Keyboard::S:
            button.s = false;
            break;
        case Keyboard::D:
            button.d = false;
            break;
        case Keyboard::Escape:
            button.escape = false;
            break;
        case Keyboard::Enter:
            button.enter = false;
            break;
        default:
            break;
    }
}

void GlobalEvent::onMousePressed(Event event, RenderWindow &window){
    if(Mouse::isButtonPressed(Mouse::Left)){
        button.attack = true;
    }
}

void GlobalEvent::onMouseReleased(Event event, RenderWindow &window){
    if(!Mouse::isButtonPressed(Mouse::Left)){
        button.attack = false;
    }
}

void GlobalEvent::onClose(Event event, RenderWindow &window){
    window.close();
}

GlobalEvent::Button GlobalEvent::getButton(void) const {
    return button;
}
