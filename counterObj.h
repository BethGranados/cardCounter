#ifndef COUNTEROBJ_H_INCLUDED
#define COUNTEROBJ_H_INCLUDED

#include "SFML/Graphics.hpp"
#include "string"


//Number on the screen that counts the number of cards scanned.
class counterObj
{
private:
    int value;
    sf::Text disp;
    sf::Font font;
public:

    //Sets default variables for the object
    counterObj();

    //Increases value
    void increment();

    //
    void update();

    //returns value
    int getValue();

    //Returns the display object to be inputted on the screen.
    sf::Text display();

    void setValue(int val)
    {
        value = val;
    }

    char intToChar(int num);


};

#endif // COUNTEROBJ_H_INCLUDED
