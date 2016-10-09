#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>
#include "codeObj.h"
#include "counterObj.h"
#include "resetButton.h"


//Class where the main loop, input and such are. Might also be a GOD object. Will need to clean later.
class engine
{
private:
    bool isRunning;
    sf::RenderWindow window;
    counterObj counter;
    codeObj cardCode;
    resetButton button;
    std::ifstream infoOutOfDoc;
    std::ofstream dateToPutInDoc;
    std::ofstream numbToPutInDoc;
public:
    //Put default values into the variables and runs the events(), update(), and render() in a loop.
    engine();

    //Takes in all keyboard events
    void events();

    //Does all things that must be done each frame
    void update();

    //Updates the display window.
    void render();


};


#endif // ENGINE_H_INCLUDED
