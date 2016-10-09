#include "codeObj.h"

codeObj::codeObj()
{
    font.loadFromFile("digital-7.ttf");     //How can I get rid of this duplicate...? Consider possibility of creating parent for counterObj and codeObj
    disp.setFont(font);
    disp.setString(" ");
    disp.setColor(sf::Color::White);
    disp.setPosition(80.f, 350.f);
    disp.setCharacterSize(12);
    currentSize = 0;

    code[MAX_CODE_SIZE + 1] = '\0';
    previousCode[MAX_CODE_SIZE + 1] = '\0';

    reset();
}
void codeObj::addChar(char toAdd)
{
    code[currentSize] = toAdd;
    increment();
    return;
}
bool codeObj::isValidChar(char toCheck)
{
    if((toCheck >= '0') && (toCheck <= '9'))
    {
        return true;
    }
    return false;
}
void codeObj::increment()
{
    currentSize++;
}
void codeObj::update()
{
    disp.setString(code);
}
void codeObj::reset()
{
    for(int x = 0; x < MAX_CODE_SIZE; x++)
    {
        code[x] = ' ';
    }
    currentSize = 0;
}


int codeObj::getCurrentSize()
{
    return currentSize;
}
sf::Text codeObj::display()
{
    return disp;
}
bool codeObj::full()
{
    if(currentSize >= MAX_CODE_SIZE)
    {
        return true;
    }
    return false;
}

bool codeObj::isEmpty()
{
    if(currentSize == 0)
    {
        return true;
    }
    return false;
}

void codeObj::setCurrentCodeAsLast()
{
    for (int x = 0; x < MAX_CODE_SIZE; x++)
    {
        previousCode[x] = code[x];
    }
}

//Check if the current code is the same as the last code we scanned
bool codeObj::alreadyScanned()
{
    for (int x = 0; x < MAX_CODE_SIZE; x++)
    {
        if (previousCode[x] != code[x])
        {
            return false;
        }
    }
    return true;
}

