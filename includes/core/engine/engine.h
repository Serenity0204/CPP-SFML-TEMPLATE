#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../config/config.h"
#include "../input_box/input_box.h"
#include "../button/buttons.h"
#include "../header/header.h"
#include "../../utils/middleware/middleware.h"
using namespace std;


class Engine 
{
private:
    // sfml private members here
    sf::RenderWindow _window;

    // system setup here
    InputBox _input_box;
    Buttons _buttons;
    Header _header;
    // private member variables here



    // private helper functions here
    // init
    void _init();
    // update
    void _update_buttons_event(sf::Event& event);
    void _update_keyboard_event();

public:
    // friend class
    friend class Middleware;
    // constructors and destructors
    Engine();
    ~Engine();
    // game processing
    void input();
    void run();
    void display();
};




#endif