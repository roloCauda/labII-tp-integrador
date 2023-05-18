#include "GeneradorLlaves.h"
#include "Llave.h"

GeneradorLlaves::GeneradorLlaves(int nivel)
{
    //llave de la interfaz. :D
    Llave *llave = new Llave(sf::Vector2i(145,10));
    llaves.push_back(llave);

    if(nivel == 1)
    {
        Llave *llave1 = new Llave(sf::Vector2i(288,214));
        Llave *llave2 = new Llave(sf::Vector2i(155,217));
        Llave *llave4 = new Llave(sf::Vector2i(160,120));
        Llave *llave5 = new Llave(sf::Vector2i(508,310));

        llaves.push_back(llave1);
        llaves.push_back(llave2);
        llaves.push_back(llave4);
        llaves.push_back(llave5);
    }

    if(nivel == 2)
    {
        Llave *llave1 = new Llave(sf::Vector2i(152,653));

        llaves.push_back(llave1);
    }

}

std::vector <Llave*> GeneradorLlaves::crearTodas()
{
    return llaves;
}
