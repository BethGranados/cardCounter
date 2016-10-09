#include "resetButton.h"

resetButton::resetButton()
{
    font.loadFromFile("digital-7.ttf");
    disp.setFont(font);
    disp.setString(" ");
    disp.setColor(sf::Color::White);
    disp.setPosition(350.f, 100.f);
    disp.setCharacterSize(12);
    disp.setString("Reset");
}

void resetButton::update()
{
    //disp.setString(code);
}

sf::Text resetButton::display()
{
    return disp;
}
bool resetButton::withinBounds(sf::Vector2i objLoc)
{
    if ((objLoc.x > 350.f) && (objLoc.x < 375.f) && (objLoc.y > 100.f) && (objLoc.y < 120.f))
    {
        return true;
    }
    return false;
}
