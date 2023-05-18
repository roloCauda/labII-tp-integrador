#ifndef GUARDADORDEPARTIDA_H
#define GUARDADORDEPARTIDA_H

class GuardadorDePartida
{
    private:
        int _vidas;
        int _llavesObtenidas;
        sf::Vector2i _posicionJugador;
        int _enemigosDerrotados;
    public:
        void guardarPartida(int vidas, int llavesObtenidas, sf::Vector2i posicionJugador, int enemigosDerrotados);
        int getVidas();
        int getLlavesObtenidas();
        sf::Vector2i getPosicionJugador();
        int getEnemigosDerrotados();
        bool grabarEnDisco();
        bool leerDeDisco(int i);
};

#endif // GUARDADORDEPARTIDA_H
