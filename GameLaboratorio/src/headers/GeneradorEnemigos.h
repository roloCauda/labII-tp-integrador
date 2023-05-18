#ifndef GENERADORENEMIGOS_H
#define GENERADORENEMIGOS_H
#include "Enemigos.h"

class GeneradorEnemigos
{
public:
    GeneradorEnemigos(int nivel);
    std::vector <Enemigos*> crearTodas();
private:
    std::vector <Enemigos*> enemigos;
};

#endif // GENERADORENEMIGOS_H
