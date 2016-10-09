#ifndef CODEOBJ_H_INCLUDED
#define CODEOBJ_H_INCLUDED


#include <SFML/Graphics.hpp>

//Numbers on screen that represent the card's input
class codeObj
{
private:
    static const int MAX_CODE_SIZE = 10;
    char code[MAX_CODE_SIZE + 1];
    char previousCode[MAX_CODE_SIZE + 1];
    sf::Text disp;
    int currentSize;
    sf::Font font;
public:
    //Sets default variables for the class.
    codeObj();

    //Adds 'toAdd' to the array code[]
    void addChar(char toAdd);

    //Checks if the character is a number
    bool isValidChar(char toCheck);

    //Increases currentSize
    void increment();

    //
    void update();

    //Empties code[] and sets currentSize to zero
    void reset();

    //Returns currentSize
    int getCurrentSize();

    //returns the display object to be inputted on the screen.
    sf::Text display();

    //Checks if the array was already filled
    bool full();

    //Checks if the array is empty
    bool isEmpty();

    //Saves the current code for use to check if we had just scanned it
    void setCurrentCodeAsLast();

    //Check if the current code is the same as the last code we scanned
    bool alreadyScanned();
};



#endif // CODEOBJ_H_INCLUDED
