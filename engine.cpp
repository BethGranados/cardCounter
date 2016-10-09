#include "engine.h"
#include "string"
#include "cstring"
#include "ctime"
#include <iostream>

using namespace std;

engine::engine()
{
    window.create(sf::VideoMode(400, 400), "Card Counter"); //Creates window.
    time_t curDate;
    tm * dateInfo;
    char LeTime[11];
    infoOutOfDoc.open("number.txt");
    int startVal;
    infoOutOfDoc >> startVal;
    counter.setValue(startVal);
    infoOutOfDoc.close();

    isRunning = true;



    while (window.isOpen())     //This will endlessly run until window is closed
    {
        while(isRunning)        //Will run endlessly until isRunning is set to false
        {
            events();   //Keyboard events
            update();   //Updating each object on the screen
            render();   //Updates the display
        }
        window.close(); //Closes the window when isRunning is set to false. I don't remember why I did this instead of just putting window.close() where ever the isRunning = false is.
                        //... I could argue that it is slightly more readable. But that might not necessarily be true.
    }
    time(&curDate);
    dateInfo = localtime(&curDate);

    strftime(LeTime, 11, "%Y-%m-%d",dateInfo);
    dateToPutInDoc.open("DateVals.txt", std::fstream::app);

    dateToPutInDoc<< LeTime << ":" << counter.getValue() <<"\n";
    dateToPutInDoc.close();
    numbToPutInDoc.open("number.txt");
    numbToPutInDoc << counter.getValue();
    numbToPutInDoc.close();
    return;
}


void engine::events()
{
    sf::Event event;
    while (window.pollEvent(event)) //When an event happens, like the resizing of the window or a keyboard type
    {
        switch (event.type) //We are going to make changes based on what kind of event it is.
        {
            case sf::Event::Closed:     //If we hit the X on the window
                isRunning = false;      //It'll close
                break;
            case sf::Event::TextEntered:    //If we type down text
                if(!cardCode.full())            //If the code's array isn't already full
                {
                    char temp = (char)event.text.unicode;   //We'll convert it to a character
                    if(cardCode.isValidChar(temp))              //Check if the character is a number
                    {
                        cardCode.addChar(temp);                     //Put it in the code array
                    }
                    else if(temp == 13)                         //If it is the enter button
                    {
                        if(!cardCode.alreadyScanned() && !cardCode.isEmpty())              //and we didn't already scan it
                        {
                            counter.increment();                    //and incremenr rhe counter
                            cardCode.setCurrentCodeAsLast();
                        }
                        cardCode.reset();                       //We'll empty the array
                    }
                }

                break;
            /*case sf::Event::MouseButtonPressed:
                if(button.withinBounds(sf::Mouse::getPosition(window)))
                {
                    counter.setValue(0);
                }
                break;*/
            default:
                break;
        }
    }
    return;
}


void engine::update()
{

    cardCode.update();
    counter.update();

    if(cardCode.full()) //If we had gone to the max amount of digits
    {
        cardCode.reset();   //We empty the cardCode's array
    }
    //button.update();


    return;
}

void engine::render()
{
    window.clear(sf::Color(79, 38, 131));   //Fill the prospective screen with purple
    window.draw(counter.display());         //Draw the counter number onto the prospective
    window.draw(cardCode.display());        //draw the code onto the prospective screen
    //window.draw(button.display());
    window.display();                       //Put prospective screen into the display
}
