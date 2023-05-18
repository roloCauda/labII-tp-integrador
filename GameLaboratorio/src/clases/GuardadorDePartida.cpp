#include <SFML\Graphics.hpp>
#include "GuardadorDePartida.h"
#include <iostream>

void GuardadorDePartida::guardarPartida(int vidas, int llavesObtenidas, sf::Vector2i posicionJugador, int enemigosDerrotados)
{
    _vidas = vidas;
    _llavesObtenidas = llavesObtenidas;
    _posicionJugador = posicionJugador;
    _enemigosDerrotados = enemigosDerrotados;

    grabarEnDisco();
}

int GuardadorDePartida::getVidas()
{
    return _vidas;
}

int GuardadorDePartida::getLlavesObtenidas()
{
    return _llavesObtenidas;
}

sf::Vector2i GuardadorDePartida::getPosicionJugador()
{
    return _posicionJugador;
}

int GuardadorDePartida::getEnemigosDerrotados()
{
    return _enemigosDerrotados;
}

bool GuardadorDePartida::grabarEnDisco()
{
    FILE *p;
    bool escribio;
    p= fopen("partidaGuardada.dat", "wb");
    if (p==NULL)return false;
    escribio=fwrite(this, sizeof*this, 1,p);
    fclose(p);
    return escribio;
}

bool GuardadorDePartida::leerDeDisco(int i)
{
    FILE *p;
    p=fopen("partidaGuardada.dat","rb");
    if(p==NULL) return false;
    fseek(p,i * sizeof(this), 0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}
