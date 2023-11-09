//
// Created by yanis on 04/10/2023.
//

#ifndef CMAKESFMLPROJECT_GLOBALEVENT_H
#define CMAKESFMLPROJECT_GLOBALEVENT_H

#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;
class GlobalEvent {

    struct Button { bool z, q, s, d, attack, escape, enter; };

public:
    GlobalEvent();
    void InputHandler(Event event, RenderWindow &window);
    GlobalEvent::Button getButton(void) const;

private:
    GlobalEvent::Button button;
    void onClose(Event event, RenderWindow &window);
    void onKeyPressed(Event event, RenderWindow &window);
    void onKeyReleased(Event event, RenderWindow &window);
    void onMousePressed(Event event, RenderWindow &window);
    void onMouseReleased(Event event, RenderWindow &window);
};

#endif //CMAKESFMLPROJECT_GLOBALEVENT_H
