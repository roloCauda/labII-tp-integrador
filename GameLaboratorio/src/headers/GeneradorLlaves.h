#ifndef GENERADORLLAVES_H
#define GENERADORLLAVES_H
#include "Llave.h"

class GeneradorLlaves
{
public:
    GeneradorLlaves(int nivel);
    std::vector <Llave*> crearTodas();
private:
    std::vector <Llave*> llaves;
};

#endif // GENERADORLLAVES_H
