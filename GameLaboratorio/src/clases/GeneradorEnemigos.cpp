#include "GeneradorEnemigos.h"

GeneradorEnemigos::GeneradorEnemigos(int nivel)
{
    if(nivel == 1)
    {
        Enemigos *enemigos1 = new Enemigos(sf::Vector2i(200,410),sf::Vector2i(450,0),true);
        Enemigos *enemigos2 = new Enemigos(sf::Vector2i(128,260),sf::Vector2i(0,450),false);
        Enemigos *enemigos3 = new Enemigos(sf::Vector2i(668,170),sf::Vector2i(668,450),false);

        enemigos.push_back(enemigos1);
        enemigos.push_back(enemigos2);
        enemigos.push_back(enemigos3);
    }
    if(nivel == 2 ){
        Enemigos *enemigos1 = new Enemigos(sf::Vector2i(100,320),sf::Vector2i(285,320),true);
        Enemigos *enemigos2 = new Enemigos(sf::Vector2i(300,420),sf::Vector2i(480,420),true);
        Enemigos *enemigos3 = new Enemigos(sf::Vector2i(575,220),sf::Vector2i(575,360),false);
        Enemigos *enemigos4 = new Enemigos(sf::Vector2i(700,180),sf::Vector2i(700,400),false);
        enemigos.push_back(enemigos1);
        enemigos.push_back(enemigos2);
        enemigos.push_back(enemigos3);
        enemigos.push_back(enemigos4);
    }

}

std::vector <Enemigos*> GeneradorEnemigos::crearTodas()
{
    return enemigos;
}
