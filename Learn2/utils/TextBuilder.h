//
// Created by yanis on 04/10/2023.
//

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class TextBuilder {
public:
    TextBuilder();
    TextBuilder(const Font& font, const String& text);

    TextBuilder setFont(const Font& font);
    TextBuilder setString(const String& string);
    TextBuilder setFillColor(Color color);
    TextBuilder setPosition(int x, int y);
    TextBuilder setCharacterSize(int size);
    TextBuilder setOutlineColor(Color color);
    TextBuilder setStyle(Uint32 style);

    Text getText();
    Font getFont();

private:
    Font font;
    Text text;
};