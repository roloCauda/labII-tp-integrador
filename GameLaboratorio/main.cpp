#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;
#include "./src/headers/Juego.h"
int main()
{
    Juego *juego = new Juego(sf::Vector2u (800,600));

    delete juego;
    return 0;
}
