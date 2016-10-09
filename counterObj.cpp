#include "SFML/Graphics.hpp"
#include "counterObj.h"

counterObj::counterObj()
{
    font.loadFromFile("digital-7.ttf");
    value = 0;
    disp.setFont(font);
    disp.setString("0");
    disp.setColor(sf::Color::White);
    disp.setCharacterSize(64);
    disp.setPosition(80.f, 140.f);
}
void counterObj::increment()
{
    value++;
}
void counterObj::update()
{
    int val = value;
    char displayedNumber[7];



    for (int y = 6; y >= 0; y--)
    {
        int temp = val % 10;
        displayedNumber[y] = intToChar(temp);

        val = val / 10;
    }

    displayedNumber[7] = '\0';
    disp.setString((std::string)displayedNumber);

}



char counterObj::intToChar(int num)
{
    return(char)(num + 48);
}

int counterObj::getValue()
{
    return value;
}
sf::Text counterObj::display()
{
    return disp;
}


