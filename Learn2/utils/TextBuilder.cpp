//
// Created by yanis on 04/10/2023.
//
#include "TextBuilder.h"

TextBuilder::TextBuilder() {
    text.setFont(font);
    text.setString("");
}

TextBuilder::TextBuilder(const Font& font, const String& string) {
    text.setFont(font);
    text.setString(string);
}

TextBuilder TextBuilder::setFont(const Font& newFont) {
    text.setFont(newFont);
    return *this;
}

TextBuilder TextBuilder::setString(const String& string) {
    text.setString(string);
    return *this;
}

TextBuilder TextBuilder::setFillColor(Color color) {
    text.setFillColor(color);
    return *this;
}

TextBuilder TextBuilder::setPosition(int x, int y) {
    text.setPosition(x, y);
    return *this;
}

TextBuilder TextBuilder::setCharacterSize(int size) {
    text.setCharacterSize(size);
    return *this;
}

TextBuilder TextBuilder::setOutlineColor(Color color) {
    text.setOutlineColor(color);
    return *this;
}

TextBuilder TextBuilder::setStyle(Uint32 style) {
    text.setStyle(style);

    return *this;
}

Text TextBuilder::getText() {
    return text;
}

Font TextBuilder::getFont() {
    return font;
}





