#ifndef BOMBA_H
#define BOMBA_H
#include "BaseObject.h"
#include "Reproductor.h"
#include <cstring>
#include <iostream>
enum estado{sinExplotar, explotando, vacio, explotar};

class Bomba : public BaseObject
{
    private:
        bool activo = false;
        int contador=0;
        std::string imagenes;
        sf::Sprite *explosion[6];
        sf::Texture *explosions[6];
        estado _estado=vacio;
        int timePrevio=120;
        int timeExplotando=120;
        Reproductor r;

    public:
        Bomba();
        sf::Sprite getExplosion(int pos);
        void cargarExplosion();
        estado getEstado(){return _estado;}
        void setEstado(estado e){_estado=e;}
        void porExplotar();
        void bombaExplotando();
        void updateExplotion();
};

#endif // BOMBA_H
