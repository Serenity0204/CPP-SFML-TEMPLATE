#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include <string>
#include <vector>
#include <cassert>
#include <SFML/Graphics.hpp>
using namespace std;

class Middleware
{
private:
    string _input_box_text;
    string _file_name;
    string _text_input;
public:
    Middleware();
    ~Middleware();
    // example
    // void load_stuff_from_engine(string text);
    // string get_stuff_from_engine();
};

extern Middleware middleware;

#endif // !MIDDLEWARE_H